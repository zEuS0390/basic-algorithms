def merge(nums1, nums2):

    merged = []

    nums1_index = 0
    nums2_index = 0

    while nums1_index < len(nums1) and nums2_index < len(nums2):
        if nums1[nums1_index] < nums2[nums2_index]:
            merged.append(nums1[nums1_index])
            nums1_index += 1
        else:
            merged.append(nums2[nums2_index])
            nums2_index += 1

    while nums1_index < len(nums1):
        merged.append(nums1[nums1_index])
        nums1_index += 1

    while nums2_index < len(nums2):
        merged.append(nums2[nums2_index])
        nums2_index += 1

    return merged

def mergeSort(nums):

    if len(nums) <= 1: return nums

    middle = len(nums) // 2

    left = nums[:middle]
    right = nums[middle:]

    return merge(mergeSort(left), mergeSort(right))

nums = [100, 5, 29, 32, 0, 51, -1]
merged = mergeSort(nums)
print(merged)
