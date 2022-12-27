#include "sort.h"
void insertion_sort_list(listint_t **list) {
  listint_t *current, *temp;

  if (list == NULL || *list == NULL || (*list)->next == NULL) {
    return;
  }

  current = (*list)->next;

  while (current != NULL) {
    temp = current;
    while (temp->prev != NULL && temp->prev->n > temp->n) {
      temp->prev->next = temp->next;
      if (temp->next != NULL) {
        temp->next->prev = temp->prev;
      }
      temp->next = temp->prev;
      temp->prev = temp->prev->prev;
      temp->next->prev = temp;
      if (temp->prev != NULL) {
        temp->prev->next = temp;
      }
      else {
        *list = temp;
      }
      print_list(*list);
    }
    current = current->next;
  }
}
