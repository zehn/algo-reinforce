#include "utils.h"

#ifdef _cpulsplus
extern "C" {
#endif
#include <sys/time.h>

double current_clock_in_million_seconds()
{
    double clock = 0.0;
    struct timeval tv;

    if (0 != gettimeofday(&tv, NULL))
        return clock;

    clock = tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0;
    return clock;
}

#ifdef _cpulsplus
}
#endif

