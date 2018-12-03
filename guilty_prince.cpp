#include<bits/stdc++.h>
using namespace std;
char ch[21][21];
int res,w,h;
void dfs(int i,int j)
{
    if(i<0 || i>=h || j<0 || j>=w)
    {
        return;
    }
    else if(ch[i][j]=='.')
    {
        ch[i][j]=35,res++;
    }
    else if(ch[i][j]==35)
    {
        return;
    }
    dfs(i,j+1);
    dfs(i+1,j);
    dfs(i,j-1);
    dfs(i-1,j);
}
int main()
{
    int T,cnt=0;
    cin>>T;
    while(T--)
    {
        cin>>w>>h;
        memset(ch,0,sizeof(ch));
        for(int i=0; i<h; i++)
        {
            cin>>ch[i];
        }
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                res=0;

                if(ch[i][j]=='@')
                {
                    dfs(i,j);
                    break;
                }
            }
            if(res)
            {
                break;
            }
        }
        cout<<"Case "<<++cnt<<": "<<res+1<<endl;
    }
    return 0;
}
