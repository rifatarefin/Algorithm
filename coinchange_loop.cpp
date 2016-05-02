#define f(a,i,n) for(int i=a;i<n;i++)
#include<bits/stdc++.h>
using namespace std;
int sol[51][1001];
int coin[51][1001];
int rrr(int *a,int *b,int n, int w)
{

    if(w==0)return 0;
    if(n==0)return INT_MAX-10000;
    if(sol[n][w]!=-1)return sol[n][w];
    int ans=INT_MAX,p=0;
    for(int i=0;i<=b[n] && i*a[n]<=w;i++)
    {
        int x= rrr(a,b,n-1,w-i*a[n])+i;
        if(x<ans )
        {
            ans=x;
            p=i;
        }
    }
    coin[n][w]=p;
    return sol[n][w]=ans;


}

void getCoins(int * a, int n, int w) {
   if (n == 0) return;
   if (w <= 0) return;
   int p=coin[n][w];
   for(int i=0;i<p;i++)
   {
       cout<<a[n]<<ends;
   }
   getCoins(a,n-1,w-p*a[n]);
}
int main()
{

        int n,k;
        scanf("%d%d",&n,&k);
        int a[n+1],b[n+1];
        f(1,i,n+1)scanf("%d%d",&a[i],&b[i]);
        memset(sol,-1,sizeof sol);
        memset(coin,0,sizeof coin);
        int ans=rrr(a,b,n,k);
        cout<<"Mnimum number of coins: "<<ans<<endl<<"Coins are: ";
        getCoins (a,n,k);



    return 0;

}

