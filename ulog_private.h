#pragma once
#include <stdbool.h>

void ulog_impl_lock(void);
bool ulog_impl_lock_timeout(void);
void ulog_impl_unlock(void);
