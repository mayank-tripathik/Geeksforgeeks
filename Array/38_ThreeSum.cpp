class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        cout<<n<<endl;
        for(int k=0;k<n-2;k++){
            int a = nums[k];
            if(k-1>=0 && nums[k] == nums[k-1])
                continue;
            int i = k+1;
            int j = nums.size()-1;
            while(i<j){
                int sum = a + nums[i] + nums[j];
                if(sum == 0){
                    vector<int> t = {a,nums[i],nums[j]};
                    ans.push_back(t);
                    while (i < j && nums[--j] == t[2]) {};
                    while (i < j && nums[++i] == t[1]) {};
                }
                else if( sum < 0) {
                    i++;
                }
                else{
                    j--;
                }
            }
            
        }
        return ans;
    }
};
