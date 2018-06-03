//This code returns the value of ncr in long long int.....
//It uses the technique of expressing n! as a product of primes
//ncr of upto 1000000...where solution is storable....


#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int sieve[1000000+1];
vector <int> v;
vector <int > vn;
vector <int> vm;
void initsieve()
{
    int i;
    for(i=0;i<=1000000;i++)
    {
        sieve[i]=0;
    }
}
long long int modexp(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    else if(b%2==0)
    {
        long long int c=modexp(a,b/2);
        return((c*c));
    }
    else
    {
        return(((a)*modexp(a,b-1)));
    }
}
void getprime()
{
    int i,j;
    for(i=2;i*i<=1000000;i++)
    {
        if(!sieve[i])
        {
            sieve[i]=1;
            v.push_back(i);
            for(j=i*i;j<=1000000;j=j+i)
            {
                sieve[j]=1;
            }
        }
    }
    for(i=1000;i<=1000000;i++)
    {
        if(!sieve[i])
            v.push_back(i);
    }
    /*for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }*/
}
 long long int getNcr(int n,int m)
 {
     vn.clear();
     vm.clear();
    long long int ans=1;
    int i,j,ln,powi,ch;
    for(i=0;i<v.size();i++)
    {
        ch=n;
        powi=0;
        while(ch>0)
        {
            ch=ch/v[i];
            powi=powi+ch;
        }
        if(powi==0)
            break;
        vn.push_back(powi);
    }
    ln=i;
    /*for(i=0;i<ln;i++)
    {
        cout<<vn[i]<<" ";
    }cout<<endl;*/
    for(i=0;i<ln;i++)
    {
        ch=m;
        powi=0;
        while(ch>0)
        {
            ch=ch/v[i];
            powi=powi+ch;
        }
        vm.push_back(powi);
    }
    /*for(i=0;i<ln;i++)
    {
        cout<<vm[i]<<" ";
    }cout<<endl;*/
    for(i=0;i<ln;i++)
    {
        ch=n-m;
        powi=0;
        while(ch>0)
        {
            ch=ch/v[i];
            powi=powi+ch;
        }
        vm[i]+=powi;
    }
    /*for(i=0;i<ln;i++)
    {
        cout<<vm[i]<<" ";
    }cout<<endl;*/
    for(i=0;i<ln;i++)
    {
        vn[i]=vn[i]-vm[i];
    }
    for(i=0;i<ln;i++)
    {
        ans=ans*modexp(v[i],vn[i]);
    }
    return ans;
 }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	long long int ans=1;
	int t,q,m,ln,powi,ch;
	initsieve();
	getprime();
	cout<<getNcr(110,100)<<endl;
	return 0;
}

