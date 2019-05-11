class Solution {
public:
    int findFirst(vector<int> &nums,int target, int i, int j){
        if(i>j)
            return -1;
        int mid = (i+j)/2;
        if(nums[mid]==target && (mid-1<0 || nums[mid-1] < nums[mid]))
            return mid;
        else if(nums[mid]<target)
            return findFirst(nums,target,mid+1,j);
        else
            return findFirst(nums,target,i,mid-1); 
    }
    
    int findSecond(vector<int> &nums,int target,int i, int j){
        if(i>j)
            return -1;
        int mid = (i+j)/2;
        if(nums[mid]==target && (mid+1==nums.size() || nums[mid+1] > nums[mid]))
            return mid;
        else if(nums[mid] > target)
            return findSecond(nums,target,i,mid-1);
        else
            return findSecond(nums,target,mid+1,j);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        ans[0] = findFirst(nums,target,0,nums.size()-1);
        if(ans[0]!=-1)
            ans[1] = findSecond(nums,target,0,nums.size()-1);
        return ans;
    }
};
