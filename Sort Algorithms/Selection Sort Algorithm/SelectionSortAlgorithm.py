def selectionSort(nums):
    for i in range(len(nums)):
        min_index = i
        for j in range(i, len(nums)):
            if nums[j] < nums[min_index]:
                min_index = j
        nums[i], nums[min_index] = nums[min_index], nums[i]

nums = [41, 32, 16, 0, 1, 47, 100, 329, 50]
selectionSort(nums)
print(nums)
