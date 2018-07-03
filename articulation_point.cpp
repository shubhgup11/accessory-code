//the articulation points are stored in the vector points...
//the process is you apply dfs... you maintain the timewhen you are visiting this node, and the lowest time the node can visit...
//now at every backtrack step you check that if the adjacent node can reach a node which is of lower time...(visited int the dfs earlier))..
//if this is the case then there is a back edge for the adgecent edge...which means if the vertex is removed the back edge would keep the graph connected...
//and in case of parent you just  need to have two independent childs...

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
#define inf INT_MAX

vector<int> points;
int times;
void init(int n,int vis_time[],int low_time[],int parent[],int vis[],int isart[])
{
    for(int i=0;i<n;i++)
    {
        vis[i]=0;
        low_time[i]=inf;
        vis_time[i]=inf;
        parent[i]=-1;
        isart[i]=0;
    }
}
void articulation_point(int i,int vis_time[],int low_time[],int vis[],int parent[],int isart[],vector<int> v[])
{
    //cout<<i<<endl;
    vis[i]=1;
    vis_time[i]=times;
    low_time[i]=times++;
    int j;
    int child=0;
    for(j=0;j<v[i].size();j++)
    {
        // cout<<v[i][j]<<" "<<endl;
        // cout<<vis[v[i][j]]<<"dhin\n";
        if(v[i][j]==parent[i])
            continue;
        if(vis[v[i][j]]==0)
        {
            //cout<<"yo";
            parent[v[i][j]]=i;
            child++;
            articulation_point(v[i][j],vis_time,low_time,vis,parent,isart,v);
            if(low_time[v[i][j]]>=vis_time[i])
            {
                isart[i]=1;
            }
            else
            {
                low_time[i]=min(low_time[i],low_time[v[i][j]]);
            }
        }
        else
        {
            low_time[i]=min(low_time[i],low_time[v[i][j]]);
        }
    }
    if((parent[i]==-1 && child>=2) || (parent[i]!=-1 && isart[i]==1))
        points.push_back(i);
}
int main() {
	fastIO;
	int n,i,j;
	int t,q,e;
	int a,b;
    cin>>n>>e;
    vector<int> v[n];
    for(i=0;i<e;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    // for(i=0;i<n;i++)
    // {
    //     for(j=0;j<v[i].size();j++)
    //     {
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int vis_time[n];
    int low_time[n];
    int parent[n];
    int vis[n];
    int isart[n];
    init(n,vis_time,low_time,parent,vis,isart);
    times=0;
    articulation_point(0,vis_time,low_time,vis,parent,isart,v);
    // for(i=0;i<n;i++)
    // {
    //     cout<<isart[i]<<" ";
    // }
    
    
    for(i=0;i<points.size();i++)
    {
        cout<<points[i]<<" ";
    }
	return 0;
}

