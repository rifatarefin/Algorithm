#define f(a,i,n) for(int i=a;i<n;i++)
#include<bits/stdc++.h>
using namespace std;
int rrr(int *a, int *b,int n,int w)
{
    if(w==0)return 0;
    if(w<0)return 1000;
    if(n==0)return 1000;
    if(a[n]>w || b[n]<=0)return rrr(a,b,n-1,w);

    int c=rrr(a,b,n-1,w);
    b[n]--;

    int e=rrr(a,b,n,w-a[n])+1;
    b[n]++;
    return min(c,e);

}

int main()
{
    int n,w;
    cin>>n;
    int a[n+1],b[n+1];
    f(1,i,n+1)cin>>a[i]>>b[i];
    cin>>w;
    cout<<rrr(a,b,n,w);


}
