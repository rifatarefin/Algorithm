
#include<bits/stdc++.h>
using namespace std;
int heap_size;
int mat[50][50];
int par[50];
int key[50];
int visited[50];

struct node
{
    int vertex,key;
};

void MIN_HEAPIFY(struct node *a, int i, int n)
{
    int l,r,smallest;
    struct node temp;
    l=2*i;
    r=(2*i+1);
    if((l<=n)&&a[l].key<a[i].key)
       smallest=l;
    else
       smallest=i;
    if((r<=n)&&(a[r].key<a[smallest].key))
       smallest=r;
    if(smallest!=i)
    {
         temp=a[i];
         a[i]=a[smallest];
         a[smallest]=temp;
         MIN_HEAPIFY(a, smallest,n);
    }
}

void BUILD_MINHEAP(struct node *a, int n)
{
    for(int k = n/2; k >= 1; k--)
    {
        MIN_HEAPIFY(a, k, n);
    }
}


struct node EXTRACT_MIN(struct node *a)
{

    struct node min=a[1];
    a[1]=a[heap_size];
    heap_size--;
    if(heap_size>1)MIN_HEAPIFY (a,1,heap_size);
    return min;
}
void HEAP_DECREASE(struct node *a,int i,int key)
{
    int k;
    for(int j=1;j<=heap_size;j++)
    {
        if(a[j].vertex==i)
        {
            k=j;
            break;
        }
        if(j==heap_size)return;
    }
    a[k].key=key;
    while(k>1 && a[k/2].key>a[k].key)
    {
        swap(a[k],a[k/2]);
        k=k/2;
    }
}


int main()
{
    int v,e;
    cin>>v>>e;
    struct node p[v+1];
    heap_size=v;

    for(int i=0;i<e;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        mat[x][y]=z;
        mat[y][x]=z;
    }
    for(int i=1;i<=heap_size;i++)
    {
        p[i].vertex=i;
        p[i].key=INT_MAX;
        key[i]=INT_MAX;
    }
    p[1].key=0;
    key[1]=0;
    BUILD_MINHEAP (p,heap_size);

    for(int i=0;i<v-1;i++)
    {
        struct node u=EXTRACT_MIN (p);
        visited[u.vertex]=1;
        for(int i=1;i<50;i++)
        {
            if(mat[u.vertex][i] && !visited[i] && mat[u.vertex][i]<key[i])
            {
                par[i]=u.vertex;
                key[i]=mat[u.vertex][i];
                HEAP_DECREASE (p,i,mat[u.vertex][i]);
            }
        }
    }
    for(int i=2;i<=v;i++)cout<<par[i]<<" "<<i<<" "<<mat[par[i]][i]<< "\n";

}
/*

5 7
1 2 2
2 3 3
1 4 6
2 4 8
2 5 5
3 5 7
4 5 9

*/
