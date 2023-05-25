#pragma once
#ifndef PASSWORD_H
#define PASSWORD_H
#include "Word.h"
class Password : public Word {
private:
	int length;
	char lowercase[26] = "abcdefghijklmnoprstuvwxyz";
	char uppercase[26] = "ABCDEFGHIJKLMNOPRSTUVWXYZ";
	char numbers[11] = "0123456789";
	char symbols[33] = "~`!@#$%^&*()_-+={[}]|\\:;\"'<,>.?/";
	char memory[100];
public:
	Password();
	Password(int l);
	~Password();
	class Password* changeLength(int nl) override;
	void drawChars() override;
	void drawPersonalizedChars(int low, int upp, int num, int sym) override;
	void viewChars() override;
	class Fake;
};
#endif