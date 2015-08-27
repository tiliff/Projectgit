#pragma once
#include <fstream>

using std::ifstream;
using std::string;
namespace profiling
{
class __declspec(dllexport)Profiler
{
public:
	static const unsigned int MAX_FRAME_SAMPLES=1000;
	static Profiler& getInstance();
private:
	Profiler() {}
	Profiler(const Profiler&);
	Profiler& operator=(const Profiler&);
	static Profiler theInstance;
#if PROFILING_ON
	const char* fileName;
	int frameIndex;
	unsigned int categoryIndex;
	unsigned int NUM_USED_CATEGORIES;
	static const unsigned int Max_Profile_Categories=20;
	struct ProfileCategory
	{
		const char* name;
		float samples[MAX_FRAME_SAMPLES];
	}categories[Max_Profile_Categories];
	void writeFrame(unsigned int frameNumber) const;
	void writeData() const;
	char getDelimiter(unsigned int index) const;
	bool wrapped() const;
#endif
public:
#if PROFILING_ON
	void addEntry(const char* category, float time);
	void newFrame();
	void shutdown();
	void initialize(const char* fileName);
#else
	void addEntry(const char* category, float time) {}
	void newFrame() {}
	void shutdown() {}
	void initialize(const char* fileName) {}
	void checkisgood(bool* status) const {}
#endif
};
#define profiler profiling::Profiler::getInstance()

}