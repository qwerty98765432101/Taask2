#include <iostream>
#include "Header1.h"

using namespace std;


int main() {
	CirclarBuffer <int> queue(10);
	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);
	queue.Enqueue(5);

	queue.Enqueue(7);
	queue.makeEmpty();
	queue.Enqueue(8);
	queue.Enqueue(9);
	queue.Enqueue(10);
	queue.Enqueue(11);

	while (!queue.isEmpty())
	{
		cout << queue.Dequeue();
	}
	
	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);
	queue.Enqueue(5);
	queue.Enqueue(6);
	queue.Enqueue(7);
	cout << endl;
	CirclarBuffer<int>::Iterator it(queue);
	it.start();
	do {
		cout << it.getValue() << endl;
		it.next();

	} while (!it.finish());
	cout << it.getValue();

	//cout << it.buffer.getSize() << endl;
	//cout << it.buffer.sizeOf();
	//cout << queue.sizeOf();

}