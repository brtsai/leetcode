class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> originSet = {{}};
        for (std::vector<int>::iterator itor = nums.begin(); itor != nums.end(); ++itor) {
            std::vector<std::vector<int>> subSetsWithNum;
            int num = *itor;
            
            for (std::vector<std::vector<int>>::iterator originSetItor = originSet.begin(); originSetItor != originSet.end(); ++originSetItor) {
                std::vector<int> subset = *originSetItor;
                std::vector<int> subsetCopy = subset;
                subsetCopy.push_back(num);
                subSetsWithNum.push_back(subsetCopy);
            }

            originSet.insert(originSet.end(), subSetsWithNum.begin(), subSetsWithNum.end());
        }

        return originSet;
    }
};
