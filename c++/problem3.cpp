#include <iostream>






class BankAccount
{
public:
	BankAccount(std::string name, double balance) : name(name), balance(balance) {}

	virtual ~BankAccount() {};
	virtual void Deposit(double amount) = 0;
	virtual void WithDraw(double amount) = 0;

	double GetBalance() const 
	{
		return this->balance;
	}
	std::string GetName()
	{
		return this->name;
	}


	void Info()
	{
		std::cout << "Name:" << this->name << " - Balance: " << this->balance << std::endl;
	}


protected:
	std::string name;
	double balance;
};


class CheckingAccount : public BankAccount
{
public:

	CheckingAccount(std::string name, double balance, double interest = 0.01) : BankAccount(name,balance) , interest(interest)
	{

	}

	void Deposit(double amount)
	{
		this->balance += amount;
	}

	void WithDraw(double amount)
	{
		//não é possível retirar mais do que tem
		if(amount > this->balance || amount < 0)
		{
			return ;
		}
		else
		{
			this->balance -= amount + (amount * this->interest);
		}
	}
private:
	double interest;
};


class SavingAccount : public BankAccount
{
public:
	SavingAccount(std::string name, double balance, double requital = 0.01) : BankAccount(name,balance) , requital(requital)
	{

	}
	void Deposit(double amount)
	{
		this->balance += amount;
	}

	void WithDraw(double amount)
	{
		//não é possível retirar mais do que tem
		if(amount > this->balance || amount < 0)
		{
			return ;
		}
		else
		{
			this->balance += (amount * this->requital);
			this->balance -= amount;
		}
	}


protected:
	// juros da poupança que o usuário vai receber(implelementação bem naive)
	double requital;

};

int main()
{
	CheckingAccount account("leonardo igor", 1000);

	account.Info();
	account.Deposit(500);
	account.WithDraw(100);


	account.Info();
	return 0;
}