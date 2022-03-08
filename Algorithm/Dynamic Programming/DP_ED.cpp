#include<iostream>
#include<algorithm>

using namespace std;

void edit_distance(string a, string b)
{
    int x=a.length(), y=b.length();
    int ed[x+1][y+1];

    for(int i=0; i<=x; i++)
    {
        for(int j=0; j<=y; j++)
        {
            if(i==0)
                ed[i][j]=j;
            else if(j==0)
                ed[i][j]=i;
            else if(a[i-1]==b[j-1])
                ed[i][j]=ed[i-1][j-1];
            else
                ed[i][j]=1+min(min(ed[i][j-1], ed[i-1][j]), ed[i-1][j-1]);

        }
    }
    cout<<"ED = "<<ed[x][y];

}

int main()
{
    string a, b; //convert a to b
    cout<<"String 1: ";
    cin>>a;
    cout<<"String 2: ";
    cin>>b;
    edit_distance(a, b);
}