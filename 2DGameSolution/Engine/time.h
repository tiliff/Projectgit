#pragma once 
#include <windows.h>
 
 typedef struct {
     LARGE_INTEGER start;
     LARGE_INTEGER stop;
 } stopWatch;
 
 class __declspec(dllexport) CStopWatch {

     stopWatch timer;
     LARGE_INTEGER frequency;
     float LIToSecs( LARGE_INTEGER & L) ;
 public:
     CStopWatch() ;
     void startTimer( ) ;
     void stopTimer( ) ;
     float getElapsedTime() ;
 };