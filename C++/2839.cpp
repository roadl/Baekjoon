#include <iostream>

int countSugarBag(int n)
{
	if (n == 3 || n == 5)
		return 1;
	else if (n < 3 || n == 4)
		return -1;

	int n5, n3;

	n5 = countSugarBag(n - 5);

	if (n5 != -1)
		return 1 + n5;

	n3 = countSugarBag(n - 3);

	if (n3 != -1)
		return 1 + n3;

	return -1;
}

int main()
{
	int n;

	std::cin >> n;

	std::cout << countSugarBag(n) << std::endl;

	return 0;
}