/*leetcode216 组合总数三

找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
*/
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> path;
    vector<vector<int>> ans;
    function<void(int, int)> dfs = [&](int i, int t) {  // i - d + 1    i 
        int d = k - path.size();
        if(t < 0 || t > (2*i - d + 1)*d / 2) return;  // 剪枝 
        if(d == 0) {
                ans.emplace_back(path);
            return;
        }

        for(int j = i; j >= d; j--) {
            path.push_back(j);
            dfs(j - 1, t - j);
            path.pop_back();
        } 
    };
    dfs(9, n);
    return ans;
}

int main() {
    int k = 3, n = 7;
    vector<vector<int>> ans = combinationSum3(3, 7);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            std::cout<<ans[i][j]<<' ';
        }
        std::cout<<std::endl;
    }
}

