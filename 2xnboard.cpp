#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int prev = 1, cur = 1, res=1;
		for(int i=1;i<n;i++)
		{
			res = prev + cur;
			prev = cur;
			cur = res;
		}

		cout << res << endl;
	}
}