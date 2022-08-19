#include <avr/io.h>
#include "hc-sr04.h"
#include "atmega328p-lib/include/uart.h"
#include "atmega328p-lib/include/utils.h"

int main()
{
    char buffer[50];
    initHcSr04(2, 3, B9600);
    while (1)
    {
        itoa(distanceCm(), buffer);
        USART_SendStr(buffer);
        USART_Transmit('\n');
        delayMicro(50000);

    }

}