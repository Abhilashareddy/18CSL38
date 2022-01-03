/*
    Design, Develop and Implement a Program in C for converting 
    an Infix Expression to Postix Expression. 
    Program should support for both parenthesized and free parenthesized expression 
    with the operators: +,-./, % (Remainder), ^(Power) and alphanumeric operands.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MX 20 // Constant Stack Size

char stack[MX];

int top=-1;
// int cp=0,co=0;

// Check stack underflow
int isEmpty() {
    if (top == -1) 
        return 1;
    else 
        return 0;
}

// Check stack overflow
int isFull() {
    if (top == MX-1)
        return 1;
    else 
        return 0;
}

// Stack Push
void push(char item){
    // Check for overflow!
    if (isFull()) 
        printf("Error: Stack Overflow!\n");
    else
        stack[++top] = item;
}

// Stack Pop
char pop() {
    if (isEmpty())
        printf("Stack Underflow!\n");
    else
        return stack[top--];
}

// Precedence of opeartors
int precedence(char op) {
    switch (op)
    {
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/':
        case '%': return 3;
        case '^': return 4;
        default:
            printf("Invalid Operator\n");
            exit(0);
            break;
    }
}

// // Check char is an operator
// int isOperator(char item){
//     // if given character matches below switch cases
//     // function will return 1 otherwise 0
//     switch (item)
//     {
//         case '+':
//         case '-':
//         case '*':
//         case '/':
//         case '%':
//         case '^': return 1;
//         default:  return 0;
//     }
// }

// Compute arithmetic operation
int compute(char symbol, int op1, int op2) {
    switch (symbol)
    {
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1/op2;
        case '%': return op1%op2;
        case '^': return pow(op1,op2);
        default:  return 0;
    }
}

// Function to convert infix to postfix 
// returns postfix string on success
int Convert(char *infix, char *postfix) {
    char ch; // holds char from infix
    // index variables
    int i=0; // infix
    int k=0; // postfix

    // for error handling purposes top element of stack will be #
    push('#');

    while((ch != infix[i++]) != '\0') {
        if( ch == '(' ) push(ch); // Push to stack
        else if ( isalnum(ch) ) postfix[k++] = ch; // insert char to postfix string
        else if ( ch == ')' ) {
            // insert char in stack till '(' is found
            while(stack[top] != '(')
                postfix[k++] = pop(); 
            pop(); // Now remove '(' from stack
        } else {
            // if char in stack is of higher precedence than ch
            // insert to postfix
            while(precedence(stack[top]) >= precedence(ch) )
                postfix[k++] = pop();
            push(ch); // Now push ch to stack
        }
    }
    // Until stack is empty
    while(stack[top]!='#') {
        // check if there's any remaining '(' in stack
        if (stack[top] == '(') {
            printf("Error: Invalid Parenthesis\n");
            exit(0);
        } else {
            // Now insert all operators remaining in stack to postfix
            postfix[k++] = pop();
        }
    }
    postfix[k] = '\0'; // set last char of postfix to NULL
    return 1;
}

// Driver program
void main() {
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    Convert(infix, postfix);
    printf("Result: %s\n", postfix);
}

