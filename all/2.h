#include "BoardGame_Classes.h"


template <typename T>
class X_O_Board_2 : public Board<T> {
public:

    X_O_Board_2() {
        this->rows = 6;
        this->columns = 7;
        this->board = new T*[this->rows];
        for (int i = 0; i < this->rows; ++i) {
            this->board[i] = new T[this->columns];
            fill(this->board[i], this->board[i] + this->columns, ' ');
        }
    }


    bool update_board(int x, int y, T symbol) override {
        if (y < 0 || y >= this->columns || this->board[0][y] != ' ')
            return false;

        for (int i = this->rows - 1; i >= 0; --i) {
            if (this->board[i][y] == ' ') {
                this->board[i][y] = symbol;
                ++this->n_moves;
                return true;
            }
        }
        return false;
    }

    void display_board() override {
        cout << endl<< " | 0 | 1 | 2 | 3 | 4 | 5 | 6 |" << endl;
        cout << " =============================" << endl;
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->columns; ++j) {
                cout << " | " << this->board[i][j];
            }
            cout << " |\n";
        }
        cout << string(this->columns * 2 + 1, '-') << "\n";
    }

    bool is_win() override {
        return check_win();
    }

    bool is_draw() override {
        return this->n_moves == this->rows * this->columns;
    }

    bool game_is_over() override {
        return is_win() || is_draw();
    }

private:
    bool check_win() {
        const int DIRECTIONS[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->columns; ++j) {
                if (this->board[i][j] == ' ')
                    continue;
                for (auto& d : DIRECTIONS) {
                    int count = 1;
                    for (int step = 1; step < 4; ++step) {
                        int ni = i + d[0] * step, nj = j + d[1] * step;
                        if (ni >= 0 && ni < this->rows && nj >= 0 && nj < this->columns &&
                            this->board[ni][nj] == this->board[i][j]) {
                            ++count;
                        } else {
                            break;
                        }
                    }
                    if (count >= 4)
                        return true;
                }
            }
        }
        return false;
    }
};


template <typename T> class X_O_Player_2 : public Player<T> {
public:
    X_O_Player_2(string n, T symbol) : Player<T>(n, symbol) {}

    void getmove(int& x, int& y) override {
        cout << this->name << " enter your move (column 0-6): ";
        cin >> y;
        x = 0;
    }
};