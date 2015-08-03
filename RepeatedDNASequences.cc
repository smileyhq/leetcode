class Solution {
public:
    #define window 0x3fffffff
    vector<string> findRepeatedDnaSequences(string s){
        unordered_map<int,int> strs;
        vector<string> rst;
        int key = 0;
        for(int i = 0; i < s.size(); i++){
            if(strs[key = ((key << 3) + (s[i] & 7)) & window]++ == 1)
                rst.push_back(string(s, i - 9, 10));
        }
        return rst;
    }
};
