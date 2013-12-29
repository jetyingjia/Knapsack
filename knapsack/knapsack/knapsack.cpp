#include"iostream"
#include<cstdlib>
#define N 5
#define c 11
using namespace std;
int i,j;
int w[N+1],v[N+1],m[N+1][c+1]={0};
void knapsack( )
	{
		int i,j;
		for(i=1;i<=N;i++)
			for(j=1;j<=c;j++)
			{	
				m[i][j]=m[i-1][j];
				if(j>=w[i]&&(m[i-1][j-w[i]]+v[i])>m[i][j])
					m[i][j]=m[i-1][j-w[i]]+v[i];
			}
		cout<<"Most value:"<<m[N][c]<<endl;
	}
/*void disp()
	{
		int i,j;
		i=N;
		int s=c;
		while(m[i][c]==m[i-1][c])
			i--;
		while(i>0)
		{   
			j=i-1;
			int s1=s;
			while(m[i][s1]-m[j][s]!=v[i]&&s>0)
				s--;
			if(s>0)
				cout<<w[i]<<v[i];
			i--;
			
		}

	}*/
int main()
	{
		cout<<"Please input the weight and value of "<<N<<" items";
		for(i=1;i<=N;i++)
			cin>>w[i]>>v[i];
		knapsack();
		
		for(i=1;i<=N;i++)
			{
				for(j=1;j<=c;j++)
					printf("%3d",m[i][j]);
				cout<<endl;
			}
		system("pause");

	}