#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

struct items
{
    double w,v;
};

items selected_items[100];
int s=0;
bool comp(items i1,items i2)
{
    return i1.v/i1.w>i2.v/i2.w;
}

double fracKnapsack(items item[],int n,double W)
{
   double cap_left=W,profit=0.00;
   //int i=0;
   while(s<n && cap_left>0)//s is globally declared
   {
       double frac=min(1.00,cap_left/item[s].w);
       cap_left=cap_left-frac*item[s].w;
       profit=profit+frac*item[s].v;
       selected_items[s].w=frac*item[s].w;
       selected_items[s].v=frac*item[s].v;
       s++;
   }
   return profit;
}
int main()
{
    int n;
    cin >> n;
    items item[n];
    double before_sort[n];
    double after_sort[n];


    for(int i=0; i<n; i++)
    {
        cin >> item[i].w;
        cin >> item[i].v;
        before_sort[i]=item[i].v/item[i].w;
    }
    double W;
    cin >> W;

    sort(item,item+n,comp);
    for(int i=0; i<n; i++)
    {
        after_sort[i]=item[i].v/item[i].w;
    }
    int select[n];
    int t=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(after_sort[i]==before_sort[j])
            {
                select[t++]=j+1;
                break;
            }
        }
    }
    int p=fracKnapsack(item,n,W);
    for(int i=0; i<s; i++)
    {
        cout <<"Item-" << select[i] <<" Weight= "<<selected_items[i].w << " profit= " << selected_items[i].v << endl;
    }
    cout << "-------------------------------------------" << endl;
    cout << "Profit= "<< p<< endl;
}

