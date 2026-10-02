#include "../main.h"
#include "util.h"

uintptr_t gta_3_base = 0;

uintptr_t find_library(const char* lib)
{
    char line[512];
    FILE* fp = fopen("/proc/self/maps", "r");
    if (!fp) return 0;
    
    while(fgets(line, sizeof(line), fp)) 
    {
        if(strstr(line, lib)) 
        {
            uintptr_t addr = strtoul(line, nullptr, 16);
            fclose(fp);
            return addr;
        }
    }

    fclose(fp);
    return 0;
}

void gta_log(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    char gBuf[1024];
    vsnprintf(gBuf, sizeof(gBuf), fmt, args);

    __android_log_print(ANDROID_LOG_INFO, "GTA3", "[CHEATMENU] %s", gBuf);

    va_end(args);
}