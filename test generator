#include<fstream>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<array>
#include<functional>
#include<deque>
#include<math.h>
#include<unordered_set>
#include<queue>
#include<list>
#include<set>
#include<iomanip>
#include<bitset>
using namespace std;
class Bancomat
{
private:
	int bani = 0, plafon = 10000, client[10000],exista[10000];
public:
	Bancomat()
	{
		for (int i = 0; i <= 9999; i++)
		{
			client[i] = 0;
			exista[i] = 0;
		}
	}
	void retragere()
	{
		int cont;
		cout << "Dinn ce cont doriti sa retrageti bani? ";
		cin >> cont;
		int sum;
		cout << "Ce suma doriti sa retrageti?: ";
		cin >> sum;
		try
		{
			if (client[cont] < sum)
				throw "Nu aveti destui bani.";
			else
				if (sum > plafon)
					throw "Nu mai e plafon.";
				else
					client[cont] -= sum;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
		cout << "Sold curent:" << client[cont]<<'\n';
	}
	void adaugare()
	{
		int cont;
		cout << "In ce cont doriti sa adaugati bani? ";
		cin >> cont;
		int sum;
		cout << "Ce suma doriti sa introduceti?: ";
		cin >> sum;
		try
		{
			if (rand() % 10 == 1)
				throw "Banii sunt falsi.";
			else
			{
				client[cont] += sum;
				exista[cont] = 1;
			}
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
		cout << "Sold curent:" << client[cont] << '\n';
	}
	void transfer()
	{
		int sender;
		cout << "Cine este senderul?: ";
		cin >> sender;
		int reciever;
		cout << "Cine este recieverul?: ";
		cin >> reciever;
		int sum;
		cout << "Ce suma doriti sa trimiteti?: ";
		cin >> sum;
		try
		{
			if (client[sender] < sum)
				throw "Nu aveti destui bani.";
			else
				if (sum > plafon)
					throw "Nu mai e plafon.";
				else
					if (exista[reciever] == 0)
						throw "Nu exista utilizatorul la care sa se faca transferul.";
					else
					{
						client[reciever] += sum;
						client[sender] -= sum;
					}
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
		cout << "Sold curent pentru sender:" << client[sender] << '\n';
		cout << "Sold curent pentru reciever:" << client[reciever] << '\n';
	}
};
int main()
{
	Bancomat bcm;
	bcm.adaugare();
	bcm.adaugare();
	bcm.adaugare();
	bcm.retragere();
	bcm.retragere();
	bcm.retragere();
	bcm.transfer();
	bcm.transfer();
	bcm.transfer();
	return 0;
}
