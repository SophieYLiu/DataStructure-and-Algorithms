// Subsets Problem
// Author: YL

#include<iostream>
#include <vector>
using namespace std;
vector<int> tobin(int d, int l) {
	vector<int> x;
	while (d >= 0 && l>0) {
		x.push_back(d % 2);
		d /= 2;
		l--;
		cout << d << l;
	}
	return x;
}
vector<vector<int> > subsets(vector<int> &nums) {
	// write your code here
	vector<vector<int>> PS;
	vector<int> ss;

	int size = pow(2, nums.size());
	cout << size;
	for (int i = size; i>0; i--) {
		vector<int> temp = tobin(i, nums.size());
		cout << temp.size();
		for (int j = 0;j<temp.size(); j++) {
			if (temp[j] == 1)
				ss.push_back(nums[j]);
		}
		PS.push_back(ss);
	}
}
int main() {
	vector<int> m;
	m.push_back(0);
	vector<vector<int>> temp = subsets(m);

	system("pause");
	return 0;
}