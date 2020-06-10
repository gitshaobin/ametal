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
 * \brief WDT�����ӿ�
 *
 * \internal
 * \par Modification history
 * - 1.00 20-05-11
 * \endinternal
 */

#ifndef __AMHW_HC32F460_WDT_H
#define __AMHW_HC32F460_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "am_types.h"

/*
 * \brief �����ṹ��εĿ�ʼ
 */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
#elif defined(__TMS470__)
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler t
#endif

/**
 * \addtogroup amhw_hc32f460_if_wdt
 * \copydoc amhw_hc32f460_wdt.h
 * @{
 */

typedef struct
{
    __IO uint32_t PERI                      : 2;
    uint32_t RESERVED2                      : 2;
    __IO uint32_t CKS                       : 4;
    __IO uint32_t WDPT                      : 4;
    uint32_t RESERVED12                     : 4;
    __IO uint32_t SLPOFF                    : 1;
    uint32_t RESERVED17                     :14;
    __IO uint32_t ITS                       : 1;
} stc_wdt_cr_field_t;

typedef struct
{
    __IO uint32_t CNT                       :16;
    __IO uint32_t UDF                       : 1;
    __IO uint32_t REF                       : 1;
    uint32_t RESERVED18                     :14;
} stc_wdt_sr_field_t;

typedef struct
{
    __IO uint32_t RF                        :16;
    uint32_t RESERVED16                     :16;
} stc_wdt_rr_field_t;

/**
 * \brief WDT�Ĵ�����ṹ��
 */
typedef struct amhw_hc32f460_wdt{
    union
    {
        __IO uint32_t CR;
        stc_wdt_cr_field_t CR_f;
    };
    union
    {
        __IO uint32_t SR;
        stc_wdt_sr_field_t SR_f;
    };
    union
    {
        __IO uint32_t RR;
        stc_wdt_rr_field_t RR_f;
    };
} amhw_hc32f460_wdt_t;


typedef enum {
    AMHW_HC32F460_WDT_TRIGGER_INTERRUPT_REQUEST = (0 << 31),
    AMHW_HC32F460_WDT_TRIGGER_RESET_REQUEST     = (1 << 31),
} amhw_hc32f460_wdt_event_request_type_t;

typedef enum {
    AMHW_HC32F460_WDT_SLEEPOFF = (1 << 16),
    AMHW_HC32F460_WDT_SLEEPON  = (0 << 16),
} amhw_hc32f460_wdt_sleepoff_t;


typedef enum {
    AMHW_HC32F460_WDT_REFRESH_RANGE_100              = 0 << 8,  /* 100% */
    AMHW_HC32F460_WDT_REFRESH_RANGE_0_25             = 1 << 8,  /* 0%~25% */
    AMHW_HC32F460_WDT_REFRESH_RANGE_25_50            = 2 << 8,  /* 25%~50% */
    AMHW_HC32F460_WDT_REFRESH_RANGE_0_50             = 3 << 8,  /* 0%~50% */
    AMHW_HC32F460_WDT_REFRESH_RANGE_50_75            = 4 << 8,  /* 50%~75% */
    AMHW_HC32F460_WDT_REFRESH_RANGE_0_25_AND_50_75   = 5 << 8,  /* 0%~25% & 50%~75% */
    AMHW_HC32F460_WDT_REFRESH_RANGE_25_75            = 6 << 8,  /* 25%~75% */
    AMHW_HC32F460_WDT_REFRESH_RANGE_0_75             = 7 << 8,  /* 0%~75% */
    AMHW_HC32F460_WDT_REFRESH_RANGE_75_100           = 8 << 8,  /* 75%~100% */
    AMHW_HC32F460_WDT_REFRESH_RANGE_0_25_AND_75_100  = 9 << 8,  /* 0%~25% & 75%~100% */
    AMHW_HC32F460_WDT_REFRESH_RANGE_25_50_AND_75_100 = 10 << 8, /* 25%~50% & 75%~100% */
    AMHW_HC32F460_WDT_REFRESH_RANGE_0_50_AND_75_100  = 11 << 8, /* 0%~50% & 75%~100% */
    AMHW_HC32F460_WDT_REFRESH_RANGE_50_100           = 12 << 8, /* 50%~100% */
    AMHW_HC32F460_WDT_REFRESH_RANGE_0_25_AND_50_100  = 13 << 8, /* 0%~25% & 50%~100% */
    AMHW_HC32F460_WDT_REFRESH_RANGE_25_100           = 14 << 8, /* 25%~100% */
    AMHW_HC32F460_WDT_REFRESH_RANGE_0_100            = 15 << 8, /* 0%~100% */
} amhw_hc32f460_wdt_refresh_range_t;


