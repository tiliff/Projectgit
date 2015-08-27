#pragma once
#if LOG_ON
#include "logger.h"

#define ASSERT(expression,...) do{ if(!(expression)) {LOG(Severe, #expression##" "##__VA_ARGS__); Logger::shutDown(); exit(1);} } while(0,0)

#endif