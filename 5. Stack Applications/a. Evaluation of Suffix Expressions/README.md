# Evaluation of suffix expression

## Algorithm

- #### Start
---
Markup numbered list:
1. Initialize a stack with top = -1
2. Input postfix expression
---
3. Loop until postfix ends
    - set val = postfix[i]
    -  if val is digit:
        - push to stack
    - else if val is an operator
        - check for stack underflow
            - output "Invalid Expression" and exit
        - op2 = stack pop
        - repeat same above two steps for op1
        - call compute(val, op1, op2) and   push result to stack
    - else
        - output "Invalid Usage of operator"
        - exit
4. Check stack has only one element left and ouput result
    - If stack.top == 0
        - output final result
    - else
        - output "Invalid Expression"

---
- #### END