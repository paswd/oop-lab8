#ifndef TITERATOR_H
#define TITERATOR_H
#include <memory>
#include <iostream>

template <class node, class T>
class TIterator {
public:
	//Конструктор
	TIterator(std::shared_ptr<node> n) {
		node_ptr = n;
	}
	//Переопределение указателя
	std::shared_ptr<T> operator * (){
		return node_ptr->GetItem();
	}
	//Переопределение элемента объект (по ссылке)
	std::shared_ptr<T> operator -> (){
		return node_ptr->GetItem();
	}
	//Переопределение инкремента
	void operator ++ (){
		node_ptr = node_ptr->GetNext();
	}
	//Переопределение инкремента
	TIterator operator ++ (int){
		TIterator iter(*this);
		(*this)++;
		return iter;
	}
	//Переопределение равенства
	bool operator == (TIterator const& i){
		return node_ptr == i.node_ptr;
	}
	//Переопределение неравенства
	bool operator != (TIterator const& i){
		return !(*this == i);
	}
private:
	std::shared_ptr<node> node_ptr;
};

#endif
