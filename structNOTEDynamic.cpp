#include <iostream>
using namespace std;

const int amountStruct = 8;
int amount=0;
string request;
struct NOTE
{
	string lastName,firstName;
	long long  phoneNumber;
	short birthday[2];
};

NOTE* database = new NOTE[amountStruct];
NOTE t;

void outputStruct(int i)
{
	cout<<database[i].lastName<<" "<<database[i].firstName<<endl;
	cout<<database[i].phoneNumber<<endl;
	cout<<database[i].birthday[0]<<"/"<<database[i].birthday[1]<<"/"<<database[i].birthday[2]<<endl;
};

int main()
{
	for (int i=0;i<amountStruct;i++)
	{
		cout<<endl<<endl<<"Enter Last and First Name "<<i<<" in database human: ";
		cin>>database[i].lastName;
		cin>>database[i].firstName;
		cout<<"Enter phone number "<<i<<" in database human: +";
		cin>>database[i].phoneNumber;
		cout<<"Enter birthday "<<i<<" in database human by dividing the date with space: ";
		cin>>database[i].birthday[0]>>database[i].birthday[1]>>database[i].birthday[2];
	}
	for(int i=0;i<amountStruct;i++)
	{
		for (int j=1;j<amountStruct;j++)
		{
			if((database[j].phoneNumber/10000000)<(database[i].phoneNumber/10000000))
			{
				t = database[i];
				database[i]=database[j];
				database[j]=t;
			}
		}
	}
	cout <<"Enter your request: ";
	cin>>request;
	for(int i=0;i<amountStruct;i++)
	{
		if (request==database[i].lastName)
		{
			outputStruct(i);
		}
		else
		{
			amount++;
		}
	}
	if(amount==amountStruct)
	{
		cout<<"Error in the database..."<<endl;
	}
	delete [] database;
	return 0;
};

