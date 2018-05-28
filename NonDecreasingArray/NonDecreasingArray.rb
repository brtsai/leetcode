def check_possibility(nums)
    count = 0
    left = 0
    right = 0
    (0...nums.length - 1).each do |index|
        if nums[index] > nums[index + 1]
            left = index
            right = index + 1
            count += 1 
        end
    end
    return false if count > 1
    return true if count < 1
    withoutLeft = nums[0...left] + nums[left+1..-1]
    withoutRight = nums[0...right] + nums[right+1..-1]
    isNonDecreasing?(withoutLeft) || isNonDecreasing?(withoutRight)
end

def isNonDecreasing?(nums)
    (0...nums.length - 1).each do |index|
        return false if nums[index] > nums[index+1]
    end
    true
end
