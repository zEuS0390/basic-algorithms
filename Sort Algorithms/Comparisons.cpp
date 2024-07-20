#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

random_device rd;
mt19937 rng(rd());

void swap(int& num1, int& num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void print(vector<int>& nums, string end = "\n") {
	cout << "[";
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << ((i != nums.size()-1)? ", ":"");
	cout << "]" << end;
}

// Function to maintain heap property (max heap)
// Time Complexity: O(log N)
void heapify(vector<int>& nums, int heap_size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2; // Corrected index for right child

    // Compare left child with largest
    if (left < heap_size && nums[left] > nums[largest])
        largest = left;

    // Compare right child with largest
    if (right < heap_size && nums[right] > nums[largest])
        largest = right;

    // If largest is not the root
    if (largest != index) {
        swap(nums[index], nums[largest]);
        // Recursively heapify the affected sub-tree
        heapify(nums, heap_size, largest);
    }
}

// Function to perform Heap Sort
// Time Complexity: O(N log N)
// Space Complexity: O(1) (in-place)
void heapSort(vector<int>& nums) {
    int length = nums.size();

    // Build Max Heap
    // Start from the last non-leaf node and heapify each node upwards
    for (int i = (length - 1) / 2; i >= 0; --i)
        heapify(nums, length, i);

    // Extract elements one by one from the heap
    for (int i = length - 1; i > 0; --i) {
        // Move current root to end
        swap(nums[0], nums[i]);
        // Call max heapify on the reduced heap
        heapify(nums, i, 0);
    }
}

vector<int> merge(vector<int> left, vector<int> right) {

	vector<int> result;

	int left_index = 0;
	int right_index = 0;

	while (left_index < left.size() && right_index < right.size()) {

		if (left[left_index] < right[right_index]) {
			result.push_back(left[left_index]);
			++left_index; 
		} else {
			result.push_back(right[right_index]);
			++right_index;
		}
	}

	while (left_index < left.size()) {
		result.push_back(left[left_index]);
		++left_index;
	}

	while (right_index < right.size()) {
		result.push_back(right[right_index]);
		++right_index;
	}

	return result;
}

// Merge Sort Algorithm
// Time Complexity: O(N*log(N))
// Space Complexity: O(N)
vector<int> mergeSort(vector<int> nums) {

	if (nums.size() <= 1) return nums;

	int middle = nums.size() / 2;
	vector<int> left(nums.begin(), nums.begin() + middle);
	vector<int> right(nums.begin() + middle, nums.end());

	return merge(
		mergeSort(left), 
		mergeSort(right)
	);
}

// Bubble Sort Algorithm
// Time Complexity: O(N^2)
// Space Complexity: O(1)
void bubbleSort(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 1; j < nums.size() - i; ++j) {
			if (nums[j] < nums[j - 1])
				swap(nums[j], nums[j-1]);
		}
	}
}
 
// Selection Sort Algorithm
// Time Complexity: O(N^2)
// Space Complexity: O(1)
void selectionSort(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		int min_index = i;
		for (int j = i; j < nums.size(); ++j) {
			if (nums[j] < nums[min_index])
				min_index = j;
		}
		swap(nums[i], nums[min_index]);
 	}
}


// Insertion Sort Algorithm
// Time Complexity: O(N^2)
// Space Complexity: O(1)
void insertionSort(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		int j = i;
		while (j > 0 && nums[j] < nums[j - 1]) {
			swap(nums[j], nums[j-1]);
			--j;
		}
	}	
}

vector<int> generate_numbers(int n) {
	vector<int> nums;
	for (int i = 0; i < n; ++i) {
		uniform_int_distribution<int> uid(1, n);
		int random_number = uid(rng);
		nums.push_back(random_number);
	}
	return nums;
}

int main(int argc, char* argv[]) {
	chrono::high_resolution_clock::time_point t1, t2;
	chrono::duration<double> ms_double;

	t1 = chrono::high_resolution_clock::now();
	int n = 50000;
	vector<int> random_numbers = generate_numbers(n);
	t2 = chrono::high_resolution_clock::now();

	ms_double = t2 - t1;
	cout << "'" << n << "' Random Numbers Generation Elapsed Time: " << ms_double.count() << "\n" << endl;

	cout << "Sorting Algorithm\t\tElapsed Time" << endl;

	vector<int> numbers1(random_numbers.begin(), random_numbers.end());
	vector<int> numbers2(random_numbers.begin(), random_numbers.end());
	vector<int> numbers3(random_numbers.begin(), random_numbers.end());
	vector<int> numbers4(random_numbers.begin(), random_numbers.end());
	vector<int> numbers5(random_numbers.begin(), random_numbers.end());

	// Bubble Sort Algorithm
	t1 = chrono::high_resolution_clock::now();
	bubbleSort(numbers1);
	t2 = chrono::high_resolution_clock::now();

	ms_double = t2 - t1;
	cout << "Bubble Sort\t\t\t" << ms_double.count() << endl;

	// Selection Sort Algorithm
	t1 = chrono::high_resolution_clock::now();
	selectionSort(numbers2);
	t2 = chrono::high_resolution_clock::now();

	ms_double = t2 - t1;
	cout << "Selection Sort\t\t\t" << ms_double.count() << endl;

	// Insertion Sort Algorithm
	t1 = chrono::high_resolution_clock::now();
	insertionSort(numbers3);
	t2 = chrono::high_resolution_clock::now();

	ms_double = t2 - t1;
	cout << "Insertion Sort\t\t\t" << ms_double.count() << endl;

	// Merge Sort Algorithm
	t1 = chrono::high_resolution_clock::now();
	numbers4 = mergeSort(numbers4);
	t2 = chrono::high_resolution_clock::now();

	ms_double = t2 - t1;
	cout << "Merge Sort\t\t\t" << ms_double.count() << endl;

	// Heap Sort Algorithm
	t1 = chrono::high_resolution_clock::now();
	heapSort(numbers4);
	t2 = chrono::high_resolution_clock::now();

	ms_double = t2 - t1;
	cout << "Heap Sort\t\t\t" << ms_double.count() << endl;

	cout << endl;
	return 0;
}

