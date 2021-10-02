/*******************************************************************************
* File Name: Rows.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Rows_ALIASES_H) /* Pins Rows_ALIASES_H */
#define CY_PINS_Rows_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Rows_0			(Rows__0__PC)
#define Rows_0_INTR	((uint16)((uint16)0x0001u << Rows__0__SHIFT))

#define Rows_1			(Rows__1__PC)
#define Rows_1_INTR	((uint16)((uint16)0x0001u << Rows__1__SHIFT))

#define Rows_2			(Rows__2__PC)
#define Rows_2_INTR	((uint16)((uint16)0x0001u << Rows__2__SHIFT))

#define Rows_3			(Rows__3__PC)
#define Rows_3_INTR	((uint16)((uint16)0x0001u << Rows__3__SHIFT))

#define Rows_INTR_ALL	 ((uint16)(Rows_0_INTR| Rows_1_INTR| Rows_2_INTR| Rows_3_INTR))

#endif /* End Pins Rows_ALIASES_H */


/* [] END OF FILE */
