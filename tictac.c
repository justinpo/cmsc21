// AUTHORS: Manzanares, Gabriel John
//          Po, Justin Andre

#include <stdio.h>

void display(char table[3][3]);

int main(){
    int cont = 0;

    do {
        int turn = 1, row1, col1, row2, col2, wrong, win = 0, playerOne, playerTwo, i, j;
        char ta[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

        printf("\nLet's play some Tic-Tac-Toe!\n");
        printf("\n");
        display(ta);

        do{
            // Checks whose turn is it
            if (turn % 2 == 0) {
                // Loops for input
                do {
                    wrong = 0;
                    printf("\nPlayer 2 it's your turn! \n");
                    printf("\n");
                    printf("Enter a row: ");
                    scanf("%i",&row2);
                    printf("Enter a column: ");
                    scanf("%i",&col2);
                    printf("\n");
                    if (!(row2 >= 0 && row2 <= 2 && col2 >= 0 && col2 <= 2) || ta[row2][col2] != ' ') {
                        printf("Invalid input!\n");
                        printf("\n");
                        wrong = 1;
                    }
                } while (wrong);

                ta[row2][col2] = '0';
            }
            else {
                // Loops for input
                do {
                    wrong = 0;
                    printf("\nGo get 'em Player 1! \n");
                    printf("\n");
                    printf("Enter a row: ");
                    scanf("%i",&row1);
                    printf("Enter a column: ");
                    scanf("%i",&col1);
                    printf("\n");
                    if (!(row1 >= 0 && row1 <= 2 && col1 >= 0 && col1 <= 2) || ta[row1][col1] != ' ') {
                        printf("Invalid input!\n");
                        printf("\n");
                        wrong = 1;
                    }
                } while (wrong);
                
                ta[row1][col1] = 'X';
            }

            display(ta);


        // Checks if somebody has won horizontally
        for (i = 0; i < 3; i++) {
            playerOne = 0;
            playerTwo = 0;

            for (j = 0; j < 3; j++) {
                if (ta[i][j] == 'X') {
                    playerOne++;
                } else if (ta[i][j] == '0') {
                    playerTwo++;
                }
                if (playerOne == 3) {
                    win = 1;
                    break;
                } else if (playerTwo == 3) {
                    win = 2;
                    break;
                }
            }

            if (win) {
                break;
            }
        }

        // Checks if somebody has won vertically
        for (i = 0; i < 3; i++) {
            playerOne = 0;
            playerTwo = 0;

            for (j = 0; j < 3; j++) {
                if (ta[j][i] == 'X') {
                    playerOne++;
                } else if (ta[j][i] == '0') {
                    playerTwo++;
                }
                if (playerOne == 3) {
                    win = 1;
                    break;
                } else if (playerTwo == 3) {
                    win = 2;
                    break;
                }
            }

            if (win) {
                break;
            }
        }

        // Checks if somebody has won diagonally
        if (ta[0][0] == ta[1][1] && ta[1][1] == ta[2][2]) {
            if (ta[0][0] == 'X') {
                win = 1;
                break;
            } else if(ta[0][0] == '0') {
                win = 2;
                break;
            }
        }

        if (ta[0][2] == ta[1][1] && ta[1][1] == ta[2][0]) {
            if (ta[0][2] == 'X') {
                win = 1;
                break;
            } else if (ta[0][2] == '0') {
                win = 2;
                break;
            }
        }        
            
            turn++;

        // Loops while boxes aren't filled and no one has won
        } while (turn < 10 && !win);

        // Declares winner
        if (win == 1) {
            printf("\nPlayer 1 wins!\n");
            printf("\n");
        }
        else if (win == 2) {
            printf("\nPlayer 2 wins!\n");
            printf("\n");
        }
        else
        {
            printf("\nDraw!\n");
            printf("\n");
        }
        
        printf("Do you want to continue?\n");
        printf("[1] Continue\n");
        printf("[2] Exit\n");
        printf("\n");
        scanf("%i", &cont);

        switch(cont) {
            case 1:
                cont = 1;
                break;
            default:
                cont = 0;
                break;
        }


    } while(cont);
}

void display(char table[3][3]){
    //201 203 187 188 185 204 205 206 186
    printf("    0   1   2\n");
    printf("  \u2554\u2550\u2550\u2550\u2566\u2550\u2550\u2550\u2566\u2550\u2550\u2550\u2557\n");
    printf("0 \u2551 %c \u2551 %c \u2551 %c \u2551\n",table[0][0],table[0][1],table[0][2]);
    printf("  \u2560\u2550\u2550\u2550\u256C\u2550\u2550\u2550\u256C\u2550\u2550\u2550\u2563\n");
    printf("1 \u2551 %c \u2551 %c \u2551 %c \u2551\n",table[1][0],table[1][1],table[1][2]);
    printf("  \u2560\u2550\u2550\u2550\u256C\u2550\u2550\u2550\u256C\u2550\u2550\u2550\u2563\n");
    printf("2 \u2551 %c \u2551 %c \u2551 %c \u2551\n",table[2][0],table[2][1],table[2][2]);
    printf("  \u255A\u2550\u2550\u2550\u2569\u2550\u2550\u2550\u2569\u2550\u2550\u2550\u255D\n");
}
