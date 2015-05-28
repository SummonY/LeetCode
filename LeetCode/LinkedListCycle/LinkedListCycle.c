#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    int val;
    struct Node *next;
}LNode, *ListNode;

typedef enum {false, true}bool;

ListNode createList();
bool hasCycle(ListNode head);

int main(int argc, const char *argv[])
{
    ListNode L;

    L = createList();

    printf("hasCycle ? %s\n", (hasCycle(L) ? "true" : "false"));
    return 0;
}

ListNode createList()
{
    ListNode L, p, q;
    L = (ListNode)malloc(sizeof(LNode));
    p = L;
    int val;
    scanf("%d", &val);
    while(val != -1) {
        q = (ListNode)malloc(sizeof(LNode));
        q->val = val;
        q->next = NULL;
        p->next = q;
        p = p->next;
        scanf("%d", &val);
        if (val == -2) {
            p->next = L;
            break;
        }
    }
    return L;
}

bool hasCycle(ListNode head)
{
    if (head == NULL || head->next == NULL)
        return false;
    ListNode fast = head;
    ListNode slow = head;

    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}
