/*******************************************************************************
* File Name: StartButton.h  
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

#if !defined(CY_PINS_StartButton_H) /* Pins StartButton_H */
#define CY_PINS_StartButton_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "StartButton_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 StartButton__PORT == 15 && ((StartButton__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    StartButton_Write(uint8 value);
void    StartButton_SetDriveMode(uint8 mode);
uint8   StartButton_ReadDataReg(void);
uint8   StartButton_Read(void);
void    StartButton_SetInterruptMode(uint16 position, uint16 mode);
uint8   StartButton_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the StartButton_SetDriveMode() function.
     *  @{
     */
        #define StartButton_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define StartButton_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define StartButton_DM_RES_UP          PIN_DM_RES_UP
        #define StartButton_DM_RES_DWN         PIN_DM_RES_DWN
        #define StartButton_DM_OD_LO           PIN_DM_OD_LO
        #define StartButton_DM_OD_HI           PIN_DM_OD_HI
        #define StartButton_DM_STRONG          PIN_DM_STRONG
        #define StartButton_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define StartButton_MASK               StartButton__MASK
#define StartButton_SHIFT              StartButton__SHIFT
#define StartButton_WIDTH              1u

/* Interrupt constants */
#if defined(StartButton__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in StartButton_SetInterruptMode() function.
     *  @{
     */
        #define StartButton_INTR_NONE      (uint16)(0x0000u)
        #define StartButton_INTR_RISING    (uint16)(0x0001u)
        #define StartButton_INTR_FALLING   (uint16)(0x0002u)
        #define StartButton_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define StartButton_INTR_MASK      (0x01u) 
#endif /* (StartButton__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define StartButton_PS                     (* (reg8 *) StartButton__PS)
/* Data Register */
#define StartButton_DR                     (* (reg8 *) StartButton__DR)
/* Port Number */
#define StartButton_PRT_NUM                (* (reg8 *) StartButton__PRT) 
/* Connect to Analog Globals */                                                  
#define StartButton_AG                     (* (reg8 *) StartButton__AG)                       
/* Analog MUX bux enable */
#define StartButton_AMUX                   (* (reg8 *) StartButton__AMUX) 
/* Bidirectional Enable */                                                        
#define StartButton_BIE                    (* (reg8 *) StartButton__BIE)
/* Bit-mask for Aliased Register Access */
#define StartButton_BIT_MASK               (* (reg8 *) StartButton__BIT_MASK)
/* Bypass Enable */
#define StartButton_BYP                    (* (reg8 *) StartButton__BYP)
/* Port wide control signals */                                                   
#define StartButton_CTL                    (* (reg8 *) StartButton__CTL)
/* Drive Modes */
#define StartButton_DM0                    (* (reg8 *) StartButton__DM0) 
#define StartButton_DM1                    (* (reg8 *) StartButton__DM1)
#define StartButton_DM2                    (* (reg8 *) StartButton__DM2) 
/* Input Buffer Disable Override */
#define StartButton_INP_DIS                (* (reg8 *) StartButton__INP_DIS)
/* LCD Common or Segment Drive */
#define StartButton_LCD_COM_SEG            (* (reg8 *) StartButton__LCD_COM_SEG)
/* Enable Segment LCD */
#define StartButton_LCD_EN                 (* (reg8 *) StartButton__LCD_EN)
/* Slew Rate Control */
#define StartButton_SLW                    (* (reg8 *) StartButton__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define StartButton_PRTDSI__CAPS_SEL       (* (reg8 *) StartButton__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define StartButton_PRTDSI__DBL_SYNC_IN    (* (reg8 *) StartButton__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define StartButton_PRTDSI__OE_SEL0        (* (reg8 *) StartButton__PRTDSI__OE_SEL0) 
#define StartButton_PRTDSI__OE_SEL1        (* (reg8 *) StartButton__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define StartButton_PRTDSI__OUT_SEL0       (* (reg8 *) StartButton__PRTDSI__OUT_SEL0) 
#define StartButton_PRTDSI__OUT_SEL1       (* (reg8 *) StartButton__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define StartButton_PRTDSI__SYNC_OUT       (* (reg8 *) StartButton__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(StartButton__SIO_CFG)
    #define StartButton_SIO_HYST_EN        (* (reg8 *) StartButton__SIO_HYST_EN)
    #define StartButton_SIO_REG_HIFREQ     (* (reg8 *) StartButton__SIO_REG_HIFREQ)
    #define StartButton_SIO_CFG            (* (reg8 *) StartButton__SIO_CFG)
    #define StartButton_SIO_DIFF           (* (reg8 *) StartButton__SIO_DIFF)
#endif /* (StartButton__SIO_CFG) */

/* Interrupt Registers */
#if defined(StartButton__INTSTAT)
    #define StartButton_INTSTAT            (* (reg8 *) StartButton__INTSTAT)
    #define StartButton_SNAP               (* (reg8 *) StartButton__SNAP)
    
	#define StartButton_0_INTTYPE_REG 		(* (reg8 *) StartButton__0__INTTYPE)
#endif /* (StartButton__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_StartButton_H */


/* [] END OF FILE */
