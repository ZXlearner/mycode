#include <vector>
#include <iostream>

int partition(std::vector<int>& nums, int low, int high) {
    int pivot = nums[high];
    int i = low;
    for (int j = low; j < high; ++j) {
        if (nums[j] >= pivot) {
            std::swap(nums[i], nums[j]);
            ++i;
        }
    }
    std::swap(nums[i], nums[high]);
    return i;
}

void quickSelect(std::vector<int>& nums, int low, int high, int k) {
	if(low > high) return;
    if (low <= high) {
        int pivotIndex = partition(nums, low, high);
        if (pivotIndex == k) {
            return ;
        } else if (pivotIndex > k) {
             partition(nums, low, pivotIndex - 1);
        } else {
            partition(nums, pivotIndex + 1, high);
        }
    }
}

std::vector<int> topK(std::vector<int>& nums, int k) {
    if (k <= 0 || k > nums.size()) {
        return {};
    }
    quickSelect(nums, 0, nums.size() - 1, k - 1);
    return std::vector<int>(nums.begin(), nums.begin() + k);
}

int main() {
    std::vector<int> nums = {3, 10000, 500, 2, 100, 8, 7, 6};
    int k = 3;
    std::vector<int> result = topK(nums, k);
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
