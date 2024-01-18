#include <iostream>
#include <vector>
using namespace std;
/*
Solve the problem by using two array
in order to determine the non-increasing subarray (left) to the LEFT of the element
and non-decreasing subarray (right) to the RIGHT of the element.

Declare count variable (n), and begin considering the array:
    - if n >= k, assign left[i] = 1 or right[i] = 1
    - else:
        - To the non-increasing subarray: increase whenever left[i] <= left[i-1] otherwise n = 1
        - To the non-decreasing subarray: increase whenever right[i] >= right[i-1] otherwise n = 1
    - continue until considering the final element of the array

The element which has left[i] = 1 and right[i] = 1, whose index is accepted to insert Good Indices array.
*/
class Solution
{
public:
    vector<int> goodIndices(vector<int> &nums, int k)
    {
        int arraySize = nums.size();
        vector<int> left(arraySize, 0), right(arraySize, 0);
        vector<int> res;
        int n = 1;
        // consider non-increasing
        for (int i = 1; i < arraySize; i++)
        {
            if (n >= k)
                left[i] = 1;
            if (nums[i] <= nums[i - 1])
                n++;
            else
                n = 1;
        }
        n = 1;
        // consider non-decreasing
        for (int i = arraySize - 2; i >= 0; i--)
        {
            if (n >= k)
                right[i] = 1;
            if (nums[i] <= nums[i + 1])
                n++;
            else
                n = 1;
        }
        // comparision
        for (int i = k; i < arraySize - k; i++)
            if (left[i] == 1 && right[i] == 1)
                res.push_back(i);

        return res;
    }
};
int main()
{
    int k = 3;
    Solution s;
    vector<int> vt = {2, 1, 1, 1, 3, 4, 7, 8, 2, 4};
    vector<int> rs = s.goodIndices(vt, k);
    for (auto x : rs)
        cout << x << " ";
}