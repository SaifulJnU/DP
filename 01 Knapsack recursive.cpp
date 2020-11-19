#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{

    // Base Case
    if (n == 0 || W == 0) //n=0 mane kono item nai ar W=0 mane knapsack tite kono kicu neyar moto jaiga nai.
        return 0;

   //diagram condition
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);  //exclude the item
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1)); //optimal one= max(include the item, exclude the item)
               // jokhon item ta include kore kaj korbo tokhon val[n-1] add hobe ar W-wt[n-1](mane knapsack er capacity komaite hobe) add hobe.
}

int main()
{
    int val[] = {1,4,3,10 };
    int wt[] = {10, 2, 5,10 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}
