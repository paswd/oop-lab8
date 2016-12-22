#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

//Кластер памяти
class AllocatorCluster {
private:
	bool Alloced; //Выделена ли память
	bool Empty; //Свободно ли
	void *Pointer; //Указатель на область памяти
	size_t Size; //Размер выделенной памяти

public:
	AllocatorCluster(void); //Конструктор
	~AllocatorCluster(void); //Деструктор

	void *Alloc(size_t size); //Выделить память
	void Free(void); //Освободить память

	bool IsEmpty(void); //Свободен ли кластер
	bool IsCurrentPointer(void *pointer); //Совпадает ли указатель с текущим
};

class Node {
public:
	std::vector <AllocatorCluster> Clusters; //Элементы на одной высоте дерева
	Node *Parent; //Ссылка на родителя
	Node *Child; //Ссылка на потомка
	size_t Level; //Текущая высота
};

class Allocator {
private:
	Node *Root; //Корень дерева
	size_t NConst; //Максимальное число потомков у одного листа
	//size_t ClusterSize;

public:
	//Methods
	Allocator(void); //Конструктор аллокатора
	~Allocator(void); //Деструктор аллокатора

	void *Alloc(size_t size); //Выделить память
	void Free(void *pointer); //Освободить память
};

#endif /* FIGURE_H */
