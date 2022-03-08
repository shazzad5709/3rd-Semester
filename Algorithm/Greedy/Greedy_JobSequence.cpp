#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct job
{
    char id;
    int dl; //deadline
    int p; //profit
};

bool cmp(struct job a, struct job b)
{
    return (a.p>b.p);
}

void js (struct job j[], int n)
{
    sort(j, j+n, cmp);

    int r[n]; //to store sequence of jobs
    int s=0;
    vector<bool> slot(n, false); //to keep tract of free time slots

    for(int i=0; i<n; i++)
    {
        for(int k=min(n, j[i].dl)-1; k>=0; k--)
        {
            if(slot[k]==false)
            {
                r[k]=i;
                slot[k]=true;
                break;
            }
        }
    }
    for(int i=0; i<n; i++)
        if(slot[i])
            cout<<j[r[i]].id<<" ";
    for(int i=0; i<n; i++)
        if(slot[i])
            s+=j[r[i]].p;
    cout<<"\nTotal profit: "<<s;
}


int main()
{
    struct job j[1000];
    int n;
    cout<<"Number of jobs: ";
    cin>>n;
    cout<<"Profits for each job: ";
    for(int i=0; i<n; i++)
        cin>>j[i].p;
    cout<<"Deadlines of each jobs: ";
    for(int i=0; i<n; i++)
        cin>>j[i].dl;
    for(int i=0; i<n; i++)
        j[i].id='a'+i;
    cout<<"Max profit sequence of jobs: ";
    sort(j, j+n, cmp);
    js(j, n);
}