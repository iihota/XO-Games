#include <iostream>
#include "BoardGame_Classes.h"
#include "1.h"
#include "2.h"
#include "3.h"
#include "4.h"
#include "5.h"
#include "6.h"
#include "7.h"
#include "8.h"

using namespace std;

int main() {
    while (true) {

        int orderrrr;
        cout << "==========  Welcome to (X,O) Games  ==========" << endl << endl
        << "1- Pyramic Tic-Tac-Toe" << endl
        << "2- Four-in-a-row" << endl 
        << "3- 5 x 5 Tic Tac Toe" << endl 
        << "4- Word Tic-tac-toe" << endl
        << "5- Numerical Tic-Tac-Toe" << endl 
        << "6- Misere Tic Tac Toe" << endl 
        << "7- 4 x 4 Tic-Tac-Toe" << endl 
        << "8- Ultimate Tic Tac Toe" << endl 
        << "9- Exit" << endl
        << "Enter your order here : " << endl;
        cin >> orderrrr;


        if (orderrrr == 1)
        {
            int choice;
            Player<char>* players[2];
            X_O_Board_1<char>* Boardd = new X_O_Board_1<char>();
            string player_1_Name, player_2_Name;

            cout << "Enter Player X name: ";
            cin >> player_1_Name;
            cout << "Choose Player X type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            switch(choice) {
                case 1:
                    players[0] = new X_O_Player_1<char>(player_1_Name, 'X');
                    break;
                case 2:
                    players[0] = new X_O_Random_Player<char>('X');
                    break;
                default:
                    cout << "Invalid choice for Player 1. Exiting the game.\n";
                    return 1;
            }

            cout << "Enter Player 2 name: ";
            cin >> player_2_Name;
            cout << "Choose Player 2 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            switch(choice) {
                case 1:
                    players[1] = new X_O_Player_1<char>(player_2_Name, 'O');
                    break;
                case 2:
                    players[1] = new X_O_Random_Player<char>('O');
                    break;
                default:
                    cout << "Invalid choice for Player 2. Exiting the game.\n";
                    return 1;
            }

            GameManager<char> x_o_game(Boardd, players);
            x_o_game.run();

            delete Boardd;
            for (int i = 0; i < 2; ++i) {
                delete players[i];
            }
        }


        // ===============================================================================================

        else if (orderrrr == 2)
        {
            string p1_name, p2_name;
            cout << "Enter Player 1 name : " ; cin >> p1_name;
            cout << "Enter Player 2 name : " ; cin >> p2_name;
            X_O_Board_2<char> board;
            X_O_Player_2<char> player1("Player 1", 'X');
            X_O_Player_2<char> player2("Player 2", 'O');

            player1.setBoard(&board);
            player2.setBoard(&board);

            Player<char>* players[2] = {&player1, &player2};
            GameManager<char> gameManager(&board, players);

            gameManager.run();
        }


        // ===============================================================================================
        else if (orderrrr == 3)
        {
            int choice;
            Player<char>* players[2];
            X_O_Board_3<char>* Boardd = new X_O_Board_3<char>();
            string player_1_Name, player_2_Name;


            cout << "Enter Player X name: ";
            cin >> player_1_Name;
            cout << "Choose Player X type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            switch(choice) {
                case 1:
                    players[0] = new X_O_Player_3<char>(player_1_Name, 'X');
                    break;
                case 2:
                    players[0] = new X_O_Random_Player_3<char>('X');
                    break;
                default:
                    cout << "Invalid choice for Player 1. Exiting the game.\n";
                    return 1;
            }

            cout << "Enter Player 2 name: ";
            cin >> player_2_Name;
            cout << "Choose Player 2 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            switch(choice) {
                case 1:
                    players[1] = new X_O_Player_3<char>(player_2_Name, 'O');
                    break;
                case 2:
                    players[1] = new X_O_Random_Player_3<char>('O');
                    break;
                default:
                    cout << "Invalid choice for Player 2. Exiting the game.\n";
                    return 1;
            }

            cout << "Player 1 count is : " << player_1_count << endl;
            cout << "Player 2 count is : " << player_2_count << endl;

            GameManager<char> x_o_game(Boardd, players);
            x_o_game.run(3);

            Boardd->Players_counter();

            cout << players[0]->getname() << " count : " << player_1_count << endl;
            cout << players[1]->getname() << " count : " << player_2_count << endl;

            if (player_1_count > player_2_count){
                cout << players[0]->getname() << " win.";
            }
            else if(player_2_count > player_1_count){
                cout << players[1]->getname() << " win.";  
            }
            else{
                cout << "==========    drow    =========";
            }
            
            delete Boardd;
            for (int i = 0; i < 2; ++i) {
                delete players[i];
            }
        }

        // ===============================================================================================

        else if (orderrrr == 4)
        {
            get_worddds();
            int choice;
            Player<char>* players[2];
            X_O_Board_4<char>* B = new X_O_Board_4<char>();
            string playerXName, player2Name;

            cout << "Enter Player X name: ";
            cin >> playerXName;
            cout << "Choose Player X type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            switch(choice) {
                case 1:
                    players[0] = new X_O_Player_4<char>(playerXName, 'X');
                    break;
                case 2:
                    players[0] = new X_O_Random_Player_4<char>('X');
                    break;
                default:
                    cout << "Invalid choice for Player 1. Exiting the game.\n";
                    return 1;
            }

            cout << "Enter Player 2 name: ";
            cin >> player2Name;
            cout << "Choose Player 2 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            switch(choice) {
                case 1:
                    players[1] = new X_O_Player_4<char>(player2Name, 'O');
                    break;
                case 2:
                    players[1] = new X_O_Random_Player_4<char>('O');
                    break;
                default:
                    cout << "Invalid choice for Player 2. Exiting the game.\n";
                    return 1;
            }

            GameManager<char> x_o_game(B, players);
            x_o_game.run();

            delete B;
            for (int i = 0; i < 2; ++i) {
                delete players[i];
            }
        }


        // ===============================================================================================


        else if (orderrrr == 5)
        {
            int choice;
            Player<int>* players[2];
            X_O_Board_5<int>* Boardd = new X_O_Board_5<int>();
            string player_1_Name, player_2_Name;

            cout << "Enter Player X name: ";
            cin >> player_1_Name;
            cout << "Choose Player X type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            switch(choice) {
                case 1:
                    players[0] = new X_O_Player_5<int>(player_1_Name,player_1);
                    break;

                default:
                    cout << "Invalid choice for Player 1. Exiting the game.\n";
                    return 1;
            }

            cout << "Enter Player 2 name: ";
            cin >> player_2_Name;
            cout << "Choose Player 2 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            switch(choice) {
                case 1:
                    players[1] = new X_O_Player_5<int>(player_2_Name,player_2);
                    break;

                default:
                    cout << "Invalid choice for Player 2. Exiting the game.\n";
                    return 1;
            }

            // Create the game manager and run the game
            GameManager<int> x_o_game(Boardd, players);
            x_o_game.run();

            // Clean up
            delete Boardd;
            for (int i = 0; i < 2; ++i) {
                delete players[i];
            }

        }

        // ===============================================================================================


        else if (orderrrr == 6)
        {    
            int choice;
            Player<char>* players[2];
            X_O_Board_6<char>* B = new X_O_Board_6<char>();
            string playerXName, player2Name;


            // Set up player 1
            cout << "Enter Player X name: ";
            cin >> playerXName;
            cout << "Choose Player X type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            switch(choice) {
                case 1:
                    players[0] = new X_O_Player_6<char>(playerXName, 'X');
                    break;
                case 2:
                    players[0] = new X_O_Random_Player_6<char>('X');
                    break;
                default:
                    cout << "Invalid choice for Player 1. Exiting the game.\n";
                    return 1;
            }

            // Set up player 2
            cout << "Enter Player 2 name: ";
            cin >> player2Name;
            cout << "Choose Player 2 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            switch(choice) {
                case 1:
                    players[1] = new X_O_Player_6<char>(player2Name, 'O');
                    break;
                case 2:
                    players[1] = new X_O_Random_Player_6<char>('O');
                    break;
                default:
                    cout << "Invalid choice for Player 2. Exiting the game.\n";
                    return 1;
            }

            GameManager<char> x_o_game(B, players);
            x_o_game.run(6);

            delete B;
            for (int i = 0; i < 2; ++i) {
                delete players[i];
            }
        }


        // ===============================================================================================


        else if (orderrrr == 7)
        {    
            int choice;
            Player<char>* players[2];
            X_O_Board_7<char>* B = new X_O_Board_7<char>();
            string playerXName, player2Name;


            cout << "Enter Player X name: ";
            cin >> playerXName;
            cout << "Choose Player X type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            switch(choice) {
                case 1:
                    players[0] = new X_O_Player_7<char>(playerXName, 'X');
                    break;
                case 2:
                    players[0] = new X_O_Random_Player_7<char>('X');
                    break;
                default:
                    cout << "Invalid choice for Player 1. Exiting the game.\n";
                    return 1;
            }

            cout << "Enter Player 2 name: ";
            cin >> player2Name;
            cout << "Choose Player 2 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            switch(choice) {
                case 1:
                    players[1] = new X_O_Player_7<char>(player2Name, 'O');
                    break;
                case 2:
                    players[1] = new X_O_Random_Player_7<char>('O');
                    break;
                default:
                    cout << "Invalid choice for Player 2. Exiting the game.\n";
                    return 1;
            }

            GameManager<char> x_o_game(B, players);
            x_o_game.run();

            delete B;
            for (int i = 0; i < 2; ++i) {
                delete players[i];
            }
        }


        // ===============================================================================================



        else if (orderrrr == 8)
        {
            int choice;
            Player<char>* players[2];
            X_O_Board_8<char>* B = new X_O_Board_8<char>();
            string playerXName, player2Name;


            // Set up player 1
            cout << "Enter Player X name: ";
            cin >> playerXName;
            cout << "Choose Player X type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            switch(choice) {
                case 1:
                    players[0] = new X_O_Player_8<char>(playerXName, 'X');
                    break;
                case 2:
                    players[0] = new X_O_Random_Player_8<char>('X');
                    break;
                default:
                    cout << "Invalid choice for Player 1. Exiting the game.\n";
                    return 1;
            }

            cout << "Enter Player 2 name: ";
            cin >> player2Name;
            cout << "Choose Player 2 type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;

            switch(choice) {
                case 1:
                    players[1] = new X_O_Player_8<char>(player2Name, 'O');
                    break;
                case 2:
                    players[1] = new X_O_Random_Player_8<char>('O');
                    break;
                default:
                    cout << "Invalid choice for Player 2. Exiting the game.\n";
                    return 1;
            }

            GameManager<char> x_o_game(B, players);
            x_o_game.run();

            // Clean up
            delete B;
            for (int i = 0; i < 2; ++i) {
                delete players[i];
            }
        }


        // ===============================================================================================

        else if (orderrrr == 9)
        {
            break;
        }
        cout << endl << endl;
    }
    return 0;
}



