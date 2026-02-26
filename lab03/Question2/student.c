// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement
      if (head == NULL || head->next == NULL) {
            return head;
      }

      struct ListNode* previous = NULL;
      struct ListNode* current = head;
      struct ListNode* newHead = head->next;

      while (current != NULL && current->next != NULL) {
            struct ListNode* A = current;
            struct ListNode* B = current->next;
            struct ListNode* nextPair = B->next;
            A->next = nextPair;
            B->next = A;

            if (previous != NULL) {
                  previous->next = B;
            }

            previous = A;
            current = nextPair;
      }

      return newHead;
}