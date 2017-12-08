#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{   
	int i,j,k,c,edge,n;
	cout<<"Enter dimension matrix: "<<endl;
	cin>>n;
    int  step, cur[4*(n-1)], shift[4*(n-1)];
    int **matrix= new int *[n];
    for (int i=0;i<n;i++)
    {
    	matrix[i]= new int[n];
    }
 
//èíèöèàëèçàöèÿ ìàññèâà ÷èñëàìè
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
//çàïðîñ êîëè÷åñòâà øàãîâ ïîâîðîòà
        cout<<"\nHow many steps to turn? Step = ";
        cin>>step;
        
        for(k=0; k<n/2;k++) //ñëîè
        {       edge = n-1-k;
                
//ñíÿòü ñëîé      
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
//ïåðåñòàâèòü
        for(i=0;i<4*(n-2*k-1);i++)
            shift[(i+step)%(4*(n-2*k-1))]=cur[i];
 
//îäåòü ñëîé        
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
        }//for - ïåðåõîä íà ñëåäóþùèé ñëîé
      
 
        cout<<"Result:\n";
        for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cout<<matrix[i][j]<<' ';
		}
		cout<<endl;
	}
	for (int i=0;i<n;i++)
    {
    	delete [] matrix[i];
    	matrix[i]=NULL;
    }
	 delete [] matrix;
	 matrix = NULL;
        return 0;
}

