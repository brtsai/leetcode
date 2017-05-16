class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        for(int i = 0; i < s.size(); i++){
            int contender = lengthOfLongestSubstringFromIndex(i,s);
            if(contender > longest) {
                longest = contender;
            }
        }
        return longest;
    }
    
    int lengthOfLongestSubstringFromIndex(int i, string s) {
        unordered_map<char, char> charsEncountered;
        int count = 0;
        if(i >= s.size()){
            return -1;
        }
        
        for(auto itor = s.begin()+i; itor!=s.end(); itor++){
            if(charsEncountered.find(*itor) == charsEncountered.end()){
                count++;
                charsEncountered.insert({*itor,*itor});
            } else{
                break;
            }
        }
        
        return count;
        
    }
};
