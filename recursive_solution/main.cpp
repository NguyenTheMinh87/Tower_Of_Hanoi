#include "lib.h"

extern int st[3][MAX];
extern int top[3];
extern int siz;
extern char ch[3];

int main()
{
    cout << "TOWER OF HANOI" << endl
        << endl;
    cout << "       >> Enter the number of disks you want to play: ";
    do
    {
        cin >> siz;
        if (siz < 1)
            cout << "There must be at least one disk" << endl
            << "Enter number of disks again: ";
    } while (siz < 1);

    for (int i = 0; i < siz; i++)
    {
        st[0][i] = siz - i;
    }
    top[0] = siz - 1;
    cout << endl
        << "Initial puzzle:" << endl;
    print();
    cout << "Solving...";
    move(siz, 0, 2, 1);
    cout << endl
        << "Done!" << endl;
    getchar();
}

