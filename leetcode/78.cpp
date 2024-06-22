/*leetcode78 子集*/
#include <iostream>
#include <vector>
#include <functional>

 using namespace std;

/* //枚举选择的数字
std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> path;
    std::vector<std::vector<int>> ans;
    std::function<void(int)>dfs = [&](int i) {
        ans.push_back(path);
        if(i == n) {
            return;
        }
        for(int j = i; j < n; j++) { // 枚举选择的数字
        path.push_back(nums[j]);
        dfs(j + 1);
        path.pop_back();            // 恢复现场
        }

    };
    dfs(0);
    return ans;
}
*/ 

/*解法2：选或者不选*/
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<int> path;
    vector<vector<int>> ans;
    function<void(int)> dfs = [&](int i) {
        if(i == n) {
            ans.emplace_back(path);
            return;
        }
        
        dfs(i + 1); // 不选

        path.push_back(nums[i]);  // 选
        dfs(i + 1);
        path.pop_back();   // 恢复现场
    };
    dfs(0);
    return ans;
}

int main() {
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<std::vector<int>> ans = subsets(a);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            std::cout<<ans[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

}