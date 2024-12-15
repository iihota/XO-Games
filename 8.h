#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>  

using namespace std;


char p1=0, p2=0, p3=0, p4=0, p5=0, p6=0, p7=0, p8=0, p9=0;

template <typename T> class X_O_Board_8:public Board<T> {
public:
    X_O_Board_8 ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};


template <typename T> class X_O_Player_8 : public Player<T> {
public:
    X_O_Player_8 (string name, T symbol);
    void getmove(int& x, int& y) ;
};


template <typename T> class X_O_Random_Player_8 : public RandomPlayer<T>{
public:
    X_O_Random_Player_8 (T symbol);
    void getmove(int &x, int &y) ;
};



template <typename T> X_O_Board_8<T>::X_O_Board_8() {
    this->rows = this->columns = 9;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 32;
        }
    }
    this->n_moves = 0;
}

template <typename T> bool X_O_Board_8<T>::update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 32|| mark == 0))
    {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 32;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

//######################################################################################

    for (int i = 0; i < 3; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && ( this->board[i][0] != 32 && (this->board[i][0] != 'x' && this->board[i][0] != 'o' )))  ||
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && ( this->board[0][i] != 32 && (this->board[0][i] != 'x' && this->board[0][i] != 'o' )))) {
                p1 = mark;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        this->board[i][j] = tolower(mark);
                    }
                }
        }
    }
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 32 && (this->board[0][0] != 'x' && this->board[0][0] != 'o' )) ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 32 && (this->board[2][0] != 'x' && this->board[2][0] != 'o' ))) {
            p1 = mark;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    this->board[i][j] = tolower(mark);
            }
        }
    }




    for (int i = 0; i < 3; i++) {
        if ((this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5] && ( this->board[i][3] != 32 && (this->board[i][3] != 'x' && this->board[i][3] != 'o' )))  ||
            (this->board[0][i+3] == this->board[1][i+3] && this->board[1][i+3] == this->board[2][i+3] && ( this->board[0][i+3] != 32 && (this->board[0][i+3] != 'x' && this->board[0][i+3] != 'o' )))) {
                p2 = mark;
            for (int i = 0; i < 3; i++) {
                for (int j = 3; j < 6; j++) {
                    this->board[i][j] = tolower(mark);
                }
            }
        }
    }
    if ((this->board[0][3] == this->board[1][4] && this->board[1][4] == this->board[2][5] && this->board[0][3] != 32 && (this->board[0][3] != 'x' && this->board[0][3] != 'o' )) ||
        (this->board[0][5] == this->board[1][4] && this->board[1][4] == this->board[2][3] && this->board[0][5] != 32 && (this->board[2][3] != 'x' && this->board[2][3] != 'o' ))) {
            p2 = mark;
            for (int i = 0; i < 3; i++) {
                for (int j = 3; j < 6; j++) {
                    this->board[i][j] = tolower(mark);
            }
        }
    }





    for (int i = 0; i < 3; i++) {
        if ((this->board[i][6] == this->board[i][7] && this->board[i][7] == this->board[i][8] && ( this->board[i][6] != 32 && (this->board[i][6] != 'x' && this->board[i][6] != 'o' )))  ||
            (this->board[0][i+6] == this->board[1][i+6] && this->board[1][i+6] == this->board[2][i+6] && ( this->board[0][i+6] != 32 && (this->board[0][i+6] != 'x' && this->board[0][i+6] != 'o' )))) {
                p3 = mark;
                for (int i = 0; i < 3; i++) {
                    for (int j = 6; j < 9; j++) {
                        this->board[i][j] = tolower(mark);
                    }
                }
        }
    }
    if ((this->board[0][6] == this->board[1][7] && this->board[1][7] == this->board[2][8] && this->board[0][6] != 32 && (this->board[0][6] != 'x' && this->board[0][6] != 'o' )) ||
        (this->board[0][8] == this->board[1][7] && this->board[1][7] == this->board[2][6] && this->board[0][8] != 32 && (this->board[2][6] != 'x' && this->board[2][6] != 'o' ))) {
            p3 = mark;
            for (int i = 0; i < 3; i++) {
                for (int j = 6; j < 9; j++) {
                    this->board[i][j] = tolower(mark);
                }
            }
    }



    for (int i = 3; i < 6; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && ( this->board[i][0] != 32 && (this->board[i][0] != 'x' && this->board[i][0] != 'o' )))  ||
            (this->board[3][i-3] == this->board[4][i-3] && this->board[4][i-3] == this->board[5][i-3] && ( this->board[3][i-3] != 32 && (this->board[3][i-3] != 'x' && this->board[3][i-3] != 'o' )))) {
                p4 = mark;
                for (int i = 3; i < 6; i++) {
                    for (int j = 0; j < 3; j++) {
                        this->board[i][j] = tolower(mark);
                    }
                }
        }
    }
    if ((this->board[3][0] == this->board[4][1] && this->board[4][1] == this->board[5][2] && this->board[3][0] != 32 && (this->board[3][0] != 'x' && this->board[3][0] != 'o' )) ||
        (this->board[3][2] == this->board[4][1] && this->board[4][1] == this->board[5][0] && this->board[3][2] != 32 && (this->board[3][2] != 'x' && this->board[3][2] != 'o' ))) {
            p4 = mark;
                for (int i = 3; i < 6; i++) {
                    for (int j = 0; j < 3; j++) {
                        this->board[i][j] = tolower(mark);
                    }
                }
    }





    for (int i = 3; i < 6; i++) {
        if ((this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5] && ( this->board[i][3] != 32 && (this->board[i][3] != 'x' && this->board[i][3] != 'o' )))  ||
            (this->board[3][i] == this->board[4][i] && this->board[4][i] == this->board[5][i] && ( this->board[3][i] != 32 && (this->board[3][i] != 'x' && this->board[3][i] != 'o' )))) {
                p5 = mark;
                for (int i = 3; i < 6; i++) {
                    for (int j = 3; j < 6; j++) {
                        this->board[i][j] = tolower(mark);
                    }
                }
        }
    }
    if ((this->board[3][3] == this->board[4][4] && this->board[4][4] == this->board[5][5] && this->board[3][3] != 32 && (this->board[3][3] != 'x' && this->board[3][3] != 'o' )) ||
        (this->board[3][5] == this->board[4][4] && this->board[4][4] == this->board[5][3] && this->board[3][5] != 32 && (this->board[5][3] != 'x' && this->board[5][3] != 'o' ))) {
            p5 = mark;
                for (int i = 3; i < 6; i++) {
                    for (int j = 3; j < 6; j++) {
                        this->board[i][j] = tolower(mark);
                    }
                }
    }






    for (int i = 3; i < 6; i++) {
        if ((this->board[i][6] == this->board[i][7] && this->board[i][7] == this->board[i][8] && ( this->board[i][6] != 32 && (this->board[i][6] != 'x' && this->board[i][6] != 'o' )))  ||
            (this->board[3][i+3] == this->board[4][i+3] && this->board[4][i+3] == this->board[5][i+3] && ( this->board[3][i+3] != 32 && (this->board[3][i+3] != 'x' && this->board[3][i+3] != 'o' )))) {
                p6 = mark;
                for (int i = 3; i < 6; i++) {
                    for (int j = 6; j < 9; j++) {
                        this->board[i][j] = tolower(mark);
                    }
                }
        }
    }
    if ((this->board[3][6] == this->board[4][7] && this->board[4][7] == this->board[5][8] && this->board[3][6] != 32 && (this->board[3][6] != 'x' && this->board[3][6] != 'o' )) ||
        (this->board[3][8] == this->board[4][7] && this->board[4][7] == this->board[5][6] && this->board[3][8] != 32 && (this->board[3][8] != 'x' && this->board[3][8] != 'o' ))) {
            p6 = mark;
                for (int i = 3; i < 6; i++) {
                    for (int j = 6; j < 9; j++) {
                        this->board[i][j] = tolower(mark);
                    }
                }
    }





    for (int i = 6; i < 9; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && ( this->board[i][0] != 32 && (this->board[i][0] != 'x' && this->board[i][0] != 'o' )))  ||
            (this->board[6][i-6] == this->board[7][i-6] && this->board[7][i-6] == this->board[8][i-6] && ( this->board[6][i-6] != 32 && (this->board[6][i-6] != 'x' && this->board[6][i-6] != 'o' )))) {
                p7 = mark;
                for (int i = 6; i < 9; i++) {
                    for (int j = 0; j < 3; j++) {
                        this->board[i][j] = tolower(mark);
                    }
                }
        }
    }
    if ((this->board[6][0] == this->board[7][1] && this->board[7][1] == this->board[8][2] && this->board[6][0] != 32 && (this->board[6][0] != 'x' && this->board[6][0] != 'o' )) ||
        (this->board[6][2] == this->board[7][1] && this->board[7][1] == this->board[8][0] && this->board[6][2] != 32 && (this->board[6][2] != 'x' && this->board[6][2] != 'o' ))) {
            p7 = mark;
                for (int i = 6; i < 9; i++) {
                    for (int j = 0; j < 3; j++) {
                        this->board[i][j] = tolower(mark);
                    }
                }
    }





    for (int i = 6; i < 9; i++) {
        if ((this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5] && ( this->board[i][3] != 32 && (this->board[i][3] != 'x' && this->board[i][3] != 'o' )))  ||
            (this->board[6][i-3] == this->board[7][i-3] && this->board[7][i-3] == this->board[8][i-3] && ( this->board[6][i-3] != 32 && (this->board[6][i-3] != 'x' && this->board[6][i-3] != 'o' )))) {
                p8 = mark;
                for (int i = 6; i < 9; i++) {
                    for (int j = 3; j < 6; j++) {
                        this->board[i][j] = tolower(mark);
                    }
                }
        }
    }
    if ((this->board[6][3] == this->board[7][4] && this->board[7][4] == this->board[8][5] && this->board[6][3] != 32 && (this->board[6][3] != 'x' && this->board[6][3] != 'o' )) ||
        (this->board[6][5] == this->board[7][4] && this->board[7][4] == this->board[8][3] && this->board[6][5] != 32 && (this->board[6][5] != 'x' && this->board[6][5] != 'o' ))) {
            p8 = mark;
                for (int i = 6; i < 9; i++) {
                    for (int j = 3; j < 6; j++) {
                        this->board[i][j] = tolower(mark);
                    }
                }
    }






    for (int i = 6; i < 9; i++) {
        if ((this->board[i][6] == this->board[i][7] && this->board[i][7] == this->board[i][8] && ( this->board[i][6] != 32 && (this->board[i][6] != 'x' && this->board[i][6] != 'o' )))  ||
            (this->board[6][i] == this->board[7][i] && this->board[7][i] == this->board[8][i] && ( this->board[6][i] != 32 && (this->board[6][i] != 'x' && this->board[6][i] != 'o' )))) {
                p9 = mark;
                for (int i = 6; i < 9; i++) {
                    for (int j = 6; j < 9; j++) {
                        this->board[i][j] = tolower(mark);
                    }
                }
        }
    }
    if ((this->board[6][6] == this->board[7][7] && this->board[7][7] == this->board[8][8] && this->board[6][6] != 32 && (this->board[6][6] != 'x' && this->board[6][6] != 'o' )) ||
        (this->board[6][8] == this->board[7][7] && this->board[7][7] == this->board[8][6] && this->board[6][8] != 32 && (this->board[6][8] != 'x' && this->board[6][8] != 'o' ))) {
            p9 = mark;
                for (int i = 6; i < 9; i++) {
                    for (int j = 6; j < 9; j++) {
                        this->board[i][j] = tolower(mark);
                    }
                }
    }

        return true;
    }
    return false;
}



