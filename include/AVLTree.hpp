/*
 * @file             AVLTree
 * @description      AVL agacinin baslik dosyasi
 * @course           1.Ogretim A grubu
 * @assignment       2.Odev
 * @date             25.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <iostream>
#include "NodeAVL.hpp"
#include "Person.hpp"
#include <algorithm>
#include <cmath>
using namespace std;

class AVLTree
{
    private:
        //kok dugumu tutan degisken
        NodeAVL * root;

        //yeni dugumun eklenecegi konumu bulur ve o konuma dugumu ekler.
        NodeAVL* SearchAndAdd(NodeAVL *, Person *);

        //dugumu sol cocuk ile degistirip agaci dengeler
        NodeAVL* SwapWithLeftChild(NodeAVL *);

        //dugumu sag cocuk ile degistirip agaci dengeler
        NodeAVL* SwapWithRightChild(NodeAVL *);

        //agaci inorder seklinde ekrana yazdirir
        void Inorder(NodeAVL *) const;

        //agaci preorder seklinde ekrana yazdirir
        void Preorder(NodeAVL *) const;

        //agaci postorder seklinde ekrana yazdirir
        void Postorder(NodeAVL *) const;

        //agaci levelorder seklinde ekrana yazdirir
        void PrintLevel(NodeAVL *,int )const;

        //parametre olarak gonderilen dugumun yuksekligini hesaplar
        int CalculateHeight(NodeAVL *)const;

        //parametre olarak gonderilen dugumu siler
        bool Remove(NodeAVL *&);

        //parametre olarak gonderilen kisinin agacta bulunup bulunmadigini kontrol eder.
        bool Search(NodeAVL *,Person *);

        //agaca her yeni eleman eklendiginde dugumlerin yuksekliklerini guncelleyen fonksiyon
        void HeightUpdate(NodeAVL *child_node)const;
    
    public:
        //kurucu fonksiyon
        AVLTree();

        //agacin bos olup olmadigini kontrol eden fonksiyon
        bool isEmpty() const;

        //agaca yeni kisi ekleyen fonksiyon
        void Add(Person *);

        //agaci inorder seklinde ekrana yazdirir
        void Inorder() const;

        //agaci preorder seklinde ekrana yazdirir
        void Preorder() const;

        //agaci postorder seklinde ekrana yazdirir
        void Postorder() const;

        //agaca her yeni eleman eklendiginde dugumlerin yuksekliklerini guncelleyen fonksiyon
        void HeightUpdate()const;

        //agaci levelorder seklinde ekrana yazdirir
        void Levelorder()const;

        //parametre olarak gonderilen kisinin agacta bulunup bulunmadigini kontrol eder.
        bool Searching(Person *);

        //agaci temizler
        void Clear();

        //dugumlerin derinliklerini hesaplar.
        int DepthCalculate(NodeAVL *&,int level=0)const;

        //yikici fonksiyon
        ~AVLTree();
};

#endif