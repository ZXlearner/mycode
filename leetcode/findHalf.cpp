/*找出一个数组中出现次数超过数组长度一半的数字：要求时间复杂度O(n),空间O(1)*/
#include <iostream> 
#include <vector>  
/*摩尔投票法*/
int findHalfNum(std::vector<int> nums) {
    int n = nums.size();
    int condiate = nums[0];
    int count = 1;
    for(int i = 0; i < n; i++) {
        if(condiate == nums[i]) {
            count++;
        } else {
            count--;
            if(count == 0) {
                condiate = nums[i];
            }
        }
    }
    return condiate;
}


int main() {
     std::vector<int> a = {3, 3, 2, 3, 4, 2};
     int ans = findHalfNum(a);
     std::cout<< ans << std::endl;
}