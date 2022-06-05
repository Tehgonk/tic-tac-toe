#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char arr[5][5] = {'1', '*', '2', '*', '3', '*', '*', '*', '*', '*', '4', '*', '5', '*', '6', '*', '*', '*', '*', '*', '7', '*', '8', '*', '9'};
int roundCount = 1, winCountX = 0, winCountO = 0;
char input, ans;

void resetGame()
{
    char resetArr[5][5] = {'1', '*', '2', '*', '3', '*', '*', '*', '*', '*', '4', '*', '5', '*', '6', '*', '*', '*', '*', '*', '7', '*', '8', '*', '9'};

    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            arr[i][j] = resetArr[i][j];
        }
    }

    roundCount = 1;
}



void drawGrid()
{
    system("cls");
    printf("r = restart\n\n");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c ", arr[i][j]);
            if (j == 4)                 // at the end of each row (last column)
            {
                printf("\n");           // add a line break.
            }
        }
        
    }
}

char playerTurn(int turn)   // turn should equal roundCount.
{
    char playerTurn;        // playerTurn is set to either 'X' or 'O'.

    if (turn % 2 != 0)
    {
        playerTurn = 'X';
    }
    else
    {
        playerTurn = 'O';
    }

    return playerTurn;      // playerTurn returns either 'X' or 'O'.
    
}

// converts input and stores in arr.
void convertInput(char cell)                        // cell should equal input.
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (cell == arr[i][j])                  // if cell matches a character in the array element
            {
                arr[i][j] = playerTurn(roundCount); // that element gets replaced with either 'X' or 'O'.
            }
            else
            {
                roundCount--;                       // in case of invalid input, does not pass turn.
            }
            
            
        }
        
    }
    
}

int checkWin(void)
{
    int win = 0;

    if (arr[0][0] == playerTurn(roundCount) && arr[0][2] == playerTurn(roundCount) && arr[0][4] == playerTurn(roundCount))
    {
        win = 1;
    } 
    else if (arr[2][0] == playerTurn(roundCount) && arr[2][2] == playerTurn(roundCount) && arr[2][4] == playerTurn(roundCount))
    {
        win = 1;
    } 
    else if (arr[4][0] == playerTurn(roundCount) && arr[4][2] == playerTurn(roundCount) && arr[4][4] == playerTurn(roundCount)) 
    {
        win = 1;
    } 
    else if (arr[0][0] == playerTurn(roundCount) && arr[2][0] == playerTurn(roundCount) && arr[4][0] == playerTurn(roundCount)) 
    {
        win = 1;
    } 
    else if (arr[0][2] == playerTurn(roundCount) && arr[2][2] == playerTurn(roundCount) && arr[4][2] == playerTurn(roundCount)) 
    {
        win = 1;
    } 
    else if (arr[0][4] == playerTurn(roundCount) && arr[2][4] == playerTurn(roundCount) && arr[4][4] == playerTurn(roundCount)) 
    {
        win = 1;
    } 
    else if (arr[0][4] == playerTurn(roundCount) && arr[2][2] == playerTurn(roundCount) && arr[4][0] == playerTurn(roundCount)) 
    {
        win = 1;
    } 
    else if (arr[0][0] == playerTurn(roundCount) && arr[2][2] == playerTurn(roundCount) && arr[4][4] == playerTurn(roundCount)) 
    {
        win = 1;
    }

    return win;
    
}

void scoreCounter() {
    if (playerTurn(roundCount) == 'X') {
        winCountX++;
    } else {
        winCountO++;
    }
}


int main() 
{
    while (1)
    {
            drawGrid();
            printf("\nScore - X's: %d   O's: %d\n", winCountX, winCountO);
            printf("\n%c's turn\n", playerTurn(roundCount));
            printf("Choose a cell: ");
            scanf(" %c", &input);

            if (input == 'r')
            {
                winCountX = 0;
                winCountO = 0;
                resetGame();
                main();
            }
            

            convertInput(input);
            drawGrid();
            
            if (checkWin())
            {
                printf("\n%c's win!\n", playerTurn(roundCount));
                printf("\nWould you like to continue? [Y/n]: ");
                scanf(" %c", &ans);
                if (ans == 'Y')
                {
                    scoreCounter();
                    resetGame();
                    main();
                }
                else
                {
                    scoreCounter();
                    printf("\nScore - X's: %d   O's: %d\n", winCountX, winCountO);
                    break;
                }
                
                
            }
            
            roundCount++; 
    }
    

    return 0;
  
}