#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_tag {
    struct node_tag*    next;
    int                 data;
}node;

node* remove_if(node* head)
{
    for (node* cur = head, * prev = NULL; cur != NULL; )
    {    
        node* tmp = cur->next;
        if (cur->data == 2)
        {
            if (prev)
            {
                prev->next = tmp;
            }
            else
            {
                head = cur->next;
            }
            free(cur);
        }
        else
        {
            prev = cur;
        }
        cur = tmp;
    }
    
    return head;
}

void remove_if(node** head)
{
    for (node** curr = head; *curr != NULL;)
    {
        node* tmp = *curr;
        if (tmp->data == 3)
        {
            *curr = tmp->next;
            free(tmp);
        }
        else
        {
            curr = &tmp->next;
        }
    }
}

void insert(node** head, int _data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = _data;
    new_node->next = *head;
    *head = new_node;
}

void print(node** head)
{
    for (node* curr = *head; curr != NULL; curr = curr->next)
    {
        printf(" %d\n", curr->data);
    }
}

int main()
{
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->data = 1;

    insert(&head, 2);
    insert(&head, 3);
    print(&head);
    printf("remove 2:\n");
    head = remove_if(head);
    print(&head);
    printf("remove 3:\n");
    remove_if(&head);
    print(&head);
    return 0;
}
