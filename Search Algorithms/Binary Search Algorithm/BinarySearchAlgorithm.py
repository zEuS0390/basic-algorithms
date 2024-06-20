def binarySearch(nums, target):
    left = 0
    right = len(nums) - 1

    while left <= right:
        middle = left + (right - left) // 2

        if nums[middle] == target:
            return middle

        if nums[middle] < target:
            left = middle + 1
        else:
            right = middle - 1

    return left

nums = [32, 42, 55, 89, 62, 88, 99, 100, 120]
index = binarySearch(nums, 1000)
print(index)
