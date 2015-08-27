#include "Profiler.h"
#ifdef PROFILING_ON
#include <cassert>
#include <fstream>
#include "assert.h"
#endif
namespace profiling
{
	Profiler Profiler::theInstance;

	Profiler& Profiler::getInstance()
	{
		return theInstance;
	}
#ifdef PROFILING_ON 
	const char* profileFileName="profiles.csv";
	static std::ofstream outStream;
	void Profiler::addEntry(const char* category, float time)
	{

		ASSERT(categoryIndex < Max_Profile_Categories);

		ProfileCategory& pc = categories[categoryIndex];

		if(frameIndex == 0)
		{
			pc.name =category;
			NUM_USED_CATEGORIES++;
		}
		else
		{	
			if (frameIndex > 0) 
			{
				ASSERT(pc.name == category && category != NULL);
				ASSERT(categoryIndex < NUM_USED_CATEGORIES);
			}
			
		}
		categoryIndex++;
		pc.samples[frameIndex % MAX_FRAME_SAMPLES] = time;
	}
	void Profiler::newFrame()
	{
		if(frameIndex > 0)
		{
			ASSERT(categoryIndex == NUM_USED_CATEGORIES);
		}
		frameIndex++;
		categoryIndex=0;
	}
	void Profiler::shutdown()
	{
		writeData();
	}
	void Profiler::initialize(const char* fileName)
	{
		this ->fileName = fileName;
		frameIndex=-1;
		categoryIndex=0;
		NUM_USED_CATEGORIES=0;
	}
	char Profiler:: getDelimiter(unsigned int index) const
	{
		return ((index+1) < NUM_USED_CATEGORIES) ? ',' : '\n';
	}
	bool Profiler::wrapped() const
	{
		return frameIndex>=MAX_FRAME_SAMPLES && frameIndex != -1;
	}
	void Profiler::writeFrame(unsigned int frameNumber) const
	{
		for(unsigned int cat = 0;cat<NUM_USED_CATEGORIES;cat++)
		{

			outStream<<categories[cat].samples[frameNumber];
			outStream<< getDelimiter(cat);
		}
	}
	void Profiler::writeData() const
	{
		outStream.open(fileName, std::ios::trunc);
		for(unsigned int i =0;i<NUM_USED_CATEGORIES;i++)
		{
			outStream << categories[i].name;

			outStream<< getDelimiter(i);
		}

		unsigned int endIndex;
		unsigned int startIndex;
		if(wrapped())
		{
			endIndex= frameIndex % MAX_FRAME_SAMPLES;
			startIndex= (endIndex +1) % MAX_FRAME_SAMPLES;
			while (startIndex != endIndex)
			{
				writeFrame(startIndex);
				startIndex=(startIndex+1)% MAX_FRAME_SAMPLES;
			}
			if(categoryIndex==NUM_USED_CATEGORIES)
				writeFrame(startIndex);
		}
		else
		{
			unsigned int NUM_ACTUAL_FRAMES  = frameIndex;
			if(categoryIndex==NUM_USED_CATEGORIES)
				NUM_ACTUAL_FRAMES++;
			startIndex=0;
			endIndex = NUM_ACTUAL_FRAMES;
			while (startIndex < endIndex)
			{
				writeFrame(startIndex++);
				startIndex++;
			}
		}
		outStream.close();
	}

#endif
}