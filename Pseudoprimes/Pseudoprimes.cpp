#include <iostream>

int baseTwo(int a, int b) {
	int num = 1;
	for (int i = 0; i < a; ++i)
		num = (num << 1) % b;
	return num;
}

bool isComposite(int a) {
	if (a > 2) {
		for (int i = 2; i < a; i++) {
			if (a % i == 0) return true;
		}
	}
	return false;
}

int main() {
	int limit;
	std::cout << "Enter upper limit: ";
	std::cin >> limit;
	std::cout << "All pseudoprimes to the base 2 that do not exceed " << limit << " are:" << std::endl;

	for (int i = 2; i <= limit; i++) {
		if (isComposite(i) && baseTwo(i - 1, i) == 1)
			std::cout << i << std::endl;
	}
	std::cout << "Done!" << std::endl;

	std::cin.ignore(1, '\n');
	std::cin.get();
}
