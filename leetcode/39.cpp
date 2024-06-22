/*leetcode39 组合总和*/ 
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n = candidates.size();
    vector<int>path;
    vector<vector<int>> res;
    std::sort(candidates.begin(), candidates.end());
    function<void(int, int)> dfs = [&](int i, int t) {
        if(t == 0) {
            res.emplace_back(path);
            return;
        } 
        if(t < candidates[i]) return;
        for(int j = i; j < n; j++) {
            path.push_back(candidates[j]);
            dfs(j, t - candidates[j]);
            path.pop_back();
        }
    };
    dfs(0, target);
    return res;
}

int main() {
      vector<int> nums = {2, 3, 6, 7};
      int target = 7;
      vector<vector<int>> ans = combinationSum(nums, target);
      for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            std::cout<<ans[i][j];
        }
        std::cout<<std::endl;
      }
}