
#define f(a,i,n) for(int i=a;i<n;i++)
#include<bits/stdc++.h>
using namespace std;
int sol[10][1000];
int rrr(int *a, int *b,int n,int w)
{
    if(w==0)return 0;
    if(w<0 || n==0)return 1000;
    if(a[n]>w || b[n]<=0)
    {
        if(sol[n-1][w]==-1)sol[n-1][w]=rrr(a,b,n-1,w);
        return sol[n-1][w];
    }

    int c=rrr(a,b,n-1,w);
    b[n]--;

    int e=rrr(a,b,n,w-a[n])+1;
    b[n]++;
    return sol[n][w]=min(c,e);

}

int main()
{
    //ifstream fin;
    //fin.open("new.txt");
    int n,w;
    cin>>n;
    int a[n+1],b[n+1];
    f(1,i,n+1)cin>>a[i]>>b[i];
    cin>>w;

    memset(sol,-1,sizeof sol);
    cout<<rrr(a,b,n,w);


}
