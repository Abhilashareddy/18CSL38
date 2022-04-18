/*
    Solving Tower of Hanoi problem with n disks
*/

#include <stdio.h>
// #include <math.h> // pow()

// Count moves
// You can also consider formula "pow(2,n)-1" to compute total moves
// Here we'll implement simple integer which increments on each function call
int moves = 0;

void TOH(int n, char src, char temp, char dest)
{
    if (n == 0) // terminate function when n=0
        return;
    TOH(n - 1, src, dest, temp);                     // src -> dest :: recursive call
    printf("Move %d from %c to %c\n", n, src, dest); // output values
    moves++;                                         // Count move
    TOH(n - 1, temp, src, dest);                     // temp -> src :: recursive call
}

void main()
{
    int val;
    printf("Enter no. of disc: ");
    scanf("%d", &val);
    TOH(val, 'S', 'T', 'D'); //  main call
    // Output total no. of moves
    printf("Total no. of moves are: %d\n", moves);
}