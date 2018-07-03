#include<bits/stdc++.h>
#include <iostream>
using namespace std;
vector<pair<int,int> > v[10000];
int vis[10000]={0};
int dist[10000];

void algo()
{   pair<int,int> p;
    multiset<pair<int,int>> s;
    int val;
    int wt;
    vector <pair<int,int>> :: iterator it;
    s.insert({0,0});
    while(!s.empty())
    {
        p=*(s.begin());
        s.erase(s.begin());
        val=p.second;
        wt=p.first;
        if(!vis[val])
        {
            vis[val]=1;
            for(it=v[val].begin();it!=v[val].end();it++)
            {
                if((dist[val]+it->first)<dist[it->second])
                {
                    dist[it->second]=dist[val]+it->first;
                    s.insert({dist[it->second],it->second});
                }
            }
        }
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int t;
	int a,b,w;
	int nodes,edges;
	cin>>nodes>>edges;
	pair<int,int> p;
	for(i=0;i<nodes;i++)
	{
	    dist[i]=100000;
	}
	dist[0]=0;
	for(int i=0;i<edges;i++)
	{
	    cin>>a>>b>>w;
	    p.first=w;
	    p.second=b;
	    v[a].push_back(p);
	    p.second=a;
	    v[b].push_back(p);
	}
	algo();
	for(int i=0;i<nodes;i++)
	{
	    cout<<dist[i]<<" ";
	}
	
	return 0;
}

