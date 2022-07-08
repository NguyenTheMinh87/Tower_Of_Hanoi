# Tower_of_Hanoi

Recursive algorithm
- Firstly, we need to solve this in the easiest case just with 1 or 2 disks. We mark three towers with name, source, destination, and auxiliary (only to help moving the disks). If we have only one disk, just move from source to destination tower. In the case we have 2 disks, first we move the smaller disk to help tower, then we move the larger disk to destination tower. Finally, we move the smaller disk from aux to destination tower. So now, we can design an algorithm for Tower of Hanoi with more than two disks. We divide the stack of disks in two parts. The largest disk (nth disk) is in one part and all other (n-1) disks are in the second part.
-Our goal is to move disk n from source to destination and then put all other (n-1) disks onto it. We can imagine applying the same in a recursive way for all given sets of disks.
- Step 1: Move n-1 disks from source to aux
- Step 2: Move nth disk from source to destination
- Step 3: Move n-1 disks from aux to destination


Iterative algorithm
- We will be given three rods and a n number of disks piled on top of each other. Disks are arranged to end up in ascending order, the disk having the smallest diameter on the top.
- The iterative solution can be figured out analyzing the recursive solution. The idea behind this method is to choose which pair of rods to make a legal move between. The legal movement is a movement that must respect the rules of the puzzle i.e. no larger disk should be placed on a smaller disk and we must move only the top disk at a time. This approach is not as intuitive as the recursive method but it works nevertheless.
- We can devise the algorithm as follows:
	If  n is even then set the destination rod to the auxiliary rod and the auxiliary rod to the source rod.
	Compute the total number of moves needed to solve the puzzle, which is equal to 2^n-1. Let total number of moves be equal to m.
	Iterate in a loop from i=1 to i=m. In each iteration of this loop, we do something depending on what remainder we get when we divide i by three. 
a. If i % 3 == 0, make the legal move between rods auxiliary and destination. 
b. If i % 3 == 1, make the legal move between rods source and destination. 
c. If i % 3 == 2, make the legal move between rods source and auxiliary. 
