#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;          // düğümün içerisindeki değer.
    struct node *next; // düğümün bir sonraki bağlı olduğu bellek adresini gösterecek.
    struct node *prev; // düğümün bir önceki bağlı olduğu bellek adresini gösterecek.
};
struct node *addfront(struct node *head, int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node)); // bellek te struct node türünde bir alan açıyorum bu alanı listeme eklemek isteyeceğim
    temp->data = key;                                               // eklemek istediğim değeri temp in datasına atıyorum.
    temp->next = head;                                              // temp listenin ilk elemanı olacağı için next inin head olması lazım.
    temp->prev = NULL;                                              // temp listenin ilk elemanı olacağı için prev in NULL olması için atama yapıyorum.
    if (head != NULL)                                               // Eğer head NULL değil ise head in prev inin temp i göstermesi lazım.
        head->prev = temp;
    head = temp; // Artık listenin başında temp olduğu için head e temp atamasını yapıyorumç
    return head; // Son olarak listenin başını geriye dönüyorum.
}
struct node *addlast(struct node *head, int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = NULL;
    struct node *last = head;
    if (head != NULL)
    {
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = temp;
        temp->prev = last;
    }
    else
    {
        temp->prev = NULL;
        head = temp;
    }
    return head;
}
// listeden girilen bir değeri silen fonksiyonu yazıyorum
struct node *deletenode(struct node *head, int key)
{
    if (head == NULL)
    {
        printf("Liste Boş"); // eğer liste boş ise Liste Bos diye yazdırıyorum.
    }
    else
    {
        struct node *del = head; // silinecek elemanı önce listenin başını gösterecek şekilde ayarlama yapıyorum.
        if (head->data == key)   // eğer silinecek eleman listenin ilk elemanı ise
        {
            head = head->next; // listenin başını bir sonraki elemana kaydırıyorum.
            free(del);         // daha sonra silinecek elemanı siliyorum
            del = NULL;        // bellek te herahangi bir sorun olmasın diye sildiğim yere NULL atıyorum.
            if (head != NULL)  // eğer listede tek eleman varsa ve ben bunu silersem head değeri NULL olacağı için NULL ın prev ine atama yapamam program hata verir.
            {
                head->prev = NULL; // eğer head NULL değil ise head in prev değeri NULL olmalıdır.
            }
        }
        else // silinecek eleman ilk eleman değil ise
        {
            while (del->data != key && del != NULL) // silinecek elemanı bulmak için döngü kuruyoruz
                del = del->next;
            if (del == NULL) // eğer silinecek eleman listede bulunamaz ise
            {
                printf("Silinecek deger listede yok."); // "Silinecek deger listede yok. şeklinde yazdırıyorum.
                return head;
            }

            del->prev->next = del->next;     // bir önceki elemanın next ini bir sonraki elemana bağlamak için kullanıyorum.
            if (del->next != NULL)           // slinecek eleman eğer son eleman ise next i NULL olacağından prev ataması programda hataya neden olacaktır. Bunun için kontrol ediyorum.
                del->next->prev = del->prev; // silinecek elemandan sonraki elemanın prev ini silinecek elemandan bir önceki elemana bağlıyorum.
            free(del);                       // daha sonra silinecek elemanı siliyorum
            del = NULL;                      // bellek te herahangi bir sorun olmasın diye sildiğim yere NULL atıyorum.
        }
    }

    return head; // en son listenin başını dönüyorum.
}
// listemizdeki eleman sayısını yazdırmak için bir fonksiyon tanımlıyorum.
int count(struct node *head)
{
    int counter = 0; // sayacımı ayarlıyorum
    while (head != NULL)
    {
        counter++;         // her defasında 1 defa arttırıyorum
        head = head->next; // while döngüsünün ilerlemesi için her defasında listenin başını bir sonraki düğüme taşıyorum.En son null olduğunda sayma işlemi bitiyor.
    }
    return counter; // sayacimi geriye döndürüyorum.
}
// listeyi yazdırmak için fonksiyonumu yazıyorum.
void print(struct node *head)
{
    if (head == NULL)
    {
        printf("Liste Bos\n"); // eğer liste boş ise Liste Bos diye yazdırıyorum.
    }
    else
    {
        while (head != NULL)
        {
            printf("Node Adress : %p", head);        // eğer liste boş değil ise düğüm adresini yazdırıyorum.
            printf("Node Value : %d\n", head->data); // ve her bir liste elemanının değerini yazdırıyorum.
            head = head->next;                       // döngüyü ilerletmek için her defasında bir sonraki düğüme geçiyorum.
        }
    }
}
// listeyi tersten yazdırmak için rekürsif bir fonksiyon yazıyorum
void print_ters(struct node *head)
{
    if (head == NULL)
        return;             // eğer liste boş ise return değip herhangi bir işelm yaptırmıyorum.
    print_ters(head->next); // eğer liste boş değil ise her defasında head in next ini çağırıyorum.
    // en son head in next i null olduğunda geriye dönecek ve aşağıdaki yerden devam ederek listeyi tersten yazacağız.
    printf("/%d ", head->data);
}
// listeyi tersten yazdırmak için rekürsif olmayan bir fonksiyon yazıyorum
void print_ters2(struct node *head)
{
    struct node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    while (last->prev != NULL)
    {
        printf("/ %d ", last->data);
        last = last->prev;
        if (last->prev == NULL)
            printf("/ %d", last->data);
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
            printf("Number of elements in the list : %d\n", count(head));
            printf("Do you want to continue? Press 1 for yes. Hayir icin 0 i seciniz.");
            scanf("%d", &checkpoint);
            break;
            break;
        case 5:
            printf("List written backwards = ");
            print_ters2(head);
            printf("\nDo you want to continue? Press 1 for yes. Hayir icin 0 i seciniz.");
            scanf("%d", &checkpoint);
            break;
        case 6:
            printf("Enter the value you want to delete.");
            scanf("%d", &data);
            head = deletenode(head, data);
            break;
        case 7:

            break;
        default:
            break;
        }
    }
    return 0;
}
