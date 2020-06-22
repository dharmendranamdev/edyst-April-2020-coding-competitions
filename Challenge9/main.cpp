#include <iostream>
#include<bits/stdc++.h>
//#define MAX 15
using namespace std;
int my =1;
//int MAX = 15;
string str;
int c = 0;
void goal(int x1, int y1, int x2,int y2,int MAX,int flag)
{
    if(x1 == x2 && y1 == y2)
    {
        c++;
        if(flag == 0)
        {
            c = 0;
            my = 0;
        }
        return;
    }
    flag = 1;
    if(str[0] == 'N' && y1+1 >= 0 && y1+1 <= MAX)
        goal(x1,y1+1,x2,y2,MAX,1);

    if(str[0] == 'S' && y1 - 1 >= 0 && y1 - 1 <= MAX)
        goal(x1,y1 - 1,x2,y2,MAX,1);

    if(str[1] == 'W' && x1 - 1 >= 0 && x1 - 1 <= MAX)
        goal(x1 - 1,y1,x2,y2,MAX,1);

    if(str[1] == 'E' && x1+1 >= 0 && x1+1 <= MAX)
        goal(x1 + 1,y1,x2,y2,MAX,1);

}

int main()
{
    int t,x1,x2,y1,y2;

    cin>>t;
    while(t--)
    {
        c = 0;
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>str;

        int MAX = ( max(x1,y1),max(x2,y2));
        //int table[MAX][MAX];

        goal(x1,y1,x2,y2,MAX,0);
        //int c = 0;
        if(c == 0 && my == 1)
            cout<<"impossible\n";
        else
            cout<<"Total Ways: "<<c<<endl;

    }
    return 0;
}
