#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        if (n <= 2) {
        }

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while (left < right) {
            if (v[left] < v[right]) {
                leftMax = max(leftMax, v[left]);
                ans += max(0, leftMax - v[left]);
                left++;
            } else {
                rightMax = max(rightMax, v[right]);
                ans += max(0, rightMax - v[right]);
                right--;
            }
        }

        return ans;
    }
};
