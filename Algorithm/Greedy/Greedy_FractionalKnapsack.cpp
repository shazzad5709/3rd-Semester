#include<iostream>
#include<algorithm>
using namespace std;

struct product
{
    int profit, weight;
};

bool ppw(struct product a, struct product b)
{
    double r1 = (double)a.profit/(double)a.weight;
    double r2 = (double)b.profit/(double)b.weight;
    return r1>r2;
}

int main()
{
    int n, w, left=0, fi=0;
    struct product p[1000];

    //USER INPUT
    // cout<<"Capacity of knapsack: ";
    // cin>>w;
    // cout<<"Number of products: ";
    // cin>>n;
    // cout<<"Enter weights of products: ";
    // for(int i=0; i<n; i++)
    //     cin>>p[i].weight;
    // cout<<"Enter profits for products: ";
    // for(int i=0; i<n; i++)
    //     cin>>p[i].profit;
    
    //INPUT FROM FILE
    FILE* input;
    input=fopen("input2.txt", "r");
    if(input==NULL)
    {
        cout<<"Error reading file\n";
        exit(0);
    }
    fscanf(input, "%d", &w); //max capacity of knapsack
    fscanf(input, "%d", &n); //number of products
    for(int i=0; i<n; i++)
        fscanf(input, "%d", &p[i].weight);
    for(int i=0; i<n; i++)
        fscanf(input, "%d", &p[i].profit);
    fclose(input);

    sort(p, p+n, ppw);
    int fw=0; //filled weight
    double tp=0; //total profit
    for(int i=0; i<n; i++)
    {
        if(fw+p[i].weight<=w)
        {
            fw+=p[i].weight;
            tp+=p[i].profit;
            fi++;
        }
        else
        {
            left=w-fw;
            tp+=p[i].profit*((double)left/(double)p[i].weight);
            fi++;
            break;
        }
    }
    cout<<"Maximum profit: "<<tp;
    cout<<"\nThis profit is obtained by taking full portions of ";
    int i;
    for(i=0; i<fi-1; i++)
    {
        cout<<p[i].weight<<"kg, ";
    }
    if(left!=0 && (i=fi-1))
        cout<<"and "<<left/__gcd(left, p[i].weight)<<"/"<<p[i].weight/__gcd(left, p[i].weight)<<" portions of "<<p[i].weight<<"kg.";
    else
        cout<<"and "<<p[i].weight<<"kg.";
}