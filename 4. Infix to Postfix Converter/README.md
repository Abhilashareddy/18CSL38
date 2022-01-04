# Algorithm

1. Initialize stack
2. Push '#'
3. Loop until infix ends
    1. if item is '('
        - push item to stack
    2. else if item is alphanumeric
        - insert to postfix string
    3. else if item is ')'
        - Loop until top of stack is '('
            - pop element from stack and insert to postfix string
        - perform pop now to remove '(' in stack
    4. else 
        - if precedence of top of stack >= precedence of item
            - pop stack and insert to postfix
        - now perform push for item
    5. end loop
4. until stack[top] = '#' // i.e. until stack empty
    1. if char in stack top is '(' then
        - output error "Invalid Parenthesis"
        - exit
    2. else if no. of operators is not equal to [ (no. of alphanumeric chars(operands) ) - 1 ]
        - output "Invalid Expression"
    3. else
        - pop and insert to postfix
5. set end character of postfix to null '\0'
6. Execute main function




    