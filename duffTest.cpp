#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "stu_duffdevice.h"
#define ARRAY_SIZE 10
using namespace std;


int writeAry[ARRAY_SIZE];

int readAry[ARRAY_SIZE];



void loopUnroll(int rPtr[], int wPtr[]){

    // Handle copy as much as we can with unrolling
    int loopCycles = (ARRAY_SIZE + 4) / 5;

    for (int i = 0; i < loopCycles; ++i)
    {
        *wPtr++ = *rPtr++;
        *wPtr++ = *rPtr++;
        *wPtr++ = *rPtr++;
        *wPtr++ = *rPtr++;
        *wPtr++ = *rPtr++;
    }


    // Take care of the remainder memory to copy
    for (int j=0; j < ARRAY_SIZE % 5; ++j)
    {
        *wPtr++ = *rPtr++;

    }
}



clock_t t = 0;
clock_t runTime;

int main(int argc, char *argv[]) {
    cout << endl << "Stuart's Duff device implementation test" << endl;

    for(int i = 0; i < ARRAY_SIZE; i++){
       readAry[i] = random() % 1000;

    }
     int *rPtr = readAry;
     int *wPtr = writeAry;
    runTime = clock();
    for(unsigned int i = 0; i < 500000; i++){

        rPtr = readAry;
        wPtr = writeAry;
        runTime = clock();
    loopUnroll(rPtr, wPtr);
    t += clock() - runTime;
    }
   

    for(int i = 0; i < ARRAY_SIZE; i++){
        assert(readAry[i] == writeAry[i]);
    }
    unsigned int nTime = t;
    cout << endl << "Naive: " << nTime << " clock ticks" << endl;

    t = 0;
           runTime = clock();

        for(unsigned int i = 0; i < 500000; i++){

            rPtr = readAry;
            wPtr = writeAry;
            duff(rPtr, wPtr);

        }

        t += clock() - runTime;
        for(int i = 0; i < ARRAY_SIZE; i++){
                    assert(readAry[i] == writeAry[i]);
                }
        unsigned int dTime = t;
        cout << "Duff: " << dTime << " clock ticks" << endl;
        double improve = (nTime - dTime);

        improve /= nTime;
        int iPercent = improve *100;
        cout << "Improvment of " << iPercent << "%!" << endl <<endl;


}
