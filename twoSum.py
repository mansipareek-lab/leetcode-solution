class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        n = len(nums)

        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]

        return [-1, -1]  # no solution found



sol = Solution()

# Test case 1
nums = [2, 7, 11, 15]
target = 9
print("Test 1:", sol.twoSum(nums, target))   # Expected: [0, 1]

# Test case 2
nums = [3, 2, 4]
target = 6
print("Test 2:", sol.twoSum(nums, target))   # Expected: [1, 2]

# Test case 3
nums = [3, 3]
target = 6
print("Test 3:", sol.twoSum(nums, target))   # Expected: [0, 1]

# Test case 4 — no solution
nums = [1, 2, 3]
target = 10
print("Test 4:", sol.twoSum(nums, target))   # Expected: [-1, -1]