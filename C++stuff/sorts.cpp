#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include <algorithm>

using namespace std;

void merge (int a[], int low, int mid, int high)
{int l[5000];
int il, i2, index;
for (index=low;index<=high;index++)
	{l[index]=a[index];}
il=low;
i2=mid+1;
index=low;
while (il<=mid && i2<high)
	{if (l[il]<l[i2])
		{a[index]=l[il];
		il++;
		index++;
		}
	else
		{a[index]=l[i2];
		i2++;
		index++;
		}
	}
while (il<=mid)
{a[index]=l[il];
il++;
index++;
}
while (i2<=high)
{a[index]=l[i2];
i2++;
index++;
}

}
void mergesort(int a[], int low, int high, int &x)
{int mid;
x++;
if (low<high)
	{mid=(low+high)/2;
	mergesort(a,low,mid, x);
	mergesort(a,mid+1, high, x);
	merge(a,low,mid,high);
	}
}
void partition (int a[],int low, int high, int pivot, int &index1, int &firsts3)
{int firstu=low;
index1=low-1;
firsts3=high+1;
while (firstu<firsts3)
	{if (a[firstu]<pivot)
		{++index1;
		swap(a[firstu],a[index1]);
		++firstu;
		}
	else if (a[firstu]==pivot)
		{++firstu;}
	else
	{--firsts3;}
	swap(a[firstu],a[firsts3]);
	}
}
void quicksort(int a[], int low,int high, int &y)
{int pivot;
y++;
int index1, firsts3;
if (low<high)
	{pivot=a[low];
	partition(a,low,high,pivot,index1,firsts3);
	quicksort(a,low,index1,y);
	quicksort(a,firsts3,high,y);
	}
}

void insertion(int a[], int length, int &z)
{ for (int i = 1; i < length; i++) 
	{for (int j = i; j > 0 && a[j - 1] > a[j]; j--) 
		{int temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
        z++;
        }
    }
}

int main()
{
int mergecount=0;
int quickcount=0;
int insertcount=0;

int answer;
int seed;
char show;
cout<<"Input the number of values to generate between 1-5000\n";
cin>>answer;
cout<<"Input a seed value\n";
cin>>seed;
int test[answer];
int tmerge[answer];
int tquick[answer];
int tinsert[answer];
srand (seed);
for (int i=0;i<answer;i++)
{test[i]=rand()%101;
tmerge[i]=test[i];
tquick[i]=test[i];
tinsert[i]=test[i];
}
mergesort(tmerge,0,answer-1,mergecount);
quicksort(tquick,0,answer-1,quickcount);
insertion(tinsert,answer,insertcount);
cout<<"Here are is how each sorting method took\n Insertionsort: "<<insertcount;
cout<<"\n Mergesort: "<<mergecount<<"\n Quicksort: "<<quickcount;
while (show!='x')
{cout<<"\nPress a to show the unsorted set, or b to show the sorted set,";
cout<<" x to end the program\n";
cin>>show;
switch (show)
{case 'a':
	cout<<"Here are the values off the set unsorted\n";
for (int i=0;i<answer;i++)
{cout<<test[i]<<" ";}
break;

case 'b':
	cout<<"Here are the values off the  sorted set\n";
for (int i=0;i<answer;i++)
{cout<<tinsert[i]<<" ";}
break;


default:
	break;
}

}

}
