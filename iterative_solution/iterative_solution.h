#ifndef ITERATIVE_SOLUTION_H_
#define ITERATIVE_SOLUTION_H_

#include "lib.h"

void movement(int disk, char fromRod, char toRod);
void move(stack <int>& s1, stack <int>& s2, char source, char destination);
void PrintStack(stack<int> s);
void printEdge(int n);
void print(int number_of_disks, stack <int> a, stack <int> b, stack <int> c);
void towerOfHanoi(int number_of_disks,stack <int> a, stack <int> b,stack <int> c);

#endif