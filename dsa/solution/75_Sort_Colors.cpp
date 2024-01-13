#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pivot = 1;
        int smaller = 0;
        int vSize = nums.size();
        // first loop: move elements smaller than pivot to LEFT side
        for(int i = 0; i < vSize; i++) {
            if(nums[i] < pivot){
                swap(nums[i],nums[smaller]);
                smaller++;
            }
        }
        int larger = vSize - 1;
        // second loop: move elements greater than pivot to RIGHT side
        for(int i = vSize - 1; i >= 0; i--) {
            if(nums[i] > pivot){
                swap(nums[i],nums[larger]);
                larger--;
            }
            else if (nums[i] < pivot) break;
        }
        for(int i = 0; i < vSize; i++) {
            cout<< nums[i] << " ";
        }
    }
};
int main() {
    // Your code here
    vector <int> nums = {2,1,0,0,2,1,1};
    Solution s;
    s.sortColors(nums);
    return 0;
}
