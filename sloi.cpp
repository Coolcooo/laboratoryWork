#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{   
	int i,j,k,c,edge,n;
	cout<<"Enter dimension matrix: "<<endl;
	cin>>n;
    int matrix[n][n], step, cur[4*(n-1)], shift[4*(n-1)];
 
//инициализация массива числами
       srand(time(0));
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			matrix[i][j]=0+rand()%10;
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cout<<matrix[i][j]<<' ';
		}
		cout<<endl;
	}
//запрос количества шагов поворота
        cout<<"\nHow many steps to turn? Step = ";
        cin>>step;
        
        for(k=0; k<n/2;k++) //слои
        {       edge = n-1-k;
                
//снять слой      
        c=0;
        for(j=k;j<edge;j++)             
                {      cur[c] = matrix[k][j];
                        c++;
                }
                for(i=k;i<edge;i++)             
                {      cur[c] = matrix[i][edge];
                        c++;
                }
                for(j=edge;j>=k;j--)    
                {      cur[c] = matrix[edge][j];
                        c++;
                }
                for(i=edge-1;i>k;i--)             
                {       cur[c] = matrix[i][k];
                        c++;
                }
//переставить
        for(i=0;i<4*(n-2*k-1);i++)
            shift[(i+step)%(4*(n-2*k-1))]=cur[i];
 
//одеть слой        
        c=0;
        for(j=k;j<edge;j++)             
                {   matrix[k][j] = shift[c];   
                    c++;
                }
                for(i=k;i<edge;i++)             
                {    matrix[i][edge]= shift[c];
                        c++;
                }
                for(j=edge;j>=k;j--)    
                {    matrix[edge][j]= shift[c];
                        c++;
                }
                for(i=edge-1;i>k;i--)             
                {     matrix[i][k]= shift[c];
                        c++;
                }
        }//for - переход на следующий слой
      
 
        cout<<"Result:\n";
        for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cout<<matrix[i][j]<<' ';
		}
		cout<<endl;
	}
        return 0;
}

