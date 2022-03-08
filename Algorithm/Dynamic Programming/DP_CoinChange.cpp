#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main()
{
    int m, n, a[100], i , j;
    cin>>m>>n;
    //m=Total Value
    //n=number of coins

    //Infinite supply of coins
    for(i=0; i<n; i++)
        cin>>a[i];

    int t[m+1];
    t[0]=0;
    for(i=1; i<=m; i++)
        t[i]=INT_MAX;

    for(i=1; i<=m; i++)
        for(j=0; j<m; j++)
        {
            if(a[j]<=i)
            {
                int x=t[i-a[j]];
                if(x!=INT_MAX && x+1<t[i])
                    t[i]=x+1;
            }
        }
    if(t[m]==INT_MAX)
        cout<<"No solution!";
    else
        cout<<"Minimum coins required: "<<t[m];
}