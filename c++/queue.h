
#ifndef QUEUE_H
#define QUEUE_H


#include <iostream>

template<class T> class Queue
{

	public:
		Queue();		

		~Queue();

		void push_back(T data);

		void push_front(T data);

		void pop();

		void clear();

		bool empty();

		T back();

		T front(); 

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

		Node *head,*end;
		std::size_t _size;

};


template<class T> Queue<T>::Queue()
{
	//inicializamos os items.
	this->head = this->end =  NULL;
	this->_size = 0;
}

template<class T> Queue<T>::~Queue()
{
	//limpamos os dados
	this->clear();
}
template<class T> bool Queue<T>::empty()
{
	//se estiver vázio retorna true.
	return (this->_size == 0);
}

template<class T> void Queue<T>::push_back(T data)
{
	//novo node.
	Node * new_node = new Node(data);

	//conseguiu alocar?
	if(new_node == NULL)
	{
		return ;
	}

	//está vázio?
	if(this->empty())
	{
		//adicionamos o novo node na head.
		this->head = this->end = new_node;
	}
	else
	{
		//não está vázio, vamos ao fim e definimos o next como o nosso novo node.
		this->end->setNext(new_node);
		//definimos o end, como o novo node.
		this->end = new_node;
	}
	//incrementamos o total de items
	this->_size++;
}
template<class T> void Queue<T>::push_front(T data)
{

	//novo node.
	Node * new_node = new Node(data);

	//conseguiu alocar?
	if(new_node == NULL)
	{
		return ;
	}

	//está vázio?
	if(this->empty())
	{
		//adicionamos o novo node na head.
		this->head = this->end = new_node;
	}
	else
	{
		//não está vázio, dizemos que o proximo do novo valor é o head.
		this->new_node->setNext(head);
		//dizemos que o head agora é o novo node.
		this->head = new_node;
	}
	//incrementamos o total.
	this->_size++;
}

template<class T> void Queue<T>::pop()
{
	//está vázio?
	if(!this->empty())
	{
		//pegamos o proximo ponteiro do head e atribuímos numa variável temporaria
		Node * tmp = this->head->getNext();

		//deletamos o head.
		delete head;

		//dizemos que o head agora é o proximo do antigo head.
		head = tmp;

		//diminuímos o total.

		this->_size--;
	}
}

template<class T> std::size_t Queue<T>::size() const
{

	//retornamos o total de items
	return this->_size;
}

template<class T> void Queue<T>::clear()
{

	//enquanto não estiver vázio
	while(!this->empty())
	{
		//removemos os items do topo.
		this->pop();
	}
	//dizemos que está vázio.
	this->head = this->end = NULL;
}

template<class T> T Queue<T>::back()
{
	//retornamos o valor do final do queue
	return this->end != NULL ? this->end->getData() : NULL;
}

template<class T> T Queue<T>::front()
{
	//retornamos o valor do começo da queue
	return this->head != NULL ? this->head->getData()  : NULL;
}

template<class T> void Queue<T>::PrintAll()
{
	//pegamos head
	Node * tmp = this->head;
	//enquanto o head não for nulo
	while(tmp)
	{
		//mostramos os valores
		std::cout << tmp->getData() << std::endl;
		//agora apontamos pro proximo ponteiro.
		tmp = tmp->getNext();
	}
}


#endif