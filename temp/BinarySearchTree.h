#include <stack>
using namespace std;

struct TreeNode{
    int elem;
    TreeNode *LChildNode;
    TreeNode *RChildNode;
    TreeNode(int e=0, TreeNode *lchild=nullptr, TreeNode *rchild=nullptr):elem(e),LChildNode(lchild),RChildNode(rchild){}
};

class BinaryTree{
public:
    BinaryTree();
    virtual ~BinaryTree();

    void insert(int e);
    void remove(int e);
    int find(const int &e);
    void printTree();
    void emtyTree();
private:
    void printTree(TreeNode* &node);
    void GetNodes(stack<TreeNode*> &st, TreeNode* &node);
    TreeNode *m_root;
}


