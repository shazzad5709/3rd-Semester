#include<iostream>
#include<algorithm>
using namespace std;

void print(int p[], int i, int a[])
{
    if(i==0)
        return;
    print(p, p[i], a);
    cout<<a[i]<<" ";
}

int main()
{
    int a[100], n, i, j;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>a[i];
    int l[100], p[100], pi=0, pm=0;
    l[0]=1;
    p[0]=0, p[1]=0;
    for(i=1; i<n; i++)
    {
        l[i]=1;
        for(j=0; j<i; j++)
        {
            if(a[j]<a[i] && (l[j]+1)>l[i])
            {
                l[i]=l[j]+1;
                p[i]=j;
                if(p[i]>pm)
                {
                    pm=p[i];
                    pi=i;
                }
            }
        }
    }
    cout<<"Length of LIS: "<<*max_element(l, l+n)<<endl;
    cout<<"Sequence: ";
    print(p, pi, a);
}