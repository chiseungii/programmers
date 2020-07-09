#include <iostream>
using namespace std;

string solution(int a, int b) {
	int days[11] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 };

	int day = 0;
	for (int i = 1; i < a; i++)
		day += days[i - 1];
	day += b - 1;

	switch (day % 7) {
	case 0:
		return "FRI";
	case 1:
		return "SAT";
	case 2:
		return "SUN";
	case 3:
		return "MON";
	case 4:
		return "TUE";
	case 5:
		return "WED";
	case 6:
		return "THU";
	}
}
