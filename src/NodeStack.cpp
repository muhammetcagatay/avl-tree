/*
 * @file             NodeStack.cpp
 * @description      Stack'in dugumunun kaynak dosyasi
 * @course           1.Ogretim A grubu
 * @assignment       2.Odev
 * @date             25.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/

#include "NodeStack.hpp"
#include <iostream>

using namespace std;

//kurucu fonksiyon
NodeStack::NodeStack(int item,NodeStack * next)
{
    this->item=item;
    this->next=next;
}