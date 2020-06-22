#include <iostream>
#include<bits/stdc++.h>
using namespace std;




bool isIsomorphic(string str1, string str2)
{
	// Two strings cannot be isomorphic if they have different lengths.
	if (str1.length() != str2.length())
		return false;

	// Use C++'s built in map to store mappings of str1 chars to str2 chars.
	map<char, char> map;

	// Use a set to keep track of already mapped characters.
	set<char> set;

	for (int i = 0; i < str1.length(); i++)
	{
		char c1 = str1[i], c2 = str2[i];

		// If c1 has been encountered before:
		if (map.find(c1) != map.end())
		{
			// Return false if first occurrence of c1 is mapped to
			// a different character.
			if (map[c1] != c2)
				return false;
		}

		// If c1 is encountered for the first time, it has not been mapped yet:
		else
		{
			// Return false if c2 is already mapped to some other char in str1
			if (set.find(c2) != set.end())
				return false;

			// All checks passed. So insert in the map, and the set.
			map[c1] = c2;
			set.insert(c2);
		}
	}
	return true;
}


int main()
{
    int t,p,n;
    char help[100];
    cin>>t;
    while(t--)
    {
        cin>>p;
        char party[p][100];
        for(int i = 0; i < p; i++)
            cin>>party[i];

        for(int i=1; i<p; i++)
	    {
		for(int j=1; j<p; j++)
		{
			if(strcmp(party[j-1], party[j])>0)
			{
				strcpy(help, party[j-1]);
				strcpy(party[j-1], party[j]);
				strcpy(party[j], help);
			}
		}
	    }
        cin>>n;


        char vote[n][100];
        for(int i = 0; i < n; i++)
            cin>>vote[i];

        //cout<<party[1];
        //cout<<endl<<vote[0];
        int table[n + 1][p];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < p; j++)
            {
                table[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < p; j++)
            {
                if (isIsomorphic(vote[i], party[j]))
                    table[i][j] = 1;
            }
        }
        for(int j = 0; j < p; j++)
        {
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                sum = sum + table[i][j];
            }
            table[n][j] = sum;
        }
        int max = INT_MIN;
        for(int i = 0; i < p; i++)
        {
            if(table[n][i] > max)
                max = table[n][i];
        }
        if(max != 0){
        for(int i = 0; i < p; i++)
        {
            if(table[n][i] == max)
            {
                cout<<party[i]<<" ";
            }
        }
        }
        else
            cout<<"stalemate";
        cout<<endl;

    }
    return 0;
}
