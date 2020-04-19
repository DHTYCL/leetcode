#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* res =new ListNode(0);
    ListNode* cur =res;
    int iter = 0;
    while (l1 != NULL ||l2 != NULL || 0 != iter) {
        int left = 0;
        int right = 0;
        if (l1 != NULL) {
            left = l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            right = l2->val;
            l2 = l2->next;
        }
        int sum = left + right + iter;
        cur->next=new ListNode(sum%10);
        cur=cur->next;
        iter = sum/10;
    }
    return res->next;
}

ListNode* getList(int input[], int len)
{
    if (input == NULL || len == 0) {
        return NULL;
    }
    ListNode* res = new ListNode(0);
    ListNode* cur = res;
    for (int i = 0;i< len; i++) {
        cur->next=new ListNode(input[i]);
        cur=cur->next;
    }
    return res->next;
}

void showList(ListNode* head)
{
    while (head != NULL) {
        cout << head->val << " " <<endl; 
        head=head->next;
    }
}

int main()
{
    int input1[] = {};
    int input2[] = {5};
    ListNode* l1 =getList(input1, sizeof(input1)/sizeof(int));
    ListNode* l2 =getList(input2, sizeof(input2)/sizeof(int));
    showList(l1);
    showList(l2);
    ListNode*l3 = addTwoNumbers(l1, l2);
    showList(l3);
    return 0;
}
