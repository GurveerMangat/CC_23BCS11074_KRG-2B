class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        int total=pow(2,n);
        for(int i=0;i<total;i++){
            vector<int> sub;
            for(int j=0;j<31;j++){
                if((i>>j)&1)sub.push_back(nums[j]);
            }
            ans.push_back(sub);
        }
        return ans;
    }
};
