#include <iostream>

void Print1(int** arr, int row, int coll) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < coll; j++)
		{

			std::cout << arr[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

void Collumn(int** arr, int row, int& coll, int id) {
	for (int i = 0; i < row; i++) {
		int* line_new = new int[coll + 1] {};
		for (int j = 0; j < id; j++) {
			line_new[j] = arr[i][j];
		}
		line_new[id] = id;
		for (int j = id; j < coll; j++) {
			line_new[j + 1] = arr[i][j];
		}
		std::swap(line_new, arr[i]);
		delete[]line_new;
	}
	coll += 1;
}

void Delete(int** arr, int row, int& coll, int id) {
	for (int i = 0; i < row; i++) {
		int* line_new = new int[coll - 1];
		for (int j = 0, newCol = 0; j < coll; j++) {
			if (j != id) 
			{
				line_new[newCol++] = arr[i][j];
			}
		}
		delete[] arr[i];
		arr[i] = line_new;
	}
	coll--;
}

void Swap(int** arr, int position, int shift, int row, int column) {
	if (position < 1 || position > 4) {
		std::cout << "Вы ввели не корректное положение.\n";
		return;
	}

	for (int k = 0; k < shift; k++) {
		if (position == 1) { // Сдвиг влево
			for (int i = 0; i < row; i++) {
				int temp = arr[i][0];
				for (int j = 0; j < column - 1; j++) {
					arr[i][j] = arr[i][j + 1];
				}
				arr[i][column - 1] = temp; // Сдвиг ненужного элемента в конец строки
			}
		}
		else if (position == 2) { // Сдвиг вправо
			for (int i = 0; i < row; i++) {
				int temp = arr[i][column - 1];
				for (int j = column - 1; j > 0; j--) {
					arr[i][j] = arr[i][j - 1];
				}
				arr[i][0] = temp; // Сдвиг ненужного элемента в начало строки
			}
		}
		else if (position == 3) { // Сдвиг вверх
			for (int i = 0; i < column; i++) {
				int temp = arr[0][i];
				for (int j = 0; j < row - 1; j++) {
					arr[j][i] = arr[j + 1][i];
				}
				arr[row - 1][i] = temp; // Сдвиг ненужного элемента в конец столбца
			}
		}
		else if (position == 4) { // Сдвиг вниз
			for (int i = 0; i < column; i++) {
				int temp = arr[row - 1][i];
				for (int j = row - 1; j > 0; j--) {
					arr[j][i] = arr[j - 1][i];
				}
				arr[0][i] = temp; // Сдвиг ненужного элемента в начало столбца
			}
		}
	}

	std::cout << "Результат после сдвигов:\n";
	Print1(arr, row, column);
}

int main() {
	setlocale(LC_ALL, "RUS");
	// Задача 1
	int collumn{4};
	int row{4};
	int** matrix = new int* [row] {};
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[collumn] {1};
	}
	std::cout << "Задача 1\nПеред вами двухмерный динамический массив:\n";
	Print1(matrix, row, collumn);
	std::cout << '\n';
	std::cout << "Введите позицию,и программа добавит столбец двухмерному массиву в указанную позицию\n*Счет начинается с нуля\n";
	int ID;
	std::cin >> ID;
	Collumn(matrix, row, collumn, ID);
	std::cout << "Перед вами новый двухмерный динамический массив:\n";
	Print1(matrix, row, collumn);
	for (int i = 0; i < row; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	// Задача 2
	int collumn1{ 4 };
	int row1{ 3 };
	int** matrix1 = new int* [row1];
	for (int i = 0; i < row1; i++) {
		matrix1[i] = new int[collumn1];
	}
	int MTX[3][4] = {
		  {1, 2, 3, 4},
		  {5, 6, 7, 8},
		  {9, 10, 11, 12}
	};
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < collumn1; j++) {
			matrix1[i][j] = MTX[i][j];
		}
	}
	std::cout << "Задача 2\nПеред вами двухмерный динамический массив:\n";
	Print1(matrix1, row1, collumn1);
	std::cout << "Введите позицию,и программа удалит столбец двухмерного массива по указанному номеру\n*Счет начинается с нуля\n";
	int ID1;
	std::cin >> ID1;
	Delete(matrix1, row1, collumn1, ID1);
	std::cout << "Перед вами новый двухмерный динамический массив:\n";
	Print1(matrix1, row1, collumn1);

	for (int i = 0; i < row1; i++) {
		delete[] matrix1[i]; 
	}
	delete[] matrix1;

	// Задача 3
	std::cout << "Задача 3.\nДана матрица порядка MхN (Mстрок,Nстолбцов).\nНеобходимо заполнить ее значениями\n";
	int row2, collumn2;
	std::cout << "Введите количество строк (M): ";
	std::cin >> row2;
	std::cout << "Введите количество столбцов (N): ";
	std::cin >> collumn2;

	int** matrix2 = new int* [row2];
	for (int i = 0; i < row2; i++) {
		matrix2[i] = new int[collumn2];
	}
	std::cout << "Введите " << (row2 * collumn2) << " чисел для заполнения матрицы:\n";
	for (int i = 0; i < row2; i++) {
		for (int j = 0; j < collumn2; j++) {
			std::cin >> matrix2[i][j];
		}
	}
	std::cout << "\nВаша матрица:\n";
	Print1(matrix2, row2, collumn2);
	std::cout << "Программа осуществит циклический сдвиг строк или столбцов указанное кол-во рааз в указанную сторону.\n";
	std::cout << "Выберите количество сдвигов и положение.\n";
	std::cout << "Влево - 1.\n";
	std::cout << "Вправо - 2.\n";
	std::cout << "Вверх - 3.\n";
	std::cout << "Вниз - 4.\n";
	int position;
	std::cin >> position;
	std::cout << "Количество сдвигов\n";
	int shift;
	std::cin >> shift;

	Swap(matrix2, position, shift, row2, collumn2);

	std::cout << "\nМатрица после циклического сдвига:\n";
	Print1(matrix2, row2, collumn2);

	for (int i = 0; i < row2; i++) {
		delete[] matrix2[i];
	}
	delete[] matrix2;

	return 0;
}

