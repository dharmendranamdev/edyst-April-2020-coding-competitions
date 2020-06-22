#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    string str;
    cin>>T;
    while(T--)
    {
        cin>>str;
        string str1 = str.substr(0,2);
        string str2 = str.substr(3,2);

        int a = stoi(str1);
        int n = stoi(str2);

        cout<<a;
        cout<<endl<<n<<endl;
        int sum = 0;
        for(int i = 0; i <= n; i++)
        {
            sum = sum + a;
            a = 2 * a - 1;
        }
        cout<<sum;

        //check digit
        int sum1 = sum;
        int nod = 0;
        while (sum1 != 0)
        {
            sum1 = sum1 / 10;
            ++nod;
        }

        cout<<"\n\n"<<nod;

        for(int i = nod; i >= 1; i--)
        {
            int x = pow(10,i);
            x = sum % x;
            int y = pow(10,i-1);
            x = x / y;
            switch(x)
            {
                case 0:
                    cout<<"A";
                    break;
                case 1:
                    cout<<"B";
                    break;
                case 2:
                    cout<<"C";
                    break;
                case 3:
                    cout<<"D";
                    break;
                case 4:
                    cout<<"E";
                    break;
                case 5:
                    cout<<"F";
                    break;
                case 6:
                    cout<<"G";
                    break;
                case 7:
                    cout<<"H";
                    break;
                case 8:
                    cout<<"I";
                    break;
                case 9:
                    cout<<"J";
                    break;
            }
        }
        cout<<endl;

    }
    return 0;
}
