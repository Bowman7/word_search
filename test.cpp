#include<iostream>
#include<random>
int returnRand(int size)
{
	int val;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution distrib(0,size);
	val= distrib(gen);
	return val;
}
int checkVal(int refVal,int p,int refAr[],int size)
{
	int checkVal=refVal;
	for(int i=0;i<size;i++)
	{
		if(refAr[i]==checkVal)
		{
			checkVal=returnRand(size);
		}
	}
	return checkVal;
}
void addRef(int baseAr[],int refAr[],int size)
{
	int refVal;
	int retCheckVal;
	for(int p=0;p<size;p++)
	{
		refVal=returnRand(size);
		retCheckVal=checkVal(refVal,p,refAr,size);
		refAr[p]=retCheckVal;

	}
}
void printRef(int refAr[],int size)
{
	int count;
	for(int i=0;i<size;i++)
	{
		std::cout<<" "<<refAr[i]<<" ";
		count++;
		if(count==3)
		{
			std::cout<<std::endl;
			count=0;
		}
	}
}
int main()
{
	char baseCh[9]={'a','b','c','d','e','f','g','h','i'};
	int baseAr[9]={0,1,2,3,4,5,6,7,8};
	int refAr[9];
	addRef(baseAr,refAr,9);
	printRef(refAr,9);
	return 0;
}
