#include "BoardGame_Classes.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;


int past_x_move, past_y_move;

template <typename T> class X_O_Board_7:public Board<T> {
public:
    X_O_Board_7 ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
};

template <typename T> class X_O_Player_7 : public Player<T> {
public:
    X_O_Player_7 (string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T> class X_O_Random_Player_7 : public RandomPlayer<T>{
public:
    X_O_Random_Player_7 (T symbol);
    void getmove(int &x, int &y) ;
};

template <typename T> X_O_Board_7<T>::X_O_Board_7() {
    this->rows = this->columns = 4;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 32;
        }
    }

    this->board[0][1] = 'X';
    this->board[0][3] = 'X';
    this->board[3][0] = 'X';
    this->board[3][2] = 'X';

    this->board[0][0] = 'O';
    this->board[0][2] = 'O';
    this->board[3][1] = 'O';
    this->board[3][3] = 'O';
    this->n_moves = 0;
}


template <typename T> bool X_O_Board_7<T>::update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 32) &&
        (this->board[past_x_move][past_y_move] == mark) && 
        ((past_x_move == x && past_y_move != y) || (past_x_move != x && past_y_move == y))&&
        ((abs(past_x_move - x) <= 1) && (past_y_move - y <= 1))
    ) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 32;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
            this->board[past_x_move][past_y_move] = 32;
        }
        return true;
    }
    return false;
}

template <typename T> void X_O_Board_7<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n--------------------------------------";
    }
    cout << endl;
}

template <typename T> bool X_O_Board_7<T>::is_win() {
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 32) ||
            (this->board[i][1] == this->board[i][2] && this->board[i][2] == this->board[i][3] && this->board[i][1] != 32) ||
        
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != 32) ||
            (this->board[1][i] == this->board[2][i] && this->board[2][i] == this->board[3][i] && this->board[0][i] != 32)) {
                return true;
            }
    }

    if ((this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 32) ||
        (this->board[0][3] == this->board[1][2] && this->board[1][2] == this->board[2][1] && this->board[0][3] != 32) ||
        (this->board[1][2] == this->board[2][1] && this->board[2][1] == this->board[3][0] && this->board[1][2] != 32) ||
        (this->board[1][3] == this->board[2][2] && this->board[2][2] == this->board[3][1] && this->board[1][3] != 32) ||

        (this->board[0][1] == this->board[1][2] && this->board[1][2] == this->board[2][3] && this->board[0][1] != 32) ||
        (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 32) ||
        (this->board[1][1] == this->board[2][2] && this->board[2][2] == this->board[3][3] && this->board[1][1] != 32) ||
        (this->board[1][0] == this->board[2][1] && this->board[2][1] == this->board[3][2] && this->board[1][0] != 32)) {
            return true;
        }
    return false;
}

template <typename T> bool X_O_Board_7<T>::is_draw() {
    return false;
}

template <typename T> bool X_O_Board_7<T>::game_is_over() {
    return is_win();
}

template <typename T> X_O_Player_7<T>::X_O_Player_7(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T> void X_O_Player_7<T>::getmove(int& x, int& y) {
    cout << endl << this->getname() << " Please enter your move x and y (0 to 2) separated by spaces : ";
    cin >> past_x_move >> past_y_move >> x >> y;
}

template <typename T> X_O_Random_Player_7<T>::X_O_Random_Player_7(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T> void X_O_Random_Player_7<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
    past_x_move = rand() % this->dimension;
    past_y_move = rand() % this->dimension;
}
