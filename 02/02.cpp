//滑动窗口问题 
//有一个大小为 k的滑动窗口，它从数组的最左边移动到最右边。
//你只能在窗口中看到 k个数字。
//每次滑动窗口向右移动一个位置
//你的任务是确定滑动窗口位于每个位置时，窗口中的最大值和最小值。

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
deque<int>q;
int a[N];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        while(q.size()&&a[q.back()]>=a[i]){
            q.pop_back();
        }
        q.push_back(i);
        if(i-q.front()+1>k)q.pop_front();
        if(i>=k)
        cout<<a[q.front()]<<" ";
    }
    q.clear();
    cout<<endl;
    for(int i=1;i<=n;i++){
        while(q.size()&&a[q.back()]<=a[i]){
            q.pop_back();
        }
        q.push_back(i);
        if(i-q.front()+1>k)q.pop_front();
        if(i>=k)
        cout<<a[q.front()]<<" ";
    }
    return 0;
}
