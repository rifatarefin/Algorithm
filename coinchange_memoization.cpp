#define f(a,i,n) for(int i=a;i<n;i++)
#include<bits/stdc++.h>
using namespace std;
int sol[100][1000][100];
int W,N;
int rrr(int *a, int *b,int n,int w,int t)
{
    if(w==0)return  0;
    if(w<0 || n==0)return 1000;

    if(sol[n][w][t]!=-1)
    {

        return sol[n][w][t];
    }

    if(a[n]>w || t<=0)
    {
        sol[n][w][t]=rrr(a,b,n-1,w,b[n-1]);
        return sol[n][w][t];
    }

    //sol[n-1][w]=
    int c=rrr(a,b,n-1,w,b[n-1]);
    b[n]--;

    int e=rrr(a,b,n,w-a[n],b[n])+1;
    b[n]++;

    int d=min(c,e);
    sol[n][w][t]=d;

    return sol[n][w][t];

}






int main()
{

    cin>>N;
    int a[N+1],b[N+1];
    f(1,i,N+1)cin>>a[i]>>b[i];
    cin>>W;
    memset(sol,-1,sizeof sol);
    int ret  = rrr(a,b,N,W,b[N]);
    cout << ret << endl;
//    f(0,i,N+1)
//    {
//        f(0,j,W+1)cout<<sol[i][j]<<ends;
//        cout<<endl;
//    }
    //cout<<sol[N][W];

}




/*


2
1 10
2 3
14


2
1 10
20 1
9








  */
