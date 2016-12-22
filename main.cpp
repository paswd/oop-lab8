#include <iostream>
#include "square.h"
#include "trapeze.h"
#include "rectangle.h"
#include "TStack.h"

using namespace std;

int main(void)
{
	//TStack *stack = new TStack;
	TStack <Figure> stack;
	cout << "-------------------------------------------\n";
	cout << "Commands:\n";
	cout << "s <value> - push Square to stack\n";
	cout << "t <value> - push Trapeze to stack\n";
	cout << "r <value> - push Rectangle to stack\n";
	cout << "d - pop from stack and print popped item\n";
	cout << "p - print stack\n";
	cout << "q - sort basic\n";
	cout << "Q - sort parallel\n";
	cout << "q - exit\n";
	cout << "-------------------------------------------\n";
	//int cnt = 0;
	while (true) {
		//cout << "%d\n", cnt;
		//cnt++;
		char cmd;
		std::shared_ptr<Figure> value;
		bool is_finished = false;
		scanf("%c", &cmd);
		switch (cmd) {
			case 'q':
				is_finished = true;
				break;
			case 's':
				//value = (Item) FSquare(std::cin);
				//value 
				//cin >> value;
				stack.push(std::make_shared <FSquare> (cin));
				break;
			case 't':
				//value = (Item) FSquare(std::cin);
				//cin >> value;
				stack.push(std::make_shared <Trapeze> (cin));
				break;
			case 'r':
				//value = (Item) FSquare(std::cin);
				//cin >> r_value;
				stack.push(std::make_shared <Rectangle> (cin));
				break;
			case 'd':
				value = stack.pop();
				if (value != NULL)
					cout << *value << endl;
				break;

			case 'q':
				stack.sort();
				break;

			case 'Q':
				stack.sort_quick();
				break;

			case 'p':
				//stack.Print();
				//cout << stack << endl;
				for (auto i : stack) {
					cout << *i << endl;
				}
				break;
			case '\n':
				break;
			default:
				cout << "Invalid command " << cmd << "\n";
				break;
		}
		if (is_finished) break;
	}
	cout << "Goodbye!\n";

	//delete stack;

	return 0;
}
