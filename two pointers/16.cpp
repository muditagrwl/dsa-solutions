class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
 
        int closest_sum = nums[0] + nums[1] + nums[2]; 
        
        for (int i = 0; i < n - 2; i++) {
            int lo = i + 1;
            int hi = n - 1;
            
            while (lo < hi) {
                int current_sum = nums[i] + nums[lo] + nums[hi];
             
                if (current_sum == target) {
                    return current_sum;
                }
                if (abs(current_sum - target) < abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }
                
                if (current_sum < target) {
                    lo++;
                } else {
                    hi--;
                }
            }
        }
        
        return closest_sum;
    }
};