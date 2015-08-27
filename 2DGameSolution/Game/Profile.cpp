#if PROFILING_ON
#include "Profile.h"
#include "Profiler.h"
namespace profiling
{
Profile::Profile(const char* category) : category(category)
{
	timer.startTimer();
}
Profile::~Profile()
{
	timer.stopTimer();
	Profiler::getInstance().addEntry(category,timer.getElapsedTime());
}
}
#endif