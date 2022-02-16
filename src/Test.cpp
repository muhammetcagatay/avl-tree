/*
 * @file             Test.cpp
 * @description      Okuma islemlerinin yapildigi, kisi bilgilerinin AVL agacina eklendigi ve bilgilerin ekrana yazildigi test dosyasi
 * @course           1.Ogretim A grubu
 * @assignment       2.Odev
 * @date             25.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "Person.hpp"
#include "Stack.hpp"
#include "AVLTree.hpp"

using namespace std;

Person* parsonAssigment(string);

AVLTree * readFile(string);

int main()
{  
    //readFile fonksiyonu yardimiyle Kisiler.txt dosyasindan kisiler okunup agaca eklenir.
    AVLTree* yeni=readFile("doc\\Kisiler.txt");
    
    //Agac levelorder seklinde ekrana yazdirilir.
    yeni->Levelorder();

    delete yeni;

    return 0;
}

//okunan satirdaki isim,yas ve boy bilgisi ile Person turunden yeni bir kisi olusturularak olusturulan dizi dondurulur.
Person* personAssigment(string line)
{ 
    /*
    her bir satiri # isaretine gore parcalayip bilgileri age,lenght,name degiskenlerini aktarir
    ve bu bilgilerler Person turunden yeni bir obje olusturur ve bu objeyi dondurur.
    */
    int age=0;

    int lenght=0;

    string name=line.substr(0,line.find("#"));

    line=line.substr(line.find("#")+1,line.length());

    string age_str=line.substr(0,line.find("#"));

    string lenght_str=line.substr(line.find("#")+1,line.length());

    stringstream geek(age_str);

    geek>>age; 

    stringstream geek1(lenght_str);

    geek1>>lenght;

    Person * newPerson=new Person(name,age,lenght);

    return newPerson;

}

//parametre olarak gonderilen dosyadaki tum kisiler satir satir okunup agaca eklenir.
AVLTree * readFile(string file_name)
{
    /*
    dosyayi satir satir okuyarak bu satirlardan olusan Person turundeki objeleri agaca ekler.
    */
    AVLTree * persons=new AVLTree();

    string text;

    string before;

    ifstream inFile;

    inFile.open(file_name);

    if(inFile.is_open())
    {
        while(!inFile.eof())
        {
            inFile>>text;
        
            Person * yeni;

            yeni=personAssigment(text); 

            persons->Add(yeni);
             
        }
    }

    inFile.close();
    
    return persons;
}