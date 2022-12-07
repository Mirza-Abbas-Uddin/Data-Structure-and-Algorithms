#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

struct activity{
    char N;
    int s,f;
};
activity A[100];
char selected[100];

bool comp(activity a1,activity a2)
{
    return a1.f<a2.f;
}
int s=1;
void ActivitySelection(int n,int X)
{
    int i=1;
    selected[0]=A[0].N;
    while(i<n)
    {
       if((A[i-1].f+X)<=A[i].s)
       {
           selected[s++]=A[i].N;
       }
       i++;
    }
}
int main()
{
    int n,X;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> A[i].N;
        cin >> A[i].s;
        cin >> A[i].f;
    }

    cin >> X;
    sort(A,A+n,comp);

    for(int i=0;i<s;i++)
    {
        cout << A[i].N << " " << endl;
    }
    for(int i=0;i<s;i++)
    {
        //cout << selected[i] << " selected" << endl;
    }
}
