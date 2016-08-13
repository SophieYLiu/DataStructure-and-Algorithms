// Largest Num
// Author: YL

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int largestNum(int x) {
	//separate digits
	vector<int> rdigits;
	int r = 0;
	while (x > 10) {
		r = x % 10;
		x /= 10;
		rdigits.push_back(r);
	}
	rdigits.push_back(x);
	int len = rdigits.size();
	//reverse back digits
	vector<int> digits;
	for (int i = len - 1; i >= 0; i--) {
		digits.push_back(rdigits[i]);
	}
	bool remove = false, repeat = false;
	int i = 0;
	int count = 0;
	int w;
	while (i < len-1 && !remove) {
		while (digits[i] == digits[i + 1]) {
			++i;
			repeat = true;
			count++;
		}
		if (count == 1)
			w = i;
		//delete
		if (repeat && digits[i] <= digits[i + 1] && digits[i+1] == digits[i+1+1]) {
			vector<int>::iterator pos = find(digits.begin(), digits.end(), digits[i]);
			if (pos != digits.end()) {
				digits.erase(pos);
				remove = true;
				break;
			}
		}
		//update
		++i;
		repeat = false;
	}
	if (count == 1)
	{
		vector<int>::iterator pos = find(digits.begin(), digits.end(), digits[w]);
		digits.erase(pos);
	}
	//put back together
	int res = 0;
	for (int i = 0;i < len - 1; i++) {
		res += static_cast<int>(digits[i] * pow(10, (len - i - 2)));
	}
	return res;

}
int main() {
	int x;
	cout << "input: ";
	cin >> x;
	cout << endl;

	cout << largestNum(x);
	system("pause");
	return 0;
	
}