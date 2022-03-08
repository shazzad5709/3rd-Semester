#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int n, m;
int a[100][100], c[100][100];

void print(int i, int j)
{
    if(i==0 || j==m+1 || j==0)
        return;
    if((a[i-1][j-1]<=a[i-1][j]) && (a[i-1][j-1]<=a[i-1][j+1]))
        print(i-1, j-1);
    else if((a[i-1][j]<=a[i-1][j-1]) && (a[i-1][j]<=a[i-1][j+1]))
        print(i-1, j);
    else if((a[i-1][j+1]<=a[i-1][j-1]) && (a[i-1][j+1]<=a[i-1][j]))
        print(i-1, j+1);
    cout<<i<<" "<<j<<endl;
}   

int main()
{ 
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>c[i][j];
    
    for(int i=1; i<m; i++)
        a[0][i]=0;
    
    for(int i=0; i<=n+1; i++)
        a[i][0]=a[i][m+1]=INT_MAX;
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(i==1)
                a[i][j]=c[i][j];
            else
                a[i][j]=c[i][j]+min(min(a[i-1][j-1], a[i-1][j]), a[i-1][j+1]);
        }
    
    int r[100];
    
    for(int i=1; i<=m; i++)
        r[i-1]=a[n][i];
    cout<<"Least Total Danger: "<<*min_element(r, r+m)<<endl;
    // cout<<endl;
    // for(int i=1; i<=n; i++)
    // {
    //     for(int j=1; j<=m; j++)
    //         cout<<a[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;
    print(n, min_element(r, r+m)-r+1);
}