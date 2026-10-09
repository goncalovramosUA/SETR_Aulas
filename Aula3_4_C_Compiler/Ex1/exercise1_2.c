#include <stdio.h>
#include <stdint.h>
#include "configData.h"

int main()
{
    extern uint16_t maxConnections;
    maxConnections_init();

    printf("The initial value of maxConnections is %u.\n", maxConnections);
    maxConnections = 10;
    printf("The new value of maxConnections is %u.\n", maxConnections);

    return 0;
}