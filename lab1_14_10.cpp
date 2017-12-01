#include <iostream>
#include <cmath>
using namespace std;

template <typename T,typename P>
void SumElementsArray (P array[], T numberMinIndex,P varriableForCounter,T amountAllElements)
{
	for(int i=numberMinIndex;i<amountAllElements;i++)//ñêëàäûâàþ â öèêëå âñå ýëåìåíòû ïîñëå ìèíèìàëüíîãî 
	{
		varriableForCounter += array[i];
	};
};
template <typename T>
void SumNullElementsAndMinIndex (T array[],int NullAmount,int minIndex,T minElement,int amountAllElements)
{
	if(array[0]==0)
	{
		NullAmount++;
	}
	
	for (int i=1;i<amountAllElements;i++)
	{
		cin>>array[i];
			if(array[i]== 0)
			{
				NullAmount++;
			};
			if(array[i] < minElement)
			{
				minElement=array[i];
				minIndex = i+1;//ïðèñâàèâàþ èíäåêñ ýëåìåíòà íà 1 áîëüøå,÷åì ìèíèìàëüíûé
			}
}
};
template <typename T,typename P>
void sortElements (T array[],P amountAllElements)
{
	for(int i=1;i<amountAllElements;i++)
	{
		for(int j=1;j<amountAllElements;j++)
		{
			if (abs(array[j])<abs(array[j-1]))//cîðòèðóþ ýëåìåíòû ïî èõ ìîäóëþ,êîãäà ïîëó÷èë âñå íóæíûå çíà÷åíèÿ èç ïåðâîãî ïóíêòà
													//(â ïåðåñòàíîâêå ýëåìåíòîâ ìîäóëü íå ó÷èòûâàþ)
			{
				int t;
				t=array[j];
				array[j]=array[j-1];
				array[j-1]=t;
				
			}
		}
	}
};

int main()
{
	int n,sumNullElements,index;
	double min,sumElements;
	sumNullElements=0;
	sumElements=0;
	cout<<"Enter amount elements: "<<endl;
	cin>>n;
	double elements[n];
	cout<<"Enter elements: "<<endl;
	cin>>elements[0];
	min=elements[0];
	index=0;
	SumNullElementsAndMinIndex(elements,sumNullElements,index,min,n);
	SumElementsArray (elements,index,sumElements,n);
	sortElements(elements,n);
	
	cout<<"Amount null elments: "<<sumNullElements<<"\nSum of elements after a minimum: "<<sumElements<<"\nThe order of the elements by their module:"<<endl;
	for (int i=0;i<n;i++)
	{
	cout <<elements[i]<<endl;
	}
	
    
	return 0;
}
