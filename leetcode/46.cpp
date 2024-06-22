/*leetcode46 全排列*/  
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    vector<int> path(n), isPath(n);
    vector<vector<int>> ans;
    function<void(int)> dfs = [&](int i) {
        if(i == n) {
           ans.push_back(path);
           return;
        }

        for(int j = 0; j < nums.size(); j++) {
            if(!isPath[j]) {
              path[i] = nums[j];
              isPath[j] = true;
              dfs(i + 1);
              isPath[j] = false;
            }
        }
    };
    dfs(0);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            std::cout<<ans[i][j];
        }
        std::cout<<std::endl;
    }
}