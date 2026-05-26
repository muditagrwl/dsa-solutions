class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        if(n==0) return 0;
        int lo = 0, hi = n-1;
        int left_max = 0, right_max = 0;
        int ans = 0;
        while(lo<=hi)
        {
            if(a[lo]<=a[hi])
            {
                if(a[lo] >= left_max)
                {
                    left_max = a[lo];
                }
                else
                {
                    ans += left_max - a[lo];
                }
                lo++;
            }
            else
            {
                if(a[hi] >= right_max)
                {
                    right_max = a[hi];
                }
                else 
                {
                    ans += right_max - a[hi];
                }
                hi--;
            }
        }
        return ans ; 
    }
};