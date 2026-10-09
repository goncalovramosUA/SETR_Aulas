#include <stdio.h>
#include <stdint.h>
#include "ConfigData_v2.h"

int main(void)
{
    uint16_t var = 2;
    configInit();
    printf("The initial value of var is %d. \n", var);
    
    var = configGetMaxConnections();
    printf("But the initial value of maxConnections was %u. \n", var);
    
    configSetMaxConnections(15);
    printf("I have change the maxConnections to 15, but var is still %u.\n", var);
    
    var = configGetMaxConnections();
    printf("Now var has the value: %u.\n", var);

    return 0;
}
