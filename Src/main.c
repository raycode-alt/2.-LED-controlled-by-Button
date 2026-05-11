
/*When button is pressed: LED ON
 When released → LED OFF*/

#include "stm32f401xe.h"


#define GPIOAEN      (1U<<0)
#define GPIOCEN      (1U<<2)
#define LED          (1U<<5)
#define BUTTON      (1U<<13)

int main (void)
{
    //Enable the clock//
	RCC->AHB1ENR  |= 	GPIOAEN;
	RCC->AHB1ENR  |=    GPIOCEN;

	//Configure the function of pin//
	GPIOA->MODER  |= (1U<<10);
	GPIOA->MODER  &=~ (1U<<11);

	GPIOC->MODER  &=~ (1U<<24);
	GPIOC->MODER  &=~ (1U<<25);


	while (1){

		if (!(GPIOC->IDR & BUTTON))
		{
			// Turn LED ON when button is pressed
			GPIOA ->ODR |= LED;

		}
		else
		{
			// Turn LED OFF when button is released
			GPIOA->ODR &=~ LED;
		}

	}


}




