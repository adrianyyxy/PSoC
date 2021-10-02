/*******************************************************************************
* File Name: Columns.h  
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

#if !defined(CY_PINS_Columns_ALIASES_H) /* Pins Columns_ALIASES_H */
#define CY_PINS_Columns_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Columns_0			(Columns__0__PC)
#define Columns_0_INTR	((uint16)((uint16)0x0001u << Columns__0__SHIFT))

#define Columns_1			(Columns__1__PC)
#define Columns_1_INTR	((uint16)((uint16)0x0001u << Columns__1__SHIFT))

#define Columns_2			(Columns__2__PC)
#define Columns_2_INTR	((uint16)((uint16)0x0001u << Columns__2__SHIFT))

#define Columns_3			(Columns__3__PC)
#define Columns_3_INTR	((uint16)((uint16)0x0001u << Columns__3__SHIFT))

#define Columns_INTR_ALL	 ((uint16)(Columns_0_INTR| Columns_1_INTR| Columns_2_INTR| Columns_3_INTR))

#endif /* End Pins Columns_ALIASES_H */


/* [] END OF FILE */
