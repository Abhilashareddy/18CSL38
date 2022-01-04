# Algorithm

1. Push
    1. Check for stack overflow
    2. increment top and insert to array
2. Pop
    1. Check for stack underflow
    2. decrement top and return item
3. Display
    - Loop from top to bottom of stack array
        - Print items
4. Palindrome
    1. Loop from bottom to top when item is less than (top+1)/2 // bottom half of stack
        - if popped element is equal to item
            - flag is true
        - else 
            - flag is false
    2. return flag

