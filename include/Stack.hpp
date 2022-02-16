/*
 * @file             Stack.hpp
 * @description      Stack'in baslik dosyasi
 * @course           1.Ogretim A grubu
 * @assignment       2.Odev
 * @date             25.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/

#ifndef STACK_HPP
#define STACK_HPP

#include "NodeStack.hpp"
using namespace std;

class Stack
{
    private:

        //stack den cikacak olan dugumu tutan degisken
        NodeStack * topOfStack;

    public:

        //kurucu fonksiyon
        Stack();

        //stack in bos olup olmadigini kontrol eder
        bool isEmpty()const;

        //stack e yeni bir eleman ekler
        void push(const int&);

        //stack den eleman cikarir
        void pop();

        //stack den cikacak olan elemani dondurur
        const int& top()const;
        
        //stack de ki tum dugumleri siler.
        void makeEmpty();

        //stack in icindeki verileri ekrana yazdirir
        friend ostream & operator << (ostream&,Stack&);
        
        //yikici fonksiyon
        ~Stack();
};


#endif