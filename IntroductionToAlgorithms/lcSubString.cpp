#include <iostream>
#include <string.h>
#include <stdlib.h>
 
using namespace std;
 
void printLCSubStr(char* X, char* Y, int m, int n)
{
    int LCSuff[m + 1][n + 1];
    int len = 0;
    int row, col;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                if (len < LCSuff[i][j]) {
                    len = LCSuff[i][j];
                    row = i;
                    col = j;
                }
            } else
                LCSuff[i][j] = 0;
        }
    }
 
    if (len == 0) {
        cout << "No Common Substring";
        return;
    }
 
    char* resultStr = (char*)malloc((len + 1) * sizeof(char));
    resultStr[len] = ' ';

    while (LCSuff[row][col] != 0) {
        resultStr[--len] = X[row - 1];
        row--;
        col--;
    }
 
    cout << resultStr;
}
 
int main()
{
    char X[] = "xzyzzyx";
    char Y[] = "zxyyzxz";
 
    int m = strlen(X);
    int n = strlen(Y);
 
    printLCSubStr(X, Y, m, n);
    return 0;
}
