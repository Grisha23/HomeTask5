//
// Created by gri on 07.04.16.
//

#ifndef HOME_TASK_5_STACK_H
#define HOME_TASK_5_STACK_H


class Stack {

private:
    int *elem;
    int size;
    int capacity;

    void resize(); // расширяет внутренний массив в 2 раза
    int clear(); // Очищает стек.  private?

public:
    Stack(); // Выделяет память под 2 элемента
    Stack(int n); // Выделяет память под n элементов
    ~Stack();
    Stack(const Stack &stack);


    int top(); //Возвращает "верхний" элемент.
    void push(int elem); // Вставляет элемент "на верх" стека.
    int get_size(); //
    int get_capacity();
    int pop(); //Возвращает значение удаленного элемента
    bool isEmpty(); //

    int del_odd();

    friend std::ostream& operator << (std::ostream &ostream, const Stack &stack);



};


#endif //HOME_TASK_5_STACK_H
