#include <bits/stdc++.h>

using namespace std;

int main()
{

    int T,n,colCount = 0,rowCount=0;
    //cout<<"Enter T:";
    cin>>T;
    while(T--)
    {
        //cout<<"\nEnter n:";
        cin>>n>>n;
        int a[n][n];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cin>>a[i][j];
        }
        for(int i = 0; i < n; i++)
        {
            int flagRow = 0;
            for(int j = 1 ; j < n; j++)
            {
                int k = j;
                int x = a[i][j];
                if(flagRow == 1)
                    break;
                while(k > 0 && flagRow == 0)
                {
                    if(x == a[i][k-1])
                    {
                            rowCount++;
                            flagRow = 1;
                            break;
                    }
                    k--;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            int flagCol = 0;
            for(int j = 1 ; j < n; j++)
            {
                int k = j;
                int x = a[j][i];
                if(flagCol == 1)
                    break;
                while(k > 0 && flagCol == 0)
                {
                    if(x == a[k-1][i])
                    {
                            colCount++;
                            flagCol = 1;
                            break;
                    }
                    k--;
                }
            }
        }
        if(rowCount == 0 && colCount == 0)
        {
            cout<<"SAFE\n";
        }
        else
        {
            cout<<"DANGER "<<rowCount<<" "<<colCount<<endl;
        }
    }
    return 0;

}
