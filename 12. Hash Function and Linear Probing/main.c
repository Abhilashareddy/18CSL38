/*
12. Given a File of N employee records with a set K of Keys(4-digit) which uniquely determine the records in file F. Assume that file F is maintained in memory by a Hash Table(HT) of m memory locations with L as the set of memory addresses (2-digit) of locations in HT. Let the keys in K and addresses in L are Integers. Design and develop a Program in C that uses Hash function H: K→L as H(K)=K mod m (remainder method), and implement hashing technique to map a given key K to the address space L. Resolve the collision (if any) using linear
 */

#include <stdio.h>
#include <stdlib.h>

// declare an array for hash table
#define MAX 10

// Create the structure for employee data
struct employee {
	int id;
       char name[15];	
};

// Alias name for struct
typedef struct employee EMP;

EMP emp[MAX]; // array of employee data
int HT[MAX]; // hash table array

// Declare a variable to store size of array HT
int ht_size = 0;

// Function for Linear Probing
void LinearProbing(int key) {
	int flag = 0, i = key % MAX; // if key is larger than MAX reset to 0 (circular index -> refer program 6)
	
	if (HT[i] == -1) {
		flag=1;
		ht_size++;
	} else {
		printf("Collision detected\n");
		// increment key
		i++;
		// until i != key and flag == 0 and ht_size < MAX
		while(i != key && flag == 0 && ht_size < MAX){
			if(HT[i] == -1) {
				flag = 1;
				ht_size++;
				break;
			}
			i = (++i) % MAX; // increment circularly (refer circular queue 6th program)
		}

	} // endif

	// after we finish above loop we'll check
	// whether flag is 0
	// that means the hash table (HT) will be full
	// as we were unable to find empty space
	if (flag == 0)
		printf("Hash Table is Full\n");
	// otherwise we'll ask user to enter details of employee
	// then store it in HT
	else {
		printf("Enter emp id: ");
		scanf("%d", &emp[i].id);
		printf("Enter emp name: ");
		scanf("%s",emp[i].name);
		// store key in HT
		HT[i] = i;
		printf("collision avoided\n");
	}

}

// Function to display entire employee data along with HT
void Display() {
	int i;
	char ch;
	printf("Would you like to hide empty values? (y/N) : ");
	scanf(" %c",&ch);
	printf("HT Key \tEmp ID \tEMP Name\n");
	// traverse HT (hash table)
	for(i=0;i<MAX;i++){
		// skip value if choice was to hide empty values
		if(ch == 'y' && HT[i] == -1)
			continue;
		else
			printf("%d \t %d \t%s \n",i, emp[i].id, emp[i].name);
	}
}

// Driver program
void main(){
	int key,i;
	char ch;
	// initialize all values in array HT (hash table) to -1
	for(i=0;i<MAX;i++) HT[i]=-1;
	// loop until user wants
	do {
		printf("Enter key: ");
		scanf("%d", &key);
		LinearProbing(key);
		printf("Do you wish to continue (y/N): ");
		scanf(" %c",&ch);
	} while(ch=='y');
	Display();
}
