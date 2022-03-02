// https://programmers.co.kr/learn/courses/30/lessons/82612
// 시뮬레이션

using namespace std;

long long solution(int price, int money, int count) {
	long long sum_price = 0;
	for (int i = 1; i <= count; i++)
		sum_price += price * i;

	long long change = sum_price - money;

	return change > 0 ? change : 0;
}
