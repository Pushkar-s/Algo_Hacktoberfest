class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //unordered_map<int, int> mp;
        int pos = 0;
        vector<pair<int, int>> temp;
      //  temp.push_back(nums[0]);
        for(int i: nums)
            {
            //if(i!=temp.back())
              //  temp.push_back(i);
            temp.push_back({i, pos++});
//            mp[i] = pos++;
        }
        
        sort(temp.begin(), temp.end());
        
        int i=0, j=temp.size()-1;
        while(i<j)
            {
            
            if(temp[i].first+temp[j].first==target)
                return {temp[i].second, temp[j].second};
            else if(temp[i].first+temp[j].first<target)
                i++;
            else j--;
        }
        
        return {};
    }
};
