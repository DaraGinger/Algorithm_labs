#include <iostream>

#pragma region  Task 1

// Функція для створення масиву та фільтрації елементів
void Task1()
{
    int size = 0, filteredSize = 0;
    std::cout << "Enter size:"; // Запитати користувача розмір масиву
    std::cin >> size;

    std::cout << "Enter numbers:\n"; // Запитати числа

    float* array = new float[size]; // Створюємо динамічний масив введених чисел

    // Заповнюємо масив користувацькими значеннями
    for (int i = 0; i < size; i++) 
    {
        std::cin >> array[i];

        // Підрахунок кількості елементів, які потрапляють у діапазон (10;25)
        if (array[i] > 10 && array[i] < 25)
            filteredSize++;
    }

    if (filteredSize != 0)
    {
        float* filteredArray = new float[filteredSize]; // Масив для відфільтрованих елементів
        int index = 0;

        // Копіюємо тільки ті елементи, які у діапазоні (10;25)
        for (int i = 0; i < size; i++)
        {
            if (array[i] > 10 && array[i] < 25)
            {
                filteredArray[index] = array[i];
                index++;
            }
        }

        std::cout << "-------\nCreated array:\n";
        for (int i = 0; i < filteredSize; i++)
        {
            std::cout << filteredArray[i] << "\n";
        }

        int firstNumber = array[0];
        int count = 0;

        for (int i = 1; i < size; i++)
        {
            // Перевіряємо решту елементів
            if (firstNumber < array[i])
                count++;
        }

        std::cout << "-------\nCount of elements that bigger than first element in array:" << count;

        // Звільняємо пам’ять, виділену під масиви
        delete[] filteredArray;
    }
    else
    {
        std::cout << "-------\nArray is empty.\n";
    }

    delete[] array;
}

#pragma endregion

#pragma region Task 2

void Task2()
{
    int numberOfRows = 8;
    int array[8][4], rowCount = 0, rows[8];

    std::cout << "Enter matrix 8*4:\n";

    // Введення матриці з клавіатури
    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << "Enter element [" << i << "," << j << "]: ";
            std::cin >> array[i][j];

            // Якщо у рядку є число 25 або 5 — позначаємо цей рядок
            if (array[i][j] == 25 || array[i][j] == 5)
            {
                rows[i] = 1;
            }
        }

        // Якщо рядок не був позначений одиницею, то збільшуємо кількість рядків 
        if (rows[i] != 1)
        {
            rowCount++;
        }
    }

    std::cout << "Matrix before:\n";

    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << array[i][j] << "\t";
        }

        std::cout << "\n";
    }

    // Динамічне виділення пам’яті під нову матрицю
    int** matrix = new int *[rowCount];
    int indexRows = 0; // Лічильник для нової матриці

    if (rowCount != 0)
    {

        for (int i = 0; i < numberOfRows; i++)
        {
            if (rows[i] != 1) // Якщо рядок не містив 25 або 5
            {
                matrix[indexRows] = new int[4]; // Виділяємо пам'ять під рядок у новій матриці

                for (int j = 0; j < 4; j++)
                {
                    // Копіюємо рядок із вихідної матриці
                    matrix[indexRows][j] = array[i][j];
                }

                indexRows++;
            }
        }

        std::cout << "-------\nResult:\n";

        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                std::cout << matrix[i][j] << " \t";
            }
            std::cout << "\n";
        }

        for (int i = 0; i < rowCount; i++)
        {
            delete[] matrix[i];
        }

        delete[]matrix;
    }
    else
    {
        std::cout << "-------\nMatrix is empty.\n";
    }
}

#pragma endregion

int main()
{
    Task1();
    Task2();
}