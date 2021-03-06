/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief LPUART DMA 接收例程，通过 HW 层接口实现
 *
 * - 操作步骤：
 *   1. 通过上位机串口一次性向 MCU 发送 5 个字符。
 *
 * - 实验现象：
 *   1. 串口打印出接收到的数据；
 *   2. 然后串口打印出 "DMA transfer done!"。
 *
 * \note
 *    1. 如需观察串口打印的调试信息，需要将 PIOB_11 引脚连接 PC 串口的 TXD，
 *       PIOB_12 引脚连接 PC 串口的 RXD；
 *    2. 如果调试串口使用与本例程相同，则不应在后续继续使用调试信息输出函数
 *      （如：AM_DBG_INFO()）。
 *
 * \par 源代码
 * \snippet demo_hc32f17x_hw_lpuart_rx_dma.c src_hc32f17x_hw_lpuart_rx_dma
 *
 *
 * \internal
 * \par Modification History
 * - 1.00 19-09-26  zp, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_hc32f17x_hw_lpuart_rx_dma
 * \copydoc demo_hc32f17x_hw_lpuart_rx_dma.c
 */

/** [src_hc32f17x_hw_lpuart_rx_dma] */
#include "ametal.h"
#include "am_hc32.h"
#include "demo_hc32_entries.h"
#include "am_hc32f17x_inst_init.h"
#include "demo_amf17x_core_entries.h"

/**
 * \brief 例程入口
 */
void demo_hc32f17x_core_hw_lpuart_rx_dma_entry (void)
{
    AM_DBG_INFO("demo amf17x_core hw lpuart rx dma!\r\n");

    /* 等待发送数据完成 */
    am_mdelay(100);

    /* 初始化引脚 */
    am_gpio_pin_cfg(PIOB_11, PIOB_11_LPUART0_RXD | PIOB_11_INPUT_FLOAT);
    am_gpio_pin_cfg(PIOB_12, PIOB_12_LPUART0_TXD | PIOB_12_OUT_PP );

    /* 使能时钟 */
    am_clk_enable(CLK_LPUART0);

    demo_hc32_hw_lpuart_rx_dma_entry(HC32_LPUART0,
                                     AMHW_HC32_LPUART_SCLK_SRC_PCLK,
                                     am_clk_rate_get(CLK_LPUART0),
                                     115200,
                                     DMA_CHAN_1,
                                     HC32_DMA_SRC_TYPE_LPUART0_RX);
}

/** [src_hc32f17x_hw_lpuart_rx_dma] */

/* end of file */
