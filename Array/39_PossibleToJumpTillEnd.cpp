class Solution {
public:
    bool canJump(vector<int>& nums) {
        int prev = 1;
        for(int i=0;i<nums.size()-1;i++){
            prev = max(prev-1,nums[i]);
            if(prev == 0)
                return false;
        }
        return true;
    }
};
