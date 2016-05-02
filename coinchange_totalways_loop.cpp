#define f(a,i,n) for(int i=a;i<n;i++)
#include<bits/stdc++.h>
using namespace std;

int sol[10001];

int main() {
    int n,w;
        cin>>n;
        int a[n+1];
        f(1,i,n+1)
        {
            cin>>a[i];

        }
        cin>>w;
        memset (sol,0,sizeof sol);
        sol[0]=1;
        f(1,i,n+1)
        {
            f(a[i],j,w+1)
            {
                sol[j]+=sol[j-a[i]];
            }
        }
        cout<<sol[w];

    return 0;
}
