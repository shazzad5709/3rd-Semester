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