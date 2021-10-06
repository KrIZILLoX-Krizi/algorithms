#include <iostream>
#include <climits>

using namespace std;

void merge(int* arr, int left, int mid, int right)
{
	int ls_size = mid-left+1;
	int rs_size = right-mid;

	int l[ls_size+1];
	int r[rs_size+1];

	r[rs_size] = INT_MAX;
	l[ls_size] = INT_MAX;

	for (int i = 0; i < mid-left+1; ++i) {
		l[i] = arr[i+left];
	}
	for(int i = 0; i < right-mid; ++i) {
		r[i] = arr[i+mid+1];
	}
	
	int li, ri;
	li = ri = 0;
	while (left <= right) {
		if(l[li] < r[ri]) {
			arr[left] = l[li];
			++li;
		}
		else {
			arr[left] = r[ri];
			++ri;
		}
		++left;
	}

	return;
}

void mergesort(int* arr, int left, int right)
{
	if(left == right) return;

	int mid = left + (right - left) / 2;

	mergesort(arr, left, mid);
	mergesort(arr, mid+1, right);
	merge(arr, left, mid, right);

	return;
}

int main(void)
{
	int size = 20;

	int arr[20] = {9,8,7,6,5,4,3,2,1,0,11,22,33,44,55,66,77,88,99,101};

	mergesort(arr, 0, size-1);

	for(int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}