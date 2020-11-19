///Recursive + Memorization = DP
#include <bits/stdc++.h>
using namespace std;
int t[100][100];
int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{

    // Base Case
    if (n == 0 || W == 0)
        return 0;

    if(t[n][W]!=-1)   // memorization base
        return t[n][W];


    if (wt[n - 1] > W)
        return t[n][W]=knapSack(W, wt, val, n - 1);
    else
        return t[n][W]= max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}

int main()
{
    memset(t,-1,sizeof(t));
    int val[] = {1,4,3,10 };
    int wt[] = {10, 2, 5,10 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}
