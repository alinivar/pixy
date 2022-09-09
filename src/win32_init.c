
#include <pixy.h>

#include "wgl_context.h"

PIXYAPI int pixyInit() {
    if (!_pixyInitWGL())
        return PIXY_FALSE;

    return PIXY_TRUE;
}

PIXYAPI void pixyTerminate() {
    _pixyTerminateWGL();
}
