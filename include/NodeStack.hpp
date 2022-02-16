/*
 * @file             NodeStack.hpp
 * @description      Stack'in dugumunun baslik dosyasi
 * @course           1.Ogretim A grubu
 * @assignment       2.Odev
 * @date             25.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/

#ifndef NODESTACK_HPP
#define NODESTACK_HPP

#include <iostream>

using namespace std;

class NodeStack
{
    public:

        //stack listesinin her bir dugumunun icindeki degeri tutan degisken
        int item;

        //sonraki dugumu tutan degisken
        NodeStack * next;
        
        //kurucu fonksiyon
        NodeStack(int item=0,NodeStack* next=NULL);
};


#endif