/*
 * Tic-Tac-Toe Game
 * 
 * This program is a simple implementation of the classic Tic-Tac-Toe game in C.
 * 
 * Features:
 * - Two players take turns to mark their chosen symbol ('X' or 'O') on a 3x3 board.
 * - The game ends when a player achieves a winning combination or the board is full (draw).
 * 
 * Game Rules:
 * - Players choose between 'X' and 'O' as their mark.
 * - Players take turns to place their mark on an empty spot on the board.
 * - The first player to get 3 of their marks in a row (horizontally, vertically, or diagonally) wins.
 * - If all 9 spots are filled and no player has won, it's a draw.
 * 
 * How to Play:
 * - Players enter their chosen symbol ('X' or 'O') at the beginning of the game.
 * - During their turn, players choose an empty spot on the board by entering a position number (1-9).
 * - The game validates the input and displays the updated board after each move.
 * - The game ends when a player wins or it's a draw.
 * 
 * Author: Ranjit Kale 
 */

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

