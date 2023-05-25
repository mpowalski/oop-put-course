#pragma once
#ifndef GUARD_H
#define GUARD_H
#include <iostream>
class Guard {
public:
	Guard() = default;
	~Guard() = default;
	virtual std::string check(std::string usrpsswrd, int lngt) = 0;
};
#endif