typedef enum {
    AMHW_HC32F460_WDT_COUNT_CLK_DIV_4    = 2,   /* PCLK3/4 */
    AMHW_HC32F460_WDT_COUNT_CLK_DIV_64   = 6,   /* PCLK3/64 */
    AMHW_HC32F460_WDT_COUNT_CLK_DIV_128  = 7,   /* PCLK3/128 */
    AMHW_HC32F460_WDT_COUNT_CLK_DIV_256  = 8,   /* PCLK3/256 */
    AMHW_HC32F460_WDT_COUNT_CLK_DIV_512  = 9,   /* PCLK3/512 */
    AMHW_HC32F460_WDT_COUNT_CLK_DIV_1024 = 0xA, /* PCLK3/1024 */
    AMHW_HC32F460_WDT_COUNT_CLK_DIV_2048 = 0xB, /* PCLK3/2048 */
    AMHW_HC32F460_WDT_COUNT_CLK_DIV_8192 = 0xD, /* PCLK3/8192 */
} amhw_hc32f460_wdt_count_clk_div_t;


typedef enum {
    AMHW_HC32F460_WDT_COUNT_PERIOD_256    = 0,   /* 256 cycle */
    AMHW_HC32F460_WDT_COUNT_PERIOD_4096   = 1,   /* 4096 cycle */
    AMHW_HC32F460_WDT_COUNT_PERIOD_16384  = 2,   /* 16384 cycle */
    AMHW_HC32F460_WDT_COUNT_PERIOD_65536  = 3,   /* 65536 cycle */
} amhw_hc32f460_wdt_count_period_t;


/**
 * \brief ����cr�Ĵ�����ֵ
 *
 * \param[in] p_hw_wdt : ָ��WDT�Ĵ������ָ��
 * \param[in] reg_val  : �Ĵ�������ֵ
 *
 * \return ��
 */
am_static_inline
void amhw_hc32f460_wdt_cr_set (amhw_hc32f460_wdt_t                *p_hw_wdt,
                               uint32_t                            reg_val)
{
    p_hw_wdt->CR = reg_val;
}

/**
 * \brief ��ȡ��������ǰ����ֵ
 *
 * \param[in] p_hw_wdt : ָ��WDT�Ĵ������ָ��
 *
 * \return ��
 */
am_static_inline
uint16_t amhw_hc32f460_wdt_count_value_get (amhw_hc32f460_wdt_t  *p_hw_wdt)
{
    return p_hw_wdt->SR_f.CNT;
}

typedef enum {
    AMHW_HC32F460_WDT_STATUS_REF   = 1 << 17,   /* ˢ�´����־ */
    AMHW_HC32F460_WDT_STATUS_UDF   = 1 << 16,   /* ���������־ */
} amhw_hc32f460_wdt_status_flag_t;

/**
 * \brief ��ȡ���Ź�״̬
 *
 * \param[in] p_hw_wdt : ָ��WDT�Ĵ������ָ��
 * \param[in] flag     : ״̬��־
 *
 * \return ��
 */
am_static_inline
am_bool_t amhw_hc32f460_wdt_status_get (amhw_hc32f460_wdt_t             *p_hw_wdt,
                                        amhw_hc32f460_wdt_status_flag_t  flag)
{
    return (p_hw_wdt->SR & flag) ? AM_TRUE : AM_FALSE;
}

/**
 * \brief ������Ź�״̬
 *
 * \param[in] p_hw_wdt : ָ��WDT�Ĵ������ָ��
 * \param[in] flag     : ״̬��־
 *
 * \return ��
 */
am_static_inline
void amhw_hc32f460_wdt_status_clr (amhw_hc32f460_wdt_t             *p_hw_wdt,
                                   amhw_hc32f460_wdt_status_flag_t  flag)
{
    p_hw_wdt->SR &= ~flag;
}



typedef enum {
    AMHW_HC32F460_WDT_REFRESH_START = 0x0123, /* ˢ�¼�����Ҫд��ĵ�һ��ֵ */
    AMHW_HC32F460_WDT_REFRESH_END   = 0x3210, /* ˢ�¼�����Ҫд��ĵڶ���ֵ */
} amhw_hc32f460_wdt_refresh_set_t;

/**
 * \brief ˢ�¿��Ź�������
 *
 * \param[in] p_hw_wdt : ָ��WDT�Ĵ������ָ��
 * \param[in] flag     : ˢ�¼�����Ҫд����ض�ֵ��amhw_hc32f460_wdt_refresh_set_t��
 *
 * \return ��
 */
am_static_inline
void amhw_hc32f460_wdt_refresh_set (amhw_hc32f460_wdt_t             *p_hw_wdt,
                                    amhw_hc32f460_wdt_refresh_set_t  flag)
{
    p_hw_wdt->RR_f.RF = flag;
}

/**
 * @}
 */
/*
 * \brief �����ṹ��εĽ���
 */

#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
#elif defined(__GNUC__)
#elif defined(__TMS470__)
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler t
#endif

#ifdef __cplusplus
}
#endif /* __AMHW_HC32F460_WDT_H */

#endif

/* end of file */