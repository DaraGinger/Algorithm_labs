#include <iostream>

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

int main()
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