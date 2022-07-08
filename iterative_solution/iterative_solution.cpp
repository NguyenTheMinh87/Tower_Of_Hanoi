#include "lib.h"

void movement(int disk, char fromRod, char toRod)
{
    cout << "move disk " << disk << " from '" << fromRod
        << "' to '" << toRod << "'" << endl;
}

void move(stack <int>& s1, stack <int>& s2, char source, char destination)
{
    if (s1.empty())                              //case1: first rod is empty
    {
        s1.push(s2.top());
        movement(s2.top(), destination, source);
        s2.pop();
    }
    else if (s2.empty())                         //case2: second rod is empty
    {
        s2.push(s1.top());
        movement(s1.top(), source, destination);
        s1.pop();
    }
    else if (s1.top() > s2.top())                //case3: top s1 > top s2
    {
        s1.push(s2.top());
        movement(s2.top(), destination, source);
        s2.pop();
    }
    else                                         //case4: top s1 < top s2
    {
        s2.push(s1.top());
        movement(s1.top(), source, destination);
        s1.pop();
    }
}

void PrintStack(stack<int> s)
{
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    PrintStack(s);
    cout << x << " ";
    s.push(x);
}

void printEdge(int n) {
    for (int i = 0; i < n; i++)
        cout << "---";
    cout << endl;
}

void print(int number_of_disks, stack <int> a, stack <int> b, stack <int> c)
{
    cout << "A: "; PrintStack(a); cout << endl;
    printEdge(number_of_disks);
    if (number_of_disks % 2 == 0)
    {
        cout << "B: "; PrintStack(c); cout << endl;
        printEdge(number_of_disks);
        cout << "C: "; PrintStack(b); cout << endl;
    }
    else
    {
        cout << "B: "; PrintStack(b); cout << endl;
        printEdge(number_of_disks);
        cout << "C: "; PrintStack(c); cout << endl;
    }
}

void towerOfHanoi(int number_of_disks,stack <int> a, stack <int> b,stack <int> c)
{
    char source = 'A', destination = 'C', auxiliary = 'B';

    //  if number of disks is even swap aux and dest
    if (number_of_disks % 2 == 0)
    {
        char temp = destination;
        destination = auxiliary;
        auxiliary = temp;
    }

    int number_of_moves = pow(2, number_of_disks) - 1;
    cout << endl << "You need to do " << number_of_moves << " step(s) to solve this puzzle" << endl;

    //implement number of disks for column a
    for (int i = number_of_disks; i >= 1; i--)
        a.push(i);

    for (int i = 1; i <= number_of_moves; i++)
    {
        cout << endl << "Step #" << left << setw(2) << i << ": ";
        if (i % 3 == 0) {
            move(b, c, auxiliary, destination);
            print(number_of_disks, a, b, c);
        }
        else if (i % 3 == 1) {
            move(a, c, source, destination);
            print(number_of_disks, a, b, c);
        }
        else if (i % 3 == 2) {
            move(a, b, source, auxiliary);
            print(number_of_disks, a, b, c);
        }
    }
    cout << endl << "Done!" << endl;
}
