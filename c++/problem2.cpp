#include <iostream>

/*
Problema clássico.
*/
class Animal
{
public:
	Animal(std::string name) : name(name){}
	//pra limpar corretamente
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




int main()
{
	Cat cat("legal");
	cat.make_sound();
	std::cout << cat.GetName() << std::endl;
	return 0;
}