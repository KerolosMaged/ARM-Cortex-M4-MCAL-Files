/*========================================================
File        : SPI_INTERFACE
Description : This file contain the declerations of SPI functions 
Author      : Kerolos Maged Amin Fekry
Date        : 30/4/2026
Github      : https://github.com/KerolosMaged
========================================================*/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "SPI_PRIVATE.h"





/*=============================================================================================================================================================*/
/*======================================================================= STATUS FLAGS ========================================================================*/
/*=============================================================================================================================================================*/

/*------------------ Read one flag from SPI_SR (returns 1 or 0) ------------------- */
uint8_t  SPI_GetFlag(SPI_n *SPI_x, SPI_FLAG Copy_Flag);

/*------------------ Check BSY flag (1 = busy , 0 = idle) ------------------- */
uint8_t  SPI_IsBusy(SPI_n *SPI_x);

void PIN_ACCESS_SPI(uint8_t Copy_port, uint8_t Copy_pin);

/*=============================================================================================================================================================*/
/*====================================================================== ERROR FLAGS ==========================================================================*/
/*=============================================================================================================================================================*/

/*------------------ Overrun : read DR then SR ------------------- */
void     SPI_ClearOVR(SPI_n *SPI_x);

/*------------------ Mode fault : read SR then write CR1 ------------------- */
/* Hardware clears SPE and MSTR on MODF, so call SPI_MasterInit again after this */
void     SPI_ClearMODF(SPI_n *SPI_x);

/*------------------ CRC error : write 0 to the flag ------------------- */
void     SPI_ClearCRCERR(SPI_n *SPI_x);

/*------------------ Frame format error (TI mode) : read SR ------------------- */
void     SPI_ClearFRE(SPI_n *SPI_x);

/*------------------ Get all error flags (0 = no error) ------------------- */
uint32_t SPI_GetErrors(SPI_n *SPI_x);


/*=============================================================================================================================================================*/
/*============================================================= DATA TRANSMISSION AND RECEPTION PROCEDURES ====================================================*/
/*=============================================================================================================================================================*/

/*=================== Full duplex buffers ===================*/

/*------------------ Master : transmit and receive buffer ------------------- */
void SPI_MasterTransiveBuffer(SPI_n *SPI_x, uint8_t *Copy_TX, uint8_t *Copy_RX, uint32_t Copy_Len);

/*------------------ Master : transmit only buffer ------------------- */
/* Waits TXE = 1 and BSY = 0 at the end, so it is safe to release CS right after */
void SPI_MasterTXBuffer(SPI_n *SPI_x, uint8_t *Copy_TX, uint32_t Copy_Len);

/*------------------ Master : receive only buffer (sends dummy bytes) ------------------- */
/* Copy_Dummy is sent on MOSI to generate the clock (example 0xFF) */
void SPI_MasterRXBuffer(SPI_n *SPI_x, uint8_t *Copy_RX, uint32_t Copy_Len, uint8_t Copy_Dummy);

/*------------------ Slave : transmit and receive buffer ------------------- */
/* Blocks until the master clocks all the frames */
void SPI_SlaveTransiveBuffer(SPI_n *SPI_x, uint8_t *Copy_TX, uint8_t *Copy_RX, uint32_t Copy_Len);

/*------------------ Slave : transmit only buffer ------------------- */
/* Incoming bytes are read and dropped to avoid OVR */
void SPI_SlaveTXBuffer(SPI_n *SPI_x, uint8_t *Copy_TX, uint32_t Copy_Len);

/*------------------ Slave : receive only buffer ------------------- */
void SPI_SlaveRXBuffer(SPI_n *SPI_x, uint8_t *Copy_RX, uint32_t Copy_Len);

/*=================== Half duplex buffers ===================*/

/*------------------ Master : receive buffer ------------------- */
/* Clears SPE after the second-last RXNE so exactly Copy_Len frames are clocked */
void SPI_MasterHalfRXBuffer(SPI_n *SPI_x, uint8_t *Copy_RX, uint32_t Copy_Len);

