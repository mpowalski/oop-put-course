#include "Password.h"
#include <iostream>
#include <stdexcept>
#include <time.h>
Password::Password() { length = 0; memory[0] = { '\0' }; }
Password::Password(int l) { length = l; memory[0] = { '\0' }; }
Password::~Password() = default;
class Password* Password::changeLength(int nl) {
	if (std::cin.fail() || nl < 1 || nl > 100) {
		if (std::cin.fail() == true) {
			int inv = 0;
			while ((inv = getchar()) != '\n' && inv != EOF);
			std::cin.clear();
			throw std::invalid_argument(" - - - - - - - - - - - - - - - - | Error: length must be a number!");
		}
		if (std::cin.fail() == false)
			throw std::invalid_argument(" - - - - - - - - - - - - - - - - | Error: length must be from 1 to 100!");
	}
	int inv = 0;
	while ((inv = getchar()) != '\n' && inv != EOF);
	std::cin.clear();
	return new class Password(length = nl);
}
void Password::drawChars() {
	for (int i = 0; i < length; i++) {
		int r = rand() % 4;
		if (r == 0)
			memory[i] = lowercase[rand() % 25];
		if (r == 1)
			memory[i] = uppercase[rand() % 25];
		if (r == 2)
			memory[i] = numbers[rand() % 10];
		if (r == 3)
			memory[i] = symbols[rand() % 32];
	}
}
void Password::drawPersonalizedChars(int low, int upp, int num, int sym) {
	for (int i = 0; i < length; i++) {
		int r = 0;
		while (1) {
			r = rand() % 4;
			if (r == 0 && low == 0)
				continue;
			else if (r == 0 && low == 1)
				break;
			if (r == 1 && upp == 0)
				continue;
			else if (r == 1 && upp == 1)
				break;
			if (r == 2 && num == 0)
				continue;
			else if (r == 2 && num == 1)
				break;
			if (r == 3 && sym == 0)
				continue;
			else if (r == 3 && sym == 1)
				break;
		}
		if (r == 0)
			memory[i] = lowercase[rand() % 25];
		if (r == 1)
			memory[i] = uppercase[rand() % 25];
		if (r == 2)
			memory[i] = numbers[rand() % 10];
		if (r == 3)
			memory[i] = symbols[rand() % 32];
	}
}
void Password::viewChars() { 
	std::cout << std::endl; 
	for (int i = 0; i < length; i++) 
		std::cout << memory[i]; 
	std::cout << std::endl << std::endl; 
}
class Password::Fake : public Password {
public:
	std::string fakeVS() { return "Qwerty1234!@#"; }
	std::string fakeS() { return "qwertyuiopasd"; }
	std::string fakeM() { return"12345678"; }
	std::string fakeW() { return "Qwe1"; }
	std::string fakeVW() { return"qwet"; }
};