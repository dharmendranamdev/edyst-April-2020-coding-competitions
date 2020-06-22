#include<bits/stdc++.h>
using namespace std;
void printArray(int a[],int n)
{
    for(int i = 0; i < n; i++)
        {
            cout<<a[i]<<" ";
        }
    cout<<endl;
}
int main(){
    int T,n,p;
    cin>>T;
    while(T--){
        cin>>n;
        cin>>p;
        int a[n];
        for(int i = 0; i < n; i++){
            a[i] = 0;
        }
        printArray(a,n);
        for(int i = 0; p != 0 && i < n; i++){
            for(int j = i; p != 0 && j < n; j++){
                a[j] = a[j] + 1;
                p--;
            }
            printArray(a,n);
        }
        if(p != 0){
            a[0] = a[0] + p;
        }
        printArray(a,n);

    }
    return 0;
}




