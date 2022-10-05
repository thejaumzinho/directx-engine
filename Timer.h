#ifndef _PROGJOGOS_TIMER_H_
#define _PROGJOGOS_TIMER_H_

#ifdef ENGINE_EXPORTS
#define DLL __declspec( dllexport ) 
#else
#define DLL __declspec( dllimport )
#endif

#include <windows.h>                            
#include "Types.h"                              


class DLL Timer
{
private:
    LARGE_INTEGER start, end;                   
    LARGE_INTEGER freq;                         
    bool stoped;                                
    
public:
    Timer();                                    

    void  Start();                             
    void  Stop();                               
    float Reset();                             
    float Elapsed();                             
    bool  Elapsed(float time);                  

    llong Stamp();                              
    float Elapsed(llong stamp);                 
    bool  Elapsed(llong stamp, float time);     
}; 


inline bool Timer::Elapsed(float time)
{ return (Elapsed() >= time ? true : false); }

inline bool Timer::Elapsed(llong stamp, float time)
{ return (Elapsed(stamp) >= time ? true : false); }

#endif