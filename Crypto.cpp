#include "CryptoFunctions.h"

void DisplayOptions() {
	printf("\n===============================================\n");
	printf("Choose an option below:\n\n");
	printf("1\t\t Input Data\n");
	printf("2\t\t Encrypt Data\n");
	printf("3\t\t Decrypt Data\n");
	printf("4\t\t Display Matrix\n");
	printf("5\t\t Display Clear Matrix\n");
	printf("\n0\t\t Quit\n");
	printf("===============================================\n\n");
}

int main(/*int argc, char* argv[]*/) {
	printf("==========Homework 1 : Crypto Problem==========\n");
	printf("\n\t\t  By: Rian Luzio\n");

	int choice = 0;
	Crypto Matrix;

	do {
		DisplayOptions();
		cin >> choice;
		cin.clear();

		if (choice == 1) {
			Matrix.InputData();
		}
		else if (choice == 2) {
			Matrix.Encrypt();
		}
		else if (choice == 3) {
			Matrix.Decrpyt();
		}
		else if (choice == 4) {
			Matrix.DisplayCryptoMatrix();
		}
		else if (choice == 5) {
			Matrix.DisplayClearMatrix();
		}
	} while (choice != 0);
}

Crypto::Crypto() {
	InputDataCount = 0;
	for (int i = 0; i < BUF; ++i) {
		CryptoMatrix[i] = '\0';
		ClearMatrix[i] = '\0';
	}
}

void Crypto::InputData() {
	char input[BUF];
	char key[9];
	int input_count = 0;
	int key_count = 0;

	do {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		key_count = 0;
		cout << "\nPlease input a key of no more than 8 characters to encrypt your string: ";
		cin.getline(key, 9);
		key_count = cin.gcount();
	} while (key_count != 9);

	do {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		printf("Please input a string of no more than 128 characters: ");
		cin.getline(input, BUF);
		input_count = cin.gcount();
	} while (input_count == 0 || input_count > 129);

	InputDataCount = input_count;

	for (int i = 0; i < InputDataCount; ++i) { InputDataBuffer[i] = input[i]; }
	for (int i = 0; i < InputDataCount; ++i) { CryptoKey[i] = key[i]; }
}

void Crypto::Encrypt() {
	int padding = 8 - (InputDataCount % 8);

	if (InputDataCount > 0) {
		for (int i = 0; i < InputDataCount + padding; ++i) {
			CryptoMatrix[i] = InputDataBuffer[i] ^ CryptoKey[i % 8];
		}
		printf("Encryption complete!\n");
	}

	else {
		printf("There is nothing to Encrypt.\n");
	}
}

void Crypto::Decrpyt() {
	//int padding = InputDataCount % 8;

	if (InputDataCount != 0) {
		for (int i = 0; i < InputDataCount; ++i) {
			ClearMatrix[i] = CryptoMatrix[i] ^ CryptoKey[i % 8];
		}

		printf("Decryption complete!\n");
	}

	else {
		printf("There is nothing to Decrypt\n");
	}
}

void Crypto::DisplayCryptoMatrix() {
	if (CryptoMatrix[0] == '\0') {
		cout << "Matrix is empty." << endl;
		return;
	}

	for (int i = 0; i < InputDataCount + (InputDataCount % 8); ++i) {
		std::cout << CryptoMatrix[i];
	}
}

void Crypto::DisplayClearMatrix() {
	if (ClearMatrix[0] == '\0') {
		cout << "Matrix is empty." << endl;
		return;
	}

	for (int i = 0; i < InputDataCount + (InputDataCount % 8); ++i) {
		std::cout << ClearMatrix[i];
	}
}
