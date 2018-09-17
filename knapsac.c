#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
	return (a>b)?a:b;
}

int main()
{
	int n;
	scanf("%d", &n);
	int val[n];
	int weight[n];

	for(int i=0;i<n;i++)
	{
		scanf("%d", &val[i]);
	}

	for(int i=0;i<n;i++)
	{
		scanf("%d", &weight[i]);
	}

	int w;
	scanf("%d", &w);
	int dp[n+1][w+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(j==0 || i==0)
			{
				dp[i][j] = 0;
			}
			else if(weight[i-1]>w)
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = max(val[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j]);
			}
		}
	}

	printf("%d\n", dp[n][w]);

	return 0;
}