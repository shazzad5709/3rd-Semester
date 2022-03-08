#include<iostream>
#include<algorithm>
using namespace std;

int d[100][100]; //direction array
//1 = diagonal, 2 = up, 3 = left 

void print_lcs(string a, int x, int y)
{
    if(x==0 || y==0)
        return;
    if(d[x][y]==1)
    {
        print_lcs(a, x-1, y-1);
        cout<<a[x-1];
    }
    else if(d[x][y]==2)
        print_lcs(a, x-1, y);
    else
        print_lcs(a, x, y-1);
}

void lcs(string a, string b)
{
    int s[100][100]; //lcs
    int x=a.length(), y=b.length(), i, j;
    for(i=0; i<x; i++)
        s[0][i]=0;
    for(i=0; i<y; i++)
        s[i][0]=0;
    for(i=1; i<=x; i++)
    {
        for(j=1; j<=y; j++)
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
    cout<<"Longest common subsequence: "<<s[x][y]<<endl;
    cout<<"Subsequence: ";
    print_lcs(a, x, y);
    return;   
}

int main()
{
    string a, b;
    cout<<"String 1: ";
    cin>>a;
    cout<<"String 2: ";
    cin>>b;
    lcs(a, b);
}