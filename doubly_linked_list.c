
#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
DoubleNode* dll_create_node(data value) {
DoubleNode *node = calloc(1, sizeof(DoubleNode));
node->value = value;
node->prev = NULL;
node->next = NULL;
return node;
}
DoubleNode* dll_prepend(DoubleNode* head, data value) {
DoubleNode* newNode = dll_create_node(value);
 newNode->next = head;
 if (head)
 head->prev = newNode;
 return newNode;
}

void dll_insert_before(DoubleNode* node, data value){
 DoubleNode* newNode = dll_create_node(value);
 DoubleNode* origPrev = node->prev;
 node->prev = newNode;
 newNode->prev = origPrev;
 newNode->next = node;
 if (origPrev)
 origPrev->next = newNode;
}

void dll_insert_after(DoubleNode* node, data value){
DoubleNode* newNode = dll_create_node(value);
DoubleNode* origNext = node->next;
node->next = newNode;
newNode->prev = node;
newNode->next = origNext;
if (origNext)
origNext->prev = newNode;
}
DoubleNode* dll_find(DoubleNode *head, data value) {
 DoubleNode *p;
 for (p = head; p != NULL && p->value != value; p = p->next);
 return p;
}

DoubleNode* dll_delete_node(DoubleNode *head, DoubleNode *node){
  if(node){
 DoubleNode *prev = node->prev;
 if (prev)
 prev->next = node->next;
DoubleNode *next = node->next;
 if (next)
next->prev = prev;

free(node);
 return head == node ? next : head;      
  }
  
  return head;
}
