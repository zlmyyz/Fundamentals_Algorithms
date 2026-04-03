//字符串哈希

//给定一个长度为 n的字符串，再给定 m个询问，
//每个询问包含四个整数 l1,r1,l2,r2
//请你判断 [l1,r1] 和 [l2,r2]
//这两个区间所包含的字符串子串是否完全相同。
//字符串中只包含大小写英文字母和数字。 
//注意，字符串的位置从 1开始编号。

#include<bits/stdc++.h>
using namespace std;
const int P=131,N=1e5+10;
char a[N];
#define ull unsigned long long
ull p[N],h[N];
ull get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
int main(){
    int n,m;
    cin>>n>>m;
    p[0]=1;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*P;
    }
    for(int i=1;i<=n;i++){
       char c;
       cin>>c;
       h[i]=h[i-1]*P+c;
    }
    while(m--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        cout<<((get(l1,r1)==get(l2,r2))?"Yes":"No")<<endl;
    }
    return 0;
}
