#ifndef TSTACKITEM_H
#define TSTACKITEM_H
#include <memory>
#include "figure.h"
#include "allocator.h"

template<class T> class TStackItem {
public:
	//Конструктор
	TStackItem(T *item);
	TStackItem(std::shared_ptr<T> item);
	//Allocator allocator();
	//Переопределение вывода
	template<class A> friend std::ostream& operator<<(std::ostream& os, const TStackItem<A>& obj);

	//Установка следующего элемента
	std::shared_ptr<TStackItem<T>> SetNext(std::shared_ptr<TStackItem> next);
	//Получить следующий элемент
	std::shared_ptr<TStackItem<T>> GetNext();
	//Получить значение текущего элемента
	std::shared_ptr<T> GetItem() const;
	//Переопределение аллокатора
	void *operator new(size_t size);
	//Переопределение деаллокатора
 	void operator delete(void *p);
	//Деструктор
	virtual ~TStackItem();
private:
	std::shared_ptr<T> item;
	std::shared_ptr<TStackItem<T>> next;
	static Allocator allocator; //Аллокатор
};
#endif /* TSTACKITEM_H */
