#include <stdio.h>
#include <stdbool.h>



int count;
int main(void)
{
    int board[9][9] = {{7,3,9,0,0,0,6,0,4},
    {2,6,8,9,1,0,7,0,0},
    {4,5,1,0,0,0,0,0,9},
    {1,9,0,0,5,0,0,4,0},
    {0,4,0,1,0,3,0,6,0},
    {0,7,0,0,6,0,0,9,2},
    {3,0,0,0,0,0,0,2,6},
    {0,0,7,0,4,6,3,5,0},
    {6,0,5,0,0,0,4,0,1}};


    bool valid(int num, int pos[2], int bo[9][9]);
    void print_board(int bo[9][9]);
    bool solver(int bo[9][9]);

    int pos_test[2] = {0,3};
    print_board(board);
    printf("\n");
    printf("________________________ \n");
    solver(board);
    print_board(board);
    /*printf("this is durnig second call... \n");
    solver(board);
    printf("this is after second call... \n");
    print_board(board);
    */
    return 0;
}



bool solver(int bo[9][9])
{
    printf("%d", count);        //just counting 
    count++;

    int find_empty_col(int bo[9][9]);
    int find_empty_row(int bo[9][9]);           //declaring functions used in this function
    void print_board(int bo[9][9]);
    bool valid(int num, int pos[2], int bo[9][9]);

    printf("\n");
    printf("___________________________");
    printf("\n");
    
    print_board(bo);

    if (find_empty_row(bo) == 100)
    {
        print_board(bo);
        return true;
    }

    int row = find_empty_row(bo);
    int col = find_empty_col(bo);

    int found[2] = {row, col};

    for (int i = 1; i<=9; i++)
    {
        if (valid(i, found, bo) == true )
        {
            bo[found[0]][found[1]] = i;
            printf("\n found %d at %d %d \n",i,row,col);
            printf("%d \n", count);
            if (solver(bo) == true)
            {
                print_board(bo);
                return true;
            }
            else
            {
                printf(" \n backtracking \n");
                bo[found[0]][found[1]] = 0;
                
            }
        }
    }
    return false;  
}

int find_empty_row(int bo[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (bo[i][j] == 0)
            {
                return i;
            }
            
        }

    }
    return 100;
}

int find_empty_col(int bo[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (bo[i][j] == 0)
            {
                return j;
            }
        }

    }
    return 100;
}

bool valid(int num, int pos[2], int bo[9][9])
{
    int i; 
    int j;

    for (i=0; i<=8; i++)
    {
        if (bo[pos[0]][i] == num) //horzontal checking
        {
            return false;
        }
    }
    
    for(j=0; j<=8; j++)
    {
        if (bo[j][pos[1]] == num) //vertical checking
        {
            return false;
        }
    }

    int box[2] = {pos[0]/3, pos[1]/3};  //checks box the item is in for valid 
    
    for(int i = box[0]*3; i < (box[0]*3)+3;i++)  //checks each row in the box
    {
        for (int j = box[1]*3; j < (box[1]*3)+3; j++)  //checks columns in the box
        {
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
    printf("\n");
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

