#include<iostream>
#include<algorithm>
using namespace std;

int ceilI(int a[], int l, int r, int k)
{
    while(r-l>1)
    {
        int m=l+(r-l)/2;
        (a[m]>=k)?  r=m : l=m;
    }
    return r;
}

int lis(int a[], int n)
{
    int t[100], i;
    for(i=0; i<=n; i++)
        t[i]=0;
    int l=1;

    t[0]=a[0];
    for(int i=1; i<n; i++)
    {
        if(a[i]<t[0])
            t[0]=a[i];
        else if(a[i]>t[l-1])
            t[l++]=a[i];
        else
            t[ceilI(t, -1, l-1, a[i])]=a[i];
    }
    return l;
}

int main()
{
    int a[100], n, i;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>a[i];
    cout<<"Length of LIS: "<<lis(a, n);
}