/* This file is part of the libopencm3 project.
 *
 * It was generated by the irq2nvic_h script.
 */

#ifndef LIBOPENCM3_LPC43xx_M0_NVIC_H
#define LIBOPENCM3_LPC43xx_M0_NVIC_H

#include <libopencm3/cm3/nvic.h>

/** @defgroup CM3_nvic_defines_LPC43xx (M0) User interrupts for LPC 43xx series M0 core
    @ingroup CM3_nvic_defines

    @{*/

#define NVIC_FLASHEEPROMAT_IRQ 4
#define NVIC_ETHERNET_IRQ 5
#define NVIC_SDIO_IRQ 6
#define NVIC_LCD_IRQ 7
#define NVIC_RTC_IRQ 0
#define NVIC_M4CORE_IRQ 1
#define NVIC_DMA_IRQ 2
#define NVIC_USB0_IRQ 8
#define NVIC_USB1_IRQ 9
#define NVIC_USART3_IRQ 27
#define NVIC_USART2_OR_C_CAN1_IRQ 26
#define NVIC_UART1_IRQ 25
#define NVIC_USART0_IRQ 24
#define NVIC_EVENTROUTER_IRQ 23
#define NVIC_SSP0_OR_SSP1_IRQ 22
#define NVIC_ADC1_IRQ 21
#define NVIC_SPI_OR_DAC_IRQ 20
#define NVIC_C_CAN0_IRQ 29
#define NVIC_I2S0_OR_I2S1_IRQ 28
#define NVIC_I2C0_OR_IRC1_IRQ 18
#define NVIC_SGPIO_IRQ 19
#define NVIC_MCPWM_IRQ 16
#define NVIC_ADC0_IRQ 17
#define NVIC_PIN_INT4_IRQ 14
#define NVIC_TIMER3_IRQ 15
#define NVIC_TIMER0_IRQ 12
#define NVIC_GINT1_IRQ 13
#define NVIC_SCT_IRQ 10
#define NVIC_RITIMER_OR_WWDT_IRQ 11

#define NVIC_IRQ_COUNT 30

/**@}*/

/** @defgroup CM3_nvic_isrprototypes_LPC43xx (M0) User interrupt service routines (ISR) prototypes for LPC 43xx series M0 core
    @ingroup CM3_nvic_isrprototypes

    @{*/

BEGIN_DECLS

void WEAK flasheepromat_isr(void);
void WEAK ethernet_isr(void);
void WEAK sdio_isr(void);
void WEAK lcd_isr(void);
void WEAK rtc_isr(void);
void WEAK m4core_isr(void);
void WEAK dma_isr(void);
void WEAK usb0_isr(void);
void WEAK usb1_isr(void);
void WEAK usart3_isr(void);
void WEAK usart2_or_c_can1_isr(void);
void WEAK uart1_isr(void);
void WEAK usart0_isr(void);
void WEAK eventrouter_isr(void);
void WEAK ssp0_or_ssp1_isr(void);
void WEAK adc1_isr(void);
void WEAK spi_or_dac_isr(void);
void WEAK c_can0_isr(void);
void WEAK i2s0_or_i2s1_isr(void);
void WEAK i2c0_or_irc1_isr(void);
void WEAK sgpio_isr(void);
void WEAK mcpwm_isr(void);
void WEAK adc0_isr(void);
void WEAK pin_int4_isr(void);
void WEAK timer3_isr(void);
void WEAK timer0_isr(void);
void WEAK gint1_isr(void);
void WEAK sct_isr(void);
void WEAK ritimer_or_wwdt_isr(void);

END_DECLS

/**@}*/

#endif /* LIBOPENCM3_LPC43xx_M0_NVIC_H */
