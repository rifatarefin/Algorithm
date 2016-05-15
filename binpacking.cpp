#include<bits/stdc++.h>
using namespace std;
int sol=INT_MAX;
vector< int >v[100];
int sum[10000];
int capacity,n,gh=0,lk=0;
int bound(int *a,int item, int bin_used)
{
    int k=0,empty=0;
    for(int i=item+1;i<=n;i++)k+=a[i];
    for(int i=1;i<=bin_used;i++)empty+=capacity-sum[i];
    return bin_used+(k-empty)/capacity;
}

int binpack(int *a, int item, int bin_used)
{
    if(item>n || bin_used==n)return bin_used;
//
    int y=bound(a,item,bin_used);
    if(bin_used>y)
    {
        gh++;
        return 100000;

    }
//
    int mx=INT_MAX,k;
    lk++;
    for(int i=1;i<=bin_used;i++)
    {
        if(sum[i]+a[item]<=capacity)
        {
            sum[i]+=a[item];
            int b=binpack(a,item+1,bin_used);
            if(b<mx)
            {
                mx=b;
                k=i;

            }
            sum[i]-=a[item];
        }

    }
    sum[bin_used+1]+=a[item];
    int mx2=binpack (a,item+1,bin_used+1);
    sum[bin_used+1]-=a[item];
    int c=min(mx,mx2);
    return c;

}

int main()
{

    cin>>capacity>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    int c=binpack(a,1,0);
    cout<<c<<endl<<gh<<ends<<lk;

// 10 10 3 6 2 1 5 7 2 4 1 9

    /*

    10 50
    8 9 9 1 7 5 5 10 1 0 7 7 5 8 6 7 3 7 9 2 7 7 8 10 6 7 8 5 6 7 2 1 9 10 10 2 4 9 7 5 4 7 5 6 7 0 5 0 5 4

10 20
8 9 9 1 7 5 5 10 1 0 7 7 5 8 6 7 3 7 9 2


    */

}
