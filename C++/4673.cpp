#include <iostream>

bool arr[10001] = { 0, };

void Check(int n) 
{
	int num = n;

	while (n != 0) {
		num += n % 10;
		n /= 10;
	}
	
	if (num <= 10000)
		arr[num] = true;

	//std::cout << num << std::endl;
}

int main()
{
	for (int i = 0; i <= 10000; i++) {
		Check(i);
	}

	for (int i = 0; i <= 10000; i++) {
		if (!arr[i])
			std::cout << i << std::endl;
	}

	return 0;
}