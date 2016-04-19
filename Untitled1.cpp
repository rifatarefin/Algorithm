
#define f(a,i,n) for(int i=a;i<n;i++)
#include<bits/stdc++.h>
using namespace std;
int sol[10][200];
int rrr(int *a, int *b,int n,int w)
{
    if(w==0)return 0;
    if(w<0 || n==0)return 1000;
    if(a[n]>w || b[n]<=0)
    {
        if(sol[n-1][w]==-1)sol[n-1][w]=rrr(a,b,n-1,w);
        return sol[n-1][w];
    }

    if(sol[n-1][w]==-1)sol[n-1][w]=rrr(a,b,n-1,w);
    int c=sol[n-1][w];
    b[n]--;

    if(sol[n][w-a[n]]==-1)sol[n][w-a[n]]=rrr(a,b,n,w-a[n])+1;
    int e=sol[n][w-a[n]];
    b[n]++;
    return min(c,e);

}

int main()
{
    ifstream fin;
    fin.open("new.txt");
    int n,w;
    fin>>n;
    int a[n+1],b[n+1];
    f(1,i,n+1)fin>>a[i]>>b[i];
    fin>>w;

    memset(sol,-1,sizeof sol);
    cout<<rrr(a,b,n,w);


}
