/**
 * dfs P2089 烤鸡
 * ------------------
 * 11
 * -------------------
 * 10
 * 1 1 1 1 1 1 1 1 1 2 
 * 1 1 1 1 1 1 1 1 2 1 
 * 1 1 1 1 1 1 1 2 1 1 
 * 1 1 1 1 1 1 2 1 1 1 
 * 1 1 1 1 1 2 1 1 1 1 
 * 1 1 1 1 2 1 1 1 1 1 
 * 1 1 1 2 1 1 1 1 1 1 
 * 1 1 2 1 1 1 1 1 1 1 
 * 1 2 1 1 1 1 1 1 1 1 
 * 2 1 1 1 1 1 1 1 1 1 
 */

/**
 * FIANL
 */
#include <iostream>
using namespace std;

//1-10记录每种配料要多少克
int ans[15]={0};
int fans[60000][15];
int cnt=0;

//n是剩余多少克，k是枚举到第几种
void dfs(int k,int n);

int main(){
    int n;cin>>n;

    dfs(1,n);

    cout<<cnt<<endl;

    for (int i = 0; i < cnt; ++i){
        for (int j = 1; j <= 10; ++j){
            cout<<fans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

void dfs(int k,int n){
    //退出条件
    if(k==10){
        if(n<=3&&n>=1){
            ans[k]=n;
            //cout<<cnt<<endl;
            for (int j = 1; j <= 10; ++j){
                fans[cnt][j]=ans[j];
            }
            ++cnt;
            return;
        }else{
            return;
        }
    }
    //继续递归
    //第k种要在1，2，3中选择
    for(int i=1;i<=3&&i<=n;++i){
        ans[k]=i;
        dfs(k+1,n-i);
        ans[k]=0;
    }
}


// #include <iostream>
// using namespace std;

// const int N = 10;
// int n;
// int arr[N]={0};
// int cnt = 0;

// // x 表示当前的位置，sum 表示当前总和
// void dfs(int x, int sum) {
//     // 退出条件
//     if (sum > n) return; // 剪枝
//     if (x > 10) {
//         if (sum == n) {
//             for (int i = 1; i <= 10; ++i) {
//                 //printf("%d ", arr[i]);
//                 if(i==10){cnt++;}
//             }
//             printf("\n");
//         }
//         return;
//     }

//     for (int i = 1; i <= 3; ++i) {
//         if (sum + i > n) continue; // 剪枝优化
//         arr[x] = i;
//         dfs(x + 1, sum + i);
//         arr[x] = 0; // 回溯
//     }
// }

// int main() {
//     scanf("%d", &n);
//     dfs(1, 0);
//     printf("%d\n", cnt);

//     return 0;
// }

// #include <algorithm>
// #include <cstring>

// //可以先通过组合数学把结果算出来，就不用维护一个二维数组保存结果

// const int N=10;

// int n;
// int cnt;        //cnt
// int arr[N];     //方案

// //x表示存到了哪一位，sum表示当前已选择的调料总和
// void dfs(int x,int sum);

// int main(){
//     scanf("%d",&n);
//     dfs(1,0);
//     cout<<cnt<<endl;

//     return 0;
// }

// void dfs(int x,int sum){
//     //退出条件
//     if(sum>n){return;}
//     if(x==10){
//         if (sum==n){
//             for (int i = 1; i <= 10; ++i){
//                 cout<<arr[i]<<" ";
//             }
//             cout<<endl;
//             cnt++;   
//         }
//         return;
//     }

//     for(int i=1;i<=3;++i){
//         arr[x]=i;
//         dfs(x+1,sum+i);
//         arr[x]=0;
//     }
// }


// //1-10记录每种配料要多少克
// int ans[15]={0};
// int fans[60000][15];
// int cnt=0;

// //n是剩余多少克，k是枚举到第几种
// void dfs(int k,int n);

// int main(){
//     int n;cin>>n;

//     dfs(1,n);

//     cout<<cnt<<endl;

//     for (int i = 0; i < cnt; ++i){
//         for (int j = 1; j <= 10; ++j){
//             cout<<fans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
    
//     //cout<<cnt<<endl;

//     return 0;
// }

// void dfs(int k,int n){
//     //退出条件
//     if(k==10){
//         if(n<=3&&n>=1){
//             ans[k]=n;
//             //cout<<cnt<<endl;
//             for (int j = 1; j <= 10; ++j){
//                 fans[cnt][j]=ans[j];
//             }
//             ++cnt;
//             return;
//         }else{
//             return;
//         }
//     }
//     //继续递归
//     //第k种要在1，2，3中选择
//     for(int i=1;i<=3&&i<=n;++i){
//         ans[k]=i;
//         dfs(k+1,n-i);
//         ans[k]=0;
//     }
//     // if (n>=3)
//     // {
//     //     ans[k]=1;
        
//     //     ans[k]=2;
//     //     dfs(k+1,n-2);
//     //     ans[k]=3;
//     //     dfs(k+1,n-3);        
//     // }else if(n>=2){
//     //     ans[k]=1;
//     //     dfs(k+1,n-1);
//     //     ans[k]=2;
//     //     dfs(k+1,n-2); 
//     // }else if(n==1){
//     //     ans[k]=1;
//     //     dfs(k+1,n-1);
//     // }else{
//     //     //不足
//     //     return;
//     // }
// }