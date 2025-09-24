#include <iostream>

#pragma region Lab1

#pragma region  Task 1

// Функція для створення масиву та фільтрації елементів
void Task1_1()
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

void Task1_2()
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

#pragma endregion

#pragma region Lab2

struct Product
{
    char Name[20];
    char Producer[20];
    float Price;
    int Count;
};

void Task2_1()
{
    Product products[5] = { {"Pen", "Kulka", 1.50, 10},
                            {"Pencil", "Kulka", 4.99, 12},
                            {"Notebook", "Nasha idea", 10.30, 4},
                            {"Lamp", "Electronics", 13.60, 5},
                            {"Paper", "Birds", 8.20, 7} };

    int index = 0; // Індекс товару з найбільшою ціною

    // Шукаємо товар із максимальною ціною
    for (int i = 0; i < 5; i++)
    {
        if (products[i].Price > products[index].Price)
        {
            index = i;
        }
    }

    // Розраховуємо загальну вартість вибраного товару
    float sum = products[index].Count * products[index].Price;

    std::cout << "Name:" << products[index].Name;
    std::cout << "\nProducer:" << products[index].Producer;
    std::cout << "\nPrice:" << products[index].Price;
    std::cout << "\nCount:" << products[index].Count;
    std::cout << "\nSummary price:" << sum;
}

#pragma endregion

#pragma region Lab3

#pragma region Task1

/* Створити лінійний односпрямований список із цілих чисел.
Визначити суму елементів списку зі значенням більше або рівним 15.
Видалити зі списку усі значення, які менші 5 */

// Структура вузла однозв’язного списку
struct List
{
    int Value;
    List* Next;
};

List* CreateList(int count, List* Head)
{
    std::cout << "Enter numbers:\n";
    List* Current = Head; // вказівник на поточний вузол

    // Заповнюємо список
    for (int i = 0; i < count; i++)
    {
        // Якщо це не останній елемент — створюємо новий вузол
        if (i != count - 1)
            Current->Next = new List();
        else
            Current->Next = NULL; // останній вузол вказує на NULL

        std::cin >> Current->Value; // зчитуємо значення у вузол
        Current = Current->Next;     // переходимо до наступного вузла
    }

    return Head; // повертаємо голову списку
}

// Рекурсивний вивід списку
void PrintList(List* Head)
{
    if (Head != NULL)
    {
        std::cout << Head->Value << "\n";
        PrintList(Head->Next);            // рекурсивний виклик для наступного вузла
    }
    else
    {
        std::cout << "----------\n";
    }
}

List* AddList(List* Head, int value, int index)
{
    std::cout << "Added item:\n";

    List* Current = Head;       // поточний вузол
    List* NewItem = new List(); // новий вузол
    NewItem->Value = value;

    // Якщо вставка на початок (index == 0)
    if (index == 0)
    {
        NewItem->Next = Current; // новий вузол стає перед головою
        Head = NewItem;          // оновлюємо голову
    }

    // Проходимо список до потрібної позиції
    for (int i = 1; i < index; i++)
    {
        Current = Current->Next;
        if (i == index - 1) // коли дійшли до позиції вставки
        {
            if (Current == NULL)
                NewItem->Next = NULL; // якщо кінець списку
            else
                NewItem->Next = Current->Next; // зв’язуємо новий вузол з наступним

            Current->Next = NewItem; // попередній елемент вказує на новий вузол
        }
    }

    PrintList(Head);

    return Head;
}

List* RemoveList(List* Head, int index)
{
    List* Current = Head;

    // Якщо видаляємо перший елемент
    if (index == 0)
    {
        Head = Current->Next; // нова голова — наступний елемент
        return Head;
    }

    List* PriorItem = Head; // попередній елемент

    // Шукаємо вузол, який потрібно видалити
    for (int i = 1; i <= index; i++)
    {
        PriorItem = Current;
        Current = Current->Next;

        if (i == index) // коли дійшли до потрібного елемента
        {
            if (Current->Next != NULL)
            {
                // якщо це не останній елемент
                PriorItem->Next = Current->Next;
            }
            else
            {
                // якщо останній — попередній стає останнім
                PriorItem->Next = NULL;
            }

            return Head;
        }
    }

    return Head;
}

// Обчислення суми елементів >= 15
void Sum(List* Head, int size)
{
    List* Current = Head;
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (Current->Value >= 15)
        {
            sum += Current->Value;
        }

        Current = Current->Next;
    }

    std::cout << "Sum of numbers greater than or equal 15: " << sum << "\n";
    std::cout << "----------\n";
}

// Видалення зі списку всіх елементів < 5
void Remove5(List* Head, int size)
{
    std::cout << "List without numbers less than 5:\n";

    List* Current = Head;
    int index = 0; // лічильник позицій

    for (int i = 0; i < size; i++)
    {
        if (Current->Value < 5)
        {
            Head = RemoveList(Head, index);
        }
        else
        {
            index++; // рухаємо індекс тільки якщо елемент залишився
        }

        Current = Current->Next;
    }

    PrintList(Head);
}

void Task3_1()
{
    int size = 0;
    std::cout << "Enter size:\n";
    std::cin >> size;
    std::cout << "----------\n";

    // Створюємо голову списку
    List* Head = new List();
    Head = CreateList(size, Head); // наповнюємо список
    std::cout << "----------\n";

    std::cout << "Created List:\n";
    PrintList(Head);

    Sum(Head, size); // знаходимо суму елементів >= 15

    Remove5(Head, size); // видаляємо елементи < 5
}

