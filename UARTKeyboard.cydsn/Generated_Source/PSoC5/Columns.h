/*******************************************************************************
* File Name: Columns.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Columns_H) /* Pins Columns_H */
#define CY_PINS_Columns_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Columns_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Columns__PORT == 15 && ((Columns__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Columns_Write(uint8 value);
void    Columns_SetDriveMode(uint8 mode);
uint8   Columns_ReadDataReg(void);
uint8   Columns_Read(void);
void    Columns_SetInterruptMode(uint16 position, uint16 mode);
uint8   Columns_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Columns_SetDriveMode() function.
     *  @{
     */
        #define Columns_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Columns_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Columns_DM_RES_UP          PIN_DM_RES_UP
        #define Columns_DM_RES_DWN         PIN_DM_RES_DWN
        #define Columns_DM_OD_LO           PIN_DM_OD_LO
        #define Columns_DM_OD_HI           PIN_DM_OD_HI
        #define Columns_DM_STRONG          PIN_DM_STRONG
        #define Columns_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Columns_MASK               Columns__MASK
#define Columns_SHIFT              Columns__SHIFT
#define Columns_WIDTH              4u

/* Interrupt constants */
#if defined(Columns__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Columns_SetInterruptMode() function.
     *  @{
     */
        #define Columns_INTR_NONE      (uint16)(0x0000u)
        #define Columns_INTR_RISING    (uint16)(0x0001u)
        #define Columns_INTR_FALLING   (uint16)(0x0002u)
        #define Columns_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Columns_INTR_MASK      (0x01u) 
#endif /* (Columns__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Columns_PS                     (* (reg8 *) Columns__PS)
/* Data Register */
#define Columns_DR                     (* (reg8 *) Columns__DR)
/* Port Number */
#define Columns_PRT_NUM                (* (reg8 *) Columns__PRT) 
/* Connect to Analog Globals */                                                  
#define Columns_AG                     (* (reg8 *) Columns__AG)                       
/* Analog MUX bux enable */
#define Columns_AMUX                   (* (reg8 *) Columns__AMUX) 
/* Bidirectional Enable */                                                        
#define Columns_BIE                    (* (reg8 *) Columns__BIE)
/* Bit-mask for Aliased Register Access */
#define Columns_BIT_MASK               (* (reg8 *) Columns__BIT_MASK)
/* Bypass Enable */
#define Columns_BYP                    (* (reg8 *) Columns__BYP)
/* Port wide control signals */                                                   
#define Columns_CTL                    (* (reg8 *) Columns__CTL)
/* Drive Modes */
#define Columns_DM0                    (* (reg8 *) Columns__DM0) 
#define Columns_DM1                    (* (reg8 *) Columns__DM1)
#define Columns_DM2                    (* (reg8 *) Columns__DM2) 
/* Input Buffer Disable Override */
#define Columns_INP_DIS                (* (reg8 *) Columns__INP_DIS)
/* LCD Common or Segment Drive */
#define Columns_LCD_COM_SEG            (* (reg8 *) Columns__LCD_COM_SEG)
/* Enable Segment LCD */
#define Columns_LCD_EN                 (* (reg8 *) Columns__LCD_EN)
/* Slew Rate Control */
#define Columns_SLW                    (* (reg8 *) Columns__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Columns_PRTDSI__CAPS_SEL       (* (reg8 *) Columns__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Columns_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Columns__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Columns_PRTDSI__OE_SEL0        (* (reg8 *) Columns__PRTDSI__OE_SEL0) 
#define Columns_PRTDSI__OE_SEL1        (* (reg8 *) Columns__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Columns_PRTDSI__OUT_SEL0       (* (reg8 *) Columns__PRTDSI__OUT_SEL0) 
#define Columns_PRTDSI__OUT_SEL1       (* (reg8 *) Columns__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Columns_PRTDSI__SYNC_OUT       (* (reg8 *) Columns__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Columns__SIO_CFG)
    #define Columns_SIO_HYST_EN        (* (reg8 *) Columns__SIO_HYST_EN)
    #define Columns_SIO_REG_HIFREQ     (* (reg8 *) Columns__SIO_REG_HIFREQ)
    #define Columns_SIO_CFG            (* (reg8 *) Columns__SIO_CFG)
    #define Columns_SIO_DIFF           (* (reg8 *) Columns__SIO_DIFF)
#endif /* (Columns__SIO_CFG) */

/* Interrupt Registers */
#if defined(Columns__INTSTAT)
    #define Columns_INTSTAT            (* (reg8 *) Columns__INTSTAT)
    #define Columns_SNAP               (* (reg8 *) Columns__SNAP)
    
	#define Columns_0_INTTYPE_REG 		(* (reg8 *) Columns__0__INTTYPE)
	#define Columns_1_INTTYPE_REG 		(* (reg8 *) Columns__1__INTTYPE)
	#define Columns_2_INTTYPE_REG 		(* (reg8 *) Columns__2__INTTYPE)
	#define Columns_3_INTTYPE_REG 		(* (reg8 *) Columns__3__INTTYPE)
#endif /* (Columns__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Columns_H */


/* [] END OF FILE */
