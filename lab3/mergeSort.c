#include "mySort.h"

void merge(int array[], unsigned int a1, unsigned int b1, unsigned int a2, unsigned int b2){
	
	int temp[MAX_SIZE_N_TO_SORT]; 
	int a, b, c;
	a = a1;
	b = a2;
	c = 0;
	
	while(a <= b1 && b <= b2){
		
		if(myCompare(array[a], array[b]) <= 0)
			myCopy(&array[a++], &temp[c++]);
		else
			myCopy(&array[b++], &temp[c++]);
	}
	
	while(a <= b1)
		myCopy(&array[a++], &temp[c++]);
	while(b <= b2)
		myCopy(&array[b++], &temp[c++]);
	
	for(a = a1, c= 0; a <= b2; a++, c++)
		myCopy(&temp[c], &array[a]);
}

void mySort(int array[], unsigned int first, unsigned int last)
    {
	
	if (first < last){
	int middle = (first + last) / 2;
	mySort(array, first, middle);
	mySort(array, middle + 1, last);
	merge(array, first, middle, middle + 1, last);
    }
}
