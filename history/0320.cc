void CreateBiTree(BiTree *T){
    TElemType ch;
    scanf("%c",&ch);
    if(ch=='#')
        *T = nullptr;
    else{
        *T=new BiTree();
        if(!*T)
            exit(OVERFLOW);
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}


typedef enum {Link,Thread} PointerTag;

typedef struct BiThrNode{
    TElemType data;
    BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
} BiThrNode, *BiThrTree;

void InThreading(BiThrTree p){
    if(p){
        InThreading(p->lchild);
        if(!p->lchild){
            p->LTag = Thread;
            p->lchild = pre;
        }
        if(!pre->rchild){
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        inThreading(p->rchild);
    }
}

Status InOrderTraverse_Thr(BiThrTree T){
    BiThrTree p;
    p = T->lchild;
    while(p!=T){
        p = p->lchild;
        printf("%c",p->data);
        while(p->RTag == Thread && p->rchild!=T){
            p = p->rchild;
            printf("%c",p->data);
        }
        p = p->rchild;
    }
    return OK;
}
