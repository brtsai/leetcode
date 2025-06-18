class Solution {
private:
    // pass by copy for inplace sort
    string getKey(string word) {
        std::sort(word.begin(), word.end());
        return word;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> anagramMappings;

        for(std::vector<string>::iterator itor = strs.begin(); itor != strs.end(); ++itor) {
            string& word = *itor;
            string key = getKey(word);
            std::unordered_map<string, vector<string>>::iterator correspondingGroup = anagramMappings.find(key);

            if (correspondingGroup == nullptr) {
                std::vector<string> group;
                anagramMappings[key] = group;
                correspondingGroup = anagramMappings.find(key);
            }
            correspondingGroup->second.push_back(word);
        }

        std::vector<vector<string>> anaGroups;
        for (std::unordered_map<string, vector<string>>::iterator itor = anagramMappings.begin(); itor != anagramMappings.end(); ++itor) {
            anaGroups.push_back(itor->second);
        }

        return anaGroups;
    }
};
