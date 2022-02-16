/*
 * @file             Person.cpp
 * @description      Kisi bilgilerini tutan sinifin kaynak dosyasi
 * @course           1.Ogretim A grubu
 * @assignment       2.Odev
 * @date             25.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/

#include "Person.hpp"
#include <iostream>

using namespace std;

//kurucu fonksiyon
Person::Person(string name,int age,int lenght)
{
    this->name=name;
    this->age=age;
    this->lenght=lenght;
}

//kisinin ismini donduren fonksiyon
string Person::getName()const
{
    return this->name;
}

//kisinin yasini donduren fonksiyon
int Person::getAge()const
{
    return this->age;
}

//kisinin boyunu donduren fonksiyon
int Person::getLenght()const
{
    return this->lenght;
}

//kisi bilgilerini ekrana yazdiran fonksiyon
ostream & operator << (ostream &output, Person &obj)
{
    cout<<obj.name<<" "<<obj.age<<" "<<obj.lenght;
}

