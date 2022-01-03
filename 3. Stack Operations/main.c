/*
    Design, Develop and Implement a menu driven Program in C for the following operations on STACK of Integers (Array Implementation of Stack with maximum size MAX)
        a. Push an Element on to Stack
        b. Pop an Element from Stack
        c. Demonstrate how Stack can be used to check Palindrome
        d. Demonstrate Overflow and Underflow situations on Stack
        e. Display the status of Stack
        f. Exit
    Support the program with appropriate functions for each of the above operations.
*/

#include <stdio.h>
#define MAX 5

// Stack implementation using arrays of int
int stack[MAX], top = -1;

// Push an element to stack
void Push(int item)
{
    // Check for overflow coondition
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        // Increment top and insert to array stack
        stack[++top] = item;
    }
}

// Pop an element from stack
int Pop()
{
    // Check for underflow condition
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        return 0;
    }
    else
    {
        // return top element and decrement top
        return stack[top--];
    }
}

// Display stack contents
void Display()
{
    int i; // Loop var
    // Check if stack empty
    if (top == -1)
    {
        printf("Stack Empty!\n");
        return;
    }
    else
    {
        printf("Stack contents: \n");
        for (i = top; i >= 0; i--)
        {
            printf("| %d |\n", stack[i]);
        }
        printf("\n");
    }
}

// Check for palindrome
int isPalindrome()
{
    int i, temp = (top + 1) / 2;
    int flag; // return value
    for (i = 0; i < temp; i++)
    {
        // If popped element matches bottom element
        if (Pop() == stack[i])
        {
            flag = 1; //  True
        }
        else
        {
            flag = 0; // False
        }
    }
    return flag;
}

// Driver program
void main()
{
    int ch, elem;
    while (1)
    {
        printf("\nStack Operations: \n");
        printf("\t1. Push\n");
        printf("\t2. Pop\n");
        printf("\t3. Display\n");
        printf("\t4. Palindrome\n");
        printf("\t5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter item: ");
            scanf("%d", &elem);
            Push(elem);
            break;
        case 2:
            elem = Pop();
            if (elem)
                printf("Popped %d\n", elem);
            break;
        case 3:
            Display();
            break;
        case 4:
            elem = isPalindrome();
            if (elem)
                printf("Stack is palindrome!\n");
            else
                printf("Stack is not palindrome!\n");
            break;
        case 5:
            return;
        }
    }
}