#include <iostream>
#include <stdlib.h>
#include <iterator>
#include "Header.h"

using namespace std;

	
        template <typename type>
		int CirclarBuffer<type>:: getTail() {
			return _tail;
		}
		template <typename type>
		int CirclarBuffer<type>:: getHead() {
			return _head;
		}
		template <typename type>
		int CirclarBuffer<type>::getSize() {
			return _bufferSize;
		}
		template <typename type>
		int CirclarBuffer<type>:: NextPosition(int position)
		{
			return (position + 1) % _bufferSize;
		}
		template <typename type>
		void CirclarBuffer<type>:: Enqueue(type toAdd)
		{

			_head = NextPosition(_head);
			Buffer[_head] = toAdd;
			if (isFull())
				_tail = NextPosition(_tail);
			else
				_length++;

		}

		template <typename type>
		type CirclarBuffer<type>:: Dequeue()
		{

			if (isEmpty()) throw exception("Queue exhausted");

			T dequeued = Buffer[_tail];
			_tail = NextPosition(_tail);
			_length--;
			return dequeued;
		}
		template <typename type>
		type CirclarBuffer<type>:: getElement() {
			if (isEmpty()) {
				throw exception("Очередь пуста");
			}
			else
				return Buffer[_tail];
		}
		template <typename type>
		int CirclarBuffer<type>:: sizeOf() {
			return _length;
		}
		template <typename type>
		void CirclarBuffer<type>:: makeEmpty() {
			_length = 0;
			_tail = 0;
			_head = _bufferSize - 1;
		}

		template <typename type>
		bool CirclarBuffer<type>:: isEmpty() {
			return(_length == 0);
		}
		template <typename type>
		bool CirclarBuffer<type>:: isFull() {
			return(_bufferSize == _length);
		}

		template <typename type>
		type CirclarBuffer<type>:: operator[](int index) {
			return Buffer[index];
		}
		



	