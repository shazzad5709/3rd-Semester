#include<iostream>
#include<algorithm>
using namespace std;

int d[100][100]; //direction array
//1 = diagonal, 2 = up, 3 = left

void print_lis(int a[], int x, int y)
{
    if(x==0 || y==0)
        return;
    if(d[x][y]==1)
    {
        print_lis(a, x-1, y-1);
        cout<<a[x-1]<<" ";
    }
    else if(d[x][y]==2)
        print_lis(a, x-1, y);
    else
        print_lis(a, x, y-1);
}

void lcs(int a[], int b[], int x)
{
    int s[100][100], i, j;
    for(i=0; i<x; i++)
        s[0][i]=s[i][0]=0;
    for(i=1; i<=x; i++)
    {
        for(j=1; j<=x; j++)
        {
            if(a[i-1]==b[j-1])
            {
                s[i][j]=1+s[i-1][j-1];
                d[i][j]=1;
            }
            else if(s[i-1][j]>=s[i][j-1])
            {
                s[i][j]=s[i-1][j];
                d[i][j]=2;
            }
            else
            {
                s[i][j]=s[i][j-1];
                d[i][j]=3;
            }
        }
    }
    cout<<"Longest Increasing Subsequence: "<<s[x][x]<<endl;
    cout<<"Sequence: ";
    print_lis(a, x, x);
}

int main()
{
    int a[100], b[100], n;
    cout<<"Number of elements: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b, b+n);
    lcs(a, b, n);
}