#include <iostream>
using namespace std;
int currentplayer;
char currentmarker;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawboard()
{
    cout<<"  "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<"\n";
    cout<<"  "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<"\n";
    cout<<"  "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<"\n";
}
bool placemarker(int slot)
{
    int row=(slot-1)/3;
    int col=(slot-1)%3;
    if(board[row][col]!='x'&& board[row][col]!='o')
    {
        board[row][col]=currentmarker;
        return true;
    }
    return false;
}
int winner()
{
    //rows
    for(int i=0;i<3;i++)
    {
       if (board[i][0] == board[i][1] && board[i][1] == board[i][2])  

            return currentplayer;

    }
    //column
    for(int i=0;i<3;i++)
    {
       if (board[0][i] == board[1][i] && board[1][i] == board[2][i])  

        return currentplayer;
    }

    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
    {
        return currentplayer;
    }
    if(board[0][2]==board[1][1]&& board[1][1]==board[2][0])
    {
        return currentplayer;
    }
    return 0;
}

void swapplayerandmarker()
{
    if(currentmarker=='x')
    {
        currentmarker='o';
    }
    else{
        currentmarker='x';
    }
    if(currentplayer==1)
    {
        currentplayer=2;
    }
    else{
        currentplayer=1;
    }
}
void game()
{
    cout<<"player one choose your marker: x or o";
    char markerp1;
    cin>>markerp1;


    currentplayer=1;
    currentmarker=markerp1;
    drawboard();
    int playerwon;
    for(int i=0;i<9;i++)
    {
        cout<<"its player"<<currentplayer<<"'s turn enter your slot:";
        int slot;
        cin>>slot;
        
        if(slot<1||slot>9)
        {
            cout<<"not valid slot, try again";
            i--;
            continue;
        }
        if(!placemarker(slot))
        {
            cout<<"slot occupied , try again";
            i--;
            continue;
        }
        drawboard();
        playerwon=winner();
        if(playerwon==1)
        {
            cout<<"player 1 wins";
            break;
        }
        if(playerwon==2)
        {
            cout<<"player 2 wins";
            break;
        }
        swapplayerandmarker();
        
    }
    if(playerwon==0)
        {
            cout<<"it's a tie";
        }

}
int main() {
    
    
    game();    
    return 0;
}