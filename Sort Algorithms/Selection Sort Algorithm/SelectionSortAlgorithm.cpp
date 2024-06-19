#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		int min_index = i;
		for (int j = i; j < nums.size(); ++j) {
			if (nums[j] < nums[min_index])
				min_index = j;
		}
		int temp = nums[i];
		nums[i] = nums[min_index];
		nums[min_index] = temp;
 	}
}

void print(vector<int>& nums) {
	cout << "[";
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << ((i != nums.size() - 1)? ", ":"");
	cout << "]" << endl;
}

int main(int argc, char* argv[]) {
	vector<int> nums = {32, -5, 0, 43, 72, 8, 9, 1, 32};
	print(nums);
	selectionSort(nums);
	print(nums);
	return 0;
}
