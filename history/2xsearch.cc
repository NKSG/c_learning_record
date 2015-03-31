template<class T>
class TreeNode
{
public:
    T data;
    unsigned int freq;
    TreeNode *lson;
    TreeNode *rson;
    TreeNode():lson(nullptr),rson(nullptr),freq(1){}
};

class BST
{
private:
    TreeNode<T> *root;
    void insertpri(TreeNode<T>* &node, T x);
    TreeNode<T> *findpri(TreeNode<T>* node, T x);
    void insubtree(TreeNode<T>* node);
    void Deletepri(TreeNode<T>* &node,T x);

public:
    BST():root(nullptr){}
    void Insert(T x);
    TreeNode<T>* Find(T x);
    void Delete(T x);
    void Traversal();
};

void BST<T>::insertpri(TreeNode<T>* &node, T x){
    if(node == nullptr){
        node = new TreeNode<T>();
        node.data = x;//不是->吧？
        return;
    }
    if(node->data > x){
        insertpri(node->lson, x);
    }
    else if(node->data<x){
        insertpri(node->rson, x);
    }else{
        ++(node->freq);
    }
}

void BST<T>::Insert(T x){
    insertpri(root,x);
}
