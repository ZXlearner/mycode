/*leetcode77 组合*/
#include <iostream> 
#include <vector>
#include <functional>

using namespace std;

// vector<vector<int>> combine(int n, int k) {
//     vector<int> path;
//     vector<vector<int>> ans;

//     function<void(int)> dfs = [&](int i) {
//         int d = k - path.size(); // 还要选d个数
//         if(d == 0) {
//            ans.push_back(path);
//            return;
//         }
       
//         for(int j = i; j >= d; j--) { // 剪枝 从[1, i]开始选，如果 i < d就不需要继续递归了
//             path.push_back(j);
//             dfs(j - 1);
//             path.pop_back();
//         } 
//     };
//     dfs(n);
//     return ans;
// }

vector<vector<int>> combine(int n, int k) {
    vector<int> path;
    vector<vector<int>> ans;
    function<void(int)> dfs = [&](int i) {
        int d = k - path.size();
        if(d == 0) {
            ans.push_back(path);
            return;
        }

        if(d < i) dfs(i - 1);
        path.push_back(i);
        dfs(i - 1);
        path.pop_back();
    };
    dfs(n);
    return ans;
}


int main() {
    int n = 4, k = 2;
    vector<vector<int>> ans = combine(4, 2);
    for(int i = 0; i < ans.size(); i++) {
        for(int k : ans[i]) {
            std::cout<<k;
        }
        std::cout<<std::endl;
    }
}
