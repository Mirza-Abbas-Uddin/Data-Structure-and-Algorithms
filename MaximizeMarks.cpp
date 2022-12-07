#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int T,M;

struct exam{
 double m,t;
};
exam selected_question[100];

bool comp(exam m1,exam m2)
{
    return m1.m/m1.t>m2.m/m2.t;
}
int s=0;
double maximize_marks(exam marks[],int n)
{
    double time_left=T;
    double mark=0.00;

    while(time_left>0 && mark<=M && s<n)
    {
        double frac=min(1.00,time_left/marks[s].t);
        time_left=time_left - marks[s].t*frac;
        mark=mark+marks[s].m*frac;
        selected_question[s].t=frac*100;
        selected_question[s].m=marks[s].m*frac;
        s++;
    }
    return mark;
}
int main()
{
    int n;
    cin >> M;
    cin >> T;
    cin >> n;

    exam marks[n];
    double before_sort[n];
    for(int i=0;i<n;i++)
    {
        cin >> marks[i].m;
        cin >> marks[i].t;
        before_sort[i]=marks[i].m/marks[i].t;
    }
    sort(marks,marks+n,comp);
    int q=0;
    int select[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(marks[i].m/marks[i].t==before_sort[j])
            {
                select[q++]=j+1;
                break;
            }
        }
    }
    double max_marks=maximize_marks(marks,n);

    for(int i=0;i<s;i++)
    {
        cout << "Question-" << select[i] << " "<< selected_question[i].t << "% done " << selected_question[i].m << " marks" << endl;
    }
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Total Marks = " << max_marks;
}
