#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>


struct Node
{
	int data;
	struct Node *next;
};

int _size = 0;

struct Node * head = NULL, * end = NULL;

struct Node * new_node(int data)
{
	//alocamos a memória pro novo ponteiro
	struct Node * p  = (struct Node * )malloc(sizeof(struct Node));
	//atribuímos o nosso valor à esse ponteiro
	p->data = data;
	//dizemos que o próximo é nulo
	p->next = NULL;
	//retornamos p.
	
	return p;
}

void push_back(int data)
{
	//criamos um novo valor
	struct Node * new_value = new_node(data);
	
	//não foi possível alocar memória.
	if(!new_value)
	{
		return ;
	}

	//checamos se o head está nulo
	if(!head)
	{		
		//se estiver, dizemos que o novo valor é o head.
		head = end = new_value;	
		
	}
	else
	{		
		//utilizamos um ponteiro pro final
		struct Node * temp = end;

		//atribuímos no final da fila
		temp->next = new_value;
		//dizemos que o novo ponteiro é o final.
		end = new_value;
	}
	_size++;
}

void push_front(int data)
{
	struct Node * new_value = new_node(data);
	
	//não foi possível alocar memória.
	if(!new_value)
	{
		return ;
	}

	//checamos se o head está nulo
	if(!head)
	{		
		//se estiver, dizemos que o novo valor é o head.
		head = new_value;		
	}
	else
	{
		//o ponteiro do proximo valor é o head
		new_value->next = head;
		//o head é o novo valor.
		head = new_value;
	}
}

void pop()
{
	//checamos se está nulo
	if(!head)
	{
		//retornamos nada
		end = NULL;
		return ;
	}
	else
	{
		//apontamos pro próximo item do head.
		struct Node * temp = head->next;
		//liberamos os dados do head
		free(head);
		//dizemos que o head é o próximo
		head = temp;
	}
	//diminuimos o valor total
	_size--;	
}


int size()
{
	return _size;
}

bool empty()
{
	return (_size == 0);
}

void print_all()
{
	//checamos se está nulo
	if(!head)
	{
		//retorna nada
		return ;
	}


	int i = 0;
	struct Node * temp = head;
	//mostramos todos os valores da nossa queue
	do
	{
		printf("%d --- %d\n",i,temp->data);
		temp = temp->next;
		i++;
	}
	while(temp != NULL);
}



int main()
{
	int array[] = {512,128,256,64,32,2,8,4,1,16};

	for(int i = 0; i < 10; i++)
	{		
		push_back(array[i]);
	}
	print_all();
	printf("------------------\n");
	pop();
	pop();
	print_all();
	printf("------------------\n");
	push_front(1024);

	print_all();
	return 0;
}