#include<iostream>
using namespace std;

bool equal3(char x, char y, char z) {
    if(x == y && x == z && x != ' ') {
        return true;
    }
    return false;
}

int checkWiner(char board[3][3]) {
    //  2: X winer
    // -2: O winer
    //  0: Tie
    //  1: No winer

    // For rows
    for(int i = 0; i < 3; i++) {
        if(equal3(board[i][0], board[i][1], board[i][2])) {
            return board[i][0] == 'X' ? 2 : -2;
        }
    }

    // For cols
    for(int i = 0; i < 3; i++) {
        if(equal3(board[0][i], board[1][i], board[2][i])) {
            return board[0][i] == 'X' ? 2 : -2;
        }
    }
    
    // Diameter 1
    if(equal3(board[0][0], board[1][1], board[2][2])) {
        return board[0][0] == 'X' ? 2 : -2;
    }

    // Diameter 2
    if(equal3(board[2][0], board[1][1], board[0][2])) {
        return board[2][0] == 'X' ? 2 : -2;
    }

    // For Tie Case
    bool tie = true;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                tie = false;
            }
        }   
    }
    if(tie) return 0;

    // Else
    return 1;
}

void drowBoard(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " |";
        }   
        cout << "\n -------------- \n";
    }
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int x, y;
    bool has_winer = false;
    char player = 'X';
    while(!has_winer) {
        cin >> x >> y;
        if(board[x][y] == ' ') {
            board[x][y] = player;
            player == 'X' ? player = 'O' : player = 'X';
            drowBoard(board);
            has_winer = checkWiner(board) != 1;
        } else {
            cout << "The field is not empty \n";
        }
    }
    int result = checkWiner(board);
    if(result == 0) {
        cout << "Tie \n";
    } else {
        cout << ((result == 2) ? "X" : "O") << ": The winer \n";
    }
    return 0;
}