#include<iostream>
#include<string>
#include<vector>

using namespace std;
void theGame();
bool checkWin(vector<string> board);
bool validIndexChecker(int index,vector<string> board);
bool checkDraw(int moves);


void theGame()
{
    vector<string> gameBoard;
    bool p1Turn=true;       
    int move_index,num_of_moves=0;

    for(int i=0;i<9;i++)
    {
        gameBoard.push_back(to_string(i));
    }
    while(true)
    {
        if(checkDraw(num_of_moves)) break;  
        if(checkWin(gameBoard)) break;

        cout<<"Board Status: \n";
        for(int i=0;i<9;i++)
        {
            cout<<gameBoard[i]<<" ";
            if((i+1)%3==0)
            {
                cout<<"\n";
            }
        }
        if(p1Turn)
        {
            cout<<"\nPlayer1's Turn ";
            cin>>move_index;
            if(validIndexChecker(move_index,gameBoard)) continue;
            else
            {
                gameBoard[move_index]="X";
                p1Turn=false;
                num_of_moves++;
            }   
        }
        else
        {
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

bool checkWin(vector<string> board)
{
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
bool validIndexChecker(int index,vector<string> board)
{
    if(index>8 || index<0 || board[index]=="X" || board[index]=="O")
    {
       cout<<"Invalid Move Try again\n"  ;
       return true;
    }
    return false;

}
bool checkDraw(int moves)
{
    if(moves==9) {cout<<"Draw!!"; return true;};
    return false;         
        
}