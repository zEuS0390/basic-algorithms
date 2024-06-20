def linearSearch(nums, target):
    for i in range(len(nums)):
        if nums[i] == target:
            return i
    return -1

nums = [32, 1, 0, -1, 5, 32, 5, 100]
index = linearSearch(nums, 5)
print(nums)
print(index)
