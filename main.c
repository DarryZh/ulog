#include <unistd.h>
#include "ulog.h"

static const char *TAG = "main";

int main(int argc, char *argv[])
{
    ULOGD(TAG, "%d\r\n", __LINE__);
    sleep(1);
    ULOGI(TAG, "%d\r\n", __LINE__);
    ULOGV(TAG, "%d\r\n", __LINE__);
    ULOGW(TAG, "%d\r\n", __LINE__);
    ULOGE(TAG, "%d\r\n", __LINE__);
    return 0;
}
