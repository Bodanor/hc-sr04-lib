#include "hc-sr04.h"

#define BAUDRATE(x) F_CPU/16/x-1

static int trig_pin;
static int echo_pin;
static int baud_speed;

void initHcSr04(int trig, int echo, int uart_baud)
{
    setState(trig, OUTPUT);
    setState(echo, INPUT);
    USART_Init(BAUDRATE(uart_baud));
    trig_pin = trig;
    echo_pin = echo;
    baud_speed = uart_baud;
}

unsigned long distanceCm(void)
{
    unsigned long duration;
    unsigned long distance;
    setState(trig_pin, LOW);
    delayMicro(2);
    setState(trig_pin, HIGH);
    delayMicro(10);
    setState(trig_pin, LOW);
    duration = pulsePin(echo_pin, HIGH);

    distance = (duration*.0343)/2;
    return distance;
}