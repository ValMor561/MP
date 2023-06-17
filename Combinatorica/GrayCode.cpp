#include "pch.h"
#include "GreyCode.h"
void GenerateGray(int N, int n,bool** g)
{
    if (n == 1) {
        g[0][0] = 0;
        g[1][0] = 1;
        return;
    }
    else
    {
        for (int i = 0; i < N / 2; i++) {
            g[i][n - 1] = 0;
            g[N - i - 1][n - 1] = 1;
        }
        GenerateGray(N / 2, n - 1, g);
        for (int i = N / 2; i < N; i++)
            for (int j = 0; j < n - 1; j++)
                g[i][j] = g[N - i - 1][j];
    }

}
bool** CodåGrey(int n) 
{
    int N = pow(2, n);
    bool **g = new bool* [N]; 
    for (int i = 0; i < N; i++)
        g[i] = new bool [n]; 
    GenerateGray(N, n, g);
    return g;
}
