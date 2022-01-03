#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MX 10

int stack[MX], top = -1;

// Check char is an operator
int isOperator(char item){
    // if given character matches below switch cases
    // function will return 1 otherwise 0
    switch (item)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^': return 1;
        default:  return 0;
    }
}

// Compute arithmetic operation
int compute(char symbol, int op1, int op2)
{
    switch (symbol)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '%':
        return op1 % op2;
    case '^':
        return pow(op1, op2);
    default:
        return 0;
    }
}

// Check for stack underflow
// Function will check whether stack is empty
// if true outputs error and exits from program
void isStackEmpty() {
    if (top<0) {
        printf("Invalid Expression!\n");
        exit(0);
    }
}

// Evaluation of given expression
int Eval(char *postfix) {
    int i=0, op1, op2; // index of postfix
    char val; // temp char of postfix string
    while(postfix[i++] != '\0') {
        val = postfix[i]; 
        // Check for digit
        if(isdigit(val)) {
            // Push to stack after converting to int
            // A char in C language is an int of ASCII value
            // Hence if we subtract any digit char with '0'
            // We'll get actual int value of val :: refer ASCII table
            stack[++top] = val - '0';
        } else if (isOperator(val)) {
            // Check stack underflow
            isStackEmpty();
            op2 = stack[top--]; // pop from stack
            isStackEmpty();
            op2 = stack[top--];
            // Compute and push result back to stack
            stack[++top] = compute(val, op1, op2);
        } else {
            printf("Invalid usage of operator\n");
            exit(0); // exit
        }
    }
    
    if(top==0){
        printf("Result: %d\n", stack[top]);
    } else {
        printf("Invalid Expression!\n");
    }

}