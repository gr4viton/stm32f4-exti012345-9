/* This file is part of the libopencm3 project.
 *
 * It was generated by the irq2nvic_h script.
 *
 * This part needs to get included in the compilation unit where
 * blocking_handler gets defined due to the way #pragma works.
 */


/** @defgroup CM3_nvic_isrpragmas_LPC43xx (M4) User interrupt service routines (ISR) defaults for LPC 43xx series M4 core
    @ingroup CM3_nvic_isrpragmas

    @{*/

#pragma weak c_can0_isr = blocking_handler
#pragma weak qei_isr = blocking_handler
#pragma weak i2c0_isr = blocking_handler
#pragma weak i2c1_isr = blocking_handler
#pragma weak timer2_isr = blocking_handler
#pragma weak timer3_isr = blocking_handler
#pragma weak mcpwm_isr = blocking_handler
#pragma weak adc0_isr = blocking_handler
#pragma weak sct_isr = blocking_handler
#pragma weak ritimer_isr = blocking_handler
#pragma weak timer0_isr = blocking_handler
#pragma weak timer1_isr = blocking_handler
#pragma weak sdio_isr = blocking_handler
#pragma weak lcd_isr = blocking_handler
#pragma weak ethernet_isr = blocking_handler
#pragma weak dma_isr = blocking_handler
#pragma weak dac_isr = blocking_handler
#pragma weak m0core_isr = blocking_handler
#pragma weak usb0_isr = blocking_handler
#pragma weak usb1_isr = blocking_handler
#pragma weak pin_int0_isr = blocking_handler
#pragma weak pin_int1_isr = blocking_handler
#pragma weak spifi_isr = blocking_handler
#pragma weak sgpio_isr = blocking_handler
#pragma weak pin_int4_isr = blocking_handler
#pragma weak pin_int5_isr = blocking_handler
#pragma weak pin_int2_isr = blocking_handler
#pragma weak pin_int3_isr = blocking_handler
#pragma weak pin_int6_isr = blocking_handler
#pragma weak pin_int7_isr = blocking_handler
#pragma weak c_can1_isr = blocking_handler
#pragma weak eventrouter_isr = blocking_handler
#pragma weak gint1_isr = blocking_handler
#pragma weak gint0_isr = blocking_handler
#pragma weak rtc_isr = blocking_handler
#pragma weak atimer_isr = blocking_handler
#pragma weak wwdt_isr = blocking_handler
#pragma weak uart1_isr = blocking_handler
#pragma weak usart0_isr = blocking_handler
#pragma weak usart3_isr = blocking_handler
#pragma weak usart2_isr = blocking_handler
#pragma weak adc1_isr = blocking_handler
#pragma weak spi_isr = blocking_handler
#pragma weak ssp1_isr = blocking_handler
#pragma weak ssp0_isr = blocking_handler
#pragma weak i2s1_isr = blocking_handler
#pragma weak i2s0_isr = blocking_handler

/**@}*/

/* Initialization template for the interrupt vector table. This definition is
 * used by the startup code generator (vector.c) to set the initial values for
 * the interrupt handling routines to the chip family specific _isr weak
 * symbols. */

#define IRQ_HANDLERS \
    [NVIC_C_CAN0_IRQ] = c_can0_isr, \
    [NVIC_QEI_IRQ] = qei_isr, \
    [NVIC_I2C0_IRQ] = i2c0_isr, \
    [NVIC_I2C1_IRQ] = i2c1_isr, \
    [NVIC_TIMER2_IRQ] = timer2_isr, \
    [NVIC_TIMER3_IRQ] = timer3_isr, \
    [NVIC_MCPWM_IRQ] = mcpwm_isr, \
    [NVIC_ADC0_IRQ] = adc0_isr, \
    [NVIC_SCT_IRQ] = sct_isr, \
    [NVIC_RITIMER_IRQ] = ritimer_isr, \
    [NVIC_TIMER0_IRQ] = timer0_isr, \
    [NVIC_TIMER1_IRQ] = timer1_isr, \
    [NVIC_SDIO_IRQ] = sdio_isr, \
    [NVIC_LCD_IRQ] = lcd_isr, \
    [NVIC_ETHERNET_IRQ] = ethernet_isr, \
    [NVIC_DMA_IRQ] = dma_isr, \
    [NVIC_DAC_IRQ] = dac_isr, \
    [NVIC_M0CORE_IRQ] = m0core_isr, \
    [NVIC_USB0_IRQ] = usb0_isr, \
    [NVIC_USB1_IRQ] = usb1_isr, \
    [NVIC_PIN_INT0_IRQ] = pin_int0_isr, \
    [NVIC_PIN_INT1_IRQ] = pin_int1_isr, \
    [NVIC_SPIFI_IRQ] = spifi_isr, \
    [NVIC_SGPIO_IRQ] = sgpio_isr, \
    [NVIC_PIN_INT4_IRQ] = pin_int4_isr, \
    [NVIC_PIN_INT5_IRQ] = pin_int5_isr, \
    [NVIC_PIN_INT2_IRQ] = pin_int2_isr, \
    [NVIC_PIN_INT3_IRQ] = pin_int3_isr, \
    [NVIC_PIN_INT6_IRQ] = pin_int6_isr, \
    [NVIC_PIN_INT7_IRQ] = pin_int7_isr, \
    [NVIC_C_CAN1_IRQ] = c_can1_isr, \
    [NVIC_EVENTROUTER_IRQ] = eventrouter_isr, \
    [NVIC_GINT1_IRQ] = gint1_isr, \
    [NVIC_GINT0_IRQ] = gint0_isr, \
    [NVIC_RTC_IRQ] = rtc_isr, \
    [NVIC_ATIMER_IRQ] = atimer_isr, \
    [NVIC_WWDT_IRQ] = wwdt_isr, \
    [NVIC_UART1_IRQ] = uart1_isr, \
    [NVIC_USART0_IRQ] = usart0_isr, \
    [NVIC_USART3_IRQ] = usart3_isr, \
    [NVIC_USART2_IRQ] = usart2_isr, \
    [NVIC_ADC1_IRQ] = adc1_isr, \
    [NVIC_SPI_IRQ] = spi_isr, \
    [NVIC_SSP1_IRQ] = ssp1_isr, \
    [NVIC_SSP0_IRQ] = ssp0_isr, \
    [NVIC_I2S1_IRQ] = i2s1_isr, \
    [NVIC_I2S0_IRQ] = i2s0_isr
