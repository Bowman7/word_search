#include"rand.h"
void printRef(int refAr[],int size)
{
	int count=0;
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
void missingNo(int refAr[],int range,int misAr[])
{
	int count=0;int p=0;
	
	for(int i=0;i<range;i++)
	{
		for(int j=0;j<range;j++)
		{
			if(i==refAr[j])
			{
				count++;
			}
			
		}
		if(count==0)
			{
				misAr[p]=i;
				p++;
			}
		count=0;
	}
}
void printMiss(std::vector<int> &misNo, int mSize)
{
	std::cout<<"Missing Nos: ";
	for(int i=0;i<mSize;i++)
	{
		std::cout<<misNo[i];
	}
}
void missingNoVec(int refAr[],int range, std::vector<int> &misNo ,int *mSize)
{
	int count=0;int val=0;
        for(int i=0;i<range;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(i==refAr[j])
			{
				count++;
			}
		}
		if(count==0)
		{
			//std::cout<<i<<std::endl;
			misNo.push_back(i);
			val++;
		}
		count=0;
	}
	*mSize=val;
}
void getRepeating(int refAr[],int size,std::vector<int> &repeatingPos,int *rSize)
{
	//std::cout<<"adsjf";
	int count=0;int vecSize=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(i==refAr[j])
			{
				count++;
				if(count==2)
				{
					repeatingPos.push_back(j);
					vecSize++;
				}
				if(count==3)
				{
					repeatingPos.push_back(j);
					vecSize++;
				}
				if(count==4)
				{
					repeatingPos.push_back(j);
					vecSize++;
				}
				if(count>4)
				{
					repeatingPos.push_back(j);
					vecSize++;
				}
			}
		        
		}
		count =0;
	}
	*rSize=vecSize;
}
void printRepeat(std::vector<int> &repeatingPos,int refAr[],int rSize)
{
	//std::cout<<"rsize:"<<rSize;
	int pos=0;
	std::cout<<std::endl;
	std::cout<<"Repeating numbers: ";
	for(int i=0;i<rSize;i++)
	{	
		pos=repeatingPos[i];
		std::cout<<refAr[pos]<<" ";
	}
}
void replaceRepeat(std::vector<int> &repeatingPos,int refAr[],int rSize,std::vector<int> &misNo)
{
	int val,pal;
	for(int i=0;i<rSize;i++)
	{
		pal=repeatingPos[i];
		val=misNo[i];
		refAr[pal]=val;
	}
	std::cout<<std::endl;
}
void run(int refAr[],int size)
{
	int misAr[10];int mSize=0;int rSize;
	std::vector<int> misNo;
	std::vector<int> repeatingPos;
	char baseCh[size]={'a','b','c','d','e','f','g','h','i'};
	int baseAr[size]={0,1,2,3,4,5,6,7,8};
	//int refAr[size];
	refAdd(refAr,size);
	printRef(refAr,size);
	missingNoVec(refAr,size,misNo,&mSize);
	printMiss(misNo,mSize);
        getRepeating(refAr,size,repeatingPos,&rSize);
	printRepeat(repeatingPos,refAr,rSize);
	replaceRepeat(repeatingPos,refAr,rSize,misNo);
	printRef(refAr,size);
	printAlp(refAr,baseCh,size);
	
	//printAlp(refAr,baseCh,9);
//	return 0;
}
