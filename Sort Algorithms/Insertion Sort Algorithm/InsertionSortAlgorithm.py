def insertionSort(nums):
    for i in range(len(nums)):
        j = i
        while j > 0 and nums[j] < nums[j-1]:
            nums[j], nums[j-1] = nums[j-1], nums[j]
            j -= 1

nums = [12, 45, 19, 0, 100, 75, 3, 1]
insertionSort(nums)
print(nums)
