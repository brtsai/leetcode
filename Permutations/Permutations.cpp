class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int numsSize = nums.size();
        if (numsSize == 1) return {{nums[0]}};
        std::vector<std::vector<int>> permutations;

        for (size_t index = 0; index < numsSize; ++index) {
            std::vector<int> remainingChoices(nums.begin(), nums.begin() + index);
            remainingChoices.insert(remainingChoices.end(), nums.begin() + index + 1, nums.end());
            std::vector<std::vector<int>> subPermutations = permute(remainingChoices);
            size_t subPermutationsSize = subPermutations.size();
            for (size_t subIndex = 0; subIndex < subPermutationsSize; ++subIndex) {
                std::vector<int>* subPermutation = &subPermutations[subIndex];
                std::vector<int> finalSubPermutation = {nums[index]};
                finalSubPermutation.insert(finalSubPermutation.end(), subPermutation->begin(), subPermutation->end());
                permutations.push_back(finalSubPermutation);
            }
        }

        return permutations;
    }
};
