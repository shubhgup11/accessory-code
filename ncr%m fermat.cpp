#include<bits/stdc++.h>
#include <iostream>
using namespace std;

long long int fac[1000001];
const long long int m=1000000000+7;
long long int modexp(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    else if(b%2==0)
    {
        long long int c=modexp(a,b/2);
        return((c*c)%m);
    }
    else
    {
        return(((a%m)*modexp(a,b-1))%m);
    }
}

void fact()
{
    fac[0]=1;
    for(int i=1;i<=1000000;i++)
    {
        fac[i]=(fac[i-1]*i)%(1000000000+7);
    }
}
long long int returnNcr(int n,int r)
{
    long long int factn=fac[n];
    long long int factr=fac[r];
    long long int factnr=fac[n-r];
    long long int dem=(factr*factnr)%(m);
    return (factn*modexp(dem,m-2))%m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int t,q;
	fact();
	cout<<returnNcr(77,3);
    //cin>>t;
	return 0;
}

