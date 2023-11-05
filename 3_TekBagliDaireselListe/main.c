#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;          // düğümün içerisindeki değer.
    struct node *next; // düğümün bir sonraki bağlı olduğu bellek adresini gösterecek.
};
struct node *addfront(struct node *head, int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node)); // bellek te struct node türünde bir alan açıyorum bu alanı listeme eklemek isteyeceğim
    temp->data = key;
    if (head == NULL)
    {
        temp->next = temp;
        head = temp;
    }
    else
    {
        temp->next = head;
        struct node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = temp;
        head = temp;
    }
    return head;
}
struct node *addlast(struct node *head, int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node)); // bellek te struct node türünde bir alan açıyorum bu alanı listeme eklemek isteyeceğim
    temp->data = key;
    if (head == NULL)
    {
        temp->next = temp;
        head=temp;
    }
    else
    {
        struct node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = temp;
        temp->next = head;
    }
    return head;
}
void print(struct node *head)
{
    if (head == NULL)
    {
        printf("Liste Bos\n"); // eğer liste boş ise Liste Bos diye yazdırıyorum.
    }
    else
    {
        if (head->next == head)
        {
            printf("Node Adress : %p", head);        // eğer liste boş değil ise düğüm adresini yazdırıyorum.
            printf("Node Value : %d\n", head->data); // ve her bir liste elemanının değerini yazdırıyorum.
        }
        else
        {
            struct node *temp = head;
            while (temp->next != head)
            {
                printf("Node Adress : %p", temp);        // eğer liste boş değil ise düğüm adresini yazdırıyorum.
                printf("Node Value : %d\n", temp->data); // ve her bir liste elemanının değerini yazdırıyorum.
                temp = temp->next;                       // döngüyü ilerletmek için her defasında bir sonraki düğüme geçiyorum.
                if (temp->next == head)
                {
                    printf("Node Adress : %p", temp);        // son terimin adresini yazdırmak için.
                    printf("Node Value : %d\n", temp->data); // son terimi yazdırmak için.
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    struct node *head = NULL;
    int data, choice, checkpoint;
    checkpoint = 1;
    while (checkpoint)
    {
        printf("\n1-Insert a node a front\n");
        printf("2-Insert a node at last\n");
        printf("3-Print the list\n");
        printf("4-Count the list\n");
        printf("5-Print reverse\n");
        printf("6-Delete one node\n");
        printf("7-Delete all list\n");
        printf("10-Exit\n");
        printf("Enter your choise?");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a value to insert:");
            scanf("%d", &data);
            head = addfront(head, data);
            printf("Do you want to continue? Press 1 for yes or 0 for no.");
            scanf("%d", &checkpoint);
            break;
        case 2:
            printf("Enter a value to insert:");
            scanf("%d", &data);
            head = addlast(head, data);
            printf("Do you want to continue? Press 1 for yes or 0 for no.");
            scanf("%d", &checkpoint);
            break;
        case 3:
            print(head);
            printf("Do you want to continue? Press 1 for yes or 0 for no.");
            scanf("%d", &checkpoint);
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        default:
            break;
        }
    }
    return 0;
}
