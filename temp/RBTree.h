#ifndef _RB_TREE_H_
#define _RB_TREE_H_
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

template<class KEY, class U>
class RB_Tree{
    private:
        RB_Tree(const RB_Tree& input){}
        const RB_Tree& operator=(const RB_Tree& input){}
        //构造函数和拷贝函数？
    private:
        enum COLOR{RED,BLACK};
        class RB_Node{
        public:
            RB_Node(){
                //RB_COLOR = BLACK;
                //why 注释掉
                right = nullptr;
                left = nullptr;
                parent = nullptr;
            }

            COLOR RB_COLOR;
            RB_Node* right;
            RB_Node* left;
            RB_Node* parent;
            KEY key;
            U data;
        };
    public:
        RB_Tree(){
            this->m_nullNode = new RB_Node();
            this->m_root = m_nullNode;
            this->m_nullNode->right = this->m_root;
            this->m_nullNode->left = this->m_root;
            this->m_nullNode->parent = this->m_root;
            this->m_nullNode->RB_COLOR = BLACK;
        }

        bool Empty(){
            if(this->m_root == this->m_nullNode){
                return true;  
            }else{
                return false;
            }
        }

        RB_Node* find(KEY key){
            RB_Node* index = m_root;
            while(index != m_nullNode){
                if(key<index->key){
                    index = index->left;
                }else if(key>index->key){
                    index = index->right;
                }else{
                    break;
                }
            }
            return index;
        }

        //开始insert操作相关函数
        bool Insert(KEY key, U data){
            RB_Node* insert_point = m_nullNode;
            RB_Node* index = m_root;

            while(index != m_nullNode){
                insert_point = index;
                if(key<index->key){
                    index = index->left;
                }else if(key>index->key){
                    index = index->right;
                }else{
                    return false;
                }
            }

            RB_Node* insert_node = new RB_Node();
            insert_node->key = key;
            insert_node->data = data;
            insert_node->RB_COLOR = RED;
            insert_node->right = m_nullNode;
            insert_node->left = m_nullNode;
            if(insert_point == m_nullNode){
                m_root = insert_node;
                m_root->parent = m_nullNode;
                m_nullNode->left = m_root;
                m_nullNode->right = m_root;
                m_nullNode->parent = m_root;
            }else{
                if(key<insert_point->key){
                    insert_point->left = insert_node;
                }else{
                    insert_point->right = insert_node;
                }
                insert_node->parent = insert_point;
            }
            InsertFixUp(insert_node);
        }

        void InsertFixUp(RB_Node* node){
            while(node->parent->RB_COLOR == RED){
                if(node->parent == node->parent->parent->left){
                    RB_Node* uncle = node->parent->parent->right;
                    if(uncle->RB_COLOR == RED){
                        node->parent->RB_COLOR = BLACK;
                        uncle->RB_COLOR = BLACK;
                        node->parent->parent->RB_COLOR = RED;
                        node = node->parent->parent;
                    }else if(uncle->RB_COLOR == BLACK){
                        if(node == node->parent->right){
                            node = node->parent;
                            RotateLeft(node);
                        }else{
                            node->parent->RB_COLOR = BLACK;
                            node->parent->parent->RB_COLOR = RED;
                            RotateRight(node->parent->parent);
                        }
                    }
                }else{
                    RB_Node* uncle = node->parent->parent->left;
                    if(uncle->RB_COLOR == RED){
                        node->parent->RB_COLOR = BLACK;
                        uncle->RB_COLOR = BLACK;
                        uncle->parent->RB_COLOR = RED;
                        node = node->parent->parent;
                    }else if(uncle->RB_COLOR == BLACK){
                        if(node == node->parent->left){
                            node = node->parent;
                            RotateRight(node);
                        }else{
                            node->parent->RB_COLOR = BLACK;
                            node->parent->parent->RB_COLOR = RED;
                            RotateLeft(node->parent->parent);
                        }
                    }
                }
            }
            m_root->RB_COLOR = BLACK;
        }
        
        bool RotateLeft(RB_Node* node){
        }

        bool RotateRight(RB_Node* node){
        }
};
