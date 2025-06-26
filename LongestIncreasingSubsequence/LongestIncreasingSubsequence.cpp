class Solution {
private:
    static string coordsToString(const int x, const int y) {
        return std::to_string(x) + "," + std::to_string(y);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> sortedNums = nums;
        std::sort(sortedNums.begin(), sortedNums.end());

        std::unordered_map<string, int> memo;

        int numsSize = nums.size();
        for (int rRow = numsSize - 1; rRow >= 0; --rRow) {
            for (int rCol = numsSize - 1; rCol >= 0; --rCol) {
                int currMin = sortedNums[rRow];
                if (rRow == numsSize - 1) {
                    memo[Solution::coordsToString(currMin, rCol)] = 0;
                    continue;
                }
                bool canTake = nums[rCol] > sortedNums[rRow];
                if (rCol == numsSize - 1) {
                    memo[Solution::coordsToString(currMin, rCol)] = canTake ? 1 : 0;
                    continue;
                }

                int opt = memo[Solution::coordsToString(currMin, rCol + 1)];
                if (canTake) opt = std::max(1 + memo[Solution::coordsToString(nums[rCol], rCol + 1)], opt);
                memo[Solution::coordsToString(currMin, rCol)] = opt;
            }
        }

        std::vector<int> canTakeRow(numsSize, 0);
        canTakeRow[numsSize - 1] = 1;
        for (int rIndex = numsSize - 2; rIndex >= 0; --rIndex) {
            canTakeRow[rIndex] = max(1 + memo[Solution::coordsToString(nums[rIndex], rIndex + 1)], canTakeRow[rIndex + 1]);
        }

        return canTakeRow[0];
    }
};

/**
  opt[currMin, i] = 
    if (canTakeCurrNum) {
        max(1 + opt[nums[i], i+1], opt[currMin, i+1])
    } else {
        opt[currMin, i+1]
    }
*/

/**
    [2, 5, 3, 4]
     0, 1, 2, 3
-inf 3, 2, 2, 1
   2 2, 2, 2, 1
   3 1, 1, 1, 1
   4 0, 0, 0, 0
   5 0, 0, 0, 0
*/
