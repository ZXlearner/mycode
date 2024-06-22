/* 
leetcode22 括号生成   
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
*/
#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

vector<string> generateParenthesis(int n) {
    int m = n*2;
    string path(m, 0);
    vector<string> res;
    function<void(int, int)> dfs = [&](int i, int open) {
        if(i == m) {
           res.push_back(path);
           return;
        }

        if(open < n) {
           path[i] = '(';
           dfs(i + 1, open + 1);
        } 

        if(i - open < open) { // 
           path[i] = ')';
           dfs(i + 1, open);
        }
    };
    dfs(0, 0);
    return res;
}

int main() {
    int n = 3;
    vector<string> ans = generateParenthesis(n);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            std::cout<<ans[i][j];
        }
        std::cout<<std::endl;
    }
}