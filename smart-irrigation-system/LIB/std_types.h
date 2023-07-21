/*
 * std_types.h
 *
 * Created: 14/06/2023 11:24:54 pm
 *  Author: Loay
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Includes */
#include "std_libraries.h"
#include "compiler.h"
#include "bit_math.h"

/* Macros */
#define E_OK		0
#define E_NOT_OK	1

/* Types declaration */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef float f32;

typedef u8 STD_ReturnType;

typedef enum {
	FALSE=0,
	TRUE
} bool_t;


#endif /* STD_TYPES_H_ */