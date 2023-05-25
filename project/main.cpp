#include "Password.h"
#include "Passwordguard.h"
void Menu() {
	std::cout << std::endl << "| generate strong password       | (1)" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "| generate personalized password | (2)" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "| check your password            | (3)" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "| show menu                      | (4)" << std::endl;
	std::cout << "|                                |" << std::endl;
	std::cout << "| end program                    | (0)" << std::endl << std::endl;
}
int main() {
	srand(time(NULL));
	int com = 0;
	std::cout << "Password Manager [open beta]" << std::endl;
	Menu();
	while (1) {
		class Password normal(12);
		std::cout << ">> User: ";
		std::cin >> com;
		if (!std::cin.fail() && com >= 0 && com <= 4) {
			if (com == 1) {
				normal.drawChars();
				normal.viewChars();
			}
			if (com == 2) {
				int nl = 0, low = 0, upp = 0, num = 0, sym = 0;
				std::string yesno;
				while (1) {
					try {
						std::cout << ">> choose length: ";
						std::cin >> nl;
						class Password* personalized = normal.changeLength(nl);
					}catch(const std::invalid_argument e){
						std::cerr << e.what() << std::endl;
						continue;
					}
					break;
				}
				while (1) {
					std::cout << ">> lower case letters? (y/n): ";
					std::cin >> yesno;
					if (yesno == "y")
						low = 1;
					std::cout << ">> upper case letters? (y/n): ";
					std::cin >> yesno;
					if (yesno == "y")
						upp = 1;
					std::cout << ">> numbers? (y/n): ";
					std::cin >> yesno;
					if (yesno == "y")
						num = 1;
					std::cout << ">> symbols? (y/n): ";
					std::cin >> yesno;
					if (yesno == "y")
						sym = 1;
					if (low == 0 && upp == 0 && num == 0 && sym == 0) {
						std::cout << " - - - - - - - - - - - - - - - - | Error: at least one case must be selected!" << std::endl;
						continue;
					}
					else
						break;
				}
				normal.drawPersonalizedChars(low, upp, num, sym);
				normal.viewChars();
			}
			if (com == 3) {
				class Passwordguard pg;
				std::string usrpsswrd;
				//class Password::Fake* fakePassword = new class Password::Fake();
				//usrpsswrd = fakePassword->fakeM();
				std::cout << ">> enter your password: ";
				std::cin >> usrpsswrd;
				int lngt = usrpsswrd.length();
				std::cout << std::endl << "strength: " << pg.check(usrpsswrd, lngt) << std::endl << std::endl;
				//delete fakePassword;
			}
			if (com == 4)
				Menu();
			if (com == 0) {
				std::cout << std::endl << "THE END" << std::endl;
				break;
			}
		}
		else {
			int inv = 0;
			while ((inv = getchar()) != '\n' && inv != EOF);
			std::cin.clear();
			std::cout << " - - - - - - - - - - - - - - - - | Error: invalid command!" << std::endl;
		}
	}
	return 0;
}