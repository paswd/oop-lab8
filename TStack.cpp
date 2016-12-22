#include "TStack.h"

template <class T> TStack<T>::TStack() : head(NULL) {
}

template <class T> std::shared_ptr<T> TStack<T>::operator[](size_t i) {
	if (i > size() - 1) {
		throw std::invalid_argument("index greater then stack size");
	}
	size_t j = 0;
	for (std::shared_ptr<T> a : *this) {
		if (j == i) {
			return a;
		}
		j++;
	}
	return std::shared_ptr<T>(NULL);
}

template <class T> void TStack<T>::sort() {
	if (size() > 1) {
		std::shared_ptr<T> middle = pop();
		TStack<T> left, right;
		while (!empty()) {
			std::shared_ptr<T> item = pop();
			if (*item < *middle) {
				left.push(item);
			} else {
				right.push(item);
			}
		}
		left.sort();
		right.sort();
		while (!left.empty()) {
			push(left.pop_last());
		}
		push(middle);
		while (!right.empty()) {
			push(right.pop_last());
		}
	}
}

template<class T > std::future<void> TStack<T>::sort_in_background() {
	std::packaged_task<void(void) >
	task(std::bind(std::mem_fn(&TStack<T>::sort_parallel), this));
	std::future<void> res(task.get_future());
	std::thread th(std::move(task));
	th.detach();
	return res;
}
template <class T> void TStack<T>::sort_parallel() {
	if (size() > 1) {
		std::shared_ptr<T> middle = pop_last();
		TStack<T> left, right;
		while (!empty()) {
			std::shared_ptr<T> item = pop_last();
			if (*item < *middle) {
				left.push(item);
			} else {
				right.push(item);
			}
		}
		std::future<void> left_res = left.sort_in_background();
		std::future<void> right_res = right.sort_in_background();
		left_res.get();
		while (!left.empty()) {
			push(left.pop_last());
		}
		push(middle);

		right_res.get();
		while (!right.empty()) {
			push(right.pop_last());
		}
	}
}

template <class T> std::ostream& operator<<(std::ostream& os, const TStack<T>& stack) {
	std::shared_ptr<TStackItem<T>> item = stack.head;

	while(item != NULL) {
		os << *item;
		item = item->GetNext();
	}

	return os;
}
template <class T> void TStack<T>::push(T *item) {
	std::shared_ptr<TStackItem < T >> other(new TStackItem<T>(item));
	other->SetNext(head);
	head = other;
}
template <class T> void TStack<T>::push(std::shared_ptr<T> &&item) {
	std::shared_ptr<TStackItem<T>> other(new TStackItem<T>(item));
	other->SetNext(head);
	head = other;
}
template <class T> bool TStack<T>::empty() {
	return head == NULL;
}
template <class T> std::shared_ptr<T> TStack<T>::pop() {
	std::shared_ptr<T> result;
	if (head != NULL) {
		result = head->GetItem();
		head = head->GetNext();
	}
	return result;
}
template <class T> std::shared_ptr<T> TStack<T>::pop_last() {
	std::shared_ptr<T> result;
	if (head != NULL) {
		std::shared_ptr<TStackItem < T>> element = head;
		std::shared_ptr<TStackItem < T>> prev = NULL;
		while (element->GetNext() != NULL) {
			prev = element;
			element = element->GetNext();
		}
		if (prev != NULL) {
			prev->SetNext(NULL);
			result = element->GetItem();
		} else {
			result = element->GetItem();
			head = NULL;
		}
	}
	return result;
}

template <class T> TIterator<TStackItem<T>,T> TStack<T>::begin()
{
	return TIterator<TStackItem<T>,T>(head);
}
template <class T> TIterator<TStackItem<T>,T> TStack<T>::end()
{
	return TIterator<TStackItem<T>,T>(NULL);
}

template <class T> TStack<T>::~TStack() {

}


template class TStack<Figure>;
template std::ostream& operator<<(std::ostream& os, const TStack<Figure> &stack);
