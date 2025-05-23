#include <cs50.h>
#include <stdio.h>

void print_hash(int row, int height);

int main(void)
{
    // Get height must be positive int 1-8
    int height;
    do
    {
     height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    for (int i = 0; i < height; i++)
    {
        print_hash(i + 1, height);
    }
}

    // Prints pyramid
void print_hash(int row, int height){
    for (int j = 0; j < height - row; j++)
    {
        printf(" ");
    }
    for (int k = 0; k < row; k++)
    {
        printf("#");
    }
    printf("  ");
    for (int m = 0; m < row; m++)
    {
        printf("#");
    }
    printf("\n");
}
