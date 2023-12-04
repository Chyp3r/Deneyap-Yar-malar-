#include <iostream>
#include <stdlib.h>  
using namespace std;

char player[2] = {'X','O'};
char board[5][5] = {{'1','|','2','|','3'},
                    {'-','|','-','|','-'},
                    {'4','|','5','|','6'},
                    {'-','|','-','|','-'},
                    {'7','|','8','|','9'}};

int turn;
int loc = 0;

void writer(int, char);

void board_writer()
{
    cout << endl;
    for (int i = 0; i <= 4; i++) 
    {
        for (int j = 0; j <= 4; j++) 
        {
            cout << board[i][j] << " ";
        }
        cout <<  endl;
    }
    cout << endl;
}

void play(char player)
{
    cout << "Turn "<< player;
    cin >> loc;
    player == 'X' ? writer(loc,'X') : writer(loc,'O');
}

void writer(int loc, char player)
{
    switch(loc)
    {
        case 1:
            board[0][0] = player;
            break;
        case 2:
            board[0][2] = player;
            break;
        case 3:
            board[0][4] = player;
            break;
        case 4:
            board[2][0] = player;
            break;
        case 5:
            board[2][2] = player;
            break;
        case 6:
            board[2][4] = player;
            break;
        case 7:
            board[4][0] = player;
            break;
        case 8:
            board[4][2] = player;
            break;
        case 9:
            board[4][4] = player;
            break;
        default:
            cout << "Hata" << endl;
            if(player == 'X') 
            {
                play('X');
            }
            else 
            {
                play('Y');
            }
    }
}

int main()
{
    board_writer();
    turn = 1;
    while(turn <= 9)
    {
        play(turn%2 == 0 ? player[1] : player[0]);
        board_writer()
        turn++;
    }
    cout << "Oyun Bitti !" << endl;
    return 0;
}
