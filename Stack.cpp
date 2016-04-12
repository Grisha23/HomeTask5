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

bool Stack::empty()
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

int Stack::print()
{
    if (size == 0) return 0; // Стек пуст

    std::cout << "Элементы стека: " << std::endl;

    for (int i = this->size - 1; i >= 0; --i)
    {
        std::cout << this->elem[i] << std::endl;
    }

    return 1;
}