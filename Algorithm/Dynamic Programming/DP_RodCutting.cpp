#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int main()
{
    int n;
    cout<<"Length of rod: ";
    cin>>n;
    cout<<"Prices: ";
    int p[1000];
    for(int i=0; i<n; i++)
        cin>>p[i];
    int v[1000];
    int s[1000];
    v[0]=0;
    int m=INT_MIN;
    
    for(int i=1; i<=n; i++)
    { 
        for(int j=1; j<=i; j++)
        {
            if (m<p[j-1]+v[i-j])
            {
                m=p[j-1]+v[i-j];
                s[i]=j;
            }
        }
        v[i]=m;
    }
    cout<<"\nMaximum obtainable revenue: "<<v[n];
    cout<<"\nOptimal cutting lengths: ";
    while(n>0)
    {
        cout<<s[n]<<" ";
        n-=s[n];
    }
}