# Explanation of Circular Queue

### A circular queue is the extended version of a regular queue where the last element is connected to the first element. Thus forming a circle-like structure.

<img alt="Circular increment in circular queue" height="278" src="https://cdn.programiz.com/sites/tutorial2program/files/circular-increment.png" title="Circular queue" width="274">

The circular queue solves the major limitation of the normal queue. In a normal queue, after a bit of insertion and deletion, there will be non-usable empty space.

<img alt="demonstrate how we cannot add element even after removing some element from the queue" height="201" src="https://cdn.programiz.com/sites/tutorial2program/files/why-circular-queue.png" title="Demerit of queue" width="337">

Here, indexes 0 and 1 can only be used after resetting the queue (deletion of all elements). This reduces the actual size of the queue.


# Circular Queue Operations
### The circular queue work as follows:

two pointers FRONT and REAR
FRONT track the first element of the queue
REAR track the last elements of the queue
initially, set value of FRONT and REAR to -1
1. __Enqueue Operation__
check if the queue is full
for the first element, set value of FRONT to 0
circularly increase the REAR index by 1 (i.e. if the rear reaches the end, next it would be at the start of the queue)
add the new element in the position pointed to by REAR
2. __Dequeue Operation__
check if the queue is empty
return the value pointed by FRONT
circularly increase the FRONT index by 1
for the last element, reset the values of FRONT and REAR to -1
However, the check for full queue has a new additional case:

__Case 1__: FRONT = 0 && REAR == SIZE - 1
__Case 2__: FRONT = REAR + 1
The second case happens when REAR starts from 0 due to circular increment and when its value is just 1 less than FRONT, the queue is full.

<img alt="enqueue and dequeue operation of the circular queue" height="1396" src="https://cdn.programiz.com/sites/tutorial2program/files/circular-queue-program.png" title="Working of circular queue">

## Applications of Circular Queue
- CPU scheduling
- Memory management
- Traffic Management

_Source and Copyright_: [Programiz.com](https://www.programiz.com/dsa/circular-queue)