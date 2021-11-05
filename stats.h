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
 * @file	stats.h
 * @brief	Header file for stats.c
 *
 * <Add Extended Description Here>
 *
 * @author	Zhi Jing
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

//print_statistics function removed as it is not needed.

void print_array(unsigned char *array, unsigned int array_size);

unsigned char find_median(unsigned char *array, unsigned int array_size);

unsigned char find_mean(unsigned char *array, unsigned int array_size);

unsigned char find_maximum(unsigned char *array, unsigned int array_size);

unsigned char find_minimum(unsigned char *array, unsigned int array_size);

void sort_array(unsigned char *array, unsigned int array_size);


#endif /* __STATS_H__ */
