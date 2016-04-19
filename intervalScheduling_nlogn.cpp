
#include<bits/stdc++.h>
using namespace std;

struct interval
{
    int start;
    int enda;
};

void MAX_HEAPIFY(interval a[], int i, int n)
{
    int l,r,largest;
    interval temp;
    l=2*i;
    r=(2*i+1);
    if((l<=n)&&a[l].enda>a[i].enda)
       largest=l;
    else
       largest=i;
    if((r<=n)&&(a[r].enda>a[largest].enda))
       largest=r;
    if(largest!=i)
    {
         temp=a[i];
         a[i]=a[largest];
         a[largest]=temp;
         MAX_HEAPIFY(a, largest,n);
    }
}


void BUILD_MAX_HEAP(interval a[], int n)
{
    for(int k = n/2; k >= 1; k--)
    {
        MAX_HEAPIFY(a, k, n);
    }
}
void HEAPSORT(interval a[], int n)
{

    BUILD_MAX_HEAP(a,n);
    int i;
    interval temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        MAX_HEAPIFY(a, 1, i - 1);
    }
}


int main()
{
    clock_t tStart = clock();
    int n;
    ifstream fin;
    fin.open("new.txt");
    fin>>n;
    interval a[n+1];
    for(int i=1;i<=n;i++)
    {
        fin>>a[i].start>>a[i].enda;
    }
    HEAPSORT (a,n);
    int now=-1,count =0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].start>=now)
        {
            cout<<a[i].start<<ends<<a[i].enda<<endl;
            now=a[i].enda;
            count++;
        }
    }
    cout<<count<<endl;
    printf("Time taken: %.4fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);


}
