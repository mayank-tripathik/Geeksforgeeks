class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string> > hash;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            hash[s].push_back(strs[i]);
        }
        for(auto itr = hash.begin();itr!=hash.end();itr++){
            vector<string> anagramGroup = (*itr).second;
            ans.push_back(anagramGroup);
        }
        return ans;
    }
};
