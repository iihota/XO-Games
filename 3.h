#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>  
using namespace std;


int player_1_count = 0, player_2_count= 0;
//     ===============   Classes    =================
template <typename T> class X_O_Board_3:public Board<T> {
public:
    X_O_Board_3();
    bool update_board (int x , int y , T symbol);
    void display_board ();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    void Players_counter();
};

template <typename T> class X_O_Player_3 : public Player<T> {
public:
    X_O_Player_3 (string name, T symbol);
    void getmove(int& x, int& y);
    int counter;
};

template <typename T> class X_O_Random_Player_3 : public RandomPlayer<T>{
public:
    X_O_Random_Player_3 (T symbol);
    void getmove(int &x, int &y) ;
};



// ==============   X O Board Classes   =============
template <typename T> X_O_Board_3<T>::X_O_Board_3() {
    this->rows = this->columns = 5;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++){
            this->board[i][j] = 32;
        }
    }
    this->n_moves = 0;
}

template <typename T> bool X_O_Board_3<T>::update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 32|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 32;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }



        return true;
    }
    return false;
}

template <typename T> void X_O_Board_3<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n----------------------------------------------------";
    }
    cout << endl;
}

template <typename T> bool X_O_Board_3<T>::is_win() {
    if (this->n_moves == 24){
        return true;
    }
    return false;
}



template <typename T> bool X_O_Board_3<T>::is_draw() {
    return (is_win());
}

template <typename T> bool X_O_Board_3<T>::game_is_over(){
    return is_win();
}


