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
4. 



    