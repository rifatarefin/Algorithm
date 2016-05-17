#include<bits/stdc++.h>
using namespace std;
int sum[10000];
int capacity,n,gh=0,lk=0;
struct
{
    int idx;
    int binCount;
}track[1000];

int bound(int *a,int item, int bin_used)
{
    int k=0,empty=0;
    for(int i=item+1;i<=n;i++)k+=a[i];
    for(int i=1;i<=bin_used;i++)empty+=capacity-sum[i];
    return bin_used+(k-empty)/capacity+2;
}

int binpack(int *a, int item, int bin_used)
{
    if(item>n)return bin_used;
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
    if(c<track[item].binCount)
    {
        track[item].binCount=c;
        if(c==mx)
        {
            track[item].idx=k;
        }
        else
        {
            track[item].idx=bin_used+1;
        }
    }


    return c;

}

int main()
{

    cin>>capacity>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)track[i].binCount=INT_MAX;
    int c=binpack(a,1,0);
    cout<<"Total bins: "<<c;
    for(int i=1;i<=c;i++)
    {
        cout<<endl<<"Bin "<<i<<": ";
        for(int j=1;j<=n;j++)
        {
            if(track[j].idx==i)
            {
                cout<<a[j]<<ends;
                track[j].idx=INT_MAX;
            }
        }

    }
    cout<<endl<<lk<<endl;

    // 10 10 3 6 2 1 5 7 2 4 1 9
    // 10 10 3 6 2 3 5 7 2 4 9 9

    /*
10 15
3 4 4 5 1 2 4 7 1 5 6 2 10 5 7

    10 50
    8 9 9 1 7 5 5 10 1 0 7 7 5 8 6 7 3 7 9 2 7 7 8 10 6 7 8 5 6 7 2 1 9 10 10 2 4 9 7 5 4 7 5 6 7 0 5 0 5 4

10 20
8 9 9 1 7 5 5 10 1 3 7 7 5 8 6 7 3 7 9 2


    */

}
