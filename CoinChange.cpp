#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int selected_coin[100];
int total_coin=0;

void GreedyCoinChange(int N,int coins[])
{
    int i=0;
    int money_left=N;
    int c=1;
    while(money_left>0)
    {
        if(money_left>=coins[i])
        {
            selected_coin[i]=c++;
            total_coin++;
            money_left=money_left-coins[i];
        }
        else
        {
            c=1;
            i++;
        }
    }
}
int main()
{
    int N,n;
    cin >> N;
    cin >> n;
    int coins[n];
    for(int i=0; i<n; i++)
    {
        cin >> coins[i];
    }
    sort(coins, coins + n, greater<int>());

    GreedyCoinChange(N,coins);
    for(int i=0; i<n; i++)
    {
        if(selected_coin[i]==0)
        {
            continue;
        }
        else
        {
           cout << coins[i] << " cents--" << selected_coin[i] << endl;
        }
    }
    cout << "------------------------------" << endl;
    cout << "Total Coin= " << total_coin;
}

