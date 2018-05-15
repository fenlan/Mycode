#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
int queen[9];

void init()
{
    memset(queen, 0, 9*sizeof(int));
}

void print()
{
    for (int i = 1; i < 9; i++)
        cout << queen[i] << " ";
    cout << endl;
}

bool canPlaceQueen(int k)
{
    for (int i = 1; i < k; i++)
        if (queen[i] == queen[k] || abs(k-1) == abs(queen[k]-queen[i]))
            return false;
    return true;
}

void eightQueen_1()
{
    int k = 1;
    while (k >= 1) {
        while (queen[k] <= 7) {
            queen[k] += 1;
            if (k == 8 && canPlaceQueen(k))
                print();
            else if (canPlaceQueen(k))
                k++;
        }
        queen[k] = 0;
        k--;
    }
}

void eightQueen_2(int k)
{
    for (int i = 1; i < 9; i++) {
        queen[k] = 1;
        if (k == 8 && canPlaceQueen(k)) {
            print();
            return ;
        }
        else if (canPlaceQueen(k)) {
            eightQueen_2(k+1);
        }
    }
}

int main()
{
    init();
    eightQueen_1();
    // eightQueen_2();

    return 0;
}