#include "lib.h"

int st[3][MAX];
int top[3] = { -1, -1, -1 };
int siz;
char ch[3] = { 'A', 'B', 'C' };

void push(int index, int item)
{
    top[index]++;
    st[index][top[index]] = item;
}

int pop(int index)
{
    int item = st[index][top[index]];
    top[index]--;
    return item;
}

void print()
{
    for (int i = siz; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i <= top[j])
                cout << st[j][i] << "  ";
            else
                cout << "   ";
        }
        cout << endl;
    }
    cout << "A  B  C\n\n";
}

void move(int n, int source, int dest, int spare)
{

    if (n == 1)
    {
        int temp = pop(source);
        push(dest, temp);
        print();
        cout << "Move disk " << temp << " from '" << ch[source] 
 << "' to '" << ch[dest] << "'" << endl;
    }
    else
    {
        move(n - 1, source, spare, dest);
        move(1, source, dest, spare);
        move(n - 1, spare, dest, source);
    }
}

