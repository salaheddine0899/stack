#pragma once
#include <assert.h>
namespace Algo {

	template <class T>
	class Node
	{
	public:
		/*Node();
		~Node();
		T* get()const {
			return this->data;
		}
		void set(T* s) {
			this->data = s;
		}*/

	private:
		T* data;
		Node* next;

		template <class T>
		friend class Stack;

	};

	template <class T>
	class Stack
	{
	private:
		Node<T> *head;
		Stack();
		~Stack();
	public:
		void push(T* e);
		void pop();
		bool empty()const;
		T* top()const;
		static Stack* creator();
		static void garabage(Stack* s);
	};

	template <class T>
	Stack<T>::~Stack()
	{
		while (this->head)
		{
			this->pop();
		}
	}
	template <class T>
	Stack<T>::Stack()
	{
		this->head = 0;
	}
	template <class T>
	void Stack<T>::push(T* e)
	{
		Node<T>* newNode = new Node<T>();
		assert(newNode);//debugage.
		//try catch //mode release.
		newNode->data = e;
		newNode->next = this->head;
		this->head = newNode;
	}

	template <class T>
	void Stack<T>::pop()
	{
		assert(!this->empty());
		Node<T>* supp = this->head;
		this->head = this->head->next;
		delete supp;
		supp = nullptr;

	}

	template <class T>
	bool Stack<T>::empty() const
	{
		return !(this->head);
	}

	template <class T>
	T* Stack<T>::top() const
	{
		assert(!this->empty());
		return this->head->data;
	}

	template <class T>
	Stack<T>* Stack<T>::creator()
	{
		Stack* s = new Stack();
		return s;
	}



	template <class T>
	void Stack<T>::garabage(Stack* s)
	{
		assert(s);
		delete s;
	}
}


