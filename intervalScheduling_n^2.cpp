#include<bits/stdc++.h>
using namespace std;
int flag[10000];
int main()
{
    clock_t tStart = clock();
    int n, cop = 0;
    ifstream fin;
    fin.open("new.txt");
    fin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)fin >> a[i] >> b[i];

    for(int i=0;i<n;i++)
    {
        int m1,m2=-1,yes=-1;
        for(int j=0;j<n;j++)
        {
            if(flag[j]==0)
            {
                m1=a[j];
                m2=b[j];
                yes=j;
                break;
            }
        }
        if(yes!=-1)
        {
            int k=yes;
            for(int j=yes;j<n;j++)
            {
                if(flag[j]==0 && b[j]<m2)
                {
                    m1=a[j];
                    m2=b[j];
                    k=j;
                }
            }
            cout<<m1<<ends<<m2<<endl;
            cop++;
            flag[k]=1;
            for(int j=0;j<n;j++)
            {
                if(a[j]<m2)flag[j]=1;
            }
        }


    }
    cout << cop << endl;
    printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
}
