#include <stdio.h>

char board[3][3];

void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n    1   2   3  (column)\n");
    for (int i = 0; i < 3; i++) {
        printf("  +---+---+---+\n");
        printf("%d | %c | %c | %c |\n", i + 1, board[i][0], board[i][1], board[i][2]);
    }
    printf("  +---+---+---+\n");
    printf(" (row)\n\n");
}

int checkWin() {
    // rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;
    }
    // columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j])
            return 1;
    }
    // diagonals
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;

    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;

    return 0;
}

int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

int main() {
    int row, col;
    char currentPlayer = 'X';

    initBoard();

    printf("Tic-Tac-Toe Game in C\n");
    printf("Player 1: X\nPlayer 2: O\n");
    printf("Enter moves as: row column (e.g. 1 1 for top-left)\n");

    while (1) {
        printBoard();
        printf("Player %c, enter row and column (1-3 1-3): ", currentPlayer);

        if (scanf("%d %d", &row, &col) != 2) {
            printf("\nInvalid input, exiting.\n");
            return 0;
        }

        // range check
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid position! Please enter values between 1 and 3.\n");
            continue;
        }

        // convert to 0-based index
        row--;
        col--;

        if (board[row][col] != ' ') {
            printf("Cell already taken! Choose another.\n");
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin()) {
            printBoard();
            printf("🎉 Player %c wins!\n", currentPlayer);
            break;
        }

        if (isBoardFull()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        // switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
