#include"matrice.h"

void matriceMenu() {
	cout << "\nМатричный калькулятор: \n";
	cout << "Функции: \n";
	cout << "0. Выход в меню\n";
	cout << "1. Сложение матриц\n";
	cout << "2. Вычитание матриц\n";
	cout << "3. Умножение матриц\n";
	cout << "4. Умножение матрицы на число\n";
	cout << "5. Сложение матрицы с числом\n";
	cout << "6. Вычитание матрицы с числом\n";
	cout << "7. Транспонирование матрицы\n";
	cout<<  "8. Определитель матрицы\n";
	cout << "9. Обратная матрица \n";
	cout << "Выберите номер действия: ";
}

int GetChoice() {
	int choice;
	while (!(cin >> choice) || (choice < 1 || choice > 10)) {
		cout << "Неправильный ввод";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return choice;
}

void OutputMatrice(int stroki, int stolbcy, int matrice[100][100]) {
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			cout << matrice[i][j] << "\t";
		}
		cout << endl;
	}
}


void InputSingleMatrice(int stroki, int stolbcy, int matrice[100][100]) {
	cout << "Введите элементы матрицы " << stroki << "x" << stolbcy << ":\n";
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			cout << "a" << i + 1 << j + 1 << " = ";
			int temp;
			while (!(cin >> temp) || temp <= 0) {
				cout << "Ошибка ввода. Введите положительное число: a" << i + 1 << j + 1 << " = ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			matrice[i][j] = temp;
		}
	}
}

void InputTwoMatrice(int stroki1, int stolbcy1, int matrice1[100][100], int stroki2, int stolbcy2, int matrice2[100][100]) {
	cout << "Введите элементы первой матрицы " << stroki1 << "x" << stolbcy1 << ":\n";
	InputSingleMatrice(stroki1, stolbcy1, matrice1);

	cout << "Введите элементы второй матрицы " << stroki2 << "x" << stolbcy2 << ":\n";
	InputSingleMatrice(stroki2, stolbcy2, matrice2);
}

void InputMatriceAndNumber(int stroki, int stolbcy, int matrice[100][100], int& chislo) {
	cout << "Введите элементы матрицы " << stroki << "x" << stolbcy << ":\n";
	InputSingleMatrice(stroki, stolbcy, matrice);

	cout << "Введите число: ";
	while (!(cin >> chislo)) {
		cout << "Ошибка ввода числа. Попробуйте снова: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void PlusMatrice(int stroki, int stolbcy, int matrice1[100][100],int matrice2[100][100],int result[100][100]) {
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			result[i][j] = matrice1[i][j] + matrice2[i][j];
		}
	}
}


void MinusMatrice(int stroki, int stolbcy, int matrice1[100][100],int matrice2[100][100],int result[100][100]) {
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			result[i][j] = matrice1[i][j] - matrice2[i][j];
		}
	}
}
void ymnozhenieMatrice(int stroki1, int stolbcy1, int matrice1[100][100],
	int stroki2, int stolbcy2, int matrice2[100][100],
	int result[100][100]) {
	for (int i = 0; i < stroki1; i++) {
		for (int j = 0; j < stolbcy2; j++) {
			result[i][j] = 0;
			for (int k = 0; k < stolbcy1; k++) {
				result[i][j] += matrice1[i][k] * matrice2[k][j];
			}
		}
	}
}

void ymnozhenieMatriceNaChislo(int stroki, int stolbcy, int matrice[100][100], int chislo, int result[100][100]) {
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			result[i][j] = matrice[i][j] * chislo;
		}
	}
}


void PlusNumMatrice(int stroki, int stolbcy, int matrice[100][100], int chislo, int result[100][100]) {
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			result[i][j] = matrice[i][j] + chislo;
		}
	}
}

void MinusNumMatrice(int stroki, int stolbcy, int matrice[100][100], int chislo, int result[100][100]) {
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			result[i][j] = matrice[i][j] - chislo;
		}
	}
}

void TransponentMatrice(int stroki, int stolbcy, int matrice[100][100], int result[100][100]) {
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbcy; j++) {
			result[j][i] = matrice[i][j];
		}
	}
}