/*------------------ Slave : receive buffer ------------------- */
void SPI_SlaveHalfRXBuffer(SPI_n *SPI_x, uint8_t *Copy_RX, uint32_t Copy_Len);


/*=============================================================================================================================================================*/
/*====================================================================== CRC CALCULATION ======================================================================*/
/*=============================================================================================================================================================*/

/*------------------ Enable CRC (CRCEN can only change when SPE = 0) ------------------- */
/* CRC size follows the frame length: 8-bit frame -> CRC8 , 16-bit frame -> CRC16 */
/* Master and Slave must use the same polynomial and the same frame length */
void     SPI_CRC_Enable(SPI_n *SPI_x, uint16_t Copy_Poly);

/*------------------ Disable CRC ------------------- */
void     SPI_CRC_Disable(SPI_n *SPI_x);

/*------------------ Send the CRC after the next data ------------------- */
/* Call it right after writing the last data to DR */
void     SPI_CRC_Next(SPI_n *SPI_x);

/*------------------ Read the CRC of the received data ------------------- */
uint16_t SPI_GetRxCRC(SPI_n *SPI_x);

/*------------------ Read the CRC of the transmitted data ------------------- */
uint16_t SPI_GetTxCRC(SPI_n *SPI_x);

/*------------------ Full duplex buffer with CRC (returns 0 = OK , 1 = CRC error) ------------------- */
uint8_t  SPI_MasterTransiveBufferCRC(SPI_n *SPI_x, uint8_t *Copy_TX, uint8_t *Copy_RX, uint32_t Copy_Len);
uint8_t  SPI_SlaveTransiveBufferCRC(SPI_n *SPI_x, uint8_t *Copy_TX, uint8_t *Copy_RX, uint32_t Copy_Len);


/*=============================================================================================================================================================*/
/*====================================================================== DISABLING THE SPI ====================================================================*/
/*=============================================================================================================================================================*/

/*------------------ Enable the SPI (SPE = 1) ------------------- */
void     SPI_Enable(SPI_n *SPI_x);

/*------------------ Disable after the last frame (wait TXE = 1 and BSY = 0 then SPE = 0) ------------------- */
void     SPI_Disable(SPI_n *SPI_x);

/*------------------ Disable and turn off the peripheral clock ------------------- */
void     SPI_DeInit(uint32_t SPI_x);


/*=============================================================================================================================================================*/
/*====================================================================== COMMUNICATION USING DMA ==============================================================*/
/*=============================================================================================================================================================*/

/*------------------ Data register address (for the DMA peripheral address) ------------------- */
uint32_t SPI_GetDRAddress(SPI_n *SPI_x);

/*------------------ Enable DMA request (RXDMAEN = bit 0 , TXDMAEN = bit 1) ------------------- */
/* The DMA stream itself is configured in the DMA driver */
void     SPI_DMA_Enable(SPI_n *SPI_x, SPI_DMA Copy_Request);

/*------------------ Disable after the DMA transfer is complete ------------------- */
void     SPI_DMA_Disable(SPI_n *SPI_x, SPI_DMA Copy_Request);


/*=============================================================================================================================================================*/
/*====================================================================== SPI INTERRUPTS =======================================================================*/
/*=============================================================================================================================================================*/

/*------------------ Enable interrupt source (RXNE , TXE , ERR) ------------------- */
/* Also enable the IRQ in the NVIC : SPI1 = 35 , SPI2 = 36 , SPI3 = 51 , SPI4 = 84 */
void SPI_EnableInterrupt(SPI_n *SPI_x, SPI_INT Copy_Int);

/*------------------ Disable interrupt source ------------------- */
void SPI_DisableInterrupt(SPI_n *SPI_x, SPI_INT Copy_Int);

/*------------------ Set the function called from the ISR ------------------- */
/* RXNE callback must read DR */
/* TXE callback must write DR or disable TXEIE, otherwise the interrupt fires forever */
/* ERR callback must clear the error flag */
void SPI_SetCallBack(SPI_n *SPI_x, SPI_INT Copy_Int, SPI_CB Copy_Func);







#endif