/*

The MIT License (MIT)

Copyright (c) 2022 Ryan Edwards

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BOARD_H__
#define __BOARD_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "usbd_def.h"

#define BOARD_SYSMEM_RESET_VECTOR	 0x1FF09800

#define USBD_VID					 0x1D50
#define USBD_LANGID_STRING			 1033
#define USBD_MANUFACTURER_STRING	 (uint8_t*) "budgetcan.io"
#define USBD_PID_FS					 0x606F
#define USBD_PRODUCT_STRING_FS		 (uint8_t*) "budgetcan_h7"
#define USBD_CONFIGURATION_STRING	 (uint8_t*) "gs_usb"
#define USBD_INTERFACE_STRING		 (uint8_t*) "gs_usb interface"
#define DFU_INTERFACE_STRING		 (uint8_t*) "budgetcan_h7 DFU interface"

#define FDCAN_SJW_INIT				 1
#define FDCAN_BRP_INIT				 8
#define FDCAN_TS1_INIT				 13
#define FDCAN_TS2_INIT				 2

#define FDCAN_DATA_SJW_INIT			 4
#define FDCAN_DATA_BRP_INIT			 2
#define FDCAN_DATA_TS1_INIT			 15
#define FDCAN_DATA_TS2_INIT			 4

#define FDCAN_FRAME_FMT_INIT		 FDCAN_FRAME_FD_BRS
#define FDCAN_MODE_INIT				 FDCAN_MODE_NORMAL
#define FDCAN_AUTO_RETX_INIT		 DISABLE
#define FDCAN_AUTO_TX_PAUSE_INIT	 DISABLE
#define FDCAN_PROT_EXCPTN_INIT		 ENABLE
#define FDCAN_STD_FLTR_NUM_INIT		 0
#define FDCAN_EXT_FLTR_NUM_INIT		 0

#define FDCAN_TX_FIFO_OPERATION_INIT FDCAN_TX_FIFO_OPERATION
#define FDCAN_MSG_RAM_OFST_INIT		 0
#define FDCAN_RX_FIFO0_ELEM_NUM_INIT 16
#define FDCAN_RX_FIFO0_ELEM_SZ_INIT	 FDCAN_DATA_BYTES_64
#define FDCAN_RX_FIFO1_ELEM_NUM_INIT 16
#define FDCAN_RX_FIFO1_ELEM_SZ_INIT	 FDCAN_DATA_BYTES_64
#define FDCAN_RX_BUFF_NUM_INIT		 64
#define FDCAN_RX_BUFF_SZ_INIT		 FDCAN_DATA_BYTES_64
#define FDCAN_TX_EVNT_NUM_INIT		 16
#define FDCAN_TX_BUFF_NUM_INIT		 16
#define FDCAN_TX_FIFO_ELEM_NUM_INIT	 16
#define FDCAN_TX_FIFO_ELEM_SZ_INIT	 FDCAN_DATA_BYTES_64

#define CAN_NUM_CHANNELS			 2
#define CAN_CLOCK_SPEED				 120000000
#define CANFD_FEATURE_ENABLED

#define BOARD_TIM2_PRESCALER   240-1

#define QUEUE_SIZE_HOST_TO_DEV 32
#define QUEUE_SIZE_DEV_TO_HOST 32

#define LED1_Pin			   GPIO_PIN_2
#define LED1_GPIO_Port		   GPIOJ
#define LED2_Pin			   GPIO_PIN_13
#define LED2_GPIO_Port		   GPIOI
#define LED3_Pin			   GPIO_PIN_3
#define LED3_GPIO_Port		   GPIOD

#ifdef CAN_TERM_FEATURE_ENABLED
#define FDCAN1_TERM_EN_GPIO_CLK_Enable __HAL_RCC_GPIOD_CLK_ENABLE
#define FDCAN2_TERM_EN_GPIO_CLK_Enable __HAL_RCC_GPIOD_CLK_ENABLE
#define FDCAN1_TERM_EN_GPIO_Port 	GPIOD
#define FDCAN1_TERM_EN_Pin 			GPIO_PIN_1
#define FDCAN2_TERM_EN_GPIO_Port 	GPIOD
#define FDCAN2_TERM_EN_Pin 			GPIO_PIN_2
#endif

void SystemClock_Config(void);
void MX_GPIO_Init(void);

#ifdef __cplusplus
}
#endif
#endif /*__ BOARD_H__ */

