#include <vector>
#include <iostream>

#include <random>

using namespace std;

// Merge Sort Algorithm
// Time Complexity: O(N*log(N))
// Space Complexity: O(N)

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

int main(int argc, char* argv[]) {
	random_device rd;
	mt19937 rng(rd());

	// vector<int> nums = {32, 19, 61, -4, 5, 100, 41, 82, 1, 5, 25, 15};
	vector<int> nums;

	for (int i = 0; i < 500; ++i) {
		uniform_int_distribution<int> uid(1, 500);
		int random_number = uid(rng);
		nums.push_back(random_number);
	}

	print(nums);
	vector<int> sorted = mergeSort(nums);
	print(sorted);
	return 0;
}

