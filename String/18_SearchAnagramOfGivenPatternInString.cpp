class Solution {
public:
    bool match(vector<int> &count1, vector<int> &count2){
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size()<p.size())
            return ans;
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        for(int i=0;i<p.size();i++){
            count1[s[i]-'a']++;
            count2[p[i]-'a']++;
        }
        if(match(count1,count2)){
            ans.push_back(0);
        }
        for(int i=p.size();i<s.size();i++){
            char removeChar = s[i - p.size()];
            count1[removeChar-'a']--;
            count1[s[i]-'a']++;
            if(match(count1,count2)){
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
    }
};
