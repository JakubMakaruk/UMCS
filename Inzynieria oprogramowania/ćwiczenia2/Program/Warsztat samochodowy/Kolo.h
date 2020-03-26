/**
 * Project Untitled
 */


#ifndef _KOLO_H
#define _KOLO_H

class Kolo {
public: 

    Kolo(int s, int w, int r, bool spr);
    
    bool getSprawnosc();
private: 
    int szerokoscOpony;
    int wysokoscProfiluOpony;
    int rozmiarFelgi;
    bool sprawnosc;
};

#endif //_KOLO_H
