//No.23
//https://leetcode.com/problems/merge-k-sorted-lists/
//Merge K Sorted Lists

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode *base = NULL;
        ListNode *other = NULL;
        if(l1->val<=l2->val){
            base = l1;
            other = l2;
        }else{
            base = l2;
            other = l1;
        }
        ListNode *new_ptr = base;
        ListNode *cur = NULL;
        while(base && other){
            if(base->val <= other->val){
                cur = base;
                base=base->next;
            }else{
                cur->next = other;
                cur = other;
                ListNode *next = other->next;
                other->next = base;
                other = next;
            }
        }
        if(other){
            cur->next = other;
        }
        return new_ptr;
    }

//分而治之的策略，还是需要详细探究下，遇到奇数偶数都需要怎么办
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size()==0) return nullptr;
        vector<ListNode*> merged(lists);
        int size = (int)merged.size();
        while(size>1){
            for(int i=0; i<size/2; i++){
                merged[i] = mergeTwoLists(merged[i*2],merged[2*i+1]);
            }
            if(size&0x01)
                merged[size/2-1] = mergeTwoLists(merged[size/2-1],merged[size-1]);
            size /= 2;
        }
        return merged[0];
    }
