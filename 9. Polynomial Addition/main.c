#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	int coef, x, y, z;
	struct node *link;
};

typedef struct node *NODE;

NODE getnode()
{
	NODE temp = (NODE)malloc(sizeof(struct node));
	temp->coef = -1;
	temp->x = -1;
	temp->y = -1;
	temp->z = -1;
	temp->link = NULL;
	return temp;
}

// function to initialize poly
NODE initpoly()
{
	char ch;
	NODE temp, head, cur;
	head = getnode();
	head->link = head; // make circular
	do
	{
		temp = getnode();
		printf("Enter Coef, x, y, z: ");
		scanf("%d%d%d%d", &temp->coef, &temp->x, &temp->y, &temp->z);
		cur = head;
		// find last node
		while (cur->link != head)
			cur = cur->link;
		cur->link = temp;  // set circular link from last node
		temp->link = head; // set circular link to head
		printf("Have you got more?:(y/N): ");
		scanf(" %c", &ch);
	} while (ch == 'y');
	return head;
}

// compare two nodes
int compare(NODE a, NODE b)
{
	if (a->x > b->x)
		return 1;
	if (a->x < b->x)
		return -1;
	if (a->y > b->y)
		return 1;
	if (a->y < b->y)
		return -1;
	if (a->z > b->z)
		return 1;
	if (a->z < b->z)
		return -1;
	return 0;
}

// attach values to ans node
void attach(int coef, int x, int y, int z, NODE head)
{
	NODE temp, cur;
	temp = getnode();
	temp->coef = coef;
	temp->x = x;
	temp->y = y;
	temp->z = z;
	cur = head;
	// find last node
	while (cur->link != head)
		cur = cur->link;
	cur->link = temp; // set circular link from last node
	temp->link = head;
}

// add two polys
NODE add(NODE a, NODE b)
{
	NODE tempa = a, ans;
	int sum, done = 0;
	a = a->link;
	b = b->link;
	ans = getnode();
	ans->link = ans; // set circular link
	do
	{
		switch (compare(a, b))
		{
		case -1:
			attach(b->coef, b->x, b->y, b->z, ans);
			// goto next node
			b = b->link;
			break;
		case 0:
			if (tempa == a)
				done = 1;
			else
			{
				sum = a->coef + b->coef;
				if (sum)
					attach(sum, a->x, a->y, a->z, ans);
				// goto next nodes
				a = a->link;
				b = b->link;
			}
			break;
		case 1:
			attach(a->coef, a->x, a->y, a->z, ans);

			// goto next node
			a = a->link;
			break;
		}
	} while (!done);
	return ans;
}

void print(NODE node)
{
	if (node == NULL)
		printf("Poly is empty\n");
	else
	{
		NODE temp = node->link;
		while (temp->link != node)
		{
			printf("%d*x^%d*y^%d*z^%d+ ", temp->coef, temp->x, temp->y, temp->z);
			temp = temp->link;
		}
		printf("%d*x^%d*y^%d*z^%d\n", temp->coef, temp->x, temp->y, temp->z);
	}
}

// evaluate exp
void eval(NODE node)
{
	int res = 0;
	int vx, vy, vz, ex, ey, ez, coef;
	NODE temp;
	printf("Enter value of x,y,z: ");
	scanf("%d%d%d", &vx, &vy, &vz);
	temp = node->link;
	while (temp != node)
	{
		ex = temp->x;
		ey = temp->y;
		ez = temp->z;
		coef = temp->coef;
		res += coef * pow(vx, ex) * pow(vy, ey) * pow(vz, ez);
		temp = temp->link;
	}
	printf("Result: %d\n", res);
}

void main()
{
	int i, ch;
	NODE a = NULL, b = NULL, c = NULL;
	printf("\n1. Init Poly1\n2. Init Poly 2\n3. View Poly 1\n4. View Poly 2\n5. Add\n6. Evaluate\n7. Exit\n");
	while (1)
	{
		printf("Choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter Elements of first poly:\n");
			a = initpoly();
			break;
		case 2:
			printf("Enter Elements of sec poly:\n");
			b = initpoly();
			break;
		case 3:
			print(a);
			break;
		case 4:
			print(b);
			break;
		case 5:
			if (a == NULL || b == NULL)
				printf("Unable to perform addition\n");
			else
			{
				c = add(a, b);
				printf("Sum:\n");
				print(c);
			}
			break;
		case 6:
			c = initpoly();
			eval(c);
			break;
		case 7:
			exit(0);
		}
	}
}
