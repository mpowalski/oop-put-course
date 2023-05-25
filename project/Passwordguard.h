#pragma once
#pragma once
#ifndef PASSWORDGUARD_H
#define PASSWORDGUARD_H
#include "Guard.h"
class Passwordguard : public Guard {
private:
	int numberoflow;
	int numberofupp;
	int numberofnum;
	int numberofsym;
public:
	Passwordguard();
	~Passwordguard();
	std::string check(std::string usrpsswrd, int lngt) override;
};
#endif
