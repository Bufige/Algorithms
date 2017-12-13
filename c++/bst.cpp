#include <iostream>


struct Node
{
	int data;
	Node * left, * right;
};


class Tree
{
public:
	Tree()
	{
		this->root = NULL;
	}
	void Insert(int data);
	Node * Search(int data);
	void Delete(int data);
	void PrintAll()
	{
		PrintAll(this->root);
	}
	
private:	
	Node * root;
	Node * new_node(int data)
	{
		Node * tmp = new Node;
		tmp->data = data;
		tmp->left = tmp->right = NULL;
		return tmp;
	}
	void PrintAll(Node * root)
	{
		if(root != NULL)
		{
			this->PrintAll(root->left);
			std::cout << root->data << std::endl;
			this->PrintAll(root->right);			
		}
	}

};

void Tree::Insert(int data)
{
	//root está vázio?
	if(this->root == NULL)
	{
		//adicionamos no root
		this->root = this->new_node(data);
		return ;
	}
	else
	{
		//vars
		Node * current = this->root, *parent = NULL;
		//var pra saber o lado que está no parent o current.
		bool side;

		while(current != NULL)
		{
			//dizemos que o atual é o parent
			parent = current;

			//já existe a informação na tree
			if(data == current->data)
			{
				//paramos a func aqui
				return ;
			}
			//se data for maior que a data de current vamos pra direita, caso contrário pra esquerda.

			current = data > current->data ? (side = 1,current->right) : (side = 0,current->left);
		}
		//current está do lado direito?
		if(side)
		{
			//criamos no lado direito de parent
			parent->right = this->new_node(data);
		}
		else
		{
			//criamos do lado esquerdo
			parent->left = this->new_node(data);
		}
	}
}
Node * Tree::Search(int data)
{
	//root está vázio?
	if(this->root == NULL)
	{
		//retornamos null
		return NULL;
	}
	else
	{
		//vars
		Node * current = this->root;
		//enquanto current não for nulo
		while(current)
		{
			//já existe? retornamos o ponteiro 
			if(data == current->data)
			{							
				return current;
			}
			//se data for maior que a data de current vamos pra direita, caso contrário pra esquerda.
			current = data > current->data ? current->right : current->left; 					
		}
	}

}
void Tree::Delete(int data)
{
	//root é nulo?
	if(this->root == NULL)
	{
		//paramos aqui
		return ;
	}
	else
	{
		//vars
		Node * current = this->root, * parent = NULL;
		//var para saber o lado que do parent está o ponteiro atual
		bool side;

		//
		while(current)
		{
			//data = a data do ponteiro atual?
			if(data == current->data)
			{
				//achamos o ponteiro alvo.
				break;
			}
			else
			{
				//dizemos que o parent é o atual que já foi analisado
				parent = current;
				//descobrimos para que lado temos que na arvore.
				current = data > current->data ? (side = 1,current->right) : (side = 0,current->left);
			}
		}

		//encontrou o valor?
		if(current == NULL)
		{
			//não encontrou
			return;
		}

		//para caso seja um leaf.

		if(current->right == NULL && current->left == NULL)
		{
			//é um leaf, definimos como nulo e deletamos.

			if(parent == NULL)
			{
				//definimos o root como nulo
				this->root = NULL;				
			}
			else
			{
				//verificamos em qual lado a leaf é do parent
				if(side)			
				{				
					parent->right = NULL;
				}
				else
				{
					parent->left = NULL;
				}				
			}
			//deletamos o ponteiro current
			delete current;
		}		
		else
		{
			//current tem 1 filho
			if(current->right == NULL || current->left == NULL)
			{
				//é o ponteiro válido do filho de current
				Node * tmp = (current->right == NULL ? current->left : current->right);

				//parent é nulo? logo current é o root
				if(parent == NULL)
				{
					delete current;
					this->root = tmp;
				}
				else // caso não seja o root
				{
					//o filho esquerdo é nulo?
					if(current->left == NULL)
					{
						//o current é de que lado do parent?
						if(side)
						{
							//current é do lado direito de parent.
							parent->right = tmp;
						}
						else
						{
							//current é do lado esquerdo de parent.
							parent->left = tmp;
						}
					}
					else
					{
						//filho direito nulo
						if(side)
						{
							//current é do lado direito de parent.
							parent->right = tmp;
						}
						else
						{
							//current é do lado esquerdo de parent.
							parent->left = tmp;
						}
					}
					delete current;
				}
			}
			else
			{
				//tem 2 filhos!

				Node * replace_right = current->right, * parent_replace = NULL ;
				//se o lado continuar right, significa que replace_right = current->right
				side = 1;

				//enquanto replace right não for nulo
				while(replace_right)
				{
					//atualizamos o parent do replace.
					parent_replace = replace_right;
					//dizemos que o replace agora é o da arvore da esquerda.
					replace_right = replace_right->left;
					//como entrou no loop, temos certeza que está na arvore da esquerda
					side = 0;
				}

				//substituimos o menor valor no lugar do valor que vai ser deletado e deletamos o menor valor da arvore.
				if(side)
				{
					parent->right = parent_replace->left;
				}
				else
				{
					parent->left = parent_replace->left;
				}
				//deletamos a leaf encontrada1
				delete parent_replace->left;
			}
		}
	}
}



int main()
{
	std::cin.tie(NULL); std::cout.sync_with_stdio(false);

	Tree tree;

	tree.Insert(1);
	tree.Insert(5);
	tree.Insert(3);
	tree.Insert(4);
	tree.Insert(10);
	tree.Insert(6);
	tree.Insert(7);
	tree.Insert(8);

	tree.PrintAll();
	
	std::cout << std::endl;
	tree.Delete(3);
	tree.PrintAll();
	
	
	return 0;
}