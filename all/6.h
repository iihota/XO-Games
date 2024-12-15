#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
using namespace std;


template <typename T> class X_O_Board_6:public Board<T> {
public:
    X_O_Board_6 ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
};

template <typename T> class X_O_Player_6 : public Player<T> {
public:
    X_O_Player_6 (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T> class X_O_Random_Player_6 : public RandomPlayer<T>{
public:
    X_O_Random_Player_6 (T symbol);
    void getmove(int &x, int &y) ;
};

template <typename T> X_O_Board_6<T>::X_O_Board_6() {
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 32;
        }
    }
    this->n_moves = 0;
}

template <typename T> bool X_O_Board_6<T>::update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 32|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

template <typename T> void X_O_Board_6<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

template <typename T> bool X_O_Board_6<T>::is_win() {
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 32) ||
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != 32)) {
            return true;
        }
    }

    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 32) ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 32)) {
        return true;
    }

    return false;
}

template <typename T> bool X_O_Board_6<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T> bool X_O_Board_6<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T> X_O_Player_6<T>::X_O_Player_6(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T> void X_O_Player_6<T>::getmove(int& x, int& y) {
    cout << endl << this->getname() << " Please enter your move x and y (0 to 2) separated by spaces : ";
    cin >> x >> y;
}

template <typename T> X_O_Random_Player_6<T>::X_O_Random_Player_6(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  
}

template <typename T>
void X_O_Random_Player_6<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  
    y = rand() % this->dimension;
}