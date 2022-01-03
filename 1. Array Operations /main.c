/* 
    1. Design, Develop and Implement a menu driven Program in C for the following Array operations.
        a. Creating an Array of N Integer Elements.
        b. Display of Array Elements with Suitable Headings.
        c. Inserting an Element (ELEM) at a given valid Position (POS)
        d. Deleting an Element at a given valid Position(POS)
        e. Exit.
    Support the program with functions for each of the above operations.

*/

#include <stdio.h>
#include <stdlib.h>

int arr[20]; // Initialize array of integers
int arr_len = 0; // Length of array

// Create an array
void Create()
{
    int i; //Loop var

    for (i = 0; i < arr_len; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    return;
}

// Display elemets
void Display()
{
    int i;

    // Check for empty array
    if (arr_len < 1)
    {
        printf("Empty Array!\n");
    }
    else
    { // if not empty
        printf("Array elements: \n");
        printf("[ ");

        for (i = 0; i < arr_len; i++)
        {
            printf("%d, ", arr[i]);
        }

        printf("]\n");
    }

    return;
}

// Insert an element at position
void Insert(int pos, int elem)
{
    int i;

    // Check if position is valid
    if (pos > arr_len)
    {
        printf("Invalid position\n");
        return; //Exit
    }

    arr_len++; // Array Size increased by 1

    // Reverse Traversal
    // keep shifting array elements to the right till position
    // This keeps existing elements
    for (i = arr_len; i >= pos; i--)
    {
        arr[i + 1] = arr[i]; // shift right
    }

    arr[pos] = elem; // Insert element at position

    return;
}

// Delete an element at position
int Delete()
{
    int i;
    int elem; // Removed element
    int pos;  // Position of element

    // Check for empty array
    if (arr_len < 1)
    {
        printf("Empty Array!\n");
        return;
    }
    else
    { // if not empty
        printf("Enter position to be deleted: ");
        scanf("%d", &pos);

        // Check if position is valid
        if (pos > arr_len)
        {
            printf("Invalid position\n");
            return; //Exit
        }

        elem = arr[pos]; // Set removed element

        for (i = pos; i < arr_len; i++)
        {
            arr[i] = arr[i + 1];
        }

        arr_len--; // Array Size decreased by 1
    }
    return elem;
}

// Driver Program
int main()
{
    int ch;        // Choice variable for menu
    int pos, item; // pos -> Position

    while (1)
    {
        printf("Array Operations:\n");
        printf("\t1. Create\n");
        printf("\t2. Display\n");
        printf("\t3. Insert\n");
        printf("\t4. Delete\n");
        printf("\t5. Exit\n");

        printf("\nEnter Choice: ");
        scanf("%d", &ch);

        // Menu operations
        switch (ch)
        {
        case 1:
            printf("Enter no. of elements: ");
            scanf("%d", &arr_len);
            Create();
            break;
        case 2:
            Display();
            break;
        case 3:
            printf("Enter the position and elements to be inserted: ");
            scanf("%d %d", &pos, &item);
            Insert(pos, item);
            break;
        case 4:
            Delete(pos);
            break;
        case 5:
            return 0; // Exit function by returning 0
        default:
            printf("Invalid Choice!\n");
        }
    }
    
    return 0;
}