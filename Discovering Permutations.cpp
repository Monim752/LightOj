#include<bits/stdc++.h>
using namespace std;
char ch[30];
bool b[30];
int N,K;
void Divper(int n)
{
    if(K==0)return;
    else if(n==N)
    {
        K--;
        for(int i=0; i<N; i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
        return;
    }
    for(int i=0; i<N; i++)
    {
        if(b[i])continue;
        b[i]=1;
        ch[n]=i+'A';
        Divper(n+1);
        b[i]=0;
    }
}
int main()
{
    int T,cas=1;
    cin>>T;
    while(T--)
    {
        memset(b, 0, sizeof(b));
        cin>>N>>K;
        cout<<"Case "<<cas++<<":"<<endl;
        Divper(0);
    }
    return 0;
}
