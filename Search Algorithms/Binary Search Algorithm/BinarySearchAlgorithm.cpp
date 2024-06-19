#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int middle = left + (right - left) / 2;

		if (nums[middle] == target)
			return middle;

		if (nums[middle] < target)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return left;
}

void print(vector<int>& nums) {
	cout << "[";
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << ((i != nums.size() - 1)? ", ":"");
	cout << "]" << endl;
}

int main(int argc, char* argv[]) {
	vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
	print(nums);
	int index = binarySearch(nums, 9);
	cout << index << endl;
	return 0;
}
