/***********
\project    MRBT - Robotický den 2014
\author 	xdavid10, xslizj00, xdvora0u @ FEEC-VUTBR
\filename	.c
\contacts	Bc. Daniel DAVIDEK	<danieldavidek@gmail.com>
            Bc. Jiri SLIZ       <xslizj00@stud.feec.vutbr.cz>
            Bc. Michal Dvorak   <xdvora0u@stud.feec.vutbr.cz>
\date		2014_03_30
\brief      This function only choses which of the 3 possible mains would run

\descrptn
    If you look here and hope to find out how this program works,
    you should look inside headerfiles on function headers to know what they do
    mainly look inside the robot_config.c and inside the struct S_robot.
    S_robot is is the core of everything.
\license    LGPL License Terms \ref lgpl_license
***********/
/* DOCSTYLE: gr4viton_2014_A <goo.gl/1deDBa> */

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// INCLUDES
//_________> project includes
//#include "main.h"
// move to headerfile
#include "defines.h"
#include "led_f4.h"
#include "waitin.h"

#include <libopencm3/stm32/rcc.h>

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/gpio.h>

#include <libopencm3/stm32/syscfg.h>

//#define SYSCFG_BASE         (0x40013800U)

#define MINE_SYSCFG_EXTICR(i)		MMIO32(SYSCFG_BASE + 0x08 + (i)*4)
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// TYPE DEFINITIONS
//____________________________________________________
// enumerations
//____________________________________________________
// structs
//____________________________________________________
// unions
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// VARIABLE DEFINITIONS
//____________________________________________________
// static variables
//____________________________________________________
// other variables


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// EXTERNAL VARIABLE DECLARATIONS
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// INLINE FUNCTION DEFINITIONS - doxygen description should be in HEADERFILE
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// STATIC FUNCTION DEFINITIONS - doxygen description should be in HEADERFILE
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// OTHER FUNCTION DEFINITIONS - doxygen description should be in HEADERFILE


void DBG_trySetup(void);
void MINE_exti_select_source(uint32_t exti, uint32_t gpioport);
void INIT_isr(uint32_t port, uint32_t exti, uint8_t nvic);
void INIT_gpio(uint32_t port, enum rcc_periph_clken rcc, uint16_t pin);


void exti9_5_isr(void)
{
    gpio_toggle(PLED, LEDGREEN0);
	exti_reset_request(EXTI5);
	exti_reset_request(EXTI6);
	exti_reset_request(EXTI7);
	exti_reset_request(EXTI8);
	exti_reset_request(EXTI9);
}

void exti3_isr(void)
{
    gpio_toggle(PLED, LEDGREEN0);
	exti_reset_request(EXTI3);
}

void exti2_isr(void)
{
    gpio_toggle(PLED, LEDGREEN0);
	exti_reset_request(EXTI2);
}

void exti1_isr(void)
{
    gpio_toggle(PLED, LEDGREEN0);
	exti_reset_request(EXTI1);
}

void exti0_isr(void)
{
    gpio_toggle(PLED, LEDGREEN0);
	exti_reset_request(EXTI0);
}

void INIT_gpio(uint32_t port, enum rcc_periph_clken rcc, uint16_t pin)
{
	/* Enable port clock. */
	rcc_periph_clock_enable(rcc);

	/* Set pin (in GPIO port [port]) to 'input float'. */
	gpio_mode_setup(port, GPIO_MODE_INPUT, GPIO_PUPD_NONE, pin);
}

void INIT_isr(uint32_t port, uint32_t exti, uint8_t nvic)
{
	/* Enable exti interrupt. */
	nvic_enable_irq(nvic);
// exti
	MINE_exti_select_source(exti, port);
	exti_set_trigger(exti, EXTI_TRIGGER_BOTH);
	exti_enable_request(exti);

}


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int main(void)
{

    INIT_clk();
	//rcc_clock_setup_hse_3v3(&hse_8mhz_3v3[CLOCK_3V3_168MHZ]);
    INIT_leds();

    INIT_gpio(GPIOA, RCC_GPIOA, GPIO0);
    INIT_gpio(GPIOE, RCC_GPIOE, GPIO0);

/*
//functional
    INIT_isr(GPIOA, EXTI0, NVIC_EXTI0_IRQ);
*/
//false hope - setting this enables int on PA0
    INIT_isr(GPIOE, EXTI0, NVIC_EXTI0_IRQ);

    //DBG_trySetup();


    uint16_t pin                = GPIO0;
    uint8_t irqn                = NVIC_EXTI0_IRQ;
    uint16_t actPort;
    while(1)
    {
        actPort = GPIOE_IDR;
        if( actPort & pin ) gpio_set(PLED,LEDBLUE3);
        else gpio_clear(PLED,LEDBLUE3);


        if( nvic_get_pending_irq(irqn) ) gpio_set(PLED,LEDORANGE1);
        else gpio_clear(PLED,LEDORANGE1);

        gpio_toggle(PLED,LEDRED2);
        mswait(222);
    }

	return 0;
}


