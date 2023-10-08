#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int unb_knp(int n, int s, int val[], int w[]){
    if(n==0) return 0;
    if(s==0) return 0;
if(dp[n][s]!=0)return dp[n][s];
    if(w[n-1] <=s){
        int op1= val[n-1]+ unb_knp(n, s-w[n-1], val, w);
        int op2= unb_knp(n-1,s,val,w);
        return max(op1, op2);
    }else{
        return unb_knp(n-1,s,val,w);
    }
}

int main()
{
    int n,w;
    cin>>n>>w;
    for (size_t i = 0; i <=n; i++)
    {
        for (size_t j = 0; j <=w; j++)
        {
            dp[i][j]=0;
        }
        
    }
    
    int val[n], weight[n];
    for (int i = 0; i < n; i++)
    {
        cin>>val[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin>>weight[i];
    }
    
    cout<<unb_knp(n,w,val,weight);

    return 0;
}