// ==============   X O Player Classes   =============
template <typename T> X_O_Player_3<T>::X_O_Player_3(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T> void X_O_Player_3<T>::getmove(int& x, int& y) {
    cout << endl << this->getname() << " Please enter your move x and y (0 to 2) separated by spaces : ";
    cin >> x >> y;
}


// ==============   X O Random Classes   =============
template <typename T> X_O_Random_Player_3<T>::X_O_Random_Player_3(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 5;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T> void X_O_Random_Player_3<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}


template <typename T> void X_O_Board_3<T>::Players_counter(){
    //=================================================================================================

    for (int i = 0; i < this->rows; i++) {
        if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] == 'X'){
            player_1_count = player_1_count + 1;
        }
        if (this->board[i][1] == this->board[i][2] && this->board[i][2] == this->board[i][3] && this->board[i][1] == 'X'){
            player_1_count = player_1_count + 1;
        }
        if (this->board[i][2] == this->board[i][3] && this->board[i][3] == this->board[i][4] && this->board[i][2] == 'X'){
            player_1_count = player_1_count + 1;
        }
        if (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] == 'X'){
            player_1_count = player_1_count + 1;
        }
        if (this->board[1][i] == this->board[2][i] && this->board[2][i] == this->board[3][i] && this->board[1][i] == 'X'){
            player_1_count = player_1_count + 1;
        }
        if (this->board[2][i] == this->board[3][i] && this->board[3][i] == this->board[4][i] && this->board[2][i] == 'X'){
            player_1_count = player_1_count + 1;
        }


        if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] == 'O'){
            player_2_count = player_2_count + 1;
        }
        if (this->board[i][1] == this->board[i][2] && this->board[i][2] == this->board[i][3] && this->board[i][1] == 'O'){
            player_2_count = player_2_count + 1;
        }
        if (this->board[i][2] == this->board[i][3] && this->board[i][3] == this->board[i][4] && this->board[i][2] == 'O'){
            player_2_count = player_2_count + 1;
        }
        if (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] == 'O'){
            player_2_count = player_2_count + 1;
        }
        if (this->board[1][i] == this->board[2][i] && this->board[2][i] == this->board[3][i] && this->board[1][i] == 'O'){
            player_2_count = player_2_count + 1;
        }
        if (this->board[2][i] == this->board[3][i] && this->board[3][i] == this->board[4][i] && this->board[2][i] == 'O'){
            player_2_count = player_2_count + 1;
        }
    }


    if (this->board[2][0] == this->board[1][1] && this->board[1][1] == this->board[0][2] && this->board[2][0] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[2][1] == this->board[1][2] && this->board[1][2] == this->board[0][3] && this->board[2][1] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[3][0] == this->board[2][1] && this->board[2][1] == this->board[1][2] && this->board[3][0] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[4][0] == this->board[3][1] && this->board[3][1] == this->board[2][2] && this->board[4][0] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[3][1] == this->board[2][2] && this->board[2][2] == this->board[1][3] && this->board[3][1] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[2][2] == this->board[1][3] && this->board[1][3] == this->board[0][4] && this->board[2][2] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[3][2] == this->board[2][3] && this->board[2][3] == this->board[1][4] && this->board[3][2] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[4][1] == this->board[3][2] && this->board[3][2] == this->board[2][3] && this->board[4][1] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[4][2] == this->board[3][3] && this->board[3][3] == this->board[2][4] && this->board[4][2] == 'X'){
        player_1_count = player_1_count + 1;
    }


    if (this->board[2][0] == this->board[1][1] && this->board[1][1] == this->board[0][2] && this->board[2][0] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[2][1] == this->board[1][2] && this->board[1][2] == this->board[0][3] && this->board[2][1] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[3][0] == this->board[2][1] && this->board[2][1] == this->board[1][2] && this->board[3][0] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[4][0] == this->board[3][1] && this->board[3][1] == this->board[2][2] && this->board[4][0] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[3][1] == this->board[2][2] && this->board[2][2] == this->board[1][3] && this->board[3][1] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[2][2] == this->board[1][3] && this->board[1][3] == this->board[0][4] && this->board[2][2] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[3][1] == this->board[2][2] && this->board[2][2] == this->board[1][3] && this->board[3][1] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[4][1] == this->board[3][2] && this->board[3][2] == this->board[2][3] && this->board[4][1] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[4][2] == this->board[3][3] && this->board[3][3] == this->board[2][4] && this->board[4][2] == 'O'){
        player_2_count = player_2_count + 1;
    }





    if (this->board[0][2] == this->board[1][3] && this->board[2][4] == this->board[0][2] && this->board[0][2] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[0][1] == this->board[1][2] && this->board[1][2] == this->board[2][3] && this->board[0][1] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[1][2] == this->board[2][3] && this->board[2][3] == this->board[3][4] && this->board[1][2] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[1][1] == this->board[2][2] && this->board[2][2] == this->board[3][3] && this->board[1][1] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[2][2] == this->board[3][3] && this->board[3][3] == this->board[4][4] && this->board[2][2] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[1][0] == this->board[2][1] && this->board[2][1] == this->board[3][2] && this->board[1][0] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[2][1] == this->board[3][2] && this->board[3][2] == this->board[4][3] && this->board[2][1] == 'X'){
        player_1_count = player_1_count + 1;
    }
    if (this->board[2][0] == this->board[3][1] && this->board[3][1] == this->board[4][2] && this->board[2][0] == 'X'){
        player_1_count = player_1_count + 1;
    }



    if (this->board[0][2] == this->board[1][3] && this->board[2][4] == this->board[0][2] && this->board[0][2] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[0][1] == this->board[1][2] && this->board[1][2] == this->board[2][3] && this->board[0][1] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[1][2] == this->board[2][3] && this->board[2][3] == this->board[3][4] && this->board[1][2] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[1][1] == this->board[2][2] && this->board[2][2] == this->board[3][3] && this->board[1][1] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[2][2] == this->board[3][3] && this->board[3][3] == this->board[4][4] && this->board[2][2] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[1][0] == this->board[2][1] && this->board[2][1] == this->board[3][2] && this->board[1][0] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[2][1] == this->board[3][2] && this->board[3][2] == this->board[4][3] && this->board[2][1] == 'O'){
        player_2_count = player_2_count + 1;
    }
    if (this->board[2][0] == this->board[3][1] && this->board[3][1] == this->board[4][2] && this->board[2][0] == 'O'){
        player_2_count = player_2_count + 1;
    }
}