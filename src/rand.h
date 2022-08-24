#ifndef RAND_H
#define RAND_H

#include<iostream>
#include<random>
#include<vector>
#include"rand.h"
void printRef(int refAr[],int size);
void refAdd(int refAr[],int size);
void printAlp(int refAr[],char  baseCh[],int range);
void missingNo(int refAr[],int range,int misAr[]);
void printMiss(std::vector<int> &misNo, int mSize);
void missingNoVec(int refAr[],int range, std::vector<int> &misNo ,int *mSize);
void getRepeating(int refAr[],int size,std::vector<int> &repeatingPos,int *rSize);
void replaceRepeat(std::vector<int> &repeatingPos,int refAr[],int rSize,std::vector<int> &misNo);
void run(int [],int size);
#endif
