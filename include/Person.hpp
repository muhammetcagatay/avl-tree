/*
 * @file             Person.hpp
 * @description      Kisi bilgilerini tutan sinifin baslik dosyasi
 * @course           1.Ogretim A grubu
 * @assignment       2.Odev
 * @date             25.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>

using namespace std;

class Person
{
    private:
    
        //kisinin adini tutan degisken
        string name;
        
        //kisinin yasini tutan degisken
        int age;

        //kisinin boyunu tutan degisken
        int lenght;
        
    public:

        //kurucu fonksiyon
        Person(string name="",int age=0,int lenght=0 );

        //kisinin ismini donduren fonksiyon
        string getName()const;

        //kisinin yasini donduren fonksiyon
        int getAge()const;

        //kisinin boyunu donduren fonksiyon
        int getLenght()const;

        //kisi bilgilerini ekrana yazdiran fonksiyon
        friend ostream & operator << (ostream&,Person&);
};

#endif