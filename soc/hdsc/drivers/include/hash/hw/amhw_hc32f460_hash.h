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
 * \brief HASH 底层操作接口
 * \internal
 * \par Modification History
 * - 1.00 20-05-22
 * \endinternal
 */

#ifndef __AMHW_HC32F460_HASH_H
#define __AMHW_HC32F460_HASH_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ametal.h"
#include "am_types.h"

/**
 * \addtogroup amhw_hc32f460_if_hash
 * \copydoc amhw_hc32f460_hash.h
 * @{
 */

/**
 * \brief HASH - 寄存器组
 */

typedef struct
{
    __IO uint32_t START                     : 1;
    __IO uint32_t FST_GRP                   : 1;
    uint32_t RESERVED2                      :30;
} stc_hash_cr_field_t;

typedef struct amhw_hc32f460_hash{
    union
    {
        __IO uint32_t CR;
        stc_hash_cr_field_t CR_f;
    };
    uint8_t RESERVED1[12];
    __IO uint32_t HR[8];
    uint8_t RESERVED9[16];
    __IO uint32_t DR[16];
} amhw_hc32f460_hash_t;

/* 数据组的最大字节数 */
#define AMHW_HC32F460_HASH_MAX_GROUP_SIZE    64
/* 最后一个组的最大字节数，剩余8个字节存储原始数据bit数 */
#define AMHW_HC32F460_HASH_LAST_GROUP_SIZE   56

/**
 * \brief 将本次运算作为消息分组的第一组运算
 *
 * \param[in] p_hw_aes : 指向HASH寄存器组基地址指针
 *
 * \retval : 无
 */
am_static_inline
void amhw_hc32f460_hash_first_group (amhw_hc32f460_hash_t *p_hw_hash)
{
	p_hw_hash->CR |= (1 << 1);
}

/**
 * \brief 将本次运算不作为消息分组的第一组运算
 *
 * \param[in] p_hw_aes : 指向HASH寄存器组基地址指针
 *
 * \retval : 无
 */
am_static_inline
void amhw_hc32f460_hash_not_first_group (amhw_hc32f460_hash_t *p_hw_hash)
{
	p_hw_hash->CR &= ~(1 << 1);
}

/**
 * \brief HASH 启动运算
 *
 * \param[in] p_hw_aes : 指向HASH寄存器组基地址指针
 *
 * \retval : 无
 */
am_static_inline
void amhw_hc32f460_hash_start (amhw_hc32f460_hash_t *p_hw_hash)
{
	p_hw_hash->CR |= (1 << 0);
}

/**
 * \brief HASH 状态检查
 *
 * \param[in] p_hw_aes : 指向HASH寄存器组基地址指针
 *
 * \retval : AM_TRUE(运算进行中)/ AM_FALSE(运算结束或未启动)
 */
am_static_inline
am_bool_t amhw_hc32f460_hash_status_check (amhw_hc32f460_hash_t *p_hw_hash)
{
    return (p_hw_hash->CR & (1 << 0)) ? AM_TRUE : AM_FALSE;
}

/**
 * \brief HASH 读取摘要(低地址对应的32位寄存器存放消息摘要的高字)
 *
 * \param[in] p_hw_hash : 指向HASH寄存器组基地址指针
 *
 * \retval : 无
 */
am_static_inline
void amhw_hc32f460_hash_read (amhw_hc32f460_hash_t *p_hw_hash, uint8_t *p_data)
{
    uint32_t i,j = 0;
    uint32_t temp = 0;
    for (i = 0; i < 8; i++){
        j = i * 4 + 3;
        temp = p_hw_hash->HR[i];

        p_data[j] = (uint8_t)temp;
        p_data[j - 1] = (uint8_t)(temp >> 8);
        p_data[j - 2] = (uint8_t)(temp >> 16);
        p_data[j - 3] = (uint8_t)(temp >> 24);
    }
}

/**
 * \brief HASH 写数据(低地址对应的32位寄存器存放数据的高字)
 *
 * \param[in] p_hw_hash : 指向HASH寄存器组基地址指针
 *
 * \retval : 无
 */
am_static_inline
void amhw_hc32f460_hash_data_write (amhw_hc32f460_hash_t *p_hw_hash, uint8_t *p_data)
{
    uint32_t temp = 0;

    int i,j = 0;
    for (i = 0; i < 16; i++){
        j = i * 4 + 3;
        temp = (uint32_t)p_data[j];
        temp |= ((uint32_t)p_data[j - 1] << 8);
        temp |= ((uint32_t)p_data[j - 2] << 16);
        temp |= ((uint32_t)p_data[j - 3] << 24);

        p_hw_hash->DR[i] = temp;
    }
}


/**
 * @} amhw_if_hc32f460_hash
 */

#ifdef __cplusplus
}
#endif

#endif /* __AMHW_HC32F460_HASH_H */

/* end of file */
