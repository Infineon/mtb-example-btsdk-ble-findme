/*******************************************************************************
* File Name:      find_me.c
*
* Description:    This file that contains the application_start() function
*
* Related Document: See Readme.md
*
*******************************************************************************
* Copyright 2021-2022, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

/*******************************************************************************
*        Header Files
*******************************************************************************/
#include "wiced_bt_dev.h"
#include "app_bt_cfg.h"
#include "wiced_bt_trace.h"
#include "app_bt_event_handler.h"
#include "wiced_bt_stack.h"
/*******************************************************************************
*        Macro Definitions
*******************************************************************************/
 /* Refer wiced_debug_uart_types_t in wiced_bt_trace.h for possible values for
  * APP_DEBUG_UART_SEL. Default macro setting below selects the PUART
  * interface. Modify as required. */
#define APP_DEBUG_UART_SEL  (WICED_ROUTE_DEBUG_TO_PUART)
/*******************************************************************************
*        Variable Definitions
*******************************************************************************/
extern const wiced_bt_cfg_buf_pool_t wiced_bt_cfg_buf_pools[WICED_BT_CFG_NUM_BUF_POOLS];

/*******************************************************************************
*        Function Prototypes
*******************************************************************************/

/*******************************************************************************
* Function Name: application_start()
********************************************************************************
* Summary: Entry point to the application. Initialize debug UART and register
*   BLE management event callback. The actual application initialization will
*   happen in BLE management event callback when the stack reports that
*   BT device is ready
*
* Parameters:
*   None
*
* Return:
*  None
*
********************************************************************************/
void application_start(void)
{
    #if (defined WICED_BT_TRACE_ENABLE)
        /* Select Debug UART setting to see debug traces on the
         * appropriate port */
        wiced_set_debug_uart( APP_DEBUG_UART_SEL);
    #endif

    WICED_BT_TRACE("**** Find Me Profile Application Start ****\n\r");

    /* Initialize Stack and Register Management Callback */
    wiced_bt_stack_init(app_bt_management_callback, &wiced_bt_cfg_settings, wiced_bt_cfg_buf_pools);;
}
