#include <iostream>
#include <stdlib.h> //cls
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
void display();
void playerTurn();
bool gameOver();

int row;
int column;
char turn = 'X';
bool draw = false;
int main() {

    cout << endl << endl <<"***************************************" << endl << endl;
    cout << "\tWelcome to Tic Tac Toe";
    cout << endl << endl <<"***************************************" << endl << endl;
    cout << "\tPlayer1 [X] " << endl;
    cout << "\tPlayer2 [O]" << endl<<endl;

    system("pause");

    while (gameOver()) {
        //system("CLS");
        display();
        playerTurn();
        gameOver();
        //display();
    }
    if (turn == 'X' && draw == false) {
        cout << "Player2 [O] wins!!! Congritulation..." << endl;
        system("pause");
    }
    else if (turn == 'O' && draw == false) {
        cout << "Player1 [X] wins!!! Congritulation..." << endl;
        system("pause");
    }
    else {
        cout << "Game Draw!!!" << endl;
        system("pause");
    }
    return 0;
}

void display() {

    system("cls");
    cout << "\t   "<< board[0][0] << "  |  " << board[0][1] << "   |   " << board[0][2] << endl;
    cout << "\t---------------------" << endl;
    cout << "\t   "<< board[1][0] << "  |  " << board[1][1] << "   |   " << board[1][2] << endl;
    cout << "\t---------------------" << endl;
    cout << "\t   "<< board[2][0] << "  |  " << board[2][1] << "   |   " << board[2][2] << endl << endl;
 
}

void playerTurn() {

    //cout << "Player1 [X] turn: " << endl;
    
    if (turn == 'X') {
        cout << "Player1 [X] turn: " << endl;
    }

    if (turn == 'O') {
        cout << "Player2 [O] turn: " << endl;
    }

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
        cout << "Invalid choice!" << endl; break;
    }
    if (turn == 'X'  && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = 'O';
        turn = 'X';
    } else {
        cout << "Box already filled......" << endl <<"Please try again....!" << endl;
        playerTurn();
    }
    display();
    
}


bool gameOver() {
    //check for winner
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return false;
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return false;
    }
    //if there is any box not filled
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return true;
            }
        }
    }

    //game draw
    draw = true;
    return false;
    
}