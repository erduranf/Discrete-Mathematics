#include <iostream>

class Alg5 {
private:
	int x, power, integer, mod, pow, count;
	int* array;

public:
	Alg5() {
		userInput();
		baseTwo(pow);
		algorithm(integer, mod, pow);
	}

	void userInput() {
		std::cout << "Enter an integer: ";
		std::cin >> integer;
		std::cout << "Enter the power value: ";
		std::cin >> pow;
		std::cout << "Enter the mod value: ";
		std::cin >> mod;
		std::cout << std::endl;
	}

	void baseTwo(int num) {
		int temp, rem = 0;
		temp = num;
		count = 0;

		for (int i = 0; num > 0; i++) {
			num /= 2;
			count++;
		}

		array = new int[count];

		for (int i = 0; temp > 0; i++) {
			rem = temp % 2;
			array[i] = rem;
			temp /= 2;
		}
	}

	void algorithm(int integer, int mod, int pow) {
		int xTemp = 0, powTemp = 0;
		x = 1;
		power = takeMod(integer, mod);

		for (int i = 0; i < count; i++) {
			xTemp = x, powTemp = power;
			if (array[i] == 1) {
				x = takeMod((x * power), mod);
				power = takeMod((power * power), mod);
				if (i == count - 1) {
					std::cout << "i = " << i << "; Because a" << i << " = 1, we find that x = (" << xTemp
						<< " . " << powTemp << ") mod " << mod << " = " << x << "." << std::endl;
				}
				else std::cout << "i = " << i << "; Because a" << i << " = 1, we find that x = ("
						<< xTemp << " . " << powTemp << ") mod " << mod << " = " << x << " and power = " 
						<< powTemp << "^2 mod " << mod << " = " << powTemp * powTemp << " mod " << mod 
						<< " = " << power << ";" << std::endl;
			}
			else if (array[i] == 0) {
				power = takeMod((power * power), mod);
				std::cout << "i = " << i << "; Because a" << i << " = 0, we have x = " << x << " and power = "
					<< powTemp << "^2 mod " << mod << " = " << powTemp * powTemp << " mod " << mod << " = " 
					<< power << ";" << std::endl;
			}
		}

		std::cout << std::endl << "According to Algorithm 5, " << integer << "^" << pow << " mod " 
			<< mod << " = " << x << "." << std::endl;
	}

	int takeMod(int a, int b) {
		return a % b;
	}

	~Alg5() {
		delete[] array; 
	}
};

int main() {
	Alg5 x1;
	std::cin.ignore(1, '/n');
	std::cin.get();
}