#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

struct node
{
    char ssn[10], name[15], dept[15], desig[15], sal[10], phno[10];
    struct node *left, *right;
};

typedef struct node *NODE;

NODE head = NULL;
int count = 0;

NODE getNode()
{
    NODE node = (NODE)malloc(sizeof(struct node));
    node->left = node->right = NULL;
    return node;
}

void insert(char *choice)
{
    NODE t = getNode();
    printf("Enter SSN, Name, Dept, Desig, Sal, Ph No: ");
    scanf("%s%s%s%s%s%s", t->ssn, t->name, t->dept, t->desig, t->sal, t->phno);
    if (head == NULL)
    {
        head = t;
    }
    else if (choice == "front")
    {
        head->left = t;
        t->right = head;
        head = t;
    }
    else if (choice == "rear")
    {
        if (head->right == NULL)
        {
            head->right = t;
        }
        else
        {
            NODE last = head;
            while (last->right != NULL)
            {
                last = last->right;
            }
            t->left = last;
            last->right = t;
        }
    }
    count++;
}

void delete (char *choice)
{
    NODE temp = head;
    if (head == NULL)
    {
        printf("Deletion Not possible\n");
    }
    else if (choice == "front")
    {
        if (temp->right == NULL)
        {
            head = NULL;
        }
        else
        {
            head = head->right;
            head->left = NULL;
        }
    }
    else if (choice == "rear")
    {

        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        if (temp->left != NULL)
            temp->left->right = NULL;
        else
            head = NULL;
    }
    free(temp);
    count--;
}

void displayDLL()
{
    NODE temp = head;
    if (head == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        printf("SSN\tName\tDept\tDesig\tSal\tPh No\n");
        while (temp != NULL)
        {
            printf("%s\t%s\t%s\t%s\t%s\t%s\n", temp->ssn, temp->name, temp->dept, temp->desig, temp->sal, temp->phno);
            temp = temp->right;
        }
    }
}

void main()
{
    int ch, i;
    while (1)
    {
        char *choices[] = {
            "Create DLL",
            "Insert Front",
            "Insert Rear",
            "Delete Front",
            "Delete Rear",
            "Queue Insert",
            "Queue Delete",
            "Display",
            "Exit"};

        for (i = 0; i < ARRAY_SIZE(choices); i++)
        {
            printf("%d. %s\n", i + 1, choices[i]);
        }
        printf("Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert("front");
            break;
        case 2:
            insert("front");
            break;
        case 3:
            insert("rear");
            break;
        case 4:
            delete ("front");
            break;
        case 5:
            delete ("rear");
            break;
        case 6:
            printf("Performing Queue Insert\n");
            insert("back");
            break;
        case 7:
            printf("Performing Queue Delete\n");
            delete ("front");
            break;
        case 8:
            displayDLL();
            break;
        case 9:
            exit(1);
        }
    }
}
