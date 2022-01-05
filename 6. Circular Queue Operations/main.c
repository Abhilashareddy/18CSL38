#include <stdio.h>

#define SIZE 5

char CQ[SIZE]; // Queue

// f -> front | r -> rear | c -> count
int f=0,r=0,c=0;

void enqueue(){
    // first we'll increment rear
    r = (r+1) % SIZE;
    if (f==r) { // if front == rear
        printf("Stack Overflow!\n");
        // now we'll revert back rear to its previous value
        // because we're not performing insert as stack is full
        if (r==0) 
            r = SIZE -1;
        else 
            r=r-1;
    } else {
        printf("Enter element: ");
        // when taking char input remember to leave a space before %c i.e. " %c" in scanf
        scanf(" %c",&CQ[r]);
        c++; // increment count
    }

}

char dequeue() {
    char item;
    if (f==r) {
        printf("Queue Undeflow!\n");
    } else {
        // increment front
        f = (f+1) % SIZE;
        item = CQ[f];
        printf("Removed %c\n", item);
        c--; // decrement count
        return item;
    }
} 

void display() {
    int i,j=0;
    if (f==r) {
        printf("Queue empty\n");
    } else {
        i = (f+1) % SIZE; // initialize i by computing front
        while(j++<c) { // until j is less than count i.e total no. of values in queue
            printf(" %c\t", CQ[i]);
            i = (i+1) % SIZE; // now increment i
        }
        printf("\n");
    }
}

void main() {
    int ch;
    while(1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\n CHoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return;
        }
    }
}
