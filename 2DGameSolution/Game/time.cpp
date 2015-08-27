 #include "time.h"
 
 float CStopWatch::LIToSecs( LARGE_INTEGER & L) {
     return ((float)L.QuadPart /(float)frequency.QuadPart) ;
 }
 
 CStopWatch::CStopWatch(){
     timer.start.QuadPart=0;
     timer.stop.QuadPart=0; 
     QueryPerformanceFrequency( &frequency ) ;
 }
 
 void CStopWatch::startTimer( ) {
     QueryPerformanceCounter(&timer.start) ;
 }
 
 void CStopWatch::stopTimer( ) {
     QueryPerformanceCounter(&timer.stop) ;
 }
 
 float CStopWatch::getElapsedTime() {
	 stopTimer();
     LARGE_INTEGER time;
     time.QuadPart = timer.stop.QuadPart - timer.start.QuadPart;
     return LIToSecs( time);
 }