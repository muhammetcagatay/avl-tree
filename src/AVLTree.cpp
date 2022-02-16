/*
 * @file             AVLTree.cpp
 * @description      AVL agacinin kaynak dosyasi
 * @course           1.Ogretim A grubu
 * @assignment       2.Odev
 * @date             25.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/

#include <iostream>
#include "Person.hpp"
#include "NodeAVL.hpp"
#include "AVLTree.hpp"
#include <algorithm>
#include <cmath>
using namespace std;

//yeni dugumun eklenecegi konumu bulur ve o konuma dugumu ekler.
NodeAVL* AVLTree::SearchAndAdd(NodeAVL *child_node,Person *new_person)
{
    if(child_node == NULL)
    {
        child_node = new NodeAVL(new_person);
    }
    else if(new_person->getLenght() < child_node->person_info->getLenght())
    {
        child_node->left = SearchAndAdd(child_node->left,new_person);
        
        if(CalculateHeight(child_node->left) - CalculateHeight(child_node->right) == 2)
        {
            
            if(new_person->getLenght() < child_node->left->person_info->getLenght())
            {   // sol sol Durumu 
                child_node = SwapWithLeftChild(child_node); //sağa dönüş
            }
                
            else
            {   //Sol Sağ Durumu
                child_node->left = SwapWithRightChild(child_node->left); //sola dönüş
                child_node = SwapWithLeftChild(child_node);
            }
        }
    }
    else if(new_person->getLenght() > child_node->person_info->getLenght())
    {
        child_node->right = SearchAndAdd(child_node->right,new_person);
        
        if(CalculateHeight(child_node->right) - CalculateHeight(child_node->left) == 2)
        {
            
            if(new_person->getLenght() > child_node->right->person_info->getLenght())
            {   // Sag Sag Durumu
                child_node = SwapWithRightChild(child_node);
            }
                
            else
            {   // Sag Sol Durumu 
                child_node->right = SwapWithLeftChild(child_node->right); 
                child_node = SwapWithRightChild(child_node); 
            }
        }
    }
    else; // Aynı eleman var.
    
    //Yüksekliği güncelle
    child_node->height= CalculateHeight(child_node);

    return child_node;		
}

//dugumu sol cocuk ile degistirip agaci dengeler
NodeAVL* AVLTree::SwapWithLeftChild(NodeAVL *child_node) 
{ 
    //swap
    NodeAVL *temp_node = child_node->left; 
    child_node->left = temp_node->right; 		  
    temp_node->right = child_node; 
    
    // Yükseklikleri Güncelle
    child_node->height= CalculateHeight(child_node);

    temp_node->height=max(CalculateHeight(temp_node->left),child_node->height)+1;

    return temp_node;
} 

//dugumu sag cocuk ile degistirip agaci dengeler
NodeAVL* AVLTree::SwapWithRightChild(NodeAVL *child_node) 
{ 
    //swap
    NodeAVL *temp_node = child_node->right; 
    child_node->right = temp_node->left;
    temp_node->left = child_node;
    
    // Yükseklikleri Güncelle 
   
    child_node->height= CalculateHeight(child_node);

    temp_node->height=max(CalculateHeight(temp_node->right),child_node->height)+1;

    
    return temp_node;
} 

//agaci inorder seklinde ekrana yazdirir
void AVLTree::Inorder(NodeAVL *child_node) const
{
    if(child_node != NULL)
    {
        Inorder(child_node->left);
        cout<<*(child_node->person_info);
        cout<<" Y";
        cout<<*(child_node->heightStack)<<",";
        cout<<"D";
        cout<<*(child_node->depth);
        cout<<"  ";
        Inorder(child_node->right);
    }
}
void AVLTree::HeightUpdate(NodeAVL *sub_node) const
{
    if(sub_node != NULL)
    {
        HeightUpdate(sub_node->left);
        HeightUpdate(sub_node->right);
        sub_node->heightStack->push(sub_node->height);

    }
}

//agaci preorder seklinde ekrana yazdirir
void AVLTree::Preorder(NodeAVL *child_node) const
{
    if(child_node != NULL)
    {
        cout<<*(child_node->person_info);
        cout<<" Y";
        cout<<*(child_node->heightStack)<<",";
        cout<<"D";
        cout<<*(child_node->depth);
        cout<<"  ";
        Preorder(child_node->left);
        Preorder(child_node->right);
    }
}

//agaci postorder seklinde ekrana yazdirir
void AVLTree::Postorder(NodeAVL *child_node) const
{
    if(child_node != NULL)
    {
        Postorder(child_node->left);
        Postorder(child_node->right);
        cout<<*(child_node->person_info);
        cout<<" Y";
        cout<<*(child_node->heightStack)<<",";
        cout<<"D";
        cout<<*(child_node->depth);
        cout<<"  ";			

    }
}	

//agaci levelorder seklinde ekrana yazdirir
void AVLTree::PrintLevel(NodeAVL *child_node,int level)const
{
    if(child_node == NULL) return;
    if(level == 0)
    {
        cout<<*(child_node->person_info);
        cout<<" Y";
        cout<<*(child_node->heightStack)<<",";
        cout<<"D";
        cout<<*(child_node->depth);
        cout<<"  ";
        //cout<<" "<<alt_Dugum->derinlik<<endl;
    }
    else
    {
        PrintLevel(child_node->left,level-1);
        PrintLevel(child_node->right,level-1);
    }
}

//parametre olarak gonderilen dugumun yuksekligini hesaplar
int AVLTree::CalculateHeight(NodeAVL *child_node)const
{
    if(child_node == NULL) return -1; // Ortada düğüm yoksa yükseklik anlamsızdır. Kodun çalışması adına -1 verilmektedir.
    return 1+max(CalculateHeight(child_node->left),CalculateHeight(child_node->right));
}

//dugumlerin derinliklerini hesaplar.
int AVLTree::DepthCalculate(NodeAVL*&child_node,int level)const
{   
    if(child_node!=NULL)
    {
        child_node->depth->push(level);
        DepthCalculate(child_node->left,level+1);  
        DepthCalculate(child_node->right,level+1);  
    }
}

//parametre olarak gonderilen dugumu siler
bool AVLTree::Remove(NodeAVL *&child_node)
{			
    NodeAVL *delete_node = child_node;
    
    if(child_node->right == NULL)
    {
        child_node = child_node->left;
    }

    else if(child_node->left == NULL)
    {
        child_node = child_node->right;
    }

    else
    {
        delete_node = child_node->left;
        NodeAVL *parent_node = child_node;

        while(delete_node->right != NULL)
        {
            parent_node=delete_node;
            delete_node=delete_node->right;
        }

        child_node->person_info = delete_node->person_info;

        if(parent_node == child_node)
        {
            child_node->left = delete_node->left;
        } 

        else
        {   
            parent_node->right = delete_node->left;
        } 
    }
    delete delete_node;
    
    return true;
}

//parametre olarak gonderilen kisinin agacta bulunup bulunmadigini kontrol eder.
bool AVLTree::Search(NodeAVL *child_node,Person *search_person)
{
    if(child_node == NULL) return false;
    if(child_node->person_info->getLenght() == search_person->getLenght()) return true;
    if(search_person->getLenght() < child_node->person_info->getLenght()) return Search(child_node->left,search_person);
    if(search_person->getLenght() > child_node->person_info->getLenght()) return Search(child_node->right,search_person);
}

//kurucu fonksiyon
AVLTree::AVLTree()
{
    root = NULL;
}

//agacin bos olup olmadigini kontrol eden fonksiyon
bool AVLTree::isEmpty() const
{
    return root == NULL;
}

//agaca yeni kisi ekleyen fonksiyon
void AVLTree::Add(Person *new_person)
{
    if(!Searching(new_person))
    {
        root = SearchAndAdd(root,new_person);
        DepthCalculate(root,0);
        HeightUpdate(root);

    }

}

void AVLTree::HeightUpdate() const
{
    HeightUpdate(root);
}

//agaci inorder seklinde ekrana yazdirir
void AVLTree::Inorder() const
{
    Inorder(root);
}

//agaci preorder seklinde ekrana yazdirir
void AVLTree::Preorder() const
{
    Preorder(root);
}

//agaci postorder seklinde ekrana yazdirir
void AVLTree::Postorder() const
{
    Postorder(root);
}

//agaci levelorder seklinde ekrana yazdirir
void AVLTree::Levelorder()const
{
    int h = CalculateHeight(root);
    for(int level=0;level<=h;level++)
    {
        PrintLevel(root,level);
    }
        
}

//parametre olarak gonderilen kisinin agacta bulunup bulunmadigini kontrol eder.
bool AVLTree::Searching(Person *search_person)
{
    return Search(root,search_person);
}

//agaci temizler
void AVLTree::Clear()
{
    while(!isEmpty()) Remove(root);
}

//yikici fonksiyon
AVLTree::~AVLTree()
{
    Clear();   
}