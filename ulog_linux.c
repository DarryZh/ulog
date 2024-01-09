#include <pthread.h>
#include <time.h>
#include <assert.h>
#include <stdint.h>
#include "ulog_private.h"

static pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void ulog_impl_lock(void)
{
    assert(pthread_mutex_lock(&mutex1) == 0);
}

bool ulog_impl_lock_timeout(void)
{
    ulog_impl_lock();
    return true;
}

void ulog_impl_unlock(void)
{
    assert(pthread_mutex_unlock(&mutex1) == 0);
}

uint32_t ulog_timestamp(void)
{
    struct timespec current_time;
    int result = clock_gettime(CLOCK_MONOTONIC, &current_time);
    assert(result == 0);
    uint32_t milliseconds = current_time.tv_sec * 1000 + current_time.tv_nsec / 1000000;
    return milliseconds;
}

char *ulog_system_timestamp(void)
{
    time_t timep;
    struct tm* timeinfo;
    static char buf[30];
    time(&timep); /*获取time_t类型的当前时间*/
    timeinfo = localtime(&timep);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", timeinfo);
    return buf;
}
