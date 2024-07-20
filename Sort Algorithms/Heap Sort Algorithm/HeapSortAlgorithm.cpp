#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::ostream;

// Function to swap two integers
void swap(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

// Function to maintain heap property (max heap)
// Time Complexity: O(log N)
void heapify(vector<int>& arr, int heap_size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Find largest among root, left child, and right child
    if (left < heap_size && arr[left] > arr[largest])
        largest = left;

    if (right < heap_size && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and recursively heapify affected subtree
    if (largest != index) {
        swap(arr[index], arr[largest]);
        heapify(arr, heap_size, largest);
    }
}

// Function to perform Heap Sort
// Time Complexity: O(N log N)
// Space Complexity: O(1) (in-place)
void heapSort(vector<int>& arr) {
    // Build max heap
    for (int i = (arr.size() - 1) / 2; i >= 0; --i) {
        heapify(arr, arr.size(), i);
    }

    // Extract elements from heap one by one
    for (int i = arr.size() - 1; i >= 0; --i) {
        // Move current root to end (largest element to the end)
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Overloading << operator to print vector
ostream& operator<<(ostream& os, const vector<int>& arr) {
    os << "{";
    for (int i = 0; i < arr.size(); ++i)
        os << arr[i] << ((i != arr.size()-1) ? ", " : "");
    os << "}";
    return os;
}

// Main function
int main(int argc, char* argv[]) {
    // Example array
    vector<int> arr = {70, 33, 65, 71, 4, 61, 78, 36, 63, 33, 12, 24, 3, 28, 21, 88, 2, 79, 40, 12};
    
    // Print original array
    cout << "Original array: " << arr << endl;

    // Perform Heap Sort
    heapSort(arr);

    // Print sorted array
    cout << "Sorted array: " << arr << endl;

    return 0;
}
