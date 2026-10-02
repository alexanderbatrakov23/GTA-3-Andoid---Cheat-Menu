#pragma once

#include <sys/stat.h>
#include <stdint.h>

extern uintptr_t gta_3_base;

uintptr_t find_library(const char* lib);
void gta_log(const char* fmt ...);