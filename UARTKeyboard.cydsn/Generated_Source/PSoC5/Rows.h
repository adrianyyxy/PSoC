/*******************************************************************************
* File Name: Rows.h  
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

#if !defined(CY_PINS_Rows_H) /* Pins Rows_H */
#define CY_PINS_Rows_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Rows_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Rows__PORT == 15 && ((Rows__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Rows_Write(uint8 value);
void    Rows_SetDriveMode(uint8 mode);
uint8   Rows_ReadDataReg(void);
uint8   Rows_Read(void);
void    Rows_SetInterruptMode(uint16 position, uint16 mode);
uint8   Rows_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Rows_SetDriveMode() function.
     *  @{
     */
        #define Rows_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Rows_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Rows_DM_RES_UP          PIN_DM_RES_UP
        #define Rows_DM_RES_DWN         PIN_DM_RES_DWN
        #define Rows_DM_OD_LO           PIN_DM_OD_LO
        #define Rows_DM_OD_HI           PIN_DM_OD_HI
        #define Rows_DM_STRONG          PIN_DM_STRONG
        #define Rows_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Rows_MASK               Rows__MASK
#define Rows_SHIFT              Rows__SHIFT
#define Rows_WIDTH              4u

/* Interrupt constants */
#if defined(Rows__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Rows_SetInterruptMode() function.
     *  @{
     */
        #define Rows_INTR_NONE      (uint16)(0x0000u)
        #define Rows_INTR_RISING    (uint16)(0x0001u)
        #define Rows_INTR_FALLING   (uint16)(0x0002u)
        #define Rows_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Rows_INTR_MASK      (0x01u) 
#endif /* (Rows__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Rows_PS                     (* (reg8 *) Rows__PS)
/* Data Register */
#define Rows_DR                     (* (reg8 *) Rows__DR)
/* Port Number */
#define Rows_PRT_NUM                (* (reg8 *) Rows__PRT) 
/* Connect to Analog Globals */                                                  
#define Rows_AG                     (* (reg8 *) Rows__AG)                       
/* Analog MUX bux enable */
#define Rows_AMUX                   (* (reg8 *) Rows__AMUX) 
/* Bidirectional Enable */                                                        
#define Rows_BIE                    (* (reg8 *) Rows__BIE)
/* Bit-mask for Aliased Register Access */
#define Rows_BIT_MASK               (* (reg8 *) Rows__BIT_MASK)
/* Bypass Enable */
#define Rows_BYP                    (* (reg8 *) Rows__BYP)
/* Port wide control signals */                                                   
#define Rows_CTL                    (* (reg8 *) Rows__CTL)
/* Drive Modes */
#define Rows_DM0                    (* (reg8 *) Rows__DM0) 
#define Rows_DM1                    (* (reg8 *) Rows__DM1)
#define Rows_DM2                    (* (reg8 *) Rows__DM2) 
/* Input Buffer Disable Override */
#define Rows_INP_DIS                (* (reg8 *) Rows__INP_DIS)
/* LCD Common or Segment Drive */
#define Rows_LCD_COM_SEG            (* (reg8 *) Rows__LCD_COM_SEG)
/* Enable Segment LCD */
#define Rows_LCD_EN                 (* (reg8 *) Rows__LCD_EN)
/* Slew Rate Control */
#define Rows_SLW                    (* (reg8 *) Rows__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Rows_PRTDSI__CAPS_SEL       (* (reg8 *) Rows__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Rows_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Rows__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Rows_PRTDSI__OE_SEL0        (* (reg8 *) Rows__PRTDSI__OE_SEL0) 
#define Rows_PRTDSI__OE_SEL1        (* (reg8 *) Rows__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Rows_PRTDSI__OUT_SEL0       (* (reg8 *) Rows__PRTDSI__OUT_SEL0) 
#define Rows_PRTDSI__OUT_SEL1       (* (reg8 *) Rows__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Rows_PRTDSI__SYNC_OUT       (* (reg8 *) Rows__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Rows__SIO_CFG)
    #define Rows_SIO_HYST_EN        (* (reg8 *) Rows__SIO_HYST_EN)
    #define Rows_SIO_REG_HIFREQ     (* (reg8 *) Rows__SIO_REG_HIFREQ)
    #define Rows_SIO_CFG            (* (reg8 *) Rows__SIO_CFG)
    #define Rows_SIO_DIFF           (* (reg8 *) Rows__SIO_DIFF)
#endif /* (Rows__SIO_CFG) */

/* Interrupt Registers */
#if defined(Rows__INTSTAT)
    #define Rows_INTSTAT            (* (reg8 *) Rows__INTSTAT)
    #define Rows_SNAP               (* (reg8 *) Rows__SNAP)
    
	#define Rows_0_INTTYPE_REG 		(* (reg8 *) Rows__0__INTTYPE)
	#define Rows_1_INTTYPE_REG 		(* (reg8 *) Rows__1__INTTYPE)
	#define Rows_2_INTTYPE_REG 		(* (reg8 *) Rows__2__INTTYPE)
	#define Rows_3_INTTYPE_REG 		(* (reg8 *) Rows__3__INTTYPE)
#endif /* (Rows__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Rows_H */


/* [] END OF FILE */
