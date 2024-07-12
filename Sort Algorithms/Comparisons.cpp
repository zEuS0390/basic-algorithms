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

	cout << endl;
	return 0;
}

