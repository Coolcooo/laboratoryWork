#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n,sumNullElements,min,index,sumElements;
	sumNullElements=0;
	sumElements=0;
	cout<<"Input amount elements: "<<endl;
	cin>>n;
	double elements[n];
	cout<<"Input elements: "<<endl;
	cin>>elements[0];
	min=elements[0];
	index=0;
	
	if(elements[0]==0)
	{
		sumNullElements++;
	}
	
	for (int i=1;i<n;i++)
	{
		cin>>elements[i];
			if(elements[i]== 0)
			{
				sumNullElements++;
			};
			if(elements[i]<min)
			{
				min=elements[i];
				index = i+1;//присваиваю индекс элемента на 1 больше,чем минимальный
			}
			
	}
	
	for(int i=index;i<n;i++)//складываю в цикле все элементы после минимального 
	{
		sumElements+=elements[i];
	};
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if (abs(elements[j])<abs(elements[j-1]))//cортирую элементы по их модулю,когда получил все нужные значени€ из первого пункта
													//(в перестановке элементов модуль не учитываю)
			{
				int t;
				t=elements[j];
				elements[j]=elements[j-1];
				elements[j-1]=t;
				
			}
		}
	}
	
	cout<<"Amount null elments: "<<sumNullElements<<"\nSum of elements after a minimum: "<<sumElements<<"\nThe order of the elements by their module:"<<endl;
	for (int i=0;i<n;i++)
	{
	cout <<elements[i]<<endl;
	}
	
    
	return 0;
}
