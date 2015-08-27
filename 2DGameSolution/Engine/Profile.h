#pragma once

#if PROFILING_ON
#include "time.h"
#endif
namespace profiling
{
class __declspec(dllexport) Profile
{
#if PROFILING_ON
	const char* category;
	CStopWatch timer;
#endif
public:
#if PROFILING_ON
	Profile(const char* category);
	~Profile();
#else
	Profile(const char* category) {}
	~Profile() {}
#endif
};
}
#if PROFILING_ON
#define PROFILE(category) profiling::Profile p(category)
#else
#define PROFILE(category)
#endif