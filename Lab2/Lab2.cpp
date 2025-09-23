#include <iostream>

struct Product
{
    char Name[20];
    char Producer[20];
    float Price;
    int Count;
};

void Task1()
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

int main()
{
    Task1();
}