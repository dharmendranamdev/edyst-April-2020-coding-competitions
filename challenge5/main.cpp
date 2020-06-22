#include <iostream>

using namespace std;

int main()

 {

    int k,t;

    cin>>t;
   for(k=0;k<t;k++)
   {
      int n,i,j,limit,temp;
      cin>>n>>limit;
      int a[n];
      for(int i=0;i<n;i++)
          cin>>a[i];
      for(i=0;i<n;i++)
      {
          for(j=i+1;j<n;j++)
          {
              if(a[i]>a[j])
             {
                 temp=a[i];
                 a[i]=a[j];
                 a[j]=temp;
             }
          }
       }
      int count=0;
      int v[n]={0};
      int flag=0;
      for(int i=n-1;i>=0;i--)
      {

            if(v[i]!=1)
            {
              if(a[i]>limit)
              {
               flag=1;break;
              }
              v[i]=1;
              count++;
              int j=i-1;
              while(j>=0)
              {
                if(a[i]+a[j]<=limit)
                {
                  v[j]=1;
                }
                j--;
              }
            }
      }
      if(flag==1)
        printf("impossible\n");
      else
        printf("%d\n",count);
   }

 }
