//#include <iostream>
#include<bits/stdc++.h>
#include <string.h>
//#include <boost/algorithm/string.hpp>
using namespace std;

vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;

  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }

  return internal;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string input;
        //vector<string> result;

        int v[n+1];
        int r[n+1];
        map<int,set<int>> mymapping;
        for(int i = 0 ; i < n; i++)
        {
            set<string> extract;
            getline(cin >> ws, input);
            //cout<<endl<<input;
            cout<<"\nwords\n";
            vector<string> sep = split(input, ' ');
            for(int i = 0; i < sep.size(); ++i)
                cout <<i<<":"<< sep[i] << endl;
            cout<<endl<<endl;

            //set<string>::iterator itr = extract.begin();
            int a =  stoi(sep[0]);

            int b = stoi(sep[1]);

            set<int> DependList;
            v[a] = b;

            for(int k = 2; k < sep.size(); k++)
            {
                DependList.insert(stoi(sep[k]));
            }

            //mymapping.insert({a,DependList});//maping
            mymapping[a] = DependList;

            //cout<<a<<" "<<b<<endl;
            //set<int>::iterator itr1;
            /*for(itr1 = DependList.begin(); itr1 != DependList.end(); ++itr1)
            {
                cout<<*itr1<<endl;
            }*/


        }
        for (auto it : mymapping)
        cout << "[ " << it.first << ", "
             << it.second << "]\n"; // Sorted


    }
    return 0;
}
