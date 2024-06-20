def bubbleSort(nums):
    for i in range(len(nums)):
        for j in range(len(nums)-i-1):
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1], nums[j]

nums = [42, 62, 8, 32, 10, -1, 0, 63, 100, 37]
bubbleSort(nums)
print(nums)

