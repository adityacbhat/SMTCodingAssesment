#include<iostream>
#include<string>
#include<vector>

using namespace std;

//function prototypes
void theGame();
bool checkWin(vector<string> board);
bool validIndexChecker(int index,vector<string> board);
bool checkDraw(int moves);

int main()
{
    theGame();

}

//main game
void theGame()
{
    //1D vector board
    vector<string> gameBoard;

    //boolean variable to track player's turns
    bool p1Turn=true;     

    //variables to accept input and track number of moves  
    int move_index,num_of_moves=0;

    //intialize the first board with numbers 0 to 8
    for(int i=0;i<9;i++)
    {
        gameBoard.push_back(to_string(i));
    }

    //Game starts with "X" turn
    while(true)
    {
        //make sure the game isn't draw or won by any player at every iteration. 
        //Loop breaks when either player wins or its a draw
        if(checkDraw(num_of_moves)) break;  
        if(checkWin(gameBoard)) break;

        //print board status at every iteration
        cout<<"Board Status: \n";
        for(int i=0;i<9;i++)
        {
            cout<<gameBoard[i]<<" ";
            if((i+1)%3==0)
            {
                cout<<"\n";
            }
        }
        //Player 1 plays when its his/her turn
        if(p1Turn)
        {
            cout<<"\nPlayer1's Turn ";
            //accepting the index from the player and make sure its valid
            cin>>move_index;
            if(validIndexChecker(move_index,gameBoard)) continue;
            //if valid then push it the "X" at that index and change p1Turn to false and increment num_of_moves
            else
            {
                gameBoard[move_index]="X";
                p1Turn=false;
                num_of_moves++;
            }   
        }
        else
        {
            //Similar steps for player2
            cout<<"\nPlayer2's Turn ";
            cin>>move_index;
            if(validIndexChecker(move_index,gameBoard))  continue;    
            else
            {
                    gameBoard[move_index]="O";
                    p1Turn=true;
                    num_of_moves++;
            }
        }
    }
}

//check win condition
bool checkWin(vector<string> board)
{
    //there are total of 8 conditions to check, i.e. 3 horizontal, 3 vertical and 2 diagonal. When symbols are same in either of these position,
    //that player wins.
    if(board[0]==board[1] && board[1]==board[2])
        {   
            cout<<board[1]<<" Wins!!";
            return true;
        }
    if(board[3]==board[4] && board[4]==board[5])
        {   
            cout<<board[4]<<" Wins!!";
            return true;
        }
    if(board[6]==board[7] && board[7]==board[8])
        {   
            cout<<board[7]<<" Wins!!";
            return true;
        }
    if(board[0]==board[3] && board[3]==board[6])
        {   
            cout<<board[3]<<" Wins!!";
            return true;
        }
    if(board[1]==board[4] && board[4]==board[7])
        {   
            cout<<board[4]<<" Wins!!";
            return true;
        }
    if(board[2]==board[5] && board[5]==board[8])
        {   
            cout<<board[5]<<" Wins!!";
            return true;
        }
    if(board[0]==board[4] && board[4]==board[8])
        {   
            cout<<board[4]<<" Wins!!";
            return true;
        }
    if(board[6]==board[4] && board[4]==board[2])
    {   
            cout<<board[4]<<" Wins!!";
            return true;
    }
    return false;
}

//check for valid index
bool validIndexChecker(int index,vector<string> board)
{
    //make sure that user enters index within 0 and 8. And doesnt enter an index where "X" or "O" already exists.
    if(index>8 || index<0 || board[index]=="X" || board[index]=="O")
    {
       cout<<"Invalid Move Try again\n"  ;
       return true;
    }
    return false;

}

//check for draw condition
bool checkDraw(int moves)
{
    //if number of moves has reached 9 then its a draw
    if(moves==9) {cout<<"Draw!!"; return true;};
    return false;         
        
}