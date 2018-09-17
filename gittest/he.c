#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n;
    long long int sum=0;
    scanf("%d", &n);
    long long int lh[n][n];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%lld", &lh[i][j]);
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((lh[1][i] < lh[0][j]) || (lh[0][i] > lh[1][j]))
            {
                if(lh[1][i] > lh[1][j])
                {
                    sum = sum + lh[1][i];
                    //sum = sum%1000000007;
                    printf("%lld \n", sum);
                }
                else
                {
                    sum = sum + lh[1][j];
                    //sum = sum%1000000007;
                    printf("%lld \n", sum);
                }
                
            }
        }
    }
    sum = sum%1000000007;
    printf("%lld \n", sum);
}