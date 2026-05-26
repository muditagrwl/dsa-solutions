class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        int lo = 0, hi = n-1;
        while(lo<hi)
        {
            int water = (hi-lo)*min(a[lo],a[hi]);
            ans = max(ans, water);
            if(a[lo]<a[hi]) lo++;
            else hi--;
        }
        return ans;
    }
};