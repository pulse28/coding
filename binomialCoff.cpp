#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int min(int a, int b)
{
	return (a<b)?a:b;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k, temp=1;
		cin >> n >> k;
		int dp[k+1];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i=1;i<=n;i++)
		{
			for(int j=min(i, k);j>0;j--)
			{
				if(i == j)
					dp[j] = 1;
				else
				{
					//temp = dp[j];
					dp[j] += dp[j-1];
				}
			}
		}
		//for(int i=0;i<=k;i++) cout << dp[i] << endl;
		cout << dp[k] << endl;
	}
	return 0;
}