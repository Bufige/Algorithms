#include <iostream>

/*
Problema clássico.
*/
class Animal
{
public:
	Animal(std::string name) : name(name){}
	//pra limpar corretamente caso vá implementar algo dinâmico, o que não é o nosso caso.
	virtual ~Animal(){}

	//implementar nas classes derivadas
	virtual void make_sound() = 0;

	std::string GetName()
	{
		return this->name;
	}

protected:
	//acessar nas classes derivadas
	std::string name;
};


class Cat : public  Animal 
{
public:
	//pode usar o using caso a base n seja public
	//using Animal::GetName;
	Cat(std::string name) : Animal(name) {}

	 void make_sound() override
	{
		std::cout << "cat sound" << std::endl;
	}
};


class Dog : public  Animal 
{
public:
	//pode usar o using caso a base n seja public
	//using Animal::GetName;
	Dog(std::string name) : Animal(name) {}

	 void make_sound() override
	{
		std::cout << "dog sound" << std::endl;
	}
};




int main()
{
	Cat cat("abc");
	Dog dog("zyx")
	cat.make_sound();
	std::cout << cat.GetName() << std::endl;
	dog.make_sound();
	std::cout << dog.GetName() << std::endl;
	return 0;
}