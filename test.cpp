#include<iostream>
#include<random>
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
void refAdd(int refAr[],int size)
{
	int val=0;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution dis(0,size-1);
	for(int i=0;i<size;i++)
	{
		refAr[i]=dis(gen);
		
	}
}
void printAlp(int refAr[],char  baseCh[],int range)
{
	int count=0;int val=0;
	for(int k=0;k<range;k++)
	{
		val=refAr[k];
		std::cout<<" "<<baseCh[val]<<" ";
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
	refAdd(refAr,9);
	//printRef(refAr,9);
	printAlp(refAr,baseCh,9);
	return 0;
}
