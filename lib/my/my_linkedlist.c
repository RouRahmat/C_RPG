/*
** EPITECH PROJECT, 2020
** linked list
** File description:
** linked list
*/

#include "my.h"

List * ll_initialise()
{
    List *list = malloc(sizeof(struct List));
    Element *element = malloc(sizeof(struct Element));

    element->next = NULL;
    element->type = -1;
    list->first = element;

    return (list);
}

// int nb = 0 : insert at beggining
// int nb = -1 : insert at end
// int nb != 0 or -1 : insert after link nb

void ll_insert(List * list, int nb, Element *new)
{
    Element *ActualElem = list->first;

    if (nb == 0) {
        new->next = list->first;
        list->first = new;
    }
    else if (nb == -1) {
        while (ActualElem->next != NULL)
            ActualElem = ActualElem->next;
        new->next = ActualElem->next;
        ActualElem->next = new;
    }
    else {
        for (int j = 1; j < nb; j++)
            ActualElem = ActualElem->next;
        new->next = ActualElem->next;
        ActualElem->next = new;
    }
}

void ll_delete(List * list, int nb)
{
    Element *toDelete = list->first;
    Element *ActualElem = list->first;
    if (nb == 0) {
        list->first = list->first->next;
        free(toDelete);
    }
    else if (nb == -1) {
        while (ActualElem->next->next != NULL)
            ActualElem = ActualElem->next;
        toDelete = ActualElem->next;
        ActualElem->next = ActualElem->next->next;
        free(toDelete);
    }
}

void ll_free(Element *head)
{
    Element *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void ll_display(List *list)
{
    Element *actual = list->first;

    while (actual != NULL) {
        my_printf("%i ->", actual->type);
        actual = actual->next;
    }
    my_printf("NULL\n");
}