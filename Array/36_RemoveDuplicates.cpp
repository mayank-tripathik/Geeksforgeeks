class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = -1;
        if(nums.size()==0)
            return 0;
        int currentUnique = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=currentUnique)
            {
                nums[++j] = currentUnique;
                currentUnique = nums[i];
            }
        }
        nums[j+1] = currentUnique;
        return j+2;
    }
};
