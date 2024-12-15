#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <algorithm>

using namespace std;

vector<string> wordsss;
void get_worddds(){
    ifstream inputFile("dic.txt");
    string word;

    while (inputFile >> word) {
        wordsss.push_back(word);
    }
    inputFile.close();
}

char get_char = 0;
char w1[3], w2[3], w3[3], w4[3], w5[3], w6[3], w7[3], w8[3], w9[3], w10[3], w11[3], w12[3], w13[3], w14[3], w15[3], w16[3];



template <typename T> class X_O_Board_4:public Board<T> {
public:
    X_O_Board_4 ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
};

template <typename T> class X_O_Player_4 : public Player<T> {
public:
    X_O_Player_4 (string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T> class X_O_Random_Player_4 : public RandomPlayer<T>{
public:
    X_O_Random_Player_4 (T symbol);
    void getmove(int &x, int &y) ;
};




template <typename T> X_O_Board_4<T>::X_O_Board_4() {
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T> bool X_O_Board_4<T>::update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(get_char);
        }


        w1[0]=this->board[0][0];   w1[1]=this->board[0][1];   w1[2]=this->board[0][2];
        w2[0]=this->board[1][0];   w2[1]=this->board[1][1];   w2[2]=this->board[1][2];
        w3[0]=this->board[2][0];   w3[1]=this->board[2][1];   w3[2]=this->board[2][2];

        w4[0]=this->board[0][0];   w4[1]=this->board[1][0];   w4[2]=this->board[2][0];
        w5[0]=this->board[0][1];   w5[1]=this->board[1][1];   w5[2]=this->board[2][1];
        w6[0]=this->board[0][2];   w6[1]=this->board[1][2];   w6[2]=this->board[2][2];

        w7[0]=this->board[0][0];   w7[1]=this->board[1][1];   w7[2]=this->board[2][2];
        w8[0]=this->board[0][2];   w8[1]=this->board[1][1];   w8[2]=this->board[2][0];


        w9[0]=this->board[0][2];   w9[1]=this->board[0][1];   w9[2]=this->board[0][0];
        w10[0]=this->board[1][2];   w10[1]=this->board[1][1];   w10[2]=this->board[1][0];
        w11[0]=this->board[2][2];   w11[1]=this->board[2][1];   w11[2]=this->board[2][0];

        w12[0]=this->board[2][0];   w12[1]=this->board[1][0];   w12[2]=this->board[0][0];
        w13[0]=this->board[2][1];   w13[1]=this->board[1][1];   w13[2]=this->board[0][1];
        w14[0]=this->board[2][2];   w14[1]=this->board[1][2];   w14[2]=this->board[0][2];

        w15[0]=this->board[2][2];   w15[1]=this->board[1][1];   w15[2]=this->board[1][1];
        w16[0]=this->board[2][0];   w16[1]=this->board[1][1];   w16[2]=this->board[0][2];

        return true;
    }
    return false;
}

template <typename T> void X_O_Board_4<T>::display_board() {
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

template <typename T> bool X_O_Board_4<T>::is_win() {

    auto find1 = find(wordsss.begin(), wordsss.end(), w1);
    auto find2 = find(wordsss.begin(), wordsss.end(), w2);
    auto find3 = find(wordsss.begin(), wordsss.end(), w3);

    auto find4 = find(wordsss.begin(), wordsss.end(), w4);
    auto find5 = find(wordsss.begin(), wordsss.end(), w5);
    auto find6 = find(wordsss.begin(), wordsss.end(), w6);

    auto find7 = find(wordsss.begin(), wordsss.end(), w7);
    auto find8 = find(wordsss.begin(), wordsss.end(), w8);



    auto find9 = find(wordsss.begin(), wordsss.end(), w9);
    auto find10 = find(wordsss.begin(), wordsss.end(), w10);
    auto find11 = find(wordsss.begin(), wordsss.end(), w11);

    auto find12 = find(wordsss.begin(), wordsss.end(), w12);
    auto find13 = find(wordsss.begin(), wordsss.end(), w13);
    auto find14 = find(wordsss.begin(), wordsss.end(), w14);

    auto find15 = find(wordsss.begin(), wordsss.end(), w15);
    auto find16 = find(wordsss.begin(), wordsss.end(), w16);


    if ((find1 != wordsss.end()) || (find2 != wordsss.end()) || (find3 != wordsss.end()) || (find4 != wordsss.end()) ||
        (find5 != wordsss.end()) || (find6 != wordsss.end()) || (find7 != wordsss.end()) || (find8 != wordsss.end()) ||
        (find9 != wordsss.end()) || (find10 != wordsss.end()) || (find11 != wordsss.end()) || (find12 != wordsss.end()) ||
        (find13 != wordsss.end()) || (find14 != wordsss.end()) || (find15 != wordsss.end()) || (find16 != wordsss.end())) {
        return true ;
    }
    return false;
}

template <typename T> bool X_O_Board_4<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T> bool X_O_Board_4<T>::game_is_over() {
    return is_win() || is_draw();
}


template <typename T> X_O_Player_4<T>::X_O_Player_4(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T> void X_O_Player_4<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y >> get_char;
}

template <typename T> X_O_Random_Player_4<T>::X_O_Random_Player_4(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T> void X_O_Random_Player_4<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}