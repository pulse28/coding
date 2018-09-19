#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int dp[k+1];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i=1;i<=n;i++)
		{
			for(int j=min(i, k);j>0;j--)
			{
				dp[j] += j*dp[j-1]; 
			}
		}

		cout << dp[k] << endl;
	}
}