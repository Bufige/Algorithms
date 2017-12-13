
#ifndef Stack_H
#define Stack_H


#include <iostream>

template<class T> class Stack
{

	public:
		Stack();		

		~Stack();

		void push(T data);
		

		void pop();

		void clear();

		bool empty();

		
		T top(); 

		std::size_t size() const;

		void PrintAll();

	private:
		class Node
		{
			public:
				//construtor do node
				Node(T data)
				{
					this->data = data;
					this->next = NULL;
				}

				//definir o dado.

				void setData(T data)
				{
					this->data = data;
				}
				//definir o proximo node.
				void setNext(Node * node)
				{
					this->next = node;
				}
				//pegar o dado.
				T getData()
				{
					return this->data;
				}
				//pegar proximo node.
				Node * getNext()
				{
					return this->next;
				}
			//dados protegidos.
			private:
				T data;
				Node * next;

		};

		Node *head, * end;
		std::size_t _size;

};

template<class T> Stack<T>::Stack()
{
	//inicializamos os items.
	this->head = this->end = NULL;
	this->_size = 0;
}

template<class T> Stack<T>::~Stack()
{
	//limpamos os items.
	this->clear();
}
template<class T> bool Stack<T>::empty()
{
	// está vázio?
	return (this->_size == 0);
}

template<class T> void Stack<T>::push(T data)
{
	//alocamos memória pro novo item
	Node * new_node = new Node(data);

	//alocou?
	if(new_node == NULL)
	{
		return ;
	}

	//está vázio?

	if(this->empty())
	{
		//dizemos que o head é o novo item.
		this->head = this->end = new_node;
	}
	else
	{

		//dizemos que o head é o next do ponteiro novo		

		new_node->setNext(this->head);
		//dizemos que o head agora é o novo ponteiro
		this->head = new_node;		
	}
	//aumentamos o total
	this->_size++;
}

template<class T> void Stack<T>::pop()
{
	//não está vázio?
	if(!this->empty())
	{
		//pegamos o próximo ponteiro
		Node * tmp = this->head->getNext();

		//deletamos o head
		delete head;

		//dizemos que o proximo ponteiro do antigo head é o novo head.
		head = tmp;

		//diminuimos o total
		this->_size--;
	}
}

template<class T> std::size_t Stack<T>::size() const
{
	//total de items.
	return this->_size;
}

template<class T> void Stack<T>::clear()
{
	//enquanto não estiver vázio
	while(!this->empty())
	{
		//tiramos o item do topo
		this->pop();
	}
	//dizemos que o head é nulo
	this->head = this->end = NULL;
}


template<class T> T Stack<T>::top()
{
	//pegamos o valor do item do topo
	return this->end != NULL ? this->end->getData()  : NULL;
}

template<class T> void Stack<T>::PrintAll()
{
	Node * tmp = this->head;
	while(tmp)
	{
		std::cout << tmp->getData() << std::endl;
		tmp = tmp->getNext();
	}
}


#endif