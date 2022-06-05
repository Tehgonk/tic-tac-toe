#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char arr[5][5] = {'a', '*', 'b', '*', 'c', '*', '*', '*', '*', '*', 'd', '*', 'e', '*', 'f', '*', '*', '*', '*', '*', 'g', '*', 'h', '*', 'i'};
int win;
char input, player;
int count, winCountX, winCountO;

void resetGrid() {
    char resetArr[5][5] = {'a', '*', 'b', '*', 'c', '*', '*', '*', '*', '*', 'd', '*', 'e', '*', 'f', '*', '*', '*', '*', '*', 'g', '*', 'h', '*', 'i'};

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            arr[i][j] = resetArr[i][j];
        }
    }
}

void drawGrid() {

    printf("r = restart\nt = reset\n\n");
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            printf("%c ", arr[i][j]);
            if (j == 4) {
                printf("\n");
            }
        }
        
    }
}

void convertInput() {

    if (count % 2 == 1) {
        player = 'X';
    } else {
        player = 'O';
    }

    switch (input)
        {
        case 'a':
            arr[0][0] = player;
            break;
        
        case 'b':
            arr[0][2] = player;
            break;
        
        case 'c':
            arr[0][4] = player;
            break;
        
        case 'd':
            arr[2][0] = player;
            break;
        
        case 'e':
            arr[2][2] = player;
            break;
        
        case 'f':
            arr[2][4] = player;
            break;
        
        case 'g':
            arr[4][0] = player;
            break;
        
        case 'h':
            arr[4][2] = player;
            break;
        
        case 'i':
            arr[4][4] = player;
            break;
        
        default:
            break;
        }
}

void checkWin() {
    if (arr[0][0] == player && arr[0][2] == player && arr[0][4] == player) {
        win = 1;
    } else if (arr[2][0] == player && arr[2][2] == player && arr[2][4] == player) {
        win = 1;
    } else if (arr[4][0] == player && arr[4][2] == player && arr[4][4] == player) {
        win = 1;
    } else if (arr[0][0] == player && arr[2][0] == player && arr[4][0] == player) {
        win = 1;
    } else if (arr[0][2] == player && arr[2][2] == player && arr[4][2] == player) {
        win = 1;
    } else if (arr[0][4] == player && arr[2][4] == player && arr[4][4] == player) {
        win = 1;
    } else if (arr[0][4] == player && arr[2][2] == player && arr[4][0] == player) {
        win = 1;
    } else if (arr[0][0] == player && arr[2][2] == player && arr[4][4] == player) {
        win = 1;
    }
}

void scoreCounter() {
    if (player == 'X') {
        winCountX++;
    } else {
        winCountO++;
    }
}


int main() {

    win = 0;
    count = 1;
    resetGrid();

    while (!win) {

        system("cls");
        drawGrid();

        printf("\nScore - X's: %d   O's: %d\n", winCountX, winCountO);
        printf("\nChoose a cell: ");
        scanf(" %c", &input);
        printf("\n");
        if ( input == 'r') {
            main();
        }
        if ( input == 't') {
            winCountX = 0;
            winCountO = 0;
            main();
        }
        convertInput();
        system("cls");
        drawGrid();
        checkWin();

        if (win) {
            scoreCounter();
            printf("\n%c's win!", player);
            sleep(3);
            main();
    }
        count++;
    }
    
    
    return 0;
  
}