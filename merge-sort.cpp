#include <iostream>
#include <vector>

using namespace std;



void printVector(vector<int>& nums) {

	int size = nums.size();

	cout << "[";

	if (size > 0) {
		cout << nums[0];
	}

	for (int i = 1; i < (int) nums.size(); i++) {

		cout << ", " << nums[i];
	}

	cout << "]" << endl;
}

vector<int> sliceVector(vector<int>& nums, int start, int end) {

	return vector<int>(nums.begin() + start, nums.begin() + end);
}

vector<int> mergeArrays(vector<int>& nums1, vector<int>& nums2) {

	int i = 0;
	int j = 0;
	int r = 0;

	int size1 = nums1.size();
	int size2 = nums2.size();

	vector<int> result(size1 + size2);

	while (i < size1 || j < size2) {

		if (j >= size2 || i < size1 && nums1[i] < nums2[j]) {
			result[r] = nums1[i];
			i++;
		}
		else {
			result[r] = nums2[j];
			j++;
		}

		r++;
	}

	return result;

}


vector<int> sort(vector<int>& nums) {

	vector<int> result;

	if (nums.size() == 1) {

		return vector<int>(1, nums[0]);
	}

	int middle = (int) round(floor(0 + nums.size()) / 2);

	vector<int> left = sliceVector(nums, 0, middle);
	left = sort(left);

	vector<int> right = sliceVector(nums, middle, nums.size());
	right = sort(right);

	return mergeArrays(left, right);
}






int main()
{
	vector<int> vec(10000);

	for (int i = 0; i < 10000; i++) {
		vec.push_back(rand() % 100000);
	}

	vector<int> sorted = sort(vec);

	printVector(sorted);
}
