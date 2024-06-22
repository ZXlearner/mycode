/*leetcode17 电话号码的不同组合*/
#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

vector<string>mapping = {{}, {}, "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> letterCombinatons(string digits) {
    int n = digits.length();
    if(n == 0) return {};
    string path(n, 0);
    vector<string> res;
    function<void(int)> dfs = [&](int i) {
        if(i == n) {
            res.emplace_back(path);
            return;
        }
        for(char c : mapping[digits[i] - '0']) {
            path[i] = c;
            dfs(i + 1);
        }
    };
    dfs(0);
    return res;
}

int main() {
    string digits = "23";
    vector<string> ans = letterCombinatons(digits);
    for(int i = 0; i < ans.size(); i++) {
        for(char c : ans[i]) {
            std::cout<<c<<' ';
        }
        std::cout<<std::endl;
    }
}