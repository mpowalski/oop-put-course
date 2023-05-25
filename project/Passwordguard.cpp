#include "Passwordguard.h"
#include <cctype>
Passwordguard::Passwordguard() { numberoflow = 0; numberofupp = 0; numberofnum = 0; numberofsym = 0; }
Passwordguard::~Passwordguard() = default;
std::string Passwordguard::check(std::string usrpsswrd, int lngt) {
	for (char c : usrpsswrd) {
		if (islower(c))
			numberoflow++;
		else if (isupper(c))
			numberofupp++;
		else if (isdigit(c))
			numberofnum++;
		else
			numberofsym++;
	}
	if (lngt <= 4) {
		if (numberoflow >= 1 && (numberofupp >= 1 || numberofnum >= 1 || numberofupp >= 1))
			return "WEAK";
		else
			return "VERY WEAK";
	}
	else if (lngt <= 8) {
		if (numberoflow >= 1 && numberofupp >= 1 && numberofnum >= 1 && numberofupp >= 1)
			return "MEDIUM";
		else
			return "WEAK";
	}
	else if (lngt <= 12) {
		if (numberoflow >= 1 && numberofupp >= 1 && numberofnum >= 1 && numberofupp >= 1)
			return "STRONG";
		else
			return "MEDIUM";
	}
	else if (lngt > 12) {
		if (numberoflow >= 1 && numberofupp >= 1 && numberofnum >= 1 && numberofupp >= 1)
			return "VERY STRONG";
		else
			return "STRONG";
	}
}