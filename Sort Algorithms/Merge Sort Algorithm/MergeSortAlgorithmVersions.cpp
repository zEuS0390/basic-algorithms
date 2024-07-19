#include <iostream>
#include <vector>

using namespace std;

void print(const int* arr, int length) {
	cout << "{";
	for (int i = 0; i < length; ++i)
		cout << arr[i] << ((i != length - 1)? ", ": "");
	cout << "}" << endl;
}

void print(const vector<int>& arr) {
	cout << "{";
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << ((i != arr.size() - 1)? ", ": "");
	cout << "}" << endl;
}

/*

   -----------------------

   C-style Array Merge Sort

   -----------------------

*/

void merge(int* arr, int left, int mid, int right) {
	int left_arr_size = mid - left + 1;
	int right_arr_size = right - mid;

	int left_arr[left_arr_size];
	int right_arr[right_arr_size];

	for (int i = 0; i < left_arr_size; ++i)
		left_arr[i] = arr[left + i];

	for (int i = 0; i < right_arr_size; ++i)
		right_arr[i] = arr[mid + 1 + i];

	int arr_ptr = left;
	int left_ptr = 0;
	int right_ptr = 0;

	while (left_ptr < left_arr_size && right_ptr < right_arr_size) {
		if (left_arr[left_ptr] < right_arr[right_ptr])
			arr[arr_ptr++] = left_arr[left_ptr++];
		else 
			arr[arr_ptr++] = right_arr[right_ptr++];
	}

	while (left_ptr < left_arr_size)
		arr[arr_ptr++] = left_arr[left_ptr++];

	while (right_ptr < right_arr_size)
		arr[arr_ptr++] = right_arr[right_ptr++];
}

void mergeSort(int *arr, int left, int right) {
	if (left >= right) return;

	int middle = left + (right - left) / 2;

	mergeSort(arr, left, middle);
	mergeSort(arr, middle + 1, right);

	merge(arr, left, middle, right);
}

/*

   -----------------------

   std::vector<int> Merge Sort (In-Place Array Approach)

   -----------------------

*/

void merge(vector<int>& arr, int left, int mid, int right) {

	int left_arr_size = mid - left + 1;
	int right_arr_size = right - mid;

	vector<int> left_arr(arr.begin() + left, arr.begin() + mid + 1);
	vector<int> right_arr(arr.begin() + mid + 1, arr.begin() + right + 1);

	int arr_ptr = left;
	int left_ptr = 0;
	int right_ptr = 0;

	while (left_ptr < left_arr_size  && right_ptr < right_arr_size) {
		if (left_arr[left_ptr] < right_arr[right_ptr])
			arr[arr_ptr++] = left_arr[left_ptr++];
		else
			arr[arr_ptr++] = right_arr[right_ptr++];
	}

	while (left_ptr < left_arr_size)
		arr[arr_ptr++] = left_arr[left_ptr++];

	while (right_ptr < right_arr_size)
		arr[arr_ptr++] = right_arr[right_ptr++];
}

void mergeSort(vector<int>& arr, int left, int right) {

	if (left >= right) return;

	int middle = left + (right - left) / 2;

	mergeSort(arr, left, middle);
	mergeSort(arr, middle+1, right);

	merge(arr, left, middle, right);
}

/*

   -----------------------

   std::vector<int> Merge Sort (Temporary Arrays Approach)

   -----------------------

*/

vector<int> merge(vector<int> left_arr, vector<int> right_arr) {
	vector<int> result;

	int left_arr_ptr = 0;
	int right_arr_ptr = 0;

	while (left_arr_ptr < left_arr.size() && right_arr_ptr < right_arr.size()) {
		if (left_arr[left_arr_ptr] < right_arr[right_arr_ptr])
			result.push_back(left_arr[left_arr_ptr++]);
		else
			result.push_back(right_arr[right_arr_ptr++]);
	}

	while (left_arr_ptr < left_arr.size())
		result.push_back(left_arr[left_arr_ptr++]);

	while (right_arr_ptr < right_arr.size())
		result.push_back(right_arr[right_arr_ptr++]);

	return result;
}

vector<int> mergeSort(vector<int> arr) {

	if (arr.size() < 2) return arr;

	int middle = arr.size() / 2;

	vector<int> left_arr(arr.begin(), arr.begin() + middle);
	vector<int> right_arr(arr.begin() + middle, arr.end());

	return merge(mergeSort(left_arr), mergeSort(right_arr));
}

// Main function
int main(int argc, char* argv[]) {

	// Using C-style Array Merge Sort
	{
		int arr[] = {10, 32, -1, 100, 15, 0, 2, 22};
		int length = sizeof(arr) / sizeof(arr[0]);
		print(arr, length);
		mergeSort(arr, 0, length-1);
		print(arr, length);
	}

	// Using std::vector<int> Merge Sort (In-Place Array Approach)
	{
		vector<int> arr = {10, 32, -1, 100, 15, 0, 2, 22};
		print(arr);
		mergeSort(arr, 0, arr.size()-1);
		print(arr);
	}

	// Using std::vector<int> Merge Sort (Temporary Arrays Approach)
	{
		vector<int> arr = {10, 32, -1, 100, 15, 0, 2, 22};
		print(arr);
		vector<int> result = mergeSort(arr);
		print(result);
	}

	return 0;
}
