/*
 * @file             NodeAVL.hpp
 * @description      AVL agacinin dugumunun baslik dosyasi
 * @course           1.Ogretim A grubu
 * @assignment       2.Odev
 * @date             25.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/

#ifndef NODE_AVL_HPP
#define NODE_AVL_HPP

#include "Person.hpp"
#include "Stack.hpp"
using namespace std;

class NodeAVL
{
    public:

        //dugumun icinde bulunan kisi bilgilerini tutan degisken
        Person* person_info;

        //dugumun yukseklik degerlerini tutan degisken
        Stack * heightStack;
        
        //dugumum derinlik degerlerini tutan degisken
        Stack * depth;

        //dugumun sol cocugunu tutan degisken
        NodeAVL * left;

        //dugumun sag cocugunu tutan degisken
        NodeAVL * right;

        //dugumun gecici olarak yuksekligini tutan degisken
        int height;

        //kurucu fonksiyon
        NodeAVL(Person* person_info=new Person(), Stack* height=new Stack(), Stack* depth=new Stack(), NodeAVL* left=NULL, NodeAVL* right=NULL);
        
        //yikici fonksiyon
        ~NodeAVL();
};

#endif