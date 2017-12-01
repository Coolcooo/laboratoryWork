#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void arrPrint(int m, int **a) {
	for (int i=0;i<m;i++)
		{
			for (int j=0;j<m;j++)
			{
				a[i][j]=0+rand()%10;
			}
		}
		for (int i=0;i<m;i++)
		{
			for (int j=0;j<m;j++)
			{
				cout<<a[i][j]<<' ';
			}
			cout<<endl;
		}
}
void reshuffleElement(int m,int **a)
{
	int i,j,k,c,edge;
	int  step, cur[4*(m-1)], shift[4*(m-1)];

	cout<<"\nHow many steps to turn? Step = ";
	        cin>>step;

	        for(k=0; k<m/2;k++) //ñëîè
	        {       edge = m-1-k;

	//ñíÿòü ñëîé
	        c=0;
	        for(j=k;j<edge;j++)
	                {      cur[c] = a[k][j];
	                        c++;
	                }
	                for(i=k;i<edge;i++)
	                {      cur[c] = a[i][edge];
	                        c++;
	                }
	                for(j=edge;j>=k;j--)
	                {      cur[c] = a[edge][j];
	                        c++;
	                }
	                for(i=edge-1;i>k;i--)
	                {       cur[c] = a[i][k];
	                        c++;
	                }
	        for(i=0;i<4*(m-2*k-1);i++)
	            shift[(i+step)%(4*(m-2*k-1))]=cur[i];

	        c=0;
	        for(j=k;j<edge;j++)
	                {   a[k][j] = shift[c];
	                    c++;
	                }
	                for(i=k;i<edge;i++)
	                {    a[i][edge]= shift[c];
	                        c++;
	                }
	                for(j=edge;j>=k;j--)
	                {    a[edge][j]= shift[c];
	                        c++;
	                }
	                for(i=edge-1;i>k;i--)
	                {     a[i][k]= shift[c];
	                        c++;
	                }
	        }

}
int main()
{
	int n;
	cout<<"Enter dimension matrix: "<<endl;
	cin>>n;
    int **matrix= new int *[n];
    for (int i=0;i<n;i++)
    {
    	matrix[i]= new int[n];
    }

       srand(time(0));
       arrPrint(n, matrix);
       reshuffleElement(n,matrix);
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

