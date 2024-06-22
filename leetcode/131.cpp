/*分割回文字符串*/ 

#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

bool isPalindrome(string s, int l, int r) {
     if(l >= r) return true;
     while(l < r) {
        if(s[l++] != s[r--]) {
            return false;
        }
     } 
     return true;      
}

vector<vector<string>> partition(string s) {
    int n = s.length();
    vector<string> path;
    vector<vector<string>> res;
    function<void(int)> dfs = [&](int i) {
        if(i == n) {
            res.emplace_back(path);
            return;
        }

        for(int j = i; j < n; j++) {
            if(isPalindrome(s, i , j)) {
                path.push_back(s.substr(i, j - i + 1));
                dfs(j + 1);
                path.pop_back();
            }
        }
    };
    dfs(0);
    return res;
}

int main(){
    string s = "aab";
    vector<vector<string>> ans;
    ans = partition(s);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            for(int k = 0; k < ans[i][j].size(); k++) {
                std::cout<<ans[i][j][k];
            }
            std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}