template <typename T> void X_O_Board_8<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
            if (j == 2 || j == 5){
                cout << "| ";
            }
        }

        if (i == 2 || i == 5){
            cout << "\n=======================================================================================";
        }
        else {
            cout << "\n---------------------------------------------------------------------------------------";
        }
    }
    cout << endl << endl;
}


template <typename T> bool X_O_Board_8<T>::is_win() { 
    if ((p1 == p2 && p2 == p3 && p1!=0)||
       (p4 == p5 && p5 == p6 && p4!=0)||
       (p7 == p8 && p8 == p9 && p7!=0)||
       (p1 == p4 && p4 == p7 && p1!=0)||
       (p2 == p5 && p5 == p8 && p2!=0)||
       (p3 == p6 && p6 == p9 && p3!=0)||
       (p3 == p5 && p5 == p7 && p3!=0)||
       (p1 == p5 && p5 == p9 && p1!=0)) {
        return true;
    }
    return false;
}

template <typename T> bool X_O_Board_8<T>::is_draw() {
    return (this->n_moves == 81 && !is_win());
}

template <typename T> bool X_O_Board_8<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T> X_O_Player_8<T>::X_O_Player_8(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T> void X_O_Player_8<T>::getmove(int& x, int& y) {
    cout << endl << this->getname() << " Please enter your move x and y (0 to 2) separated by spaces : ";
    cin >> x >> y;
}

template <typename T> X_O_Random_Player_8<T>::X_O_Random_Player_8(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 9;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T> void X_O_Random_Player_8<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}