#include<iostream>

using namespace std;
class D
{
	int *a;
	int n,k;
public:
	 D(int size=10)
	 {
	 	 n=size;
	 	 if(size!=0)
	 	 {
	 	 	a=new int[n*(n+1)/2];
	 	 }
	 	 else
	 	 	a=0;
	 }
	 ~D()
	 {
	 	delete []a;
	 }
	 void store(int x,int i,int j);
	 int retrieve(int i,int j);
	 void show();


   };

void D::store(int x,int i,int j)
{
	if(i<1||i>n||j<1||j>n)
	{
		std::cout<<"\nOut of bound";
		exit(0);
	}
	else if(i<j&&x!=0)
		std::cout<<"\nMust be zero";
	else if(i>=j)
	{
        k= i*(i-1)/2+j-1;
		a[k+1]=x;
	}
}

int D::retrieve(int i,int j)
{
	 if(i<1||i>n||j<1||j>n)
	 	std::cout<<"\nOut of bound";
	 else if(i==j)
	 	return a[i*(i-1)/2+j];
	 else if(i>j)
	 	return a[i*(i-1)/2+j];
	 else if(j>i)
	 	return a[j*(j-1)/2+i];
}
void D::show()
{
	std::cout<<"\nSparse matrix : ";
	for (int i = 1; i <= n*(n+1)/2; ++i)
	{
		cout<<a[i]<<" ";
	}

    std::cout<<"\nComplete matrix :\n";
	for(int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
		{
			if(i==j)
				std::cout<<a[i*(i-1)/2+j]<<" ";
			else if(i>j)
			    std::cout<<a[i*(i-1)/2+j]<<" ";
			else if(j>i)
				std::cout<<a[j*(j-1)/2+i]<<" ";
		}
		std::cout<<"\n";
	}

}



int main()
{

	int m1=0,m2=0,y=0,i=0,j=0;
	std::cout<<"\nEnter the size of diagonal matrix : \n";
	std::cin>>m1>>m2;
	if(m1!=m2)
	{
		std::cout<<"\nInvalid size";
		exit(0);
	}
	D ob(m1);


	std::cout<<"\nEnter the elements of array : \n";
	for (i = 1; i <= m1; ++i)
	{
		for (j = 1; j <= m2; ++j)
		{
			if(i>=j)
			{

				cin>>y;
	            ob.store(y,i,j);
			}
		}
	}
	std::cout<<"\nMatrix is : \n";
    ob.show();
    std::cout<<"\nEnter the location of retrieval : \n";
    std::cin>>i>>j;
    cout<<"Retrieved value is : "<<ob.retrieve(i,j)<<"\n";
	return 0;
}
