#include<bits/stdc++.h>
using namespace std;
int vis[200000+10],visited[200000+10];
int n,a,b;
vector<int>G[200000+10];
void dfs(int s, int now)
{
    for(int i=0; i<G[s].size(); i++)
    {
        if(G[s][i]!=s)
        if(visited[G[s][i]]==0)
        {
            if(now==1)
            {
                b++;
                visited[G[s][i]]=1;
                dfs(G[s][i],0);
            }
            else
            {
                a++;
                visited[G[s][i]]=1;
                dfs(G[s][i],1);
            }
        }
    }
}
int main()
{
    int t,cnt=0;
    scanf("%d",&t);
    while(t--)
    {
        int u,v;
        int m=0;
        memset(vis,0,sizeof(vis));
        memset(visited,0,sizeof(visited));
        cin>>n;
        for(int i=0; i<200000; i++)
        G[i].clear();
        for(int i=0; i<n; i++)
        {
            cin>>u>>v;
            if(u>v)
                swap(u,v);
            G[u].push_back(v);
            G[v].push_back(u);
            vis[u]=vis[v]=1;
            m=max(m,u);
            m=max(m,v);
        }
        int sum=0;
        for(int i=1; i<=m; i++)
        {
            a=b=0;
            if(vis[i]&&!visited[i])
            {
                a++;
                visited[i]=1;
                dfs(i,1);
                sum+=max(a,b);
            }
        }
        printf("Case %d: %d\n",++cnt,sum);
    }
    return 0;
}
