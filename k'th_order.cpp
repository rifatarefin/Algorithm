#include<bits/stdc++.h>
using namespace std;
void nsort(int* a,int s,int e)
{
    int flag[e-s+1];
    for(int i=0;i<=e-s;i++)flag[i]=a[s+i];
    int p;
    for(int i=0;i<=e-s;i++)
    {
        int min1=INT_MAX;
        for(int j=0;j<=e-s;j++)
        {
            if(flag[j]<min1)
            {
                min1=flag[j];
                p=j;
            }
        }
        a[s+i]=min1;
        flag[p]=INT_MAX;
    }


}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int find(int* a, int s, int n, int k ) {
    // start point s, length n, find k-th number
    if ( n == 1 && k == 1 )
        return a[s];

    int m = (n+4) /5;
    int mid[m];
    for (int i=0; i<m; i++) {
        int t = s+i*5;      // 5-elements block pointer
        if ( n-t > 4 ) {
            nsort(a, t,t+4);      // sort 5 elements
            mid[i] = a[t+2];
        }
        else {      // less than 5 left
            nsort(a, t, n-1);    // sort the rest
            mid[i] = a[t+(n-t-1)/2];
        }
    }

    return find(mid, 0, m, (m+1)/2);
}

int partition (int arr[], int low, int high)
{
    int pos;
    int size=high-low+1;
    int ad[size];
    for(int i=0;i<size;i++)ad[i]=arr[low+i];

    int pivot = find(ad,0,size,size/2);
    for(int i=low;i<=high;i++)
    {
        if(arr[i]==pivot)
        {
            pos=i;
        }
    }
    swap(&arr[pos],&arr[high]);
    //int pivot=arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high,int idx)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        if(idx==pi)
        {
            cout<<arr[pi];
            return ;
        }
        quickSort(arr, low, pi - 1,idx);
        quickSort(arr, pi + 1, high,idx);
    }
    else
    {
        if(low==idx)
        {
            cout<<arr[low];
            return ;
        }
        else if(high==idx)
        {
            cout<<arr[high];
            return ;
        }
    }
}

int main()
{
    int n;
    ifstream fin;
    fin.open("new.txt");
    fin>>n;
    int a[n],k;
    for(int i=0;i<n;i++)fin>>a[i];
    //cout<<find(a,0,n,n/2);
    fin>>k;
    quickSort(a,0,n-1,k-1);

}
