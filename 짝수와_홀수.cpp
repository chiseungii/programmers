#include <iostream>
using namespace std;

string solution(int num) {
	if (num % 10 % 2) return "Odd";
	else return "Even";
}
