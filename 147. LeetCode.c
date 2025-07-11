/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * CriaLista();
void Insere(struct ListNode * p,struct ListNode* n);

struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode * p = CriaLista();
    struct ListNode * n = head;

    while (n != NULL) {
        Insere(p, n);
        n = n->next;
    }

    return p->next;
}

struct ListNode * CriaLista() {
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->next = NULL;
    return p;
}

void Insere (struct ListNode * p,struct ListNode* n) {
    struct ListNode * new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->val = n->val;
    new->next = NULL;
    struct ListNode * q = p;

    while(q->next != NULL && q->next->val < new->val) {
        q = q->next;
    }
    new->next = q->next;
    q->next = new;

}
