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
        printf("\nAlready taken, please enter again\n\n");
    }
    return value;
}

bool strcmp3(char* one, char* two, char* three){
    printf("%s %s %s\n", one, two, three);
    return strcmp(one,two)==0 && strcmp(two,three)==0;
}

bool playerWin(char * board[3][3]){
    if(strcmp3(board[0][0], board[0][1], board[0][2])){
        return true;
    } else if(strcmp3(board[1][0], board[1][1], board[1][2])){
        return true;
    } else if(strcmp3(board[2][0], board[2][1], board[2][2])){
        return true;
    } else if(strcmp3(board[0][0], board[1][0], board[2][0])){
        return true;
    } else if(strcmp3(board[0][1], board[1][1], board[2][1])){
        return true;
    } else if(strcmp3(board[0][2], board[1][2], board[2][2])){
        return true;
    } else if(strcmp3(board[0][0], board[1][1], board[2][2])){
        return true;
    } else if(strcmp3(board[0][2], board[1][1], board[2][0])){
        return true;
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
        if(playerWin(board)){
            printf("\nTHE WINNER IS PLAYER %s\n", playerChar);
            break;
        }
    }
    
    return 0;
}