#pragma endregion

#pragma region Task2

/*Дано покажчик P 1 на перший елемент непорожнього двозв’язного
списку.Перегрупувати його елементи, перемістити всі елементи
з непарними номерами в кінець списку(в тому самому порядку)
та вивести покажчик на перший елемент перетвореного списку.Операції
виділення та звільнення пам’яті не застосовувати, поля з даними(Data)
не змінювати*/

// Структура для двозв’язного списку
struct BidirectionalList
{
    int Value;                    // Значення вузла
    BidirectionalList* Next;      // Вказівник на наступний вузол
    BidirectionalList* Prior;     // Вказівник на попередній вузол
};

// Рекурсивне створення списку
void CreateBidirectionalList(int count, BidirectionalList** Head, BidirectionalList* Prior)
{
    if (count > 0)
    {
        (*Head) = new BidirectionalList();   // створюємо новий вузол

        std::cout << "Enter number:";
        std::cin >> (*Head)->Value;          // зчитуємо його значення

        (*Head)->Prior = Prior;              // попередній елемент (NULL для першого)
        (*Head)->Next = NULL;                // наступний поки невідомий

        // Рекурсивно створюємо наступний елемент списку
        CreateBidirectionalList(count - 1, &((*Head)->Next), (*Head));
    }
    else
    {
        (*Head) = NULL; // кінець списку
    }
}

// Рекурсивний друк списку
void PrintBidirectionalList(BidirectionalList* Head)
{
    if (Head != NULL)
    {
        std::cout << Head->Value << "\n"; // виводимо значення поточного вузла
        PrintBidirectionalList(Head->Next); // переходимо далі
    }
    else
    {
        std::cout << "----------\n"; // роздільник (кінець списку)
    }
}

// Додавання нового вузла у список на вказану позицію
void AddBidirectionalList(BidirectionalList** Head, int value, int index)
{
    BidirectionalList* Current = *Head;
    BidirectionalList* Prior = NULL;
    BidirectionalList* NewItem = new BidirectionalList();
    NewItem->Value = value;

    // Вставка на початок списку
    if (index == 0)
    {
        *Head = NewItem;            // нова голова списку
        NewItem->Next = Current;    // стара голова тепер йде після нової
        NewItem->Prior = NULL;      // у голови попереднього немає
        Current->Prior = NewItem;   // стара голова тепер має зворотний зв’язок
    }

    // Проходимо список до потрібного індексу
    for (int i = 1; i <= index; i++)
    {
        if (Current->Next == NULL)  // якщо дійшли до кінця
            Prior = Current;

        Current = Current->Next;    // рухаємось далі

        if (i == index) // коли дійшли до потрібної позиції
        {
            if (Current == NULL)    // вставка в кінець
            {
                NewItem->Next = NULL;
                NewItem->Prior = Prior;
                Prior->Next = NewItem;
            }
            else // вставка між вузлами
            {
                NewItem->Next = Current;
                Prior = Current->Prior;
                NewItem->Prior = Prior;
                Prior->Next = NewItem;
            }
        }
    }
}

// Видалення вузла зі списку за індексом
void RemoveBidirectionalList(BidirectionalList** Head, int index)
{
    BidirectionalList* Current = *Head;

    // Видалення голови списку
    if (index == 0)
    {
        *Head = Current->Next;   // нова голова
        Current->Prior = NULL;   // обнуляємо попередній у нової голови
    }

    // Пошук вузла для видалення
    for (int i = 1; i <= index; i++)
    {
        Current = Current->Next;

        if (i == index)
        {
            BidirectionalList* Prior = NULL;

            if (Current->Next == NULL) // видалення останнього елемента
            {
                Prior = Current->Prior;
                Prior->Next = NULL;
            }
            else // видалення елемента посередині
            {
                Current->Prior->Next = Current->Next;
                Current->Next->Prior = Current->Prior;
            }
        }
    }
}

// Перегрупування: усі непарні елементи переносяться в кінець списку
void Regrouping(int count, BidirectionalList** Head)
{
    std::cout << "Regrouping list:\n";

    BidirectionalList* Current = *Head;
    int index = 0;

    for (int i = 0; i < count; i++)
    {
        if (Current->Value % 2 != 0) // якщо значення непарне
        {
            RemoveBidirectionalList(Head, index);        // видаляємо з поточної позиції
            AddBidirectionalList(Head, Current->Value, count - 1); // додаємо в кінець
        }
        else
        {
            index++; // якщо парне — залишаємо і зсуваємо індекс
        }

        Current = Current->Next; // рухаємось далі
    }
}

// Тестова функція: створення списку, вивід, перегрупування
void Task3_2()
{
    int count = 0;

    std::cout << "Enter list size:";
    std::cin >> count;

    BidirectionalList** Head = new BidirectionalList * (); // вказівник на голову списку
    BidirectionalList* Prior = new BidirectionalList();    // початковий попередній (NULL для голови)

    CreateBidirectionalList(count, Head, Prior); // створюємо список

    std::cout << "----------\n";

    PrintBidirectionalList(*Head); // вивід списку

    Regrouping(count, Head); // перегрупування елементів

    PrintBidirectionalList(*Head); // повторний вивід
}

int main()
{
    Task3_2(); // запуск програми
}


#pragma endregion

#pragma endregion


int main()
{
    Task3_2();
}