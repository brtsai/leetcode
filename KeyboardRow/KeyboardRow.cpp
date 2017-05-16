class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> toReturn;
        string row1 = "qwertyuiopQWERTYUIOP";
        string row2 = "asdfghjklASDFGHJKL";
        string row3 = "zxcvbnmZXCVBNM";
        int count = 0;
        for(auto itor = words.begin(); itor != words.end(); ++itor) {
            fprintf(stdout, "%s\n", itor->c_str());
            if(itor->find_first_of(row1) != string::npos) count++;
            if(itor->find_first_of(row2) != string::npos) count++;
            if(itor->find_first_of(row3) != string::npos) count++;
            if(count < 2) toReturn.push_back(*itor);
            count = 0;
        }
        
        return toReturn;
    }
};
