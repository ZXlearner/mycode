/*leetcode79 单词搜索*/   
#include <iostream>
#include <vector>
#include <string>
#include <functional> 

using namespace std;

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    int l = word.size();
    vector<vector<int>> on_path;
    function<bool(int, int, int)> dfs = [&](int i, int j, int t) {
      if(t == l) {
        return true;
      }
      if(i >=0 && i <= m && j >= 0 && j <= n && board[i][j] == word[t] && !on_path[i][j]) {
        on_path[i][j] = true;
        if(dfs(i - 1, j, t + 1) || dfs(i + 1, j, t + 1) || dfs(i, j - 1, t + 1) || dfs(i, j + 1, t + 1)) {
            return true;
        }
        on_path[i][j] = false;
        return false;
      }
    };

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(dfs(i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}