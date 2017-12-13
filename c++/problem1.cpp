#include <iostream>
#include <cstdlib>
#include <ctime>


/*
Apenas demonstração de conhecimento.

Utilzamos os conceitos de templates, arrays, algoritmo de busca linear e algoritmo de pesquisa(bubble sort)
*/


//função para retornar um número aleatório
std::size_t random (std::size_t low, std::size_t high) 
{
    return low + (rand() % (high - low + 1));
}

//start é o ponteiro inicial do obj e end é o ponteiro final.
//value é do tipo obj e constante passado por referência, assim não vai fazer uma cópia e não será possível modificar dentro da função.
template <class obj, class type> obj find(obj start, obj end, const type& value)
{
	//enquanto o ponteiro inicial for diferente do ponteiro final
	while(start != end)
	{
		//o valor do ponteiro na posição atual é igual ao que procuramos?
		if(*start == value)
		{
			//logo retornamos o ponteiro inicial.
			return start;
		}
		//incrementamos o ponteiro
		++start;
	}
	//retornamos o ponteiro final, padrão, estilo std::find do std.
	return end;
}

//dizemos que items é uma array do tipo obj e n é o seu tamanho.
template <class obj> void sort(obj items[], std::size_t n)
{
	//declaração das variáveis locais
	std::size_t  i , j;
	//de i até n-1;
	for(i = 0 ; i < n -1; i++)
	{
		//variável pra checar se já foi tudo ordenado
		bool swap = false;
		//de j + 1 até n. i = 0, logo j = 1 até n, depois j = i + 1 = 2 até n, logo j = i + 1 = 3 até n...
		for(j = i + 1; j < n; j++)
		{
			//se o item atual de i é maior que o de j, eu inverto os items.
			if(items[i] > items[j])
			{
				//variável temporária para receber o item
				obj tmp;
				tmp = items[i];
				items[i] = items[j];
				items[j] = tmp;
				//digo que foi trocado
				swap = true;
			}
		}
		//percorreu de j até n e não trocou nenhum? logo já está ordenada.
		if(!swap)
		{
			//paramos nossa função.
			break;
		}
	}
}

int main()
{
	//
	srand(time(NULL));

	//ponteiro , tamanho e maior valor
	int * vetor,size,highest = -9999999;

	//perguntamos e recebemos o valor do tamanho do vetor
	std::cout << "Digite o tamanho do vetor" << std::endl;
	std::cin >> size;

	//alocamos memória
	vetor = new int[size];

	//preenchemos de 0 até n - n o vetor com números aleatórios de 0 até 1024 e durante isso salvamos o maior número
	for(int i = 0 ; i < size; i++)
	{
		vetor[i] = random(0,1024);
		if(vetor[i] > highest)
		{
			highest = vetor[i];
		}
	}

	//útilizamos o algoritmo que criamos acima o de pesquisa, procuramos pelo maior número
	std::cout << "Maior numero:" << *find(vetor,vetor + size, highest) << std::endl;

	//agora utilizamos a função que criamos acima para organizar os items em ordem crescente.
	sort(vetor, size);

	std::cout << "Listar numeros em ordem" << std::endl;
	//percorremos o vetor e mostramos os valores
	for(int i = 0 ; i < size; i++)
	{
		std::cout << vetor[i] << std::endl;
	}
	return 0;
}