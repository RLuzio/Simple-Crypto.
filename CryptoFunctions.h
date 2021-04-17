#pragma once
#include <iostream>

using namespace std;

const int BUF = 129;

class Crypto {
private:
	char InputDataBuffer[BUF];
	char CryptoKey[8];
	char CryptoMatrix[BUF];
	char ClearMatrix[BUF];
	short InputDataCount;
public:
	Crypto();
	void InputData();
	void Encrypt();
	void Decrpyt();
	void DisplayCryptoMatrix();
	void DisplayClearMatrix();
};
