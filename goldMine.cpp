#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b, int c)
{
	if(a>=b && a>=c) return a;
	else if(b>=a && b>=c) return b;
	else return c;
}
/*
int isvalid(int x, int y, int n, int m)
{
	if(x>=0 && y>=0 && x<n && y<n)
	{
		return 1;
	}
	return 0;
}

int mine(int n, int m, int a[][], int x, int y)
{
	if(isvalid(x, y, n, m))
	{
		return (max(mine(n, m, a, x-1, y+1), mine(n, m, a, x, y+1), mine(n, m, a, x+1, y+1)));
	}
	else
	{

	}
}
*/
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		int a[n][m];

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin >> a[i][j];
			}
		}

		int dp[n][m];
		memset(dp, 0, sizeof(dp));

		for(int i=0;i<n;i++)
		{
			dp[i][0] = a[i][0];
		}

		for(int i=1;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(n != 1)
				{
					if(j==0)
						dp[j][i] = max(0, a[j][i]+dp[j][i-1], a[j][i]+dp[j+1][i-1]);
					else if(j==n-1)
						dp[j][i] = max(0, a[j][i]+dp[j][i-1], a[j][i]+dp[j-1][i-1]);
					else
						dp[j][i] = max(a[j][i]+dp[j-1][i-1], a[j][i]+dp[j][i-1], a[j][i]+dp[j+1][i-1]);
				}
				else
				{
					dp[j][i] = dp[j][i-1]+a[j][i];
				}
			}
		}
		int res=0;
		for(int i=0;i<n;i++)
		{
			if(dp[i][m-1] > res) res = dp[i][m-1];
		}
		/*
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		*/
		cout << res << endl;

	}

	return 0;
}