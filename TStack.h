#ifndef TSTACK_H
#define TSTACK_H
#include "TStackItem.h"
#include "TIterator.h"
#include <iostream>
#include <memory>
#include <future>
#include <mutex>
#include <pthread.h>

template <class T> class TStack {
public:
	//Конструктор
	TStack();

	//Добавление в стек
	void push(T* item);
	void push(std::shared_ptr<T> item);
	//Проверка на пустоту
	bool empty();
	size_t size();
	//Удаление из стека
	std::shared_ptr<T> pop();
	std::shared_ptr<T> pop_last();

	//Итератор: начало
	TIterator<TStackItem<T>, T> begin();
	//Итератор: конец
	TIterator<TStackItem<T>, T> end();

	std::shared_ptr<T> operator[] (size_t i);
	void sort();
	void sort_parallel();

	//Переопределение вывода
	template <class A> friend std::ostream& operator<<(std::ostream& os,const TStack<A>& stack);
	//Деструктор
	virtual ~TStack();

private:
	std::future<void> sort_in_background();
	std::shared_ptr<TStackItem<T>> head;
};
#endif /* TSTACK_H */
