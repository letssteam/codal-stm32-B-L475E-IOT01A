/**
 ******************************************************************************
 * @file    es_wifi_io.h
 * @author  MCD Application Team
 * @brief   This file contains the functions prototypes for es_wifi IO operations.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2017 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#ifndef WIFI_IO_H
#define WIFI_IO_H

#include "STM32Pin.h"
#include "STM32SPI.h"
#include "stm32l4xx_hal.h"
#include "wiring_time.h"

/* Exported macro ------------------------------------------------------------*/
#define WIFI_RESET_MODULE()          \
    do {                             \
        resetPin.setDigitalValue(0); \
        delay(10);                   \
        resetPin.setDigitalValue(1); \
        delay(500);                  \
    } while (0);

#define WIFI_ENABLE_NSS()          \
    do {                           \
        nssPin.setDigitalValue(0); \
    } while (0);

#define WIFI_DISABLE_NSS()         \
    do {                           \
        nssPin.setDigitalValue(1); \
    } while (0);

#define WIFI_IS_CMDDATA_READY() (commandDataReadyPin.getDigitalValue() == 1)

#ifdef __cplusplus
extern "C" {
#endif

int8_t SPI_WIFI_DeInit(void);
int8_t SPI_WIFI_Init(uint16_t mode);
int8_t SPI_WIFI_ResetModule(void);
int16_t SPI_WIFI_ReceiveData(uint8_t* pData, uint16_t len, uint32_t timeout);
int16_t SPI_WIFI_SendData(uint8_t* pData, uint16_t len, uint32_t timeout);
void SPI_WIFI_Delay(uint32_t Delay);
void SPI_WIFI_ISR(void);

#ifdef __cplusplus
}
#endif

#endif /* WIFI_IO_H */
