#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int m[100][100], s[100][100]={};

void print(int s[][100], int i, int j)
{
    if(i==j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        print(s, i, s[i][j]);
        print(s, s[i][j]+1, j);
        cout<<")";
    }
}

int lc(int p[], int i, int j)
{
    if(m[i][j]!=-1)
        return m[i][j];
    if(i==j)
        m[i][j]=0;
    else
    {
        m[i][j]=INT_MAX;
        for(int k=i; k<j; k++)
        {
            int q=lc(p, i, k)+lc(p, k+1, j)+p[i-1]*p[k]*p[j];
            if(q<m[i][j])
            {
                m[i][j]=q;
                s[i][j]=k;
            }
        }
    }
    return m[i][j];
}

int main()
{
    int n;
    cout<<"Total Dimensions: ";
    cin>>n;
    cout<<"Dimensions: ";
    int p[100];
    for(int i=0; i<n; i++)
        cin>>p[i];
    
    //memoized version
    for(int i=1; i<n; i++)
        for(int j=0; j<n; j++)
            m[i][j]=-1;
    cout<<"Cost: "<<lc(p, 1, n-1)<<endl;
    print(s, 1, n-1);
}



    //table version
    // int i, j, k, l, q;
    // for(l=2; l<n; l++)
    // {
    //     for(i=1; i<n-l+1; i++)
    //     {
    //         j=i+l-1;
    //         m[i][j]=INT_MAX;
    //         for(k=i; k<=j-1; k++)
    //         {
    //             q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
    //             if(q<m[i][j])
    //             {
    //                 m[i][j]=q;
    //                 s[i][j]=k;
    //             }
    //         }
    //     }
    // }
    //cout<<"Cost: "<<m[1][n-1]<<endl;
