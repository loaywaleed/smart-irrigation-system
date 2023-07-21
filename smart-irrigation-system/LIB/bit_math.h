/*
 * bit_math.h
 *
 * Created: 14/07/2023 8:14:16 am
 *  Author: Loay
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/* Macros */
#define BIT_MASK	0x01u
#define PORT_MASK	0xff

/* Macro functions declarations */
#define SET_BIT(REG, BIT)		(REG |= (BIT_MASK << BIT))
#define CLEAR_BIT(REG, BIT)		(REG &= ~(BIT_MASK << BIT))
#define TOGGLE_BIT(REG, BIT)	(REG ^= (BIT_MASK << BIT))
#define READ_BIT(REG, BIT)		((REG >> BIT) & BIT_MASK)



#endif /* BIT_MATH_H_ */