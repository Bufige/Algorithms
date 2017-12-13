#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>


struct Node
{
	int data;
	struct Node *previous,*next;
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
	p->previous = p->next = NULL;
	//retornamos p.

	return p;
}

int size()
{
	return _size;
}

bool empty()
{
	return (_size == 0);
}

void push_back(int data)
{
	struct Node * new_value = new_node(data);

	if(!new_value)
	{
		return ;
	}


	if(!head)
	{
		head = new_value;	

		end = head;	
	}	
	else
	{
		struct Node * temp = end;

		//o proximo ponteiro é o novo valor
		temp->next = new_value;
		//dizemos que o novo ponteiro é o final.
		temp->next->previous = end;
		//dizemos que o final é o novo ponteiro
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
		head->previous = new_value;

		new_value->next = head;
		//o head é o novo valor.
		head = new_value;
	}
	_size++;
}

void print_linear()
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

void print_reverse()
{
	//checamos se está nulo
	if(!head)
	{
		//retorna nada
		return ;
	}


	int i = 0;
	struct Node * temp = end;
	//mostramos todos os valores da nossa queue
	do
	{
		printf("%d --- %d\n",i,temp->data);
		temp = temp->previous;
		i++;
	}
	while(temp != NULL);
}


void pop_front()
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
		//definimos o anterior como nulo.
		head->previous = NULL;
	}
	_size--;
}


void pop_back()
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
		struct Node * temp = end->previous;
		//liberamos os dados do head
		free(end);
		//dizemos que o head é o próximo
		end = temp;
		end->next = NULL;
	}	
	_size--;
}

int find(int data)
{
	if(!head)
	{
		return false;
	}
	else
	{
		//ponteiro do inicio
		struct Node * temp = head;
		do
		{
			//checamos se o valor é igual aos valores percorrido
			if(temp->data == data)
			{
				//é igual
				return data;
			}		
			//iremos pro proximo
			temp = temp->next;			
		}
		while(temp != NULL);
	}
	return -1;
}

//swap, trocamos os valores de a por b e de b por a.
void swap(struct Node *a, struct Node *b)
{
	a->data ^= b->data;
	b->data ^= a->data;
	a->data ^= b->data;
}

//bubble sort reference -> https://en.wikipedia.org/wiki/Bubble_sort
void sort()
{
	//vázio
	if(!head)
	{
		return ;
	}	
	else
	{
		bool _swap;
		struct Node * temp, * previous = NULL;
		//loop
		do
		{
			//ponteiro pra cabeça
			temp = head;
			//pra saber se já percorremos
			_swap = 0;


			//checamos se proximo != do anterior.
			while(temp->next != previous)
			{
				//checamos se o atual é maior que o proximo
				if(temp->data > temp->next->data)
				{
					//trocamos os valores
					swap(temp,temp->next);
					//definimos que a troca foi feita.
					_swap = true;
				}
				//o ponteiro atual é o proximo ponteiro agora.
				temp = temp->next;
			}
			//ponteiro atual é o anterior agora.
			previous = temp;
		}
		while(_swap); 
		// se swap for falso, ou seja, atual->data <= atual->proximo->data, logo já organizamos a lista.
	}
}



int main()
{
	int array[] = {512,128,256,64,32,2,8,4,1,16};

	for(int i = 0; i < 10; i++)
	{		
		push_back(array[i]);
	}
	
	printf("------------------\n");
	sort();
	print_linear();
	printf("------------------\n");
	pop_front();
	pop_back();
	print_reverse();
	printf("------------------\n");
	printf("found:%d\n",find(64));
	
	return 0;
}