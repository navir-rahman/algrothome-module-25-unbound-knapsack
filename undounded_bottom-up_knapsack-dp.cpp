#include <bits/stdc++.h>
using namespace std;
// int dp[1005][1005];
// int unb_knp(int n, int s, int val[], int w[]){
//     if(n==0) return 0;
//     if(s==0) return 0;
// if(dp[n][s]!=0)return dp[n][s];
//     if(w[n-1] <=s){
//         int op1= val[n-1]+ unb_knp(n, s-w[n-1], val, w);
//         int op2= unb_knp(n-1,s,val,w);
//         return max(op1, op2);
//     }else{
//         return unb_knp(n-1,s,val,w);
//     }
// }

int main()
{
    int n,s;
    cin>>n>>s;
    int dp[n+1][s+1]; 
    for (size_t i = 0; i <=n; i++)
    {
        for (size_t j = 0; j <=s; j++)
        {
           if(i ==0 ||j==0) dp[i][j]=0;
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


    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=s; j++)
        {
            if(weight[i-1] <=j){
                dp[i][j]=max(val[i-1]+dp[i][j-weight[i-1]] ,dp[i-1][j]);
            }
            else{
                dp[i][j]= dp[i-1][j];
            }
        }
        
    }
    
    
    cout<<dp[n][s];

    return 0;
}