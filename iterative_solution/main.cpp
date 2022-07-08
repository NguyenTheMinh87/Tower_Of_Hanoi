#include "lib.h"

int main()
{
    int number_of_disks;
    stack <int> a, b, c;

    cout << "\t---TOWER OF HANOI---" << endl << endl;
    cout << "Enter number of disks: ";
    do {
        cin >> number_of_disks;
        if (number_of_disks < 1)
            cout << "There must be at least one disk" << endl
            << "Enter number of disks again: ";
    } while (number_of_disks < 1);

    towerOfHanoi(number_of_disks, a, b, c);
    getchar();
}

