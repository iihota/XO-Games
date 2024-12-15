#include "BoardGame_Classes.h"


//   ===============   Classes    ==============
template <typename T> class X_O_Board_1:public Board<T> {
    public:
        X_O_Board_1();
        bool update_board (int x , int y , T symbol);
        void display_board ();
        bool is_win();
        bool is_draw();
        bool game_is_over();
};

template <typename T> class X_O_Player_1 : public Player<T> {
    public:
        X_O_Player_1 (string name, T symbol);
        void getmove(int& x, int& y);
};

template <typename T> class X_O_Random_Player : public RandomPlayer<T>{
    public:
        X_O_Random_Player (T symbol);
        void getmove(int &x, int &y);
};



//   =============   X O Board Functions    ==================
template <typename T> X_O_Board_1<T>::X_O_Board_1() {
    this->rows = 3 ;
    this->columns = 5;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++){
            this->board[i][j] = 32;
        }
    }
    this->n_moves = 0;
}

template <typename T> bool X_O_Board_1<T>::update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= this->rows)&&!(x == 0 && y !=0)&& !(x == 1 && ((y<0)||(y>2)))&& !(x == 2 && ((y<0)||(y>4))) && (this->board[x][y] == 32|| mark == 0)){
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

template <typename T> void X_O_Board_1<T>::display_board() {
    cout << endl;
    cout << "                    | (0,0) "<< this->board[0][0] << " |" << endl << "          -------------------------------" << endl ;
    cout << "          | (1,0) "<< this->board[1][0]  << " | (1,1) "<< this->board[1][1]<< " | (1,2) "<< this->board[1][2] << " |" << endl << "--------------------------------------------------" << endl;
    cout << "| (2,0) "<< this->board[2][0]  << " | (2,1) "<< this->board[2][1] << " | (2,2) "<< this->board[2][2] << " | (2,3) "<< this->board[2][3] << " | (2,4) "<< this->board[2][4] << " |" ;
    cout << endl << endl;
}

template <typename T> bool X_O_Board_1<T>::is_win() {
    if ((this->board[0][0] == this->board[1][0] && this->board[1][0] == this->board[2][0] && this->board[0][0] != 32) ||
        (this->board[0][0] == this->board[1][2] && this->board[1][2] == this->board[2][4] && this->board[0][0] != 32) ||
        (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 32) ||
        (this->board[1][0] == this->board[1][1] && this->board[1][1] == this->board[1][2] && this->board[1][0] != 32) ||
        (this->board[2][0] == this->board[2][1] && this->board[2][1] == this->board[2][2] && this->board[2][0] != 32) ||
        (this->board[2][1] == this->board[2][2] && this->board[2][2] == this->board[2][3] && this->board[2][1] != 32) ||
        (this->board[2][2] == this->board[2][3] && this->board[2][3] == this->board[2][4] && this->board[2][2] != 32)
        ){
            return true;
        }
    return false;
}

template <typename T> bool X_O_Board_1<T>::is_draw(){
    return (this->n_moves == 9 && !is_win());
}

template <typename T> bool X_O_Board_1<T>::game_is_over() {
    return is_win() || is_draw();
}


//   =============   X O Players Functions    ==================
template <typename T> X_O_Player_1<T>::X_O_Player_1(string name, T symbol) : Player<T>(name, symbol){}

template <typename T> void X_O_Player_1<T>::getmove(int& x, int& y) {
    cout << endl << this->getname() << " Please enter your move x and y (0 to 2) separated by spaces : ";
    cin >> x >> y;
}


//   =============   X O Random Functions    ==================
template <typename T> X_O_Random_Player<T>::X_O_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  
}

template <typename T> void X_O_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}