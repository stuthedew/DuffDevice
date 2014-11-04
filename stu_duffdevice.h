#ifndef __STU_DUFFDEVICE_H__
#define __STU_DUFFDEVICE_H__


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

#ifndef ARRAY_SIZE
#define ARRAY_SIZE 10
#endif

#undef SERIAL_DEBUG
#ifdef SERIAL_DEBUG
#define IF_SERIAL_DEBUG(x) ({x;})
#else
#define IF_SERIAL_DEBUG(x)
#endif

inline void duff(int rPtr[], int *wPtr){
   int n = (ARRAY_SIZE + 7);      /* ARRAY_SIZE > 0 assumed */
   n >>= 3;

    switch (ARRAY_SIZE % 8)
    {
        case 0:   do {    *wPtr = *rPtr++;
        case 7:           *wPtr = *rPtr++;
        case 6:           *wPtr = *rPtr++;
        case 5:           *wPtr = *rPtr++;
        case 4:           *wPtr = *rPtr++;
        case 3:           *wPtr = *rPtr++;
        case 2:           *wPtr = *rPtr++;
        case 1:           *wPtr = *rPtr++;
                  } while (--n > 0);
    }

}

inline void duff(const int* readPtr, int* writePtr, uint8_t len){
    
   int n = (len + 7);      /* ARRAY_SIZE > 0 assumed */
   n >>= 3;                /* n>>3 == n/8  bit shift is faster than divide*/ 

    //const int* readPtr = reinterpret_cast<const int*>(readBuf);
    //int* writePtr = reinterpret_cast<int*>(writeP);
    
    switch (len % 8)
    {
        case 0:   do {    *writePtr = *readPtr++;
        case 7:           *writePtr = *readPtr++;
        case 6:           *writePtr = *readPtr++;
        case 5:           *writePtr = *readPtr++;
        case 4:           *writePtr = *readPtr++;
        case 3:           *writePtr = *readPtr++;
        case 2:           *writePtr = *readPtr++;
        case 1:           *writePtr = *readPtr++;
                  } while (--n > 0);
    }

}



#endif
