#include<bits/stdc++.h>
using namespace std;
/*
void MySorting(int a[],int b[],int n)
{
    for(int i = 1; i < n; i++)
    {
        int  j = i;
        while(j > 0 && a[j-1] > a[j])
        {
            swap(a[j-1],a[j]);
            swap(b[j-1],b[j]);
            j--;
        }
    }
}
*/
int Knapsack01(int wt[],int p[],int n,int w)
{
    //sorting the weights and correspondence to profit ,...no  need bcz amounts are already sorted
    //MySorting(wt,p,n);

    //table declaration
    int Table[n+1][w+1];

    for(int i = 0; i < w + 1; i++)//choose 0 weight,you can't make any amount(Row)
        Table[0][i] = INT_MAX;
    for(int i =0; i < n+1; i++)//first coulmn initialize with 0,making 0 amount,no need to pick coin
        Table[i][0] = 0;
    for(int i = 1 ; i < n + 1; i++)
    {
        for(int j = 1; j < w + 1; j++)
        {
            if(wt[i-1] > j)//if coin value > amount then  select above cell value
            {
                Table[i][j] = Table[i-1][j];
            }
            else
            {
                Table[i][j] = min(Table[i-1][j] , p[i-1] + Table[i][j - wt[i - 1]] ); //in knapsack i - 1 ,if we choose i than choose i-1 but here we can choose more
            }
        }
    }
    return Table[n][w];
}



int main(){
    int t,w,n;
    cin>>t;
    while(t--)
    {
        cin>>w;
        cin>>n;
        int energy[n];
        int amount[n];
        for(int i = 0; i < n; i++)
        {
            cin>>energy[i];
            amount[i] = pow(2,i);
        }
        int val = Knapsack01(amount,energy,n,w);
        cout<<val<<endl;
    }
    return 0;
}




