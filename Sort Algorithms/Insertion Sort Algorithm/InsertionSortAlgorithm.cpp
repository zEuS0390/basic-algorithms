#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		int j = i;
		while (j > 0 && nums[j] < nums[j - 1]) {
			int temp = nums[j - 1];
			nums[j - 1] = nums[j];
			nums[j] = temp;
			--j;
		}
	}	
}

void print(vector<int>& nums) {
	cout << "[";
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << ((i != nums.size()-1)? ", ":"");
	cout << "]" << endl;
}

int main(int argc, char* argv[]) {
	vector<int> nums = {25, 32, 12, 1, 0, 45, -2, 5};
	print(nums);
	insertionSort(nums);
	print(nums);
	return 0;
}
