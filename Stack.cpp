//
// Created by gri on 07.04.16.
//

#include <stddef.h>
#include <iostream>
#include "Stack.h"

Stack::Stack()
{
    this->elem = new int[2];
    this->size = 0;
    this->capacity = 2;
}

Stack::Stack(int n)
{
    this->elem = new int[n];
    this->size = n;
    this->capacity = n;
}

Stack::~Stack()
{
    std::cout << "system: вызыван деструктор" << std::endl;
    delete[] this->elem;
    std::cout << "system: память освобождена" << std::endl;
}

Stack::Stack(const Stack &stack)
{
    std::cout << "system: вызван конструктор копирования" << std::endl;

    this->clear(); // Очищает все поля стека перед копированием.

    int capacity = stack.capacity;
    int size = stack.size;

    this->elem = new int[capacity];

    for (int i = 0; i < size; ++i)
    {
       this->elem[i] = stack.elem[i];
    }

    this->size = size;
    this->capacity = capacity;

}

int Stack::clear()
{
    delete[] this->elem;
    this->size = 0;
    this->capacity = 0;
}

bool Stack::isEmpty()
{
    return (size==0);
}

void Stack::push(int elem)
{
    if ((this->size+1) <= this->capacity)
    {
        this->elem[size] = elem;
        this->size++;
    }
    else
    {
        this->resize();

        this->elem[size] = elem;
        this->size++;

    }

}
void Stack::resize()
{
    int new_size = 2*this->size;
    int *tmp = new int[new_size];
    for (int i = 0; i < this->size; i++)
    {
        tmp[i] = this->elem[i];
    }
    delete[] this->elem;
    this->elem = NULL;


    this->elem = tmp;
    this->capacity = new_size;
}

int Stack::top()
{
    return this->elem[this->size-1];
}

int Stack::pop()
{
    if (this->size == 0) std::__throw_out_of_range("Невозможно удалить элемент. Стек пуст.");

    int tmp = this->elem[this->size - 1];
    this->elem[this->size - 1] = 0;
    this->size--;
    return tmp;

}

int Stack::get_size()
{
    return this->size;
}

int Stack::get_capacity()
{
    return this->capacity;
}

int Stack::del_odd()
// Метод удаляет все нечетные по номеру элементы сверху. Т.е. 1-й, 3-й и тд сверху.
{
    if (this->isEmpty()) return 0; //Стек пуст.

    int size = this->get_size();
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
            array[count] = this->pop(); // Четные перезаписываем в массив.
            count++;
        }
        else
        {
            this->pop(); //
        }
    }

    for (int j = arr_size - 1; j >= 0; --j)
    {
        this->push(array[j]);
    }

    delete[] array;

    return 1;
}