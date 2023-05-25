#pragma once
#ifndef WORD_H
#define WORD_H
class Word {
public:
	Word() = default;
	~Word() = default;
	virtual class Word* changeLength(int nl) = 0;
	virtual void drawChars() = 0;
	virtual void drawPersonalizedChars(int low, int upp, int num, int sym) = 0;
	virtual void viewChars() = 0;
};
#endif