#include<stdio.h>
#include<stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    if (l1 == NULL && l2 != NULL) {
        return l2;
    };
    if (l2 == NULL && l1 != NULL) {
        return l1;
    };
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current_node = head;
    int head_flag = 1;
    int up_bit=0;
    //l1与l2都不是空的
    while (l1 != NULL &&(l2 != NULL)){
        int sum = l1->val + l2->val+ up_bit;
        up_bit = 0;
        if (sum >= 10) {
            up_bit = 1;
            sum -= 10;
        }
        if (head_flag == 1) {
            head_flag = 0;
            current_node->val = sum;
            current_node->next = NULL;
        }
        else {
            struct ListNode* temp_node = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp_node->val = sum;
            temp_node->next = NULL;
            current_node->next = temp_node;
            current_node = temp_node;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    //l1 与l2不等长
    struct ListNode* left_node = NULL;
    if (l1 != NULL) {
        left_node = l1;
    }
    if (l2 != NULL){
        left_node = l2;
    }
    while (left_node != NULL)
    {
        int sum = left_node->val + up_bit;
        up_bit = 0;
        if (sum >= 10) {
            up_bit = 1;
            sum -= 10;
        }
        struct ListNode* temp_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp_node->val = sum;
        temp_node->next = NULL;
        current_node->next = temp_node;
        current_node = temp_node;
        left_node = left_node->next;
    }
    //最后还是有进位的情况
    if (up_bit == 1) {
        struct ListNode* temp_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp_node->val = 1;
        temp_node->next = NULL;
        current_node->next = temp_node;
        current_node = temp_node;
    }
    return head;
}
int main() {
    int head_flag = 1;
    ListNode* l1head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* l1current_node = l1head;

    ListNode* l2head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* l2current_node = l2head;
    for (int i = 0; i < 7; i++) {
        if (head_flag == 1) {
            head_flag = 0;
            l1current_node->val = 1;
            l1current_node->next = NULL;
        }
        else
        {
            ListNode* temp_node = (ListNode*)malloc(sizeof(ListNode));
            temp_node->val = i;
            temp_node->next = NULL;
            l1current_node->next = temp_node;
            l1current_node = temp_node;
        }
    
    }
    head_flag = 1;
    for (int i = 0; i < 8; i++) {
        if (head_flag == 1) {
            head_flag = 0;
            l2current_node->val = 0;
            l2current_node->next = NULL;;
        }
        else
        {
            ListNode* temp_node2 = (ListNode*)malloc(sizeof(ListNode));
            temp_node2->val = i + 2;
            temp_node2->next = NULL;
            l2current_node->next = temp_node2;
            l2current_node = temp_node2;
        }

    }
    ListNode *ans_node= addTwoNumbers(l1head, NULL);
    while (ans_node !=NULL)
    {
        printf("%d\r\n", ans_node->val);
        ans_node = ans_node->next;
    }
    return 0;
}