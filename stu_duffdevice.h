#ifndef __STU_DUFFDEVICE_H__
#define __STU_DUFFDEVICE_H__

#define ARRAY_SIZE 10
#include <stddef.h>

// Stuff that is normally provided by Arduino

#ifdef ARDUINO
#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

#else
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#endif


#undef SERIAL_DEBUG
#ifdef SERIAL_DEBUG
#define IF_SERIAL_DEBUG(x) ({x;})
#else
#define IF_SERIAL_DEBUG(x)
#endif

inline void duff(int rPtr[], int wPtr[]){
   int n = (ARRAY_SIZE + 7) / 8;      /* ARRAY_SIZE > 0 assumed */

    switch (ARRAY_SIZE % 8)
    {
        case 0:   do {    *wPtr++ = *rPtr++;
        case 7:           *wPtr++ = *rPtr++;
        case 6:           *wPtr++ = *rPtr++;
        case 5:           *wPtr++ = *rPtr++;
        case 4:           *wPtr++ = *rPtr++;
        case 3:           *wPtr++ = *rPtr++;
        case 2:           *wPtr++ = *rPtr++;
        case 1:           *wPtr++ = *rPtr++;
                  } while (--n > 0);
    }

}

inline void duff(int rPtr[], int wPtr[]){
   int n = (ARRAY_SIZE + 7) / 8;      /* ARRAY_SIZE > 0 assumed */

    switch (ARRAY_SIZE % 8)
    {
        case 0:   do {    *wPtr++ = *rPtr++;
        case 7:           *wPtr++ = *rPtr++;
        case 6:           *wPtr++ = *rPtr++;
        case 5:           *wPtr++ = *rPtr++;
        case 4:           *wPtr++ = *rPtr++;
        case 3:           *wPtr++ = *rPtr++;
        case 2:           *wPtr++ = *rPtr++;
        case 1:           *wPtr++ = *rPtr++;
                  } while (--n > 0);
    }

}



#endif
