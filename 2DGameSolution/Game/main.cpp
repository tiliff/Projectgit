#include"Setup.h"



int main()
{
	LOG(Error,"Example Error log message");
	LOG(Warning,"Example warning log message");
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF );
	//ASSERT(false,"Fail");
	profiler.initialize("Profiles.csv");
	//Engine::sampleFunctionThatReturnsTrue();
	Core::Init("Game Demo",1910,1040);
	Core::RegisterUpdateFn(MeUpdateFn);
	Core::RegisterDrawFn(MeDrawFn);
	Core::GameLoop();
	profiler.shutdown();
	END_LOG
}

