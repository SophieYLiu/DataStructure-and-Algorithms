// Image Directory
// Author: YL

#include<iostream>
#include<string>
#include<vector>
using namespace std;
//check if a image
bool isImage(string s) {
	int pos = s.find('.');
	string s1 = s.substr(pos);
	if (s1 == ".jpeg" || s1 == ".png" || s1 == ".gif")
		return true;
	else
		return false;
}
//get the level length (c is the # of spaces + 1)
int lookup(int c) {
	int len = 0;
	int curr = 5;//level 1 is "/dir1"
	while (c != 0) {
		len += curr;
		c--;
		curr++;
	}
	return len;
}

int main() {
	string str;
	str = "dir1\n dir11\n dir12\n  picture.jpeg\n  dir121\n  file1.txt\ndir2\n file2.gif";

	string temp;
	bool found_file = false;
	int level_len = 0;
	//detect image
	int i = 0;
	while (i < str.length()) {
		//get each dir and saved in temp
		while (i<str.length() && str[i] != '\n') {
			temp += str[i];
			if (str[i] == '.')
				found_file = true;
			i++;
		}
		//test if an image then get length
		if (found_file && isImage(temp))
		{
			int count = 0; //# of prefix spaces
			for (int k = 0; k < temp.length(); k++) {
				if (temp[k] == ' ')
					count++;
				else
					break;
			}
			level_len += lookup(count);
		}
		//updates
		i++;
		temp = "";
		found_file = false;
	}
	cout << level_len;
	system("pause");
	return 0;


	
}