#include <algorithm>
#include "BoardGame_Classes.h"
#include <iomanip>

int m;
bool gg;
vector<int> player_1 = {1,3,5,7,9};
vector<int> player_2 = {2,4,6,8};



template <typename T> class X_O_Board_5:public Board<T> {
public:
    X_O_Board_5 ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
};

template <typename T> class X_O_Player_5 : public Player<T> {
public:
    X_O_Player_5 (string name,vector<int> vec);
    void getmove(int& x, int& y);
    virtual bool get_num_player(int num);
    vector<int> VEC;
};


template <typename T> X_O_Board_5<T>::X_O_Board_5() {
    this->rows = this->columns = 3;
    this->board = new int*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new int[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T> bool X_O_Board_5<T>::update_board(int x, int y, T mark) {
    if (gg&&!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
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

template <typename T> void X_O_Board_5<T>::display_board() {
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

template <typename T> bool X_O_Board_5<T>::is_win() {
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] + this->board[i][1] + this->board[i][2] == 15 && (this->board[i][0] != 0 && this->board[i][1] != 0 && this->board[i][2] != 0)) ||
            (this->board[0][i] + this->board[1][i] + this->board[2][i] == 15 && (this->board[0][i] != 0 && this->board[1][i] != 0 && this->board[2][i] != 0))) {
            return true;
        }
    }

    if ((this->board[0][0] + this->board[1][1] + this->board[2][2] == 15 && (this->board[0][0] != 0 && this->board[1][1] != 0 && this->board[2][2] != 0)) ||
        (this->board[0][2] + this->board[1][1] + this->board[2][0] == 15 && (this->board[0][2] != 0 && this->board[1][1] != 0 && this->board[2][0] != 0))) {
        return true;
    }
    return false;
}

template <typename T> bool X_O_Board_5<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T> bool X_O_Board_5<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T> X_O_Player_5<T>::X_O_Player_5(string name,vector<int> vec) : Player<T>(name) {
    this->VEC = vec;
}

template <typename T> void X_O_Player_5<T>::getmove(int& x, int& y) {
    
    cout << endl << this->getname() << " Please enter your move x and y (0 to 2) separated by spaces : ";
    cin >> x >> y >> m;
    this->symbol = m;
    gg = this->get_num_player(m);
}

template <typename T> bool X_O_Player_5<T>::get_num_player(int num){
    auto if_in = find(this->VEC.begin(),this->VEC.end(),num);
    if(if_in != this->VEC.end()){
        this->VEC.erase(if_in);
        return true;
        }
    else{return false;}
};