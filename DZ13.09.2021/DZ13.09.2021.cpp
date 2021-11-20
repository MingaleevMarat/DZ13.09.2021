// DZ13.09.2021.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
void FillRand(int** arr, const int rows, const int cols);
void clear(int** arr, const unsigned int rows);
int** allocate(const unsigned int rows, const unsigned int cols);
void print(int** arr, const int rows, const int cols);
void push_col_back(int** array, const unsigned int rows,  unsigned int& cols);
void push_row_back(int** array, const unsigned int rows, unsigned int& cols);
int main()
{
    setlocale(LC_ALL, "");
    unsigned int rows, cols;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество элементов строки: ";
    std::cin >> cols;
    int** array = allocate(rows, cols);
    FillRand(array, rows, cols);
    print(array, rows, cols);
    std::cout << "Добавляем столбец в конец массива:\n";
    push_col_back(array, rows, cols);
    print(array, rows, cols);
    std::cout << "Удаляем столбец с конца массива:\n";
    push_row_back(array, rows, cols);
    print(array, rows, cols);
    clear(array, rows);
    return 0;
}

void push_col_back(int** array, const unsigned int rows,  unsigned int& cols)
{
    for (int i = 0; i < rows; ++i)
    {
        int* buffer = new int[cols + 1]{};
        for (int j = 0; j < cols; ++j)
            buffer[j] = array[i][j];
        delete[] array[i];
        array[i] = buffer;
    }
    cols++;
}

void print(int** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
       
        for (int j = 0; j < cols; j++)
        {
        std:: cout << arr[i][j] << "\t";
        }
    std:: cout << std::endl;
    }
}
int** allocate(const unsigned int rows, const unsigned int cols)
{
    int** arr = new int* [rows];	
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols] {};	
    }
    return arr;
}
void clear(int** arr, const unsigned int rows)
{  
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
void FillRand(int** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
}
void push_row_back(int** array, const unsigned int rows, unsigned int& cols)
{
    for (int i = 0; i < rows; ++i)
    {
        int* buffer = new int[cols-1]{};
        for (int j = 0; j < cols; ++j)
            buffer[j] = array[i][j];
    }
    cols--;
}