/*
 * @file             NodeAVL.cpp
 * @description      AVL agacinin dugumunun kaynak dosyasi
 * @course           1.Ogretim A grubu
 * @assignment       2.Odev
 * @date             25.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/

#include "NodeAVL.hpp"

using namespace std;

//kurucu fonksiyon
NodeAVL::NodeAVL(Person* person_info, Stack* heightStack, Stack* depth, NodeAVL* left, NodeAVL* right)
{
    this->person_info=person_info;
    this->heightStack=heightStack;
    this->depth=depth;
    this->left=left;
    this->right=right;
    height=0;
}

//yikici fonksiyon
NodeAVL::~NodeAVL()
{
    delete person_info;
    delete heightStack;
    delete depth;
}