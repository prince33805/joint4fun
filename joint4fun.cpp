#include<iostream>
#include<string>
#include<ctime>
#include <cstdlib>
using namespace std;

int row,col,boardsize;
struct playerInfo 
{
	char playerName[99];
	char playerID;
};

int PlayerDrop( char board[][10], playerInfo activePlayer ); 
int BotDrop( char board[][10], playerInfo activePlayer );
void CheckBelow ( char board[][10], playerInfo activePlayer, int dropChoice ); 
void DisplayBoard ( char board[][10] );
int CheckFour ( char board[][10], playerInfo activePlayer );
int FullBoard( char board[][10] );
void PlayerWin ( playerInfo activePlayer );
int restart ( char board[][10] );
int GetValue(int t);
char input[99];

int main()
{
	playerInfo playerOne;
    playerInfo playerTwo;
	char board[9][10]; 
	int trueWidth = 7; 
	int trueLength = 6; 
	int dropChoice, win, full, again;
    int players;

    srand(time(0));
	cout << "Welcome to Join4fun." << endl << endl;
    do{
        cout<<"Would you like to play 1 or 2 players? or press 3 to exit"<<endl;
        cin >> players;
            if(players == 1)
		        {
                    cout << "Player One name: ";
	                cin  >> playerOne.playerName;
	                playerOne.playerID = 'X';
                    cout << "Bot name: ";
	                cin  >> playerTwo.playerName;
	                playerTwo.playerID = 'O';
                    do{
	                    cout<<"Choose Board Size 1.4X5 2.6X7 3.8X10 : ";
	                    cin>>boardsize;
	                }while(boardsize>3||boardsize<0);

                    full = 0,win=0,again=0;
                    DisplayBoard( board);
                    do{
                        dropChoice = PlayerDrop( board, playerOne );
                        CheckBelow( board, playerOne, dropChoice );
                        
                        win = CheckFour( board, playerOne );
                        if ( win == 1 )
                        {
                            PlayerWin(playerOne);
                            again = restart(board);
                            if (again == 2)
                            {
                                break;
                            }
                        }

                        dropChoice = BotDrop( board, playerTwo );
                        CheckBelow( board, playerTwo, dropChoice );
                        DisplayBoard( board );
                        win = CheckFour( board, playerTwo );
                        if ( win == 1 )
                        {
                            PlayerWin(playerTwo);
                            again = restart(board);
                            if (again == 2)
                                {
                                    break;
                                }
                        }
                        full = FullBoard( board );
                        if(boardsize==1){
					        row=4;
					        col=5;
					    }else if (boardsize==2) {
					        row=6;
					        col=7;
					    }else if(boardsize==3){
					        row=8;
					        col=10;
					    }
                        if ( full == col )
                        {
                            cout << "The board is full,draw!" << endl;
                            again = restart(board);
                        }

                    }while ( again != 2 );
		        }
		    else if(players==2)
		        {
			        cout << "Player One name: ";
	                cin  >> playerOne.playerName;
	                playerOne.playerID = 'X';
	                cout << "Player Two name: ";
	                cin  >> playerTwo.playerName;
	                playerTwo.playerID = 'O';
                    do{
	                    cout<<"Choose Board Size 1.4X5 2.6X7 3.8X10 : ";
	                    cin>>boardsize;
	                }while(boardsize>3||boardsize<0);
            
                    full = 0,win=0,again=0;
                    DisplayBoard( board);
                    do{
                        dropChoice = PlayerDrop( board, playerOne );
                        CheckBelow( board, playerOne, dropChoice );
                        DisplayBoard( board );
                        win = CheckFour( board, playerOne );
                        if ( win == 1 )
                        {
                            PlayerWin(playerOne);
                            again = restart(board);
                            if (again == 2)
                            {
                                break;
                            }
                        }

                        dropChoice = PlayerDrop( board, playerTwo );
                        CheckBelow( board, playerTwo, dropChoice );
                        DisplayBoard( board );
                        win = CheckFour( board, playerTwo );
                        if ( win == 1 )
                        {
                            PlayerWin(playerTwo);
                            again = restart(board);
                            if (again == 2)
                                {
                                    break;
                                }
                        }
                        full = FullBoard( board );
                        if(boardsize==1){
					        row=4;
					        col=5;
					    }else if (boardsize==2) {
					        row=6;
					        col=7;
					    }else if(boardsize==3){
					        row=8;
					        col=10;
					    }
                        if ( full == col )
                        {
                            cout << "The board is full,draw!" << endl;
                            again = restart(board);
                        }

                    }while ( again != 2 );
		        }
		            else if(players==3)
			        exit(1);
	    }while(players != 1 || players != 2);

return 0;
}

int PlayerDrop( char board[][10], playerInfo activePlayer )
{
	int dropChoice,bodcol;
    if(boardsize==1){
        bodcol=5;
    }else if (boardsize==2) {
        bodcol=7;
    }else if(boardsize==3){
        bodcol=10;
    }
    
	do
	{
		cout << activePlayer.playerName << "'s Turn ";
		cout << "Please enter a number between 1 and"<<bodcol<<": ";
		cin  >> dropChoice;

		while ( board[1][dropChoice] == 'X' || board[1][dropChoice] == 'O' )
		{
			cout << "full,please enter a new row: ";
			cin  >> dropChoice;
		}

	}while ( dropChoice < 1 || dropChoice > bodcol );

return dropChoice;
}

