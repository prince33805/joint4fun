#include<iostream>
#include<string>
using namespace std;

int row,col;
struct playerInfo 
{
	char playerName[99];
	char playerID;
};

int PlayerDrop( char board[][10], playerInfo activePlayer ); // ãËé¼ÙéàÅè¹Å§ªèÍ§äË¹
void CheckBelow ( char board[][10], playerInfo activePlayer, int dropChoice ); // 
void DisplayBoard ( char board[][10] );
int CheckFour ( char board[][10], playerInfo activePlayer );
int FullBoard( char board[][10] );
void PlayerWin ( playerInfo activePlayer );
int restart ( char board[][10] );

int main()
{
	playerInfo playerOne;
    playerInfo playerTwo;
	char board[9][10]; 
	int trueWidth = 7; 
	int trueLength = 6; 
	int dropChoice, win, full, again;

	cout << "Welcome to Join4fun." << endl << endl;
	cout << "Player One fucking name: ";
	cin  >> playerOne.playerName;
	playerOne.playerID = 'X';
	cout << "Player Two fucking name: ";
	cin  >> playerTwo.playerName;
	playerTwo.playerID = 'O';
	do{
	    cout<<"Enter row:";
	    cin>>row;
	    cout<<"Enter col:";
	    cin>>col;
	}while(row <5 || col<5);
	
	full = 0,win=0,again=0;
	DisplayBoard( board);
	do
	{
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
		if ( full == 7 )
		{
			cout << "The board is full,draw!" << endl;
			again = restart(board);
		}

	}while ( again != 2 );

	

return 0;
}

int PlayerDrop( char board[][10], playerInfo activePlayer )
{
	int dropChoice;
	do
	{
		cout << activePlayer.playerName << "'s Turn ";
		cout << "Please enter a number between 1 and"<<col<<": ";
		cin  >> dropChoice;

		while ( board[1][dropChoice] == 'X' || board[1][dropChoice] == 'O' )
		{
			cout << "full,please enter a new row: ";
			cin  >> dropChoice;
		}

	}while ( dropChoice < 1 || dropChoice > col );

return dropChoice;
}

void CheckBelow ( char board[][10], playerInfo activePlayer, int dropChoice ) //´Ùx o
{
	int length, turn;
	length = col;
	turn = 0;

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

void DisplayBoard ( char board[][10] )  //ÊÃéÒ§µÒÃÒ§
{
	int i, ix;
	
	for(i = 1; i <= row; i++)
	{
		cout << "|";
		for(ix = 1; ix <= col; ix++)
		{
			if(board[i][ix] != 'X' && board[i][ix] != 'O')
				board[i][ix] = '*';

			cout << board[i][ix];
			
		}

		cout << "|" << endl;
	}

}

int CheckFour ( char board[][10], playerInfo activePlayer )  
{
	char XO;
	int win;
	
	XO = activePlayer.playerID;
	win = 0;

	for( int i = row+2; i >= 1; --i )
	{
		
		for( int ix = col+2; ix >= 1; --ix )
		{
			
			if( board[i][ix] == XO     &&   //à©ÕÂ§«éÒÂ
				board[i-1][ix-1] == XO &&
				board[i-2][ix-2] == XO &&
				board[i-3][ix-3] == XO )
			{
				win = 1;
			}
			

			if( board[i][ix] == XO   &&     //á¹Ç¹Í¹
				board[i][ix-1] == XO &&
				board[i][ix-2] == XO &&
				board[i][ix-3] == XO )
			{
				win = 1;
			}
					
			if( board[i][ix] == XO   &&     //á¹ÇµÑé§
				board[i-1][ix] == XO &&
				board[i-2][ix] == XO &&
				board[i-3][ix] == XO )
			{	
				win = 1;
			}
					
			if( board[i][ix] == XO     &&    //à©ÕÂ§¢ÇÒ
				board[i-1][ix+1] == XO &&
				board[i-2][ix+2] == XO &&
				board[i-3][ix+3] == XO )
			{
				win = 1;
			}
						
			if ( board[i][ix] == XO   &&    //á¹ÇµÑé§
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

int FullBoard( char board[][10] ) //àµçÁµÒÃÒ§
{
	int full;
	full = 0;
	for ( int i = 1; i <= col; ++i )
	{
		if ( board[1][i] != '*' )
			++full;
	}

return full;
}

void PlayerWin ( playerInfo activePlayer ) // ÊÃØº¼Å
{
	cout << endl << " Connected Four, "<<activePlayer.playerName<< " Win!" << endl;
}

int restart ( char board[][10] )    //àÃÔèÁãËÁè
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