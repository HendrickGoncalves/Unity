
#include "payment.h"

uint8_t validValue(float value) {
    return (value >= 0.01 && value <= 9999) ? 1 : 0;
}

uint8_t validStatus(char *status) {
    if(!strncmp(status, "regular", strlen("regular")) || !strncmp(status, "estudante", strlen("estudante")) || !strncmp(status, "aposentado", strlen("aposentado")) ||
        !strncmp(status, "VIP", strlen("VIP")))
        return 1;

    return 0;
}

int payment(float value, char status[15]) {
    if(validValue(value) && validStatus(status))    
        return 0;
    else if(!validValue(value))
        return 1;
    else if(!validStatus(status))
        return 2;
    
    return 3; 
}