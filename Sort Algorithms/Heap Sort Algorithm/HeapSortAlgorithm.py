# Heapify (Maintain Heap Property)
def heapify(arr, heap_size, index):
    """
    Maintains the heap property in the subtree rooted at index 'index'.
    Args:
    - arr: List of integers, representing the array to be sorted
    - heap_size: Integer, size of the heap
    - index: Integer, root index of the subtree to be heapified
    """
    largest = index
    left = 2 * index + 1    # Left child index
    right = 2 * index + 2   # Right child index

    # Check if left child exists and is greater than the current largest
    if left < heap_size and arr[left] > arr[largest]:
        largest = left

    # Check if right child exists and is greater than the current largest
    if right < heap_size and arr[right] > arr[largest]:
        largest = right

    # If the largest element is not the root, swap them and heapify the affected subtree
    if index != largest:
        arr[index], arr[largest] = arr[largest], arr[index]
        heapify(arr, heap_size, largest)

# Heap Sort Algorithm
def heapSort(arr):
    """
    Sorts the array 'arr' in ascending order using the heap sort algorithm.
    Args:
    - arr: List of integers, representing the array to be sorted
    """
    length = len(arr)

    # Build Max Heap
    # Start from the last non-leaf node and heapify down to the root
    for i in range((length-1)//2, -1, -1):
        heapify(arr, length, i)

    # Extract elements one by one from the heap
    # Move the root (max element) to the end of the array and heapify the reduced heap
    for i in range(length-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

# Example usage:
arr = [74, 34, 92, 74, 73, 87, 41, 25, 63, 12, 51, 39, 10, 37, 15, 33, 85, 77, 22, 44, 14, 91, 26, 65, 97, 52, 0, 85, 
       14, 24, 40, 20, 86, 86, 79, 50, 24, 83, 26, 30, 27, 1, 87, 69, 2, 14, 88, 8, 12, 29]

print("Original array:")
print(arr)

heapSort(arr)

print("Sorted array:")
print(arr)
