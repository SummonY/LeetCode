/*
 *Write a function to delete a node (except the tail) in a singly linked list, 
 * given only access to that node.
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
 * the linked list should become 1 -> 2 -> 4 after calling your function.
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};

class Solution {
    public:
        ListNode *createList()
        {
            ListNode *L = new ListNode;
            L->next = nullptr;

            int value;
            cin >> value;

            while (value != -1) {
                ListNode *p = new ListNode;
                p->val = value;
                p->next = L->next;
                L->next = p;
                cin >> value;
            }
            return L;
        }

        void visitListNode(ListNode *L)
        {
            ListNode *p = L->next;

            while (p)
            {
                cout << p->val << " ";
                p = p->next;
            }
            cout << endl;
        }

};


int main()
{
    ListNode *L; 
    Solution sl;
    
    L = sl.createList();
    sl.visitListNode(L); 
    return 0;
}
