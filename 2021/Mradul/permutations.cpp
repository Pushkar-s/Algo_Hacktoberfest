class Solution {
public:
    
    void permuteUtil(vector<int> &nums, vector<vector<int>>&ans, int l, int r)
    {
    
        if(l==r)
        {
            ans.push_back(nums);
        }
        
        for(int i = l; i<=r; i++)
        {
            swap(nums[i], nums[l]);
            permuteUtil(nums, ans, l+1, r);
            swap(nums[i], nums[l]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteUtil(nums, ans, 0, nums.size()-1);
        return ans;
        
    }
};