int BotDrop( char board[][10], playerInfo activePlayer )
{
	int dropChoice,bodcol;
    if(boardsize==1){
        bodcol=5;
		dropChoice = rand()%5+1;
    }else if (boardsize==2) {
        bodcol=7;
		dropChoice = rand()%7+1;
    }else if(boardsize==3){
        bodcol=10;
		dropChoice = rand()%10+1;
    }
    
	do
	{
		cout << activePlayer.playerName << "'s Turn It's choose"<<dropChoice<<"\n";
		while ( board[1][dropChoice] == 'X' || board[1][dropChoice] == 'O' )
		{
			cout << "full,please enter a new row: ";
			cin  >> dropChoice;
		}

	}while ( dropChoice < 1 || dropChoice > bodcol );

return dropChoice;
}

void CheckBelow ( char board[][10], playerInfo activePlayer, int dropChoice )
{
	int length, turn;
	turn = 0;
    if(boardsize==1){
        length=4;
    }else if (boardsize==2) {
        length=6;
    }else if(boardsize==3){
        length=8;
    }
	do 
	{
		if ( board[length][dropChoice] != 'X' && board[length][dropChoice] != 'O' )
		{
			board[length][dropChoice] = activePlayer.playerID;
			turn = 1;
		}
		else
		--length;
	}while (  turn != 1 );


}

void DisplayBoard ( char board[][10] ){  
if(boardsize==1){
    int i, ix;
	for(i = 1; i <= 4; i++)
	{
		cout << "|";
		for(ix = 1; ix <= 5; ix++)
		{
			if(board[i][ix] != 'X' && board[i][ix] != 'O')
				board[i][ix] = '*';

			cout <<" "<<board[i][ix]<<" ";
			
		}

		cout << "|" << endl;
	}
}else if (boardsize==2) {
    int i, ix;
	
	for(i = 1; i <= 6; i++)
	{
		cout << "|";
		for(ix = 1; ix <= 7; ix++)
		{
			if(board[i][ix] != 'X' && board[i][ix] != 'O')
				board[i][ix] = '*';

			cout <<" "<<board[i][ix]<<" ";
			
		}

		cout << "|" << endl;
	}
}else if(boardsize==3)
{
    int i, ix;
	
	for(i = 1; i <= 8; i++)
	{
		cout << "|";
		for(ix = 1; ix <= 10; ix++)
		{
			if(board[i][ix] != 'X' && board[i][ix] != 'O')
				board[i][ix] = '*';

			cout <<" "<<board[i][ix]<<" ";
			
		}

		cout << "|" << endl;
	}
}
}

int CheckFour ( char board[][10], playerInfo activePlayer )  
{
	char XO;
	int win;
	
	XO = activePlayer.playerID;
	win = 0;
    if(boardsize==1){
        row=4;
        col=5;
    }else if (boardsize==2) {
        row=6;
        col=7;
    }else if(boardsize==3){
        row=8;
        col=10;
    }
	for( int i = row+2; i >= 1; --i )
	{
		
		for( int ix = col+2; ix >= 1; --ix )
		{
			
			if( board[i][ix] == XO     &&  
				board[i-1][ix-1] == XO &&
				board[i-2][ix-2] == XO &&
				board[i-3][ix-3] == XO )
			{
				win = 1;
			}
			

			if( board[i][ix] == XO   &&    
				board[i][ix-1] == XO &&
				board[i][ix-2] == XO &&
				board[i][ix-3] == XO )
			{
				win = 1;
			}
					
			if( board[i][ix] == XO   &&     
				board[i-1][ix] == XO &&
				board[i-2][ix] == XO &&
				board[i-3][ix] == XO )
			{	
				win = 1;
			}
					
			if( board[i][ix] == XO     &&  
				board[i-1][ix+1] == XO &&
				board[i-2][ix+2] == XO &&
				board[i-3][ix+3] == XO )
			{
				win = 1;
			}
						
			if ( board[i][ix] == XO   &&   
				 board[i][ix+1] == XO &&
				 board[i][ix+2] == XO &&
				 board[i][ix+3] == XO )
			{
				win = 1;
			}
		}
		
	}

return win;
}

int FullBoard( char board[][10] ) 
{
	int full;
	full = 0;
	if(boardsize==1){
        row=4;
        col=5;
    }else if (boardsize==2) {
        row=6;
        col=7;
    }else if(boardsize==3){
        row=8;
        col=10;
    }
	for ( int i = 1; i <= col; ++i )
	{
		if ( board[1][i] != '*' )
			++full;
	}

return full;
}

void PlayerWin ( playerInfo activePlayer ) 
{
	cout << endl << " Connected Four, "<<activePlayer.playerName<< " Win!" << endl;
}

int restart ( char board[][10] )   
{
	int restart;

	cout << "Would you like to restart? Yes(1) No(2): ";
	cin  >> restart;
	if ( restart == 1 )
	{
		for(int i = 1; i <= row; i++)
		{
			for(int j = 1; j <= col; j++)
			{
				board[i][j] = '*';
			}
		}
	}
	else
		cout << "Bye!" << endl;
return restart;
}