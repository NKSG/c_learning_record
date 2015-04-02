#include <iostream>
#include "BinarySearchTree.h"
#include <unistd.h>

BinaryTree::BinaryTree(){
    m_root = nullptr;
}

BinaryTree::~BinaryTree(){
    emptyTree();
}

void BinaryTree::insert(int e){
    if(!m_root){
        m_root = new TreeNode(e,nullptr,nullptr);
        return;
    }
    TreeNode *pNode = m_root;
    while(pNode){
        if(e>pNode->elem){
            if(pNode->RChildNode == nullptr){
                pNode->RChildNode = new TreeNode(e,nullptr,nullptr);
                break;
            }
            pNode = pNode->RChildNode;
        }
        else if(e<pNode->elem){
            if(pNode->LChildNode == nullptr){
                pNode->LChildNode = new TreeNode(e,nullptr,nullptr);
                break;
            }
            pNode = pNode->LChildNode;
        }
        else break;
    }
}

void BinaryTree::remove(int e){
    TreeNode *pNode = m_root;
    TreeNode *preNode;
    while(pNode){
        if(e<pNode->elem){
            preNode = pNode;
            pNode = pNode->LChildNode;
        }else if(e>pNode->elem){
            preNode = pNode;
            pNode = pNode->RChildNode;
        }else break;
    }
    if(pNode){
        if(pNode->LChildNode && pNode->RChildNode){
        
        }else{
            pNode = pNode
        }
    }
}


Node RotateLeft(Node h){
    Node x = h.Right;
    h.Right = x.Left;
    x.Left = h;
    x.Color = h.Color;
    h.Color = Red;
    return x;
}
