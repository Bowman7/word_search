#include<iostream>
#include<random>
#include<vector>
void printRef(int refAr[],int size)
{
	int count;
	for(int i=0;i<size;i++)
	{
		std::cout<<" "<<refAr[i]<<" ";
		count++;
		if(count==3)
		{
			//std::cout<<std::endl;
			count=0;
		}
	}
}
void refAdd(int refAr[],int size)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution dis(0,size-1);
	for(int i=0;i<size;i++)
	{
		refAr[i]=dis(gen);
	}
        
}
void subRepeat(int ref[],int range)
{
	int count=0;
	std::vector<int> left;
	for( int p=0;p<range;p++)
	{
		for(int k=0;k<range;k++)
		{
			if(p!=ref[k])
			{
				count++;
			}
		}
		if(count==range)
		{
			left.push_back(p);
		}
	}
	for(int i=0;i<=left.size();i++)
	{
		std::cout<<ref[i]<<std::endl;
	}
}
int main()
{
	char baseCh[9]={'a','b','c','d','e','f','g','h','i'};
	int baseAr[9]={0,1,2,3,4,5,6,7,8};
	int refAr[9];
	refAdd(refAr,9);
	subRepeat(refAr,9);
	printRef(refAr,9);
	return 0;
}
