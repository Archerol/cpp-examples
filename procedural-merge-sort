#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void printVector(vector<int>& nums) {

	int size = nums.size();

	cout << "[";

	if (size > 0) {
		cout << nums[0];
	}

	for (int i = 1; i < (int)nums.size(); i++) {

		cout << ", " << nums[i];
	}

	cout << "]" << endl;
}

void mergeArrays(vector<int>*& _nums, int start, int middle, int end) {

	int i = start;
	int j = middle;
	int r = 0;

	vector<int> nums = *_nums;

	int size = nums.size();

	vector<int> result(size);

	while (r < size) {

		if (r < i && r < j || i >= middle && j > end) {
			result[r] = nums[r];
			r++;
			continue;
		}

		if (j > end || i < middle && nums[i] < nums[j]) {
			result[r] = nums[i];
			i++;
		}
		else {
			result[r] = nums[j];
			j++;
		}

		r++;
	}

	*_nums = result;
}


void sort(vector<int>*& nums, int start, int end) {

	if (start == end) {
		return;
	}

	int middle = (int)round(floor(start + end) / 2);

	sort(nums, start, middle - 1);
	sort(nums, middle, end);

	mergeArrays(nums, start, middle, end);

}






int main()
{
	vector<int> vec(0);

	for (int i = 0; i < 1000; i++) {
		vec.push_back(rand() % 10000);
	}

	vector<int>* pointer = &vec;

	sort(pointer, 0, vec.size() - 1);

	printVector(vec);
}
