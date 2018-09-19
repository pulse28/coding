#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long int res=0;
	int s[n+1][n+1];
	memset(s, 0, sizeof(s));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(j==1) 
				s[i][j] = 1;
			else
				s[i][j] = j*s[i-1][j] + s[i-1][j-1];
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		res += s[n][i];
	}

	cout << res << endl;

	return 0;
}