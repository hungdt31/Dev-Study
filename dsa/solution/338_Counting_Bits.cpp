#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        // n+1 as we are going to count from 0 to n
        vector<int> t(n+1);
        // t[0] will be 0 beacuse 0 has count of set bit is 0;
        t[0] = 0;
        // we can compute current set bit count using previous count
        // as x/2 in O(1) time
        // i%2 will be 0 for even number ans 1 for odd number
        for(int i = 1; i<=n; ++i)
            t[i] = t[i/2] + i%2;
        return t;
    }
};
int main(){
    Solution s;
    vector <int> vt = s.countBits(12);
    for (auto x : vt) cout << x << " ";
    // Output: 0 1 1 2 1 2 2 3 1 2 2 3 2 
}