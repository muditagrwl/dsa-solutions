class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n); 
        int lo = 0, hi = n - 1;
        int index = n - 1;
        
        while (lo <= hi) {
            if (abs(nums[lo]) > abs(nums[hi])) {
                ans[index] = nums[lo] * nums[lo];
                lo++;
            } else {
                ans[index] = nums[hi] * nums[hi];
                hi--;
            }
            index--;
        }
        
        return ans;
    }
};