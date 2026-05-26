class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = 0;
 
        for (int pile : piles) {
            hi = max(hi, pile);
        }
       
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long total_hours = 0; 
            
            for (int pile : piles) {
               
                total_hours += (pile + mid - 1) / mid;
            }
            
        
            if (total_hours <= h) {
                hi = mid;
            } 
            
            else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};