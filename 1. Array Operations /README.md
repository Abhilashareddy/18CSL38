**1. Design, Develop and Implement a menu driven Program in C for the following Array operations.**

* Creating an Array of N Integer Elements. 

* Display of Array Elements with Suitable Headings.

* Inserting an Element (ELEM) at a given valid Position (POS) 

* Deleting an Element at a given valid Position(POS)

* Exit.

_Support the program with functions for each of the above operations._

# Algorithm

1. Function to create array
    - Take no. of values
    - Take input values for array
2. Display an array
    - output array elements
3. Insert an element at given position
    - check position is valid
    - increase array size by 1
    - move values right (right shift elements) from end to given position by +1
    - assign element to given position on array
4. Delete an element from given postion
    - check for valid position
    - left shift element from given position till end
    - return removed element // optional
