#include<iostream>
#include"matrice.h"
#include<locale>
#include <limits>
#include <string>

int main() {
	setlocale(LC_ALL, "Russian");
	bool exit = false;

	while (!exit) {
		matriceMenu();
		int choice = GetChoice();

		if (choice >= 1 && choice <= 9) {
			do {
				MatriceOperation(choice);
			} while (GetYesOrNo());
		}
		else if (choice == 10) {
			exit = true;
			cout << "Выход из программы\n";
		}
		else {
			cout << "Неправильный ввод\n";
		}
	}

	return 0;
}
