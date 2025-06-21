class Solution {
private:
    static void printVec(vector<int>& nums) {
        bool firstFlag = true;
        for (auto& num : nums) {
            if (not firstFlag) std::cout << ",";
            std::cout << num;
            firstFlag = false;
        }
        std::cout << endl;
    }

public:
    void sortColors(vector<int>& nums) {
        size_t numsSize = nums.size();
        size_t nextRedSlot = 0;
        size_t nextBlueSlot = numsSize - 1;

        for (size_t index = 0; index < numsSize and index <= nextBlueSlot;) {
            //Solution::printVec(nums);
            switch(nums[index]) {
                case 0:
                    nums[index] = nums[nextRedSlot];
                    nums[nextRedSlot] = 0;
                    ++nextRedSlot;
                case 1:
                    ++index;
                    break;
                case 2:
                    nums[index] = nums[nextBlueSlot];
                    nums[nextBlueSlot] = 2;
                    if (nextBlueSlot == 0) return;
                    --nextBlueSlot;
                    break;
            }
        }
    }
};
