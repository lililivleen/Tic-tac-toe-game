#include <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

int checkWin();
void displayBoard();
void markBoard(int choice, char player);

int main() {
    int choice, playerTurn = 1;
    char player = 'X';

    while (1) {
        displayBoard();
        printf("Player %c, enter a number (1-9): ", player);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        markBoard(choice, player);

        if (checkWin()) {
            displayBoard();
            printf("Player %c wins!\n", player);
            break;
        }

        player = (player == 'X') ? 'O' : 'X';  // Switch player
    }

    return 0;
}

void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

void markBoard(int choice, char player) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
    } else {
        printf("Cell already taken! Try again.\n");
    }
}

int checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||  // Row check
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {  // Column check
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0;
}

     
