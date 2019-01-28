#include <iostream>
#include <vector>
using namespace std;

void s_swap(std::vector<int> &nums, int low, int high){

    int temp = nums[low];
    nums[low] = nums[high];
    nums[high] = temp;
}

int removeDuplicates(std::vector<int> &nums){

    if(nums.empty()) return 0;
    if(nums.size() == 1) return 1;

    int high = nums.size() - 1;
    int low = 0;
    int number_found;

    while(low < high){
        number_found = nums[low];
        low++;
        while(nums[low] == number_found){
            if(low > high) break;
            if(nums[low] != nums[high]){
                s_swap(nums, low, high);
                low++;
                high--;
                while(nums[low-1] == nums[high]) high--;
            }
        }
    }

    return low;
}


int main(){

    std::vector<int> nums = {1,1,2};
    std::cout << removeDuplicates(nums);

    return 0;
}