int Opredelitel(int n, int matrice[100][100]) {
	if (n == 1)
		return matrice[0][0];
	int opred = 0;
	int temp[100][100];

	for (int f = 0; f < n; f++) {
		int minori = 0;
		for (int i = 1; i < n; i++) {
			int minorj = 0;
			for (int j = 0; j < n; j++) {
				if (j == f)
					continue;
				temp[minori][minorj] = matrice[i][j];
				minorj++;
			}
			minori++;
		}
		opred += ((f % 2 == 0) ? 1 : -1) * matrice[0][f] * Opredelitel(n - 1, temp);
	}
	return opred;
}

void PodMatrice(int n, int matrice[100][100], int podmatrice[100][100], 
	int strokaremove, int stolbecremove) {
	int stroka = 0, stolbec = 0;
	for (int i = 0; i < n; i++) {
		if (i == strokaremove) {
			continue;
		}
		stolbec = 0;
		for (int j = 0; j < n; j++) {
			if (j == stolbecremove) {
				continue;
			}
			podmatrice[stroka][stolbec] = matrice[i][j];
			stolbec++;
		}
		stroka++;
	}
}

void MatriceDop(int size, int matrice[100][100], int dop[100][100]) {
	int podmatrice[100][100];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			PodMatrice(size, matrice, podmatrice, i, j);
			int minorOpred = Opredelitel(size - 1, podmatrice);
			dop[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * minorOpred;
		}
	}
}

bool ObratMatrice(int n, int matrice1[100][100], double obr[100][100]) {
		int opredmatrice1 = Opredelitel(n, matrice1);
		if (opredmatrice1 == 0) {
			return false;
		}
		int dop[100][100];
		MatriceDop(n, matrice1, dop);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				obr[i][j] = static_cast<double>(dop[j][i]) / static_cast<double>(opredmatrice1);
			}
		}
		return true;
}

