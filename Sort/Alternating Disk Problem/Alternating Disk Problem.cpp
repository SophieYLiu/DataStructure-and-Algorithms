/*Alternating Disks Problem

1.  Author: YL
2.  Problem statement: Given 2n alternating disks (light, dark) the program reads the number of single color disks                                                                                                                                    
 (light or dark), arranges the disks in the correct order and outputs the number of swaps                                                                                                                               
 INPUT: a positive integer n and a list of 2n disks of alternating colors dark-light, starting with dark                                                                                                                                                                        
 OUTPUT: a list of 2n disks, the first n disks are light, the next n disks are dark,                                                                                                                               
 and an integer m representing the number of moves to move the dark ones after the light ones

3.  NOTE: I will use 2 algorithms in 1 source code.
4.  Algorithms explanation:
 - ALG 1> left to right:
scan from the leftmost, compare with the immediate right one and do swap if necessary
when reaches the end, comes back to the leftmost
repeat until it is sorted
 - ALG 2>: lawnmower:
scan from the leftmost, compare with the immediate right one and do swap if necessary
when reaches end, start from the end moving backwards, compare with the immediate left one
and do swap if necessary
repeat until it is sorted*/
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//void print(char* arr, int n) {
//	for (int i = 0; i < n; i++)
//		cout << arr[i] << " ";
//}
//
//int main()
//{
//	int n, m, confirm_code = 0;//n is the number of single colored, m is the nber of swaps
//	char disk[20];
//	do {
//		cout << "Enter the number of the single color disks (light or dark): ";
//		cin >> n;
//		cout << endl;
//		cout << "Initial configuration\nList of disks\n";
//		//intialization the alternating values
//		for (int i = 0; i < n; i++) {
//			disk[2 * i] = 'd';
//			disk[2 * i + 1] = 'l';
//		}
//		//print out the disk 
//		for (int i = 0; i < 2 * n; i++)
//			cout << disk[i] << " ";
//		cout << endl;
//		m = 0; //reset m before entering in the loop
//		//SORTING I begins here----Right to left algorithm
//		//for (int j = 0; j < n; j++) {
//		//	for (int i = 0; i < 2 * n; i++) {
//		//		if (disk[i] == 'd' && disk[i+1] == 'l'){
//		//			swap(disk[i], disk[i+1]);
//		//                       m++;}
//		//	}
//		//}
//		//SORTING II begins here---lawnmover
//		for (int j = 0; j < n; j++) {
//			for (int i = 0; i < 2 * n; i++) {
//				if (disk[i] == 'd' && disk[i + 1] == 'l') {
//					swap(disk[i], disk[i + 1]);
//					m++;
//				}
//			}
//			for (int i = n - 1; i >= 0; i--) {
//				if (disk[i] == 'l'&&disk[i - 1] == 'd') {
//					swap(disk[i], disk[i - 1]);
//					m++;
//				}
//			}
//		}
//		cout << "After moving darker ones to the right\nList of disks\n";
//		//print out the sorted disk
//		print(disk, 2 * n);
//		cout << endl << "Number of Swaps is " << m << endl;
//		cout << "Do you want to test another round? (Press 1 for Yes and 0 for No)";
//		cin >> confirm_code;
//		if (confirm_code != 0 && confirm_code != 1)
//			exit;
//	} while (confirm_code == 1);
//		system("pause");
//		return 0;
//	}
/*ALG 1> left to right:
scan from the leftmost, compare with the immediate right one and do swap if necessary
when reaches the end, comes back to the leftmost
repeat until it is sorted
*/
#include<iostream>
#include<algorithm>
using namespace std;

void print(char* arr, int n) {
	for (int i = 0; i < 2 * n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int n, m = 0;//n is the number of single colored, m is the nber of swaps
	char disk[100];
	//print out welcome message
	cout << "CPSC 335-x – Programming Assignment #1: The alternating disks problem: left to right algorithm\n";
//=============================== 1ST : left to right ==============================================
		cout << "Example # 1"  << "\nEnter the number of the single color disks (light or dark): ";
		cin >> n;
		cout << endl;
		cout << "Initial configuration...\nList of disks\n";

		//intialization the alternating values
		for (int i = 0; i < n; i++) {
			disk[2 * i] = 'd';
			disk[2 * i + 1] = 'l';
		}
		//print out the disk 
		print(disk, n);
		//SHUFFLING
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < 2 * n; i++) {
				if (disk[i] == 'd' && disk[i + 1] == 'l') {
					swap(disk[i], disk[i + 1]);
					m++;
				}
			}
		}

		cout << "After moving darker ones to the right\nList of disks\n";
		//print out the sorted disk
		print(disk, n);
		//print the number of swap
		cout << "Number of Swaps is " << m << endl;
//=============================== 2ND: Lawnmower ================================================
		cout << "Example #2"  << "\n Enter the number of the single color disks (light or dark): ";
		cin >> n;
		m = 0; //reset number of swaps
		cout << endl;
		cout << "Initial configuration\nList of disks\n";
        //intialization the alternating values
		for (int i = 0; i < n; i++) {
			disk[2 * i] = 'd';
			disk[2 * i + 1] = 'l';
		}
		//print out the disk 
		print(disk, n);

		//SHUFFLING
		for (int j = 0; j < n / 2 + 1; j++) {
			for (int i = 0; i < 2 * n; i++) {
				if (disk[i] == 'd' && disk[i + 1] == 'l') {
					swap(disk[i], disk[i + 1]);
					m++;
				}
			}
			for (int i = 2 * n - 1; i >= 0; i--) {
				if (disk[i] == 'l' && disk[i - 1] == 'd') {
					swap(disk[i], disk[i - 1]);
					m++;
				}
			}
		}
		cout << "After moving darker ones to the right\nList of disks\n";
		//print out the sorted disk
		print(disk, n);

		//print the number of swap
		cout << "Number of Swaps is " << m << endl;
		system("pause");
	return 0;
}
