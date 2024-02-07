#include <stdio.h>
int checkWin(char*,char);
void displayBoard(char*);
void main() 
{
    char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    printf("Welcome to Tic-Tac-Toe!\n");
    displayBoard(board);
    char currentPlayer;
	printf("Choose the mark X or O\n");
    scanf("%c",&currentPlayer);
    int totalMoves = 0;
    while (totalMoves < 9) 
	{
        printf("Current board:\n");
        displayBoard(board);

        int position;
        do 
		{
            printf("Player %c, enter position (1-9): ", currentPlayer);
            scanf("%d", &position);
            position--; 
        } while (position < 0 || position > 8 || board[position] != ' ');

        board[position] = currentPlayer;
        totalMoves++;

        if (checkWin(board, currentPlayer)) 
		{
            printf("Player %c wins!\n", currentPlayer);
            displayBoard(board);
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    if (totalMoves == 9) 
	{
        printf("It's a draw!\n");
        displayBoard(board);
    }
}

void displayBoard(char* board) 
{
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}


int checkWin(char* board, char player) 
{
   
    if ((board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)) {
        return 1; 
    }
    return 0;
}

