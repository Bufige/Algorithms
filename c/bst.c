#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>


struct Node
{
	int data;
	struct Node *left,*right;
};



struct Node * new_node(int data)
{

	//alocamos a memória pro novo ponteiro
	struct Node * p  = (struct Node * )malloc(sizeof(struct Node));
	//atribuímos o nosso valor à esse ponteiro
	p->data = data;
	//dizemos que o próximo é nulo
	p->left = p->right = NULL;
	//retornamos p.

	return p;
}

struct Node * insert(struct Node * leaf,int data)
{
	//posição atual existe um item?
	if(!leaf)
	{		
		//não existe logo vamos colocar aqui e paramos a recursão.
		return new_node(data);
	}
	else
	{
		//o dado que queremos inserir é maior que o dado atual?
		if (data > leaf->data)
		{
			//se for, dizemos que a folha da direita é igual a função resurva para a folha da direita.
			//assim repetimos o processo até achar
        	leaf->right  = insert(leaf->right, data);
		}
    	else if (data < leaf->data)
    	{
    		//mesma coisa acima.
        	leaf->left = insert(leaf->left, data);
    	}
    	else 
    	{
    		//valor já existe, logo não adicionamos e paramos a recursão.
        	return leaf;
        }
	}
}

struct Node * find(struct Node * leaf, int data)
{
	//folha atual é nula?
	if(leaf != NULL)
	{
		//se a folha atual é igual ao que procuramos, paramos aqui.
		if(data == leaf->data)
		{
			return leaf;
		}
		else if(data > leaf->data) //o dado que procuramos, é maior que o dado da folha atual?
		{
			//se for, vamos pra folha da direita. 
			return find(leaf->right,data);
		}
		else
		{
			//não é maior, logo vamos para a folha da esquerda.
			return find(leaf->left,data);
		}		
	}
	//percorremos tudo e não achamos nada, logo vamos retornar nulo.
	return NULL;
}

void print_all(struct Node * leaf)
{
	//folha atual é nula?
	if(leaf != NULL)
	{		
		//percorremos as folhas da esquerda que são as menores valores.
		print_all(leaf->left);
		//mostramos o dado da folha atual.
		printf("%d\n", leaf->data);
		//percorremos as folhas da direita que são os maiores valores.
		print_all(leaf->right);
	}
}

void clear(struct Node * leaf)
{
	//o ponteiro atual é nulo?
	if(leaf != NULL)
	{
		//começamos pelos valores menores.
		clear(leaf->left);
		//depois vamos aos maiores
		clear(leaf->right);
		//limpamos o atual.
		free(leaf);
	}
}


int main()
{
	int array[] = {512,128,256,64,32,2,8,4,1,16};


	struct Node * root = NULL;
	for(int i = 0; i < 10; i++)
	{		
		root = insert(root,array[i]);		
	}
	
	print_all(root);

	struct Node * found = find(root,64);

	printf("encontrado:%d\n", found != NULL ? found->data : -1);
	clear(root);
	return 0;
}