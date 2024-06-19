#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int>& nums, int target) {
	for (int i = 0; i < nums.size(); ++i) {
		if (target == nums[i])
			return i;
	}
	return -1;
}

void print(vector<int>& nums) {
	cout << "[";
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << ((i != nums.size()-1)? ", ":"");
	cout << "]" << endl;
}

int main(int argc, char* argv[]) {
	vector<int> nums = {32, 61, 40, 19, 20, 75, 36, -2};
	int target = 20;
	int index = linearSearch(nums, target);
	print(nums);
	cout << "target: " << target << endl;
	cout << "index: " << index << endl;
	return 0;
}
