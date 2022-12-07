#include<iostream>
#include<algorithm>
using namespace std;

struct Item
{
    int weight,value;
};
int dp[100][100];

void knapsack(int n,Item items[],int W)
{
    for(int i=1; i<=n; i++)
    {
        for(int w=1; w<=W; w++)
        {
            if(w>=items[i-1].weight)
            {
                dp[i][w]=max(dp[i-1][w],items[i-1].value+dp[i-1][w-items[i-1].weight]);
            }
            else
            {
                dp[i][w]=dp[i-1][w];
            }
        }
    }
}
int find_w(int n,int row,int W)
{
    for(int i=0;i<=W;i++)
    {
        if(n==dp[row][i])
        {
            return i;
        }
    }
}
void print_selected_item(int n,Item items[],int W)
{
    int i=n,w=W;
    while(i!=0)
    {
        if(dp[i][w]!=dp[i-1][w])
        {
            cout <<"Item- "<< i << endl;
            w=find_w(dp[i][w]-items[i-1].value,i-1,W);
        }
        i--;
    }
}
int main()
{
    int n,W;
    cin >> n;
    Item items[n];
    for(int i=0; i<n; i++)
    {
        cin >> items[i].weight >> items[i].value;
    }
    cin >> W;
    knapsack(n,items,W);

    cout << "Max Profit: " << dp[n][W] << endl;
    print_selected_item(n,items,W);
}
/*
4
2 12
1 10
3 20
2 15
5
*/
