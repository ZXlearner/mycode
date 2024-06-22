#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++) {
        if(ans.empty() || nums[i][0] > ans.back()[1]) {
            ans.push_back({nums[i][0], nums[i][1]});
        } else if(nums[i][0] <= ans.back()[1]){
            ans.back()[1] = std::max(ans.back()[1], nums[i][1]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = merge(v);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            std::cout<< ans[i][j] <<" ";
        }
        std::cout<<std::endl;
    }
}
