#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

struct node
{
	char usn[10], name[15], branch[10], sem[10], phno[10];
	struct node *link;
};

typedef struct node *NODE;

NODE head = NULL;

NODE getNode()
{
	NODE node = (NODE)malloc(sizeof(struct node));
	node->link = NULL;
	return node;
}

void insert(char *ch)
{
	NODE temp = getNode();
	printf("Enter details: USN, Name, Branch, Sem, Ph No.: \n");
	scanf("%s%s%s%s%s", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
	if (head == NULL)
	{
		head = temp;
	}
	else if (ch == "front")
	{
		temp->link = head;
		head = temp;
	}
	else if (ch == "rear")
	{
		NODE cur = head;
		while (cur->link != NULL)
		{
			cur = cur->link;
		}
		cur->link = temp;
	}
}

void printSLL()
{
	NODE temp = head;
	if (temp == NULL)
		printf("EMpty!");
	else
		printf("USN\tName\tBranch\tSem\tPh No.\n");
	while (temp != NULL)
	{
		printf("%s\t%s\t%s\t%s\t%s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
		temp = temp->link;
	}
}

void delete (char *ch)
{
	NODE temp = head;
	if (head == NULL)
		printf("Delete not possible\n");
	else if (ch == "front")
	{
		head = head->link;
	}
	else if (ch == "rear")
	{
		if (head->link == NULL)
			head = NULL;
		else
		{

			NODE last;
			while (temp->link != NULL)
			{
				last = temp;
				temp = temp->link;
			}
			last->link = NULL;
		}
	}
	free(temp);
}

void main()
{
	int ch, i;
	char *choices[] = {
		"Create SLL",
		"Insert Front",
		"Insert Rear",
		"Delete Front",
		"Delete Rear",
		"Stack Push",
		"Stack Pop",
		"Display",
		"Exit"};
	while (1)
	{
		// If u find ARRAY_SIZE to be confusing
		// here you can manually type length of above choices array
		// or you can also define all choices by typing manually inside a printf
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
			insert("front");
			break;
		case 7:
			delete ("front");
			break;
		case 8:
			printSLL();
			break;
		case 9:
			exit(1);
		}
		printf("\n");
	}
}
