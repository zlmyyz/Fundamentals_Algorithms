//小苯有 n个数字，初始均为白色，他可以染红一些数字来获取分数，
//可进行任意次以下操作：选择一个区间 l,r(1≤l<r≤n)
//，满足区间端点的数字奇偶性相同，
//且区间中（包括端点）的所有数字均为白色。
//将这段区间的所有数字染红，得分为该区间的 a[l]+a[r]
//小苯想知道自己最多可以获得多少分，若一次操作都不做则得分为 0
//输入描述
//每个测试文件包含多组测试数据：
//第一行输入整数 
//T?(1≤T≤10 4)
//，代表数据组数；每组测试数据：第一行一个正整数 n(1≤n≤2×1e5)，表示数字的个数；
//第二行n个整数
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ll long long
ll a[N],dp[N];
int main(){
    int T;
    cin>>T;
    while(T--){
        ll flag[2]={(ll)-1e18,(ll)-1e18};
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];       
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            int t=abs(a[i])&1;
            if(flag[t]!=-1e18){
                dp[i]=max(dp[i],flag[t]+a[i]);
            }
            flag[t]=max(flag[t],dp[i-1]+a[i]);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
