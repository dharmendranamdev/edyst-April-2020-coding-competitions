#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int getLowValue(set<int>& lowValue, int& n)
{
	auto it = lowValue.lower_bound(n);

	// Since 'lower_bound' returns the first
	// iterator greater than 'n', thus we
	// have to decrement the pointer for
	// getting the minimum value
	--it;

	return (*it);
}

// Function to calculate maximum triplet sum
int maxTripletSum(int arr[], int n)
{
	// Initialize suffix-array
	int maxSuffArr[n + 1];

	// Set the last element
	maxSuffArr[n] = 0;

	// Calculate suffix-array containing maximum
	// value for index i, i+1, i+2, ... n-1 in
	// arr[i]
	for (int i = n - 1; i >= 0; --i)
		maxSuffArr[i] = max(maxSuffArr[i + 1], arr[i]);

	int ans = 0;

	// Initialize set container
	set<int> lowValue;

	// Insert minimum value for first comparison
	// in the set
	lowValue.insert(INT_MIN);

	for (int i = 0; i < n - 1; ++i) {
		if (maxSuffArr[i + 1] > arr[i]) {
			ans = max(ans, getLowValue(lowValue,
									arr[i])
							- arr[i] + maxSuffArr[i + 1]);

			// Insert arr[i] in set<> for further
			// processing
			lowValue.insert(arr[i]);
		}
	}
	return ans;
}


int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];

        for(int i = 0; i < n; i++)
            cin>>a[i];

        int max = maxTripletSum(a, n);
        cout<<max<<endl;
    }
    return 0;
}
