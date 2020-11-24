
#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
    int i, j;
    int T[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                T[i][j] = 0;

            else if (wt[i - 1] <= j)
                T[i][j] = max(val[i - 1]+ T[i - 1][j- wt[i - 1]], T[i - 1][j]); ///ekhane knapsack function ke call na kore optimal
                                                                                ///data T namok table store kore rakhlam.
            else
                T[i][j] = T[i - 1][j];     
        }
    }

    return T[n][W];  /// table er last e optimal answer store kora ache tai last element return kore dilam.
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}
