#include <iostream>
#include <limits>
#include "Stack.h"
#include "string"
#include "string.h"


int del_odd(Stack *stack)
// Метод удаляет все нечетные по номеру элементы сверху. Т.е. 1-й, 3-й и тд сверху.
{
    if (stack->empty()) return 0; //Стек пуст.

    int size = stack->get_size(); // Размер стека.
    int *array;
    int arr_size = 0; // Размер массива, в который перезаписываются все ЧЕТНЫЕ элементы.
    if (size % 2 == 0)
    {
        array = new int[size - (size / 2)];
        arr_size = size / 2;
    }
    else
    {
        int tmp = (double) size / 2 + 0.5;
        arr_size = size - tmp;
        array = new int[arr_size]; // (size - tmp) это количество четных элементов. size - все. tmp удаленные(нечетн)

    }
    int count = 0; // счетчик
    for (int i = 1; i <= size; ++i)
    {
        if (i % 2 == 0)
        {
            array[count] = stack->pop(); // Четные перезаписываем в массив.
            count++;
        }
        else
        {
            stack->pop(); // Нечетные удаляем.
        }
    }

    for (int j = arr_size - 1; j >= 0; --j)
    {
        stack->push(array[j]); // Записываем уже в пустой стек все сохраненные, четные, элементы
    }

    delete[] array;

    return 1;
}
void enter_from_keyboard(Stack *stack)
{
    std::string tmp;

    std::cout << "Введите элементы стека: " << std::endl;
    while(true)
    {

        std::getline(std::cin, tmp);

        try
        {
            (stack)->push(std::stoi(tmp));
        }
        catch (std::exception e)
        {
            std::cout << "Ввод закончен" << std::endl;
            break;
        }

        tmp.clear();

    }
}
int main() {

    int n = 0;
    std::cout << "Количество обьектов: " << std::endl;
    std::cin >> n;

    if (n <= 0 )
    {
        std::cout << "error: неверное значение" << std::endl;
        return 0;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    Stack *arr[n];


    for (int j = 0; j < n; ++j)
    {
        Stack *stack = new Stack();
        enter_from_keyboard(stack);
        arr[j] = stack;
        if (!del_odd(arr[j])) std::cout<< "error: не получилось удалить нечетные (по номеру сверху) элементы, т.к. стек пуст." << std::endl;
    }

    std:: cout << "\nВывод элементов массива." << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << "-й элемент :" << std::endl;

        if (!(arr[i]->print()))
        {
            std::cout << "Стек пуст." << std::endl;
        }
        delete(arr[i]);
    }


    return 0;
}