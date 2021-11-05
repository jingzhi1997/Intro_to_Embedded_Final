/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file		stats.c
 * @brief 	A program to analyze a given array by sorting the array and returning the median, mean, maximum and minimum of the array.
 *
 *
 * @author	Zhi Jing
 * @date		11/4/2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};                         
	sort_array(test,SIZE);
	print_array(test,SIZE);
	
	printf("Median:		%d\nMean:		%d\nMaximum:	%d\nMinimum:	%d\n",find_median(test,SIZE),find_mean(test,SIZE),find_maximum(test,SIZE),find_minimum(test,SIZE));

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

//print_statistics function removed as it is not needed.

unsigned char find_median(unsigned char *array, unsigned int array_size){
	return *(array + (array_size/2));
}
unsigned char find_mean(unsigned char *array, unsigned int array_size){
	unsigned int sum = 0;
	for(unsigned char i=0; i<array_size;){
		sum += *(array + i);
		i++;
	}
	return sum/array_size;
}


unsigned char find_maximum(unsigned char *array, unsigned int array_size){
	return *array;
}

unsigned char find_minimum(unsigned char *array, unsigned int array_size){
	return *(array + array_size -1);
}


void sort_array(unsigned char *array, unsigned int array_size){

	unsigned char num_swaps = 0;
	unsigned char temp;
	unsigned char *array_pos;
	do{
		num_swaps = 0;
		for(unsigned char i=0; i<array_size;){
			array_pos = array + i;
			if(*array_pos < *(array_pos + 1)){
				temp = *array_pos;
				*array_pos = *(array_pos +1);
				*(array_pos + 1) = temp;
				num_swaps++;
			}
			i++;
		}
	}while(num_swaps);
}
	
void print_array(unsigned char *array, unsigned int array_size){

	for(unsigned char i=0; i<array_size;){
		printf("	%d \n",*(array + i));
		i++;
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

