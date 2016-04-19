#define f(a,i,n) for(int i=a;i<n;i++)
#include<bits/stdc++.h>
using namespace std;
int sol[100][1000];
int W,N;
int rrr(int *a, int *b,int n,int w)
{
    if(w==0)return 0;
    if(w<0 || n==0)return 1000;

    if(sol[n][w]!=-1)return sol[n][w];

    if(a[n]>w || b[n]<=0)
    {
        return sol[n-1][w]=rrr(a,b,n-1,w);

    }

    //sol[n-1][w]=
    int c=rrr(a,b,n-1,w);
    b[n]--;

    //sol[n][w-a[n]]=
    int e=rrr(a,b,n,w-a[n])+1;
    b[n]++;
    int d=min(c,e);
    if(d==e)cout<<a[n]<<ends;
    if(w==W && n==N)cout<<endl;
    return sol[n][w]=d;

}

int main()
{

    cin>>N;
    int a[N+1],b[N+1];
    f(1,i,N+1)cin>>a[i]>>b[i];
    cin>>W;

    memset(sol,-1,sizeof sol);
    cout<<rrr(a,b,N,W);


}
