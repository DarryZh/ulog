#include <assert.h>
#include "ulog_private.h"

static int s_lock = 0;

void ulog_impl_lock(void)
{
    s_lock = 1;
}

bool ulog_impl_lock_timeout(void)
{
    ulog_impl_lock();
    return true;
}

void ulog_impl_unlock(void)
{
    s_lock = 0;
}

/* FIXME: define an API for getting the timestamp in soc/hal IDF-2351 */
uint32_t ulog_early_timestamp(void)
{
    return 0;
}

uint32_t ulog_timestamp(void) __attribute__((alias("ulog_early_timestamp")));
