#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int board[9][9] = {{2,8,9,0,3,0,0,1,4},
    {0,0,0,5,0,6,7,9,2},
    {5,0,0,0,0,9,0,0,0},
    {0,0,0,0,0,2,0,0,0},
    {4,0,5,0,6,0,8,0,3},
    {0,0,0,3,0,0,0,0,0},
    {0,0,0,2,0,0,0,0,1},
    {3,4,6,0,0,1,0,0,0},
    {8,1,0,0,4,0,3,7,9}};


    bool valid(int num, int pos[2], int bo[9][9]);
    void print_board(int bo[9][9]);

    int pos_test[2] = {0,3};
    print_board(board);
    bool result = valid(6, pos_test, board );
    if (result == true)
    {
        printf("valid");
    }
    else if(result == false)
    {
        printf("false");
    }
    else 
    {
        printf("this seems to have not worked");
    }

    return 0;
}



bool solver(){

return false;
}

bool valid(int num, int pos[2], int bo[9][9])
{
    printf("validating...");
    int i; 
    int j;

    for (i=0; i>=8; i++)
    {
        if (bo[pos[0]][i] == num) //horzontal checking
        {
            return false;
        }
    }
    
    for(j=0; j>=8; j++)
    {
        if (bo[j][pos[1]] == num) //vertical checking
        {
            return false;
        }
    }

    int box[2] = {pos[0]/3, pos[1]/3};  //checks box the item is in for valid 
    
    for(int i = box[0]*3; i < (box[0]*3)+3;i++)
    {
        printf("%d", box[0]*3);
        printf("%d", i);
        for (int j = box[1]*3; j < (box[1]*3)+3; j++)
        {
            printf("%d", box[1]*3);
            printf("%d", j);
            if (bo[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

void print_board(int bo[9][9])
{
    for (int i=0; i<=8; i++) // Looping through each line(row(vertically down the board))
    {
        for (int j=0; j<=8; j++) // Looping through each column(horizontally accross the board)
        {
            printf("%d ", bo[i][j]);
            if (j==8)
            {
                printf("\n");       // New line at the end of each row
            }
        }
    }

}

