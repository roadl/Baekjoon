#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

// case 1: 걸어가는게 빠름 (T > D)
// case 2: 여러번 뛰어 가는게 빠름
// case 3: 뛰고 걸어가기

// 일단 가는데 몇번 뛰어야 하는지 계산
// N번 뛰어야 한다 -> N-1번 뛰고 걷는것과 비교하여 결과 출력?
// 바로 뛰는 거리가 남은거리보다 멀 경우는 따로 처리
// 뛰고 돌아가는거, 그냥 걸어가는거, 두번 뛰는거

void jump(double *distance, double *time, int D, int T)
{
	*distance -= D;
	*time += T;
}

void solve(int X, int Y, int D, int T)
{
	double distance = sqrt(pow(X, 2) + pow(Y, 2));
	double time = 0;
	
	//cout << "distance: " << distance << endl;

	if (T > D)
		time = distance;
	else if (distance < D) {
		double temp = D - distance + T;
		if (temp < distance && temp < 2 * T)
			time = temp;
		else if (distance < 2 * T)
			time = distance;
		else
			time = 2 * T;
	}
	else {
		while (distance >= D)
			jump(&distance, &time, D, T);
		if (distance < T)
			time += distance;
		else
			time += T;
	}
	cout << setprecision(20) << time << endl;
}

int main()
{
	int X, Y, D, T;

	cin >> X >> Y >> D >> T;

	solve(X, Y, D, T);

	return 0;
}