bool GetYesOrNo() {
	string input;

	while (true) {
		cout << "\nХотите повторить? (yes/no): ";
		cin >> input;

		if (input == "y" || input == "yes") {
			return true;
		}
		else if (input == "n"||  input == "no") {

			return false;
		}
		cout << "Ошибка! Пожалуйста, введите 'yes' или 'no': ";
	}
}
void MatriceOperation(int operation) {
	int matrice1[100][100], matrice2[100][100], result[100][100];
	int stroki, stolbcy, chislo;

	switch (operation) {
	case 3: {  // Умножение матриц
		int stroki1, stolbcy1, stroki2, stolbcy2;

		do {
			cout << "Введите значение для строк первой матрицы\n";
			cin >> stroki1;
			if (stroki1 <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stroki1 <= 0);
		
		do {
			cout << "Введите значение для столбцов первой матрицы\n";
			cin >> stolbcy1;
			if (stolbcy1 <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stolbcy1  <= 0);

		do {
			cout << "Введите значение для строк второй матрицы\n";
			cin >> stroki2;
			if (stroki2 <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stroki2 <= 0);

		do {
			cout << "Введите значение для столбцов второй матрицы\n";
			cin >> stolbcy2;
			if (stolbcy2 <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stolbcy2 <= 0);


		
		if (stolbcy1 != stroki2) {
			cout << "Число столбцов первой матрицы должно быть равно числу строк второй.\n";
			return;
		}
		

		// Вводим две матрицы
		InputTwoMatrice(stroki1, stolbcy1, matrice1, stroki2, stolbcy2, matrice2);

		ymnozhenieMatrice(stroki1, stolbcy1, matrice1, stroki2, stolbcy2, matrice2, result);
		cout << "Результат умножения:\n";
		OutputMatrice(stroki1, stolbcy2, result);
		break;
	}
	case 1:  // Сложение матриц
	case 2:  // Вычитание матриц
		do {
			cout << "Введите количество строк для матрицы: ";
			cin >> stroki;
			if (stroki <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stroki <= 0);
		do{
			cout << "Введите количество столбцов для матрицы: ";
			cin >> stolbcy;
			if (stolbcy <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stolbcy <= 0);

		// Вводим две матрицы
		cout << "Введите элементы первой матрицы:\n";
		InputSingleMatrice(stroki, stolbcy, matrice1);
		cout << "Введите элементы второй матрицы:\n";
		InputSingleMatrice(stroki, stolbcy, matrice2);

		if (operation == 1) {
			PlusMatrice(stroki, stolbcy, matrice1, matrice2, result);
			cout << "Результат сложения матриц:\n";
		}
		else {
			MinusMatrice(stroki, stolbcy, matrice1, matrice2, result);
			cout << "Результат вычитания матриц:\n";
		}

		OutputMatrice(stroki, stolbcy, result);
		break;

	case 4: {  // Умножение матрицы на число
		do {
			cout << "Введите количество строк для матрицы: ";
			cin >> stroki;
			if (stroki <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stroki <= 0);
		do {
			cout << "Введите количество столбцов для матрицы: ";
			cin >> stolbcy;
			if (stolbcy <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stolbcy <= 0);
		InputMatriceAndNumber(stroki, stolbcy, matrice1, chislo);
		ymnozhenieMatriceNaChislo(stroki, stolbcy, matrice1, chislo, result);
		cout << "Результат умножения матрицы на число:\n";
		OutputMatrice(stroki, stolbcy, result);
		break;
	}

	case 5: { // Сложение матрицы с числом
		do {
			cout << "Введите количество строк для матрицы: ";
			cin >> stroki;
			if (stroki <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stroki <= 0);
		do {
			cout << "Введите количество столбцов для матрицы: ";
			cin >> stolbcy;
			if (stolbcy <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stolbcy <= 0);
		InputMatriceAndNumber(stroki, stolbcy, matrice1, chislo);
		PlusNumMatrice(stroki, stolbcy, matrice1, chislo, result);
		cout << "Результат сложения матрицы с числом:\n";
		OutputMatrice(stroki, stolbcy, result);
		break;
	}

	case 6: {  // Вычитание числа из матрицы
		do {
			cout << "Введите количество строк для матрицы: ";
			cin >> stroki;
			if (stroki <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stroki <= 0);
		do {
			cout << "Введите количество столбцов для матрицы: ";
			cin >> stolbcy;
			if (stolbcy <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stolbcy <= 0);
		InputMatriceAndNumber(stroki, stolbcy, matrice1, chislo);
		MinusNumMatrice(stroki, stolbcy, matrice1, chislo, result);
		cout << "Результат вычитания числа из матрицы:\n";
		OutputMatrice(stroki, stolbcy, result);
		break;
	}

	case 7: {  // Транспонирование матрицы

		do {
			cout << "Введите количество строк для матрицы: ";
			cin >> stroki;
			if (stroki <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stroki <= 0);
		do {
			cout << "Введите количество столбцов для матрицы: ";
			cin >> stolbcy;
			if (stolbcy <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stolbcy <= 0);
		InputSingleMatrice(stroki, stolbcy, matrice1);
		TransponentMatrice(stroki, stolbcy, matrice1, result);
		cout << "Транспонированная матрица:\n";
		OutputMatrice(stolbcy, stroki, result);
		break;
	}

	case 8: {  // Определитель матрицы
		do {
			cout << "Введите количество строк для матрицы: ";
			cin >> stroki;
			if (stroki <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stroki <= 0);
		do {
			cout << "Введите количество столбцов для матрицы: ";
			cin >> stolbcy;
			if (stolbcy <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stolbcy <= 0);
		InputSingleMatrice(stroki, stolbcy, matrice1);
		if (stroki != stolbcy) {
			cout << "Определитель может быть вычислен только для квадратной матрицы.\n";
			return;
		}
		int opred = Opredelitel(stroki, matrice1);
		cout << "Определитель матрицы равен: " << opred << "\n";
		break;
	}

	case 9: {  // Обратная матрица
		do {
			cout << "Введите количество строк для матрицы: ";
			cin >> stroki;
			if (stroki <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stroki <= 0);
		do {
			cout << "Введите количество столбцов для матрицы: ";
			cin >> stolbcy;
			if (stolbcy <= 0) {
				cout << "Значение должно быть положительным\n";
			}
		} while (stolbcy <= 0);
		InputSingleMatrice(stroki, stolbcy, matrice1);
		if (stroki != stolbcy) {
			cout << "Обратная матрица возможна только для квадратной матрицы.\n";
			return;
		}
		double obr[100][100];
		if (ObratMatrice(stroki, matrice1, obr)) {
			cout << "Обратная матрица:\n";
			for (int i = 0; i < stroki; i++) {
				for (int j = 0; j < stolbcy; j++) {
					cout << obr[i][j] << "\t";
				}
				cout << endl;
			}
		}
		else {
			cout << "Матрица вырождена.\n";
		}
		break;
	}
	case 0: {  // Выход
		cout << "Выход из программы.\n";
		exit(0);  // Завершаем программу
		break;
	}

	default:
		cout << "Неизвестная операция.\n";
		break;
	}
}
