#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 1; j < nums.size() - i; ++j) {
			if (nums[j] < nums[j - 1]) {
				int temp = nums[j];
				nums[j] = nums[j - 1];
				nums[j - 1] = temp;
			}
		}
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
	bubbleSort(nums);
	print(nums);
	return 0;
}
