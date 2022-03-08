// L = {w | w is a set of string that ends with 11}

#include<iostream>
using namespace std;

int cs=0; //current state

void q0(char c)
{
    int ps=cs;
    if(c=='1')
        cs=1;
    else if(c=='0')
        cs=0;
    else
        cs=-1;
    if(cs!=-1)
        cout<<"T(q"<<ps<<", "<<c<<")=q"<<cs<<endl;
}

void q1(char c)
{
    int ps=cs;
    if(c=='1')
        cs=2;
    else if(c=='0')
        cs=0;
    else
        cs=-1;
    if(cs!=-1)
        cout<<"T(q"<<ps<<", "<<c<<")=q"<<cs<<endl;
}

void q2(char c)
{
    int ps=cs;
    if(c=='1')
        cs=2;
    else if(c=='0')
        cs=0;
    else
        cs=-1;
    if(cs!=-1)
        cout<<"T(q"<<ps<<", "<<c<<")=q"<<cs<<endl;
}

void DFA(string w)
{
    for(int i=0; i<w.length(); i++)
    {
        if(cs==0)
            q0(w[i]);
        else if(cs==1)
            q1(w[i]);
        else if(cs==2)
            q2(w[i]);
        else
        {
            cout<<"Invalid string\n";
            return;
        }
    }
    (cs==2)? cout<<"\nACCEPTED" : cout<<"\nREJECTED";
        return;
}
int main()
{
    string w;
    cout<<"Enter string: ";
    cin>>w;
    DFA(w);
    //cout<<"\n\nTransition Table: \n";
    string ts[4];
    ts[0]="   T   0   1\n";
    ts[1]="->q0  q0  q1\n";
    ts[2]="  q1  q0  q2\n";
    ts[3]=" *q2  q0  q2\n";
    cout<<endl<<ts[0]<<ts[1]<<ts[2]<<ts[3];
}