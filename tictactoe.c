#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void drawBoard(char * board[3][3]){
    printf("Column\t 1 | 2 | 3 \n");
    printf("      \t   |   |   \n");
    printf("Row 1 \t %s | %s | %s \n", board[0][0], board[0][1], board[0][2]);
    printf("      \t---|---|---\n");
    printf("Row 2 \t %s | %s | %s \n", board[1][0], board[1][1], board[1][2]);
    printf("      \t---|---|---\n");
    printf("Row 3 \t %s | %s | %s \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int * askForPlacement(int * placementTuple){//[row, col]
    printf("Choose a row (1-3): ");
    scanf("%d", &placementTuple[0]);//row
    printf("Choose a column (1-3): ");
    scanf("%d", &placementTuple[1]);//col
    return placementTuple;
}

bool checkPlacement(int * placementTuple, char * board[3][3]){
    int row = placementTuple[0]-1;
    int col = placementTuple[1]-1;
    bool value = board[row][col] == ".";
    if(!value){
        printf("\nSomething went wrong, please try again\n\n");
    }
    return value;
}

bool playerWin(char * board[3][3], char * player){
    bool board1D[] = {
        board[0][0] == player,
        board[0][1] == player,
        board[0][2] == player,
        board[1][0] == player,
        board[1][1] == player,
        board[1][2] == player,
        board[2][0] == player,
        board[2][1] == player,
        board[2][2] == player
    };

    bool winCases[] = {
        board1D[0] && board1D[1] && board1D[2],
        board1D[3] && board1D[4] && board1D[5],
        board1D[6] && board1D[7] && board1D[8],
        board1D[0] && board1D[3] && board1D[6],
        board1D[1] && board1D[4] && board1D[7],
        board1D[2] && board1D[5] && board1D[8],
        board1D[0] && board1D[4] && board1D[8],
        board1D[2] && board1D[4] && board1D[6]
    };

    for(int i = 0; i < 8; i++){
        if(winCases[i]){
            return true;
        }
    }
    return false;
}

int main(){
    int placementTuple[2];
    char * board[3][3] = {
        {".", ".", "."},
        {".", ".", "."},
        {".", ".", "."}
    };
    drawBoard(board);

    for(int round = 1; round <= 9; round++){//max 9 turns in tictactoe
        char * playerChar = round%2 == 0 ? "X" : "O";
        int * placement;
        do {
            placement = askForPlacement(placementTuple);
        } while (!checkPlacement(placement, board));
        board[placement[0]-1][placement[1]-1] = playerChar;
        drawBoard(board);
        if(playerWin(board, playerChar)){
            printf("\nTHE WINNER IS PLAYER %s\n", playerChar);
            break;
        }
    }
    
    return 0;
}