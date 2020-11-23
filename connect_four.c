/*  Connect Four 
   [TERMINAL EDITION]
    by Jason McGuire  */

#include <stdio.h>

int drop_chip(int, int, int board[6][7]);
int scan_board(int, int board[6][7]);
void update_board(int board[6][7]);

int main() {
    int winner = 0;                 // Used for while loop in main 
    int choice;                     // The column # chosen by the player 
    int player1 = 1, player2 = 2;   // Used to differentiate players in functions
    int board[6][7] = {             // The game board as a 2D array
        {0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,0}
    };

    update_board(board);
    while (winner == 0) {
        /* Player 1's turn */
        printf("\033[01;32mPlayer 1 pick a column (1-7): ");
        scanf("%d", &choice);
        
        while (choice < 1 || choice > 7) {
            printf("Invalid column try again: ");
            scanf("%d", &choice);
        }
        /* "Drops chip" into chosen column*/
        board[6][7] = drop_chip(player1, choice, board);
        /* Prints the updated board */
        update_board(board);
        
        /* Checks for four in a row */
        winner = scan_board(player1, board);
        /* Break if four in a row is found*/
        if (winner > 0) {
            break;
        }
        
        /* Player 2's turn */
        printf("\033[01;32mPlayer 2 pick a column (1-7): ");
        scanf("%d", &choice);
        
        while (choice < 1 || choice > 7) {
            printf("Invalid column try again: ");
            scanf("%d", &choice);
        }
        
        board[6][7] = drop_chip(player2, choice, board);
        
        update_board(board);
        
        winner = scan_board(player2, board);

        if (winner > 0) {
            break;
        }
    }
    printf("\033[01;32mPlayer %d is the winner", winner);
}

int drop_chip(int player, int x, int board[6][7]) {
    int i;
    /* Looks for the first empty space in the chosen
        column and changes it to player # */
    for (i=5; i>=0; i--) {
        if (board[i][x-1] == 0) {
            board[i][x-1] = player;
            break;
        }
    }
    return board[6][7];
}

int scan_board(int winner, int x[6][7]) {
    int i, j;
    
    for (i=6; i>0; i--) {
        for (j=0; j<7; j++) {
            /* Check for four in a row vertically */
            if (x[i][j] > 0 && x[i][j] == x[i-1][j] && x[i-1][j] == x[i-2][j] && x[i-2][j] == x[i-3][j]) {
                return winner;
                break;
            /* Check horizontally */
            } else if (x[i][j] > 0 && x[i][j] == x[i][j+1] && x[i][j+1] == x[i][j+2] && x[i][j+2] == x[i][j+3]) {
                return winner;
                break;
            /* Check diagonally(reverse) */
            } else if (x[i][j] > 0 && x[i][j] == x[i-1][j+1] && x[i-1][j+1] == x[i-2][j+2] && x[i-2][j+2] == x[i-3][j+3]) {
                return winner;
                break;
            /* Check diagonally(forward) */
            } else if (x[i][j] > 0 && x[i][j] == x[i+1][j+1] && x[i+1][j+1] == x[i+2][j+2] && x[i+2][j+2] == x[i+3][j+3]) {
                return winner;
                break;
            }
        }
    }
    return 0;
}

void update_board(int x[6][7]) {
    /* Prints the board */
    int i, j, a;
    int *cell;

    for (i=0; i<30; i++) {
        printf("\n");
    }
    
    printf("\033[01;34m_________________________________________________________\n");

    for (a=0; a<6; a++){
        for (j=0; j<7; j++) {
            printf("   ___  ");
        }
        
        printf("\n");
    
        for (i=0; i<7; i++) {
            printf("  /   \\ ");
        }
        
        printf("\n");
        
        for (i=0; i<7; i++) {
            
            printf(" |  ");
            if (x[a][i] == 1) {
                printf("\033[01;33m%d", x[a][i]);
            
            } else if (x[a][i] == 2) {
                printf("\033[01;31m%d", x[a][i]);
            
            } else {
                printf("%d", x[a][i]);
            }
            printf("\033[1;34m  |");
        }
        
        printf("\n");
        
        for (i=0; i<7; i++) {
            printf("  \\___/ ");
        }
        printf("\n");
    }
    
    printf("_________________________________________________________\n");
}