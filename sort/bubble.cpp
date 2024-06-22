#include<iostream>  
#include<vector>
using namespace std;
template<class T>
void swap(T &a, T &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void BubbleSort(std::vector<int> &nums, int n) {
   if (n <= 1) return;
   bool isSwap;
   for (int i = 1 ; i < n; i++) {
    isSwap = false;
    for (int j = 1; j < n - i + 1; j++) {
        if (nums[j] < nums[j - 1]) {
            std::swap(nums[j], nums[j - 1]);
            isSwap = true;
        }
    }
    if (isSwap == false) break;
   }
}


int main(){
    vector<int> a = {34,66,2,5,95,4,46,27};
     BubbleSort(a, a.size());
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] <<endl;
    }
    return 0;
}