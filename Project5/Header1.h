#pragma once
using namespace std;

template <typename type>

class CirclarBuffer {

	type* Buffer;
	int _head;
	int _tail = 0;
	int _length = 0;
	int _bufferSize;
public:
	CirclarBuffer() : _head(0), _tail(0), _length(0), _bufferSize(0), Buffer(nullptr) {};
	CirclarBuffer(int bufferSize) {
		Buffer = new type[bufferSize];
		_bufferSize = bufferSize;
		_head = _bufferSize - 1;

	}

	int getTail() {
		return _tail;
	}
	
	int getHead() {
		return _head;
	}
	
	int getSize() {
		return _bufferSize;
	}
	
	int NextPosition(int position)
	{
		return (position + 1) % _bufferSize;
	}
	
	void Enqueue(type toAdd)
	{
		if (isFull()) {
			throw exception("Queue is full");
		}
		else {
			_length++;
			_head = NextPosition(_head);
			Buffer[_head] = toAdd;

		}
	}
	
	type Dequeue()
	{

		if (isEmpty()) throw exception("Queue exhausted");

		type dequeued = Buffer[_tail];
		_tail = NextPosition(_tail);
		_length--;
		return dequeued;
	}
	
	type getElement() {
		if (isEmpty()) {
			throw exception("Очередь пуста");
		}
		else
			return Buffer[_tail];
	}
	
	int sizeOf() {
		return _length;
	}
	
	void makeEmpty() {
		_length = 0;
		_tail = 0;
		_head = _bufferSize - 1;
	}

	
	bool isEmpty() {
		return(_length == 0);
	}
	
	bool isFull() {
		return(_bufferSize == _length);
	}

	
	type  operator[](int index) {
		return Buffer[index];
	}




	class Iterator {
	public:

		CirclarBuffer buffer;
		int current;

	public:



		Iterator(CirclarBuffer& buffer) {
			this->buffer = buffer;
		}

		void start() {
			current = buffer.getTail();
		}

		void next() {
			current = (current + 1) % buffer.getSize();
		}

		bool finish() {
			return current == buffer.getHead();
		}


		type getValue() {
			return buffer[current];
		}
	};
};