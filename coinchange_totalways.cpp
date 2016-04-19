
#define f(a,i,n) for(int i=a;i<n;i++)
#include<bits/stdc++.h>
using namespace std;
int sol[100][10000];
int ddd(int *a,int n,int w)
{
    if(w==0)return 1;
    if(w<0 || n==0)return 0;
    if(sol[n][w]!=-1)return sol[n][w];
    return sol[n][w]=ddd(a,n,w-a[n])+ddd(a,n-1,w);

}

int main()
{
    int n,w;
    cin>>n;
    int a[n+1];
    f(1,i,n+1)
    {
        cin>>a[i];

    }
    cin>>w;
    memset (sol,-1,sizeof sol);
    cout<<ddd(a,n,w);


}
