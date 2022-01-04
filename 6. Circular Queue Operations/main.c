#include <stdio.h>

#define SIZE 5

char CQ[SIZE];

int f=0,r=0,c=0;

void enqueue(){
    r = (r+1) % SIZE;
    if (f==r) {
        printf("Stack Overflow!\n");
        if (r==0) 
            r = SIZE -1;
        else 
            r=r-1;
    } else {
        printf("Enter element: ");
        scanf(" %c",&CQ[r]);
        c++;
    }

}

char dequeue() {
    char item;
    if (f==r) {
        printf("Queue Undeflow!\n");
    } else {
        f = (f+1) % SIZE;
        item = CQ[f];
        printf("Removed %c\n", item);
        c--;
        return item;
    }
} 

void display() {
    int i,j=0;
    if (f==r) {
        printf("Queue empty\n");
    } else {
        i = (f+1) % SIZE;
        while(j++<c) {
            printf(" %c\t", CQ[i]);
            i = (i+1) % SIZE;
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
