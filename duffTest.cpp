#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "stu_duffdevice.h"
#undef ARRAY_SIZE
#define ARRAY_SIZE 100

using namespace std;


int writeAry;

int readAry[ARRAY_SIZE];



void loopUnroll(int rPtr[], int *wPtr){

    // Handle copy as much as we can with unrolling
    int loopCycles = (ARRAY_SIZE + 4) / 5;

    for (int i = 0; i < loopCycles; ++i)
    {
        *wPtr = *rPtr++;
        *wPtr = *rPtr++;
        *wPtr = *rPtr++;
        *wPtr = *rPtr++;
        *wPtr = *rPtr++;
    }


    // Take care of the remainder memory to copy
    for (int j=0; j < ARRAY_SIZE % 5; ++j)
    {
        *wPtr = *rPtr++;

    }
}



clock_t t = 0;
clock_t runTime;
unsigned int nTime = 0;
unsigned int dTime = 0;

int main(int argc, char *argv[]) {
    cout << endl << "Stuart's Duff device implementation test" << endl;

    for(int i = 0; i < ARRAY_SIZE; i++){
       readAry[i] = random() % 1000;

    }

     int *rPtr = readAry;
     int *wPtr = &writeAry;
    runTime = clock();
    for(unsigned int j = 0; j < 500000; j++){

        rPtr = readAry;
        wPtr = &writeAry;
    loopUnroll(rPtr, wPtr);
    
    
     //assert(readAry[ARRAY_SIZE - 1] == writeAry);
    }
nTime = clock() - runTime;   

/*
    for(int i = 0; i < ARRAY_SIZE; i++){
        assert(readAry[i] == writeAry[i]);
    }*/

    cout << endl << "Naive: " << nTime << " clock ticks" << endl;


           
runTime = clock();
        for(unsigned int j = 0; j < 500000; j++){

            rPtr = readAry;
            wPtr = &writeAry;
            
            duff(rPtr, wPtr, ARRAY_SIZE);
            //duff(rPtr, wPtr);
            

//            assert(readAry[ARRAY_SIZE - 1] == writeAry);
        }
dTime = clock() - runTime;
assert(readAry[ARRAY_SIZE - 1] == writeAry);
        /*
        for(int i = 0; i < ARRAY_SIZE; i++){
                    assert(readAry[i] == writeAry[i]);
                }
                */

        cout << "Duff: " << dTime << " clock ticks" << endl;
        double improve = (nTime - dTime);

        improve /= nTime;
        int iPercent = improve *100;
        cout << "Improvment of " << iPercent << "%!" << endl <<endl;


}
