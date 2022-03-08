#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//USING STRUCTURE
struct time
{
    int start, finish;
};

bool sortbyfinish (struct time a1, struct time a2)
{
    return (a1.finish<a2.finish);
}

int main()
{
    int n;
    struct time a[1000];

    //USER INPUT
    // cout<<"Enter the number of activites: ";
    // cin>>n;
    // cout<<"Enter the starting time of the activities: ";
    // for(int i=0; i<n; i++)
    //     cin>>a[i].start;
    // cout<<"Enter the finishing time of the activities: ";
    // for(int i=0; i<n; i++)
    //     cin>>a[i].finish;

    //INPUT FORM FILE
    FILE* input;
    input=fopen("input1.txt", "r");
    if(input==NULL)
    {
        cout<<"Error reading file\n";
        exit(0);
    }

    fscanf(input, "%d", &n);
    for(int i=0; i<n; i++)
        fscanf(input, "%d", &a[i].start);
    for(int i=0; i<n; i++)
        fscanf(input, "%d", &a[i].finish);
    fclose(input);

    sort(a, a+n, sortbyfinish);
    cout<<"Selected activities are:\n("<<a[0].start<<", "<<a[0].finish<<")\n";  
        //the activity that is finished first is always selected
    for(int i=0, j=1; j<n; j++)
    {
        if(a[j].start>=a[i].finish)
        {
            cout<<"("<<a[j].start<<", "<<a[j].finish<<")\n";
            i=j;
        }
    }
}


//USING VECTOR PAIR

//prints activity number

// int main()
// {
//     int n;
//     cout<<"Enter the number of activites: ";
//     cin>>n;
//     vector<pair<int, int>> a, b;
//     for(int i=0; i<n; i++)
//     {
//         int start, finish;
//         cin>>start>>finish;
//         b.push_back(make_pair(finish, start));
//         a.push_back(make_pair(finish, start));
//     }
//     sort(a.begin(), a.end());
//     // for(int i=0; i<n; i++)
//     //     cout<<a[i].first<<" "<<a[i].second<<endl;
//     cout<<"Selected activities are: 1 ";   //the activity that is finished first is always selected
//     for(int i=0, j=1; j<n; j++)
//     {
//         if(a[j].second>=a[i].first)
//         {
//             cout<<j+1<<" ";
//             i=j;
//         }
//     }
// }


//prints starting and finishing time

// int main()
// {
//     int n;
//     cout<<"Enter the number of activites: ";
//     cin>>n;
//     int start[1000], finish[1000];
//     for(int i=0; i<n; i++)
//         cin>>start[i];
//     for(int i=0; i<n; i++)
//         cin>>finish[i];
//     vector<pair<int, int>> a;
//     for(int i=0; i<n; i++)
//     {
//         a.push_back(make_pair(finish[i], start[i]));
//     }
//     sort(a.begin(), a.end());
//     cout<<"Selected activities are:\n("<<a[0].second<<", "<<a[0].first<<")\n";  
//         //the activity that is finished first is always selected
//     for(int i=0, j=1; j<n; j++)
//     {
//         if(a[j].second>=a[i].first)
//         {
//             cout<<"("<<a[j].second<<", "<<a[j].first<<")\n";
//             i=j;
//         }
//     }
// }