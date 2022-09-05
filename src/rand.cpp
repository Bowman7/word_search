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
	setWord(refAr);
	printRef(refAr,size);
	printAlp(refAr,baseCh,size);
	//refAr[0]=1;refAr[4]=0;refAr[8]=3
	//printAlp(refAr,baseCh,9);
//	return 0;
}
void setWord(int refAr[])
{
	int val;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution dis(0,9);
	val=dis(gen);
	std::cout<<"gen no: "<<val<<std::endl;
	switch(val)
	{
	case 0:
		refAr[0]=1;refAr[1]=0;refAr[2]=3;break;
	case 1:
		refAr[0]=1;refAr[4]=0;refAr[8]=6;break;
	case 2:
		refAr[0]=3;refAr[3]=0;refAr[6]=1;break;
	case 3:
		refAr[5]=2;refAr[4]=0;refAr[3]=1;break;
	case 4:
		refAr[6]=4;refAr[7]=6;refAr[8]=6;break;
	case 5:
		refAr[6]=5;refAr[4]=8;refAr[2]=6;break;
	case 6:
		refAr[8]=5;refAr[4]=0;refAr[0]=3;break;
	case 7:
		refAr[3]=5;refAr[4]=4;refAr[5]=3;break;
	case 8:
		refAr[1]=1;refAr[4]=8;refAr[7]=6;break;
	case 9:
		refAr[8]=7;refAr[7]=0;refAr[6]=3;break;
	}
}
void switchAr(int realAr[],int refAr[])
{
	for(int i=0;i<9;i++)
	{
		realAr[i]=refAr[i];
	}
}
