
#include "ocpwm.h"
#include "defines.h"
#include "p24HJ256GP610A.h"

unsigned int DUTY_MIN = T20ms / 20 * MINPWM; // valor minimo de DUTY
unsigned int DUTY_MAX = T20ms / 20 * MAXPWM; // valor maximo de DUTY

unsigned int duty1, duty2, duty3, duty4, duty5;

void inicDuty()
{
    duty1 = DUTY_MAX / 2;
    duty2 = DUTY_MAX / 2;
    duty3 = DUTY_MAX / 2;
    duty4 = DUTY_MAX / 2;
    duty5 = DUTY_MAX / 2;
}