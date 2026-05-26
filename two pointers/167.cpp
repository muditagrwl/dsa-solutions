class Solution {
public:
    vector<int> twoSum(vector<int>& a, int b) {
        int n = a.size();
        int lo = 0; 
        int hi = n-1;
        vector<int> ans;
        while(lo<hi)
        {
            if(a[lo]+a[hi] == b)
            {
                ans.push_back(lo+1);
                ans.push_back(hi+1);
            }
            if(a[lo] + a[hi]>b)
            {
                hi--;
            }
            else lo++;

        }
        return ans;
    }
};