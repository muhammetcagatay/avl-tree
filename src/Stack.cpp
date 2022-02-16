/*
 * @file             Stack.cpp
 * @description      Stack'in kaynak dosyasi
 * @course           1.Ogretim A grubu
 * @assignment       2.Odev
 * @date             25.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/

#include "Stack.hpp"
#include <iostream>

using namespace std;

//kurucu fonksiyon
Stack::Stack()
{
    topOfStack=NULL;
    push(-1);
}

//stack in bos olup olmadigini kontrol eder
bool Stack::isEmpty()const
{
    return topOfStack==NULL;
}

//stack e yeni bir eleman ekler
void Stack::push(const int& item)
{
    topOfStack=new NodeStack(item,topOfStack);
}

//stack den eleman cikarir
void Stack::pop()
{
    if(isEmpty()) throw "HATA";

    NodeStack * delete_node=topOfStack;

    topOfStack=topOfStack->next;

    delete delete_node;
}

//stack den cikacak olan elemani dondurur
const int& Stack::top()const
{
    return topOfStack->item;
}

//stack de ki tum dugumleri siler.
void Stack::makeEmpty()
{
     while(!isEmpty()) pop();
}

//stack in icindeki verileri ekrana yazdirir
ostream & operator << (ostream &output, Stack &obj)
{
    cout<<"(";
    while(!obj.isEmpty())
    {
        if(obj.top()==-1)
        {
            obj.pop();
        }
        else
        {
            if(obj.topOfStack->next==NULL||obj.topOfStack->next->item==-1)
            {
                cout<<obj.top();
                obj.pop();
            }
            else
            {
                cout<<obj.top()<<",";
                obj.pop();
            }
        }
    }
    cout<<")";
}

//yikici fonksiyon
Stack::~Stack()
{
    makeEmpty();
}