void DBG_trySetup(void)
{

/*
    INIT_gpio(GPIOA, RCC_GPIOA, GPIO0);
    INIT_isr(GPIOA, EXTI0, NVIC_EXTI0_IRQ);
*/
    //SYSCFG_EXTICR
    uint32_t port               = GPIOE;
    enum rcc_periph_clken rcc   = RCC_GPIOE;
    uint16_t pin                = GPIO0;
    //uint8_t irqn                = NVIC_EXTI0_IRQ;

    INIT_gpio(port, rcc, pin);
    //INIT_isr(GPIOB, EXTI1, NVIC_EXTI1_IRQ);


    //____________________________________________________
	//exti_select_source(exti, port);
    uint32_t exti = EXTI0; // = 1<<0
    uint32_t reg = 0; // SYSCFG_EXTICR1 = EXTI3:EXTI0
    uint8_t shift = 0*4;
    uint8_t a = 0;

    uint32_t mask;
    uint32_t bits;
    // enable all pins of port PE to be the interupts
    for(a=0;a<4;a++)
    {
        reg = a;
        shift = 4*a;
        mask = 0x0000000F<<shift; // = in EXTICR1 = EXTI0
        bits = 0x00000004<<shift; // PE in EXTI0 = PE0

        // lpc43xx\memorymap.h PERIPH_BASE
        // Table 2.
        MINE_SYSCFG_EXTICR(reg) = (MINE_SYSCFG_EXTICR(reg) & ~mask) | bits;
    }
/*
0B0000: PA[x] pin = 0x00
0B0001: PB[x] pin = 0x01
0B0010: PC[x] pin = 0x02
0B0011: PD[x] pin = 0x03
0B0100: PE[x] pin = 0x04
0B0101: PF[x] pin = 0x05
0B0110: PG[x] pin = 0x06
0B0111: PH[x] pin = 0x07
*/

    exti = EXTI0|EXTI1|EXTI2|EXTI3|EXTI4|EXTI5|EXTI6|EXTI7|EXTI8|EXTI9|EXTI10;

    //____________________________________________________
	//exti_enable_request(EXTI0); // EMR IMR
	EXTI_IMR |= exti;
	EXTI_EMR |= exti;

    //____________________________________________________
	//exti_set_trigger(exti, EXTI_TRIGGER_BOTH);
    EXTI_RTSR |= exti; // raising trigger enabled on exti line
    EXTI_FTSR |= exti; // falling trigger enabled on exti line

    //____________________________________________________
	//nvic_enable_irq(NVIC_EXTI1_IRQ);

	nvic_enable_irq(NVIC_EXTI0_IRQ);
	nvic_enable_irq(NVIC_EXTI1_IRQ);
	nvic_enable_irq(NVIC_EXTI2_IRQ);
	nvic_enable_irq(NVIC_EXTI3_IRQ);
	nvic_enable_irq(NVIC_EXTI9_5_IRQ);
// EXTI1 in NVIC = 0x0000 005C
/*
    //uint8_t irqn = 7;
	NVIC_ISER(irqn / 32) = (1 << (irqn % 32));
*/
/*
	nvic_clear_pending_irq(irqn);
	nvic_disable_irq(irqn);
	nvic_enable_irq(irqn);
*/

//    nvic_set_priority(irqn,10);
/*
    // it is enabled
	if(	nvic_get_irq_enabled(irqn) )
    {
        gpio_set(PLED,LEDBLUE3);
        mswait(222);
        gpio_clear(PLED,LEDBLUE3);
    }
*/


}



void MINE_exti_select_source(uint32_t exti, uint32_t gpioport)
{
	uint32_t line;
	for (line = 0; line < 16; line++) {
		if (!(exti & (1 << line))) {
			continue;
		}

		uint32_t bits = 0, mask = 0x0F;

		switch (gpioport) {
		    default:
		case GPIOA:
			bits = 0;
			break;
		case GPIOB:
			bits = 1;
			break;
		case GPIOC:
			bits = 2;
			break;
		case GPIOD:
			bits = 3;
			break;
#if defined(GPIOE) && defined(GPIO_PORT_E_BASE)
		case GPIOE:
			bits = 4;
			break;
#endif
#if defined(GPIOF) && defined(GPIO_PORT_F_BASE)
		case GPIOF:
			bits = 5;
			break;
#endif
#if defined(GPIOG) && defined(GPIO_PORT_G_BASE)
		case GPIOG:
			bits = 6;
			break;
#endif
#if defined(GPIOH) && defined(GPIO_PORT_H_BASE)
		case GPIOH:
			bits = 7;
			break;
#endif
#if defined(GPIOI) && defined(GPIO_PORT_I_BASE)
		case GPIOI:
			bits = 8;
			break;
#endif
		}

		uint8_t shift = (uint8_t)(4 * (line % 4));
		uint32_t reg = line / 4;
		bits <<= shift;
		mask <<= shift;

#if defined(AFIO_BASE)
		AFIO_EXTICR(reg) = (AFIO_EXTICR(reg) & ~mask) | bits;
#else
        MINE_SYSCFG_EXTICR(reg) = (MINE_SYSCFG_EXTICR(reg) & ~mask) | bits;
#endif
	};
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// EXTERNAL REFERENCES



