#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int dp[1001][1001];


// i think this should be suitable when ,the ncr value stays within limit


void computencr()
{
    int i;
    int j;
    for(i=0;i<=1000;i++)
    {
    dp[0][i]=0;
    dp[i][0]=1;
    }
    dp[1][0]=1;
    dp[1][1]=1;
    for(i=2;i<=1000;i++)
    {
        for(j=1;j<=i;j++)
        {
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%(1000000000+7);
        }
    }
    
    
    // for printing ncr ,not checked with a online judge
   /* for(i=0;i<=1000;i++)
    {
        for(j=0;j<=1000;j++)
        {
            cout<<dp[i][j]<<" ";
            if(dp[i][j]==0)
                break;
        }
        cout<<endl;
    }*/
}
int returnNcR(int n,int r)
{
    return dp[n][r];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int t,q;
	computencr();
	cout<<returnNcR(77,3);
	return 0;
}

