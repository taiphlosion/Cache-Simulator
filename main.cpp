#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <sstream>
#include <map>
#include <cmath>
#include <iomanip>

//TAI TRAN

#include "directMap.h"
#include "fullAss.h"
#include "setAss.h"

using namespace std;

int main(){

    string hexAddress, temp;
    vector<int> values = {1024, 2048, 4096, 8192, 16384};
    vector<string>addressStore;
    bool FIFO = true;
    bool LRU = false;

    fstream trace;
    trace.open("traceFiles/gcc.trace");
    // //Capture data
    while (trace >> temp) {
        trace >> hexAddress;
        hexAddress = hexAddress;
        trace >> temp;
        addressStore.push_back(hexAddress);
    }
//**************BEGIN*****************
//***CACHE SIZE: 1024***
    DirectMapped d_cache_1024(1024, 64);

    FullyAssociative f_cache_1024_FIFO(1024, 64, FIFO);
    SetAssociative s2_cache_1024_FIFO(1024, 64, 2, FIFO);
    SetAssociative s4_cache_1024_FIFO(1024, 64, 4, FIFO);
    SetAssociative s8_cache_1024_FIFO(1024, 64, 8, FIFO);

    FullyAssociative f_cache_1024_LRU(1024, 64, LRU);
    SetAssociative s2_cache_1024_LRU(1024, 64, 2, LRU);
    SetAssociative s4_cache_1024_LRU(1024, 64, 4, LRU);
    SetAssociative s8_cache_1024_LRU(1024, 64, 8, LRU);
    

    for (int j = 0; j < addressStore.size(); j++){
        d_cache_1024.accessCache(addressStore.at(j));

        f_cache_1024_FIFO.accessCache(addressStore.at(j));
        s2_cache_1024_FIFO.accessCache(addressStore.at(j), FIFO);
        s4_cache_1024_FIFO.accessCache(addressStore.at(j), FIFO);
        s8_cache_1024_FIFO.accessCache(addressStore.at(j), FIFO);

        f_cache_1024_LRU.accessCache(addressStore.at(j));
        s2_cache_1024_LRU.accessCache(addressStore.at(j), LRU);
        s4_cache_1024_LRU.accessCache(addressStore.at(j), LRU);
        s8_cache_1024_LRU.accessCache(addressStore.at(j), LRU);
    }
    cout << "________________________________________________________________" << endl;
    cout << "______________________________1024______________________________" << endl;
    cout << "Direct map cache: " << d_cache_1024.getHitRate() << endl;
    cout << "FIFO:" << endl;  
    cout << "Fully associative cache: " << f_cache_1024_FIFO.getHitRate() << endl;
    cout << "2 Set associative cache: " << s2_cache_1024_FIFO.getHitRate() << endl;
    cout << "4 Set associative cache: " << s4_cache_1024_FIFO.getHitRate() << endl;
    cout << "8 Set associative cache: " << s8_cache_1024_FIFO.getHitRate() << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "LRU:" << endl;        
    cout << "Fully associative cache: " << f_cache_1024_LRU.getHitRate() << endl;
    cout << "2 Set associative cache: " << s2_cache_1024_LRU.getHitRate() << endl;
    cout << "4 Set associative cache: " << s4_cache_1024_LRU.getHitRate() << endl;
    cout << "8 Set associative cache: " << s8_cache_1024_LRU.getHitRate() << endl;
    cout << "________________________________________________________________" << endl;

//***CACHE SIZE: 1024, FIFO POLICY END***
//***************END******************


//**************BEGIN*****************
//***CACHE SIZE: 2048, FIFO POLICY BEGIN***
    DirectMapped d_cache_2048(2048, 64);

    FullyAssociative f_cache_2048_FIFO(2048, 64, FIFO);
    SetAssociative s2_cache_2048_FIFO(2048, 64, 2, FIFO);
    SetAssociative s4_cache_2048_FIFO(2048, 64, 4, FIFO);
    SetAssociative s8_cache_2048_FIFO(2048, 64, 8, FIFO);

    FullyAssociative f_cache_2048_LRU(2048, 64, LRU);
    SetAssociative s2_cache_2048_LRU(2048, 64, 2, LRU);
    SetAssociative s4_cache_2048_LRU(2048, 64, 4, LRU);
    SetAssociative s8_cache_2048_LRU(2048, 64, 8, LRU);

    


    for (int j = 0; j < addressStore.size(); j++){
        d_cache_2048.accessCache(addressStore.at(j));

        f_cache_2048_FIFO.accessCache(addressStore.at(j));
        s2_cache_2048_FIFO.accessCache(addressStore.at(j), FIFO);
        s4_cache_2048_FIFO.accessCache(addressStore.at(j), FIFO);
        s8_cache_2048_FIFO.accessCache(addressStore.at(j), FIFO);

        f_cache_2048_LRU.accessCache(addressStore.at(j));
        s2_cache_2048_LRU.accessCache(addressStore.at(j), LRU);
        s4_cache_2048_LRU.accessCache(addressStore.at(j), LRU);
        s8_cache_2048_LRU.accessCache(addressStore.at(j), LRU);
    }

    cout << "______________________________2048______________________________" << endl;
    cout << "Direct map cache: " << d_cache_2048.getHitRate() << endl;
    cout << "FIFO:" << endl;  
    cout << "Fully associative cache: " << f_cache_2048_FIFO.getHitRate() << endl;
    cout << "2 Set associative cache: " << s2_cache_2048_FIFO.getHitRate() << endl;
    cout << "4 Set associative cache: " << s4_cache_2048_FIFO.getHitRate() << endl;
    cout << "8 Set associative cache: " << s8_cache_2048_FIFO.getHitRate() << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "LRU:" << endl;        
    cout << "Fully associative cache: " << f_cache_2048_LRU.getHitRate() << endl;
    cout << "2 Set associative cache: " << s2_cache_2048_LRU.getHitRate() << endl;
    cout << "4 Set associative cache: " << s4_cache_2048_LRU.getHitRate() << endl;
    cout << "8 Set associative cache: " << s8_cache_2048_LRU.getHitRate() << endl;
    cout << "________________________________________________________________" << endl;
//***CACHE SIZE: 2048, FIFO POLICY END***
//***************END******************

//**************BEGIN*****************
//***CACHE SIZE: 4096, FIFO POLICY BEGIN***
    DirectMapped d_cache_4096(4096, 64);

    FullyAssociative f_cache_4096_FIFO(4096, 64, FIFO);
    SetAssociative s2_cache_4096_FIFO(4096, 64, 2, FIFO);
    SetAssociative s4_cache_4096_FIFO(4096, 64, 4, FIFO);
    SetAssociative s8_cache_4096_FIFO(4096, 64, 8, FIFO);

    FullyAssociative f_cache_4096_LRU(4096, 64, LRU);
    SetAssociative s2_cache_4096_LRU(4096, 64, 2, LRU);
    SetAssociative s4_cache_4096_LRU(4096, 64, 4, LRU);
    SetAssociative s8_cache_4096_LRU(4096, 64, 8, LRU);

    


    for (int j = 0; j < addressStore.size(); j++){
        d_cache_4096.accessCache(addressStore.at(j));

        f_cache_4096_FIFO.accessCache(addressStore.at(j));
        s2_cache_4096_FIFO.accessCache(addressStore.at(j), FIFO);
        s4_cache_4096_FIFO.accessCache(addressStore.at(j), FIFO);
        s8_cache_4096_FIFO.accessCache(addressStore.at(j), FIFO);

        f_cache_4096_LRU.accessCache(addressStore.at(j));
        s2_cache_4096_LRU.accessCache(addressStore.at(j), LRU);
        s4_cache_4096_LRU.accessCache(addressStore.at(j), LRU);
        s8_cache_4096_LRU.accessCache(addressStore.at(j), LRU);
    }

    cout << "______________________________4096______________________________" << endl;
    cout << "Direct map cache: " << d_cache_4096.getHitRate() << endl;
    cout << "FIFO:" << endl;  
    cout << "Fully associative cache: " << f_cache_4096_FIFO.getHitRate() << endl;
    cout << "2 Set associative cache: " << s2_cache_4096_FIFO.getHitRate() << endl;
    cout << "4 Set associative cache: " << s4_cache_4096_FIFO.getHitRate() << endl;
    cout << "8 Set associative cache: " << s8_cache_4096_FIFO.getHitRate() << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "LRU:" << endl;        
    cout << "Fully associative cache: " << f_cache_4096_LRU.getHitRate() << endl;
    cout << "2 Set associative cache: " << s2_cache_4096_LRU.getHitRate() << endl;
    cout << "4 Set associative cache: " << s4_cache_4096_LRU.getHitRate() << endl;
    cout << "8 Set associative cache: " << s8_cache_4096_LRU.getHitRate() << endl;
    cout << "________________________________________________________________" << endl;
//***CACHE SIZE: 4096, FIFO POLICY END***
//***************END******************

//**************BEGIN*****************
//***CACHE SIZE: 8192, FIFO POLICY BEGIN***
    DirectMapped d_cache_8192(8192, 64);

    FullyAssociative f_cache_8192_FIFO(8192, 64, FIFO);
    SetAssociative s2_cache_8192_FIFO(8192, 64, 2, FIFO);
    SetAssociative s4_cache_8192_FIFO(8192, 64, 4, FIFO);
    SetAssociative s8_cache_8192_FIFO(8192, 64, 8, FIFO);

    FullyAssociative f_cache_8192_LRU(8192, 64, LRU);
    SetAssociative s2_cache_8192_LRU(8192, 64, 2, LRU);
    SetAssociative s4_cache_8192_LRU(8192, 64, 4, LRU);
    SetAssociative s8_cache_8192_LRU(8192, 64, 8, LRU);

    


    for (int j = 0; j < addressStore.size(); j++){
        d_cache_8192.accessCache(addressStore.at(j));

        f_cache_8192_FIFO.accessCache(addressStore.at(j));
        s2_cache_8192_FIFO.accessCache(addressStore.at(j), FIFO);
        s4_cache_8192_FIFO.accessCache(addressStore.at(j), FIFO);
        s8_cache_8192_FIFO.accessCache(addressStore.at(j), FIFO);

        f_cache_8192_LRU.accessCache(addressStore.at(j));
        s2_cache_8192_LRU.accessCache(addressStore.at(j), LRU);
        s4_cache_8192_LRU.accessCache(addressStore.at(j), LRU);
        s8_cache_8192_LRU.accessCache(addressStore.at(j), LRU);
    }

    cout << "______________________________8192______________________________" << endl;
    cout << "Direct map cache: " << d_cache_8192.getHitRate() << endl;
    cout << "FIFO:" << endl;  
    cout << "Fully associative cache: " << f_cache_8192_FIFO.getHitRate() << endl;
    cout << "2 Set associative cache: " << s2_cache_8192_FIFO.getHitRate() << endl;
    cout << "4 Set associative cache: " << s4_cache_8192_FIFO.getHitRate() << endl;
    cout << "8 Set associative cache: " << s8_cache_8192_FIFO.getHitRate() << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "LRU:" << endl;        
    cout << "Fully associative cache: " << f_cache_8192_LRU.getHitRate() << endl;
    cout << "2 Set associative cache: " << s2_cache_8192_LRU.getHitRate() << endl;
    cout << "4 Set associative cache: " << s4_cache_8192_LRU.getHitRate() << endl;
    cout << "8 Set associative cache: " << s8_cache_8192_LRU.getHitRate() << endl;
    cout << "________________________________________________________________" << endl;
//***CACHE SIZE: 8192, FIFO POLICY END***
//***************END******************

//**************BEGIN*****************
//***CACHE SIZE: 16384, FIFO POLICY BEGIN***
    DirectMapped d_cache_16384(16384, 64);

    FullyAssociative f_cache_16384_FIFO(16384, 64, FIFO);
    SetAssociative s2_cache_16384_FIFO(16384, 64, 2, FIFO);
    SetAssociative s4_cache_16384_FIFO(16384, 64, 4, FIFO);
    SetAssociative s8_cache_16384_FIFO(16384, 64, 8, FIFO);

    FullyAssociative f_cache_16384_LRU(16384, 64, LRU);
    SetAssociative s2_cache_16384_LRU(16384, 64, 2, LRU);
    SetAssociative s4_cache_16384_LRU(16384, 64, 4, LRU);
    SetAssociative s8_cache_16384_LRU(16384, 64, 8, LRU);

    


    for (int j = 0; j < addressStore.size(); j++){
        d_cache_16384.accessCache(addressStore.at(j));

        f_cache_16384_FIFO.accessCache(addressStore.at(j));
        s2_cache_16384_FIFO.accessCache(addressStore.at(j), FIFO);
        s4_cache_16384_FIFO.accessCache(addressStore.at(j), FIFO);
        s8_cache_16384_FIFO.accessCache(addressStore.at(j), FIFO);

        f_cache_16384_LRU.accessCache(addressStore.at(j));
        s2_cache_16384_LRU.accessCache(addressStore.at(j), LRU);
        s4_cache_16384_LRU.accessCache(addressStore.at(j), LRU);
        s8_cache_16384_LRU.accessCache(addressStore.at(j), LRU);
    }

    cout << "______________________________16384______________________________" << endl;
    cout << "Direct map cache: " << d_cache_16384.getHitRate() << endl;
    cout << "FIFO:" << endl;  
    cout << "Fully associative cache: " << f_cache_16384_FIFO.getHitRate() << endl;
    cout << "2 Set associative cache: " << s2_cache_16384_FIFO.getHitRate() << endl;
    cout << "4 Set associative cache: " << s4_cache_16384_FIFO.getHitRate() << endl;
    cout << "8 Set associative cache: " << s8_cache_16384_FIFO.getHitRate() << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "LRU:" << endl;        
    cout << "Fully associative cache: " << f_cache_16384_LRU.getHitRate() << endl;
    cout << "2 Set associative cache: " << s2_cache_16384_LRU.getHitRate() << endl;
    cout << "4 Set associative cache: " << s4_cache_16384_LRU.getHitRate() << endl;
    cout << "8 Set associative cache: " << s8_cache_16384_LRU.getHitRate() << endl;
    cout << "________________________________________________________________" << endl;
//***CACHE SIZE: 16384, FIFO POLICY END***
//***************END******************




    
}
