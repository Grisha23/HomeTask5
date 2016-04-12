#include <iostream>
#include <limits>
#include "Stack.h"
#include "string"
#include "string.h"


void enter_from_keyboard(Stack &stack)
{
    std::string tmp;

    std::cout << "Введите элементы стека: " << std::endl;
    while(true)
    {

        std::getline(std::cin, tmp);

        try
        {
            stack.push(std::stoi(tmp));
        }
        catch (std::exception e)
        {
            std::cout << "Ввод закончен" << std::endl;
            break;
        }

        tmp.clear();

    }
}

std::ostream& operator << (std::ostream &ostream, const Stack &stack)
{
    if (stack.size == 0)
    {
        ostream << "Стек пуст.\n";
        return ostream;
    }
    for (int i = stack.size - 1; i >= 0; --i)
    {
        ostream << stack.elem[i] << "\n";
    }
    return ostream;
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
        enter_from_keyboard(*stack);
        arr[j] = stack;
        if (!(arr[j]->del_odd())) std::cout<< "error: не получилось удалить нечетные (по номеру сверху) элементы, т.к. стек пуст." << std::endl;
    }

    std:: cout << "\nВывод элементов массива." << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << i << "-й элемент :" << std::endl;

        std::cout << *arr[i] << std::endl;
        delete(arr[i]);
    }


    return 0;
}