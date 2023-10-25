#include <stdio.h>
#include <stdlib.h>
struct node
{
       int data;                // düğümün içerisindeki değer.
       struct node *next;       // düğümün bir sonraki bağlı olduğu bellek adresini gösterecek.
       struct node *prev;       // düğümün bir önceki bağlı olduğu bellek adresini gösterecek. 
};
struct node *addfront(struct node *head,int key){
    struct node *temp=(struct node *)malloc(sizeof(struct node));   // bellek te struct node türünde bir alan açıyorum bu alanı listeme eklemek isteyeceğim
    temp->data=key;     //eklemek istediğim değeri temp in datasına atıyorum.
    temp->next=head;    //temp listenin ilk elemanı olacağı için next inin head olması lazım.
    temp->prev=NULL;    //temp listenin ilk elemanı olacağı için prev in NULL olması için atama yapıyorum.
    if(head!=NULL)      //Eğer head NULL değil ise head in prev inin temp i göstermesi lazım.
        head->prev=temp;
    head=temp;          //Artık listenin başında temp olduğu için head e temp atamasını yapıyorumç
    return head;        //Son olarak listenin başını geriye dönüyorum.
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
