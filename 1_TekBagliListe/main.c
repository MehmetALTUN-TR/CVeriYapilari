#include <stdio.h>
#include <stdlib.h>
// tek bağlı doğrusal liste uygulaması
// Bir düğüm yapısı oluşturuyoruz
struct node
{
       int data;          // düğümün içerisindeki değer.
       struct node *next; // düğümün bir sonraki bağlı olduğu bellek adresini gösterecek.
};
// listemizin başına eleman eklemek istediğimizde kullanacağımız fonksiyon.
struct node *addfront(struct node *head, int key)
{
       struct node *temp = (struct node *)malloc(sizeof(struct node)); // bellek te struct node türünde bir alan açıyorum bu alanı listeme eklemek isteyeceğim
       temp->data = key;                                               // temp in datasına eklemek istediğim değer olan key i atıyorum.
       temp->next = head;                                              // temp başa ekleneceği için temp in next i bir önceki listenin başı olan head olması lazım.
       head = temp;                                                    // daha sonra listenin başını temp olarak güncelliyorum.
       return temp;                                                    // son olarak temp i geri dönüyrum yani listenin başını head i de geri dönebilirdik aynı şey olurdu.
};
// listemizin sonuna eleman eklemek için fonksiyonumuzu yazıyoruz.
struct node *addlast(struct node *head, int key)
{
       struct node *temp = (struct node *)malloc(sizeof(struct node)); // bellek te struct node türünde bir alan açıyorum bu alanı listeme eklemek isteyeceğim.
       temp->data = key;                                               // temp in datasına eklemek istediğim değer olan key i atıyorum.
       temp->next = NULL;                                              // temp son eleman olacağı için temp in next ine null atıyorum.
       if (head == NULL)
       {
              head = temp; // eğer liste boş ise listenin başını head olarak güncelliyorum ve tek elemanlı bir liste olmuş oluyor.
       }
       else
       {
              struct node *last = head;  // son elemanı bulmak için last adında geçici bir alan oluşturuyorum ve bunun listenin başını tutmasını istiyorum.
              while (last->next != NULL) // listenin sonunu bulmak için while döngüsü yazıyorum.
              {
                     last = last->next; // eğer last ın next i null değilse sürekli lastı bir adım ileri taşıyorum ta ki null olana kadar.
              }
              last->next = temp; // artık listenin sonunu bulduğuma göre last ın next ini eklemek istediğim değere bağlıyorum.
       }
       return head; // en son return head diyerek listemin başını geri dönüyorum.
};
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
// listeyi tersten yazdırmak için rekürsif bir fonksiyon yazıyorum
void print_ters(struct node *head)
{
       if (head == NULL)
              return;          // eğer liste boş ise return değip herhangi bir işelm yaptırmıyorum.
       print_ters(head->next); // eğer liste boş değil ise her defasında head in next ini çağırıyorum.
       // en son head in next i null olduğunda geriye dönecek ve aşağıdaki yerden devam ederek listeyi tersten yazacağız.
       printf("%d", head->data);
}
// listeden girilen bir değeri silen fonksiyonu yazıyorum
struct node *deletenode(struct node *head, int key)
{
       if (head == NULL)
       {
              printf("Liste bos"); // eğer liste boş ise liste boş diye yazdırıyorum.
              return head;
       }
       else
       {
              struct node *temp = head; // listenin başını temp de tutuyorum
              if (head->data == key)    // eğer silinecek eleman ilk eleman ise onu direk siliyorum
              {
                     head = temp->next;
                     free(temp);
                     return head;
              }
              else // eğer silinecek eleman ilk eleman değil ise onu liste içerisinde arıyıp siliyorum.
              {
                     while (temp->next != NULL && temp->next->data != key) // aramak için kullandığım temp in next değeri null değil ve temp in next inin datası aramak
                     {                                                     // istediğim değer eşit değil ise aramaya devam ediyorum.
                            temp = temp->next;                             // her defasında temp i bir sonraki düğüme taşıyorum.
                     }
                     if (temp->next == NULL) // eğer aradığım değer listede yoksa aradığınız deger listede yok diye geri bildirim yapıyorum.
                     {
                            printf("Aradiginiz Deger Listede Yok");
                            return head;
                     }

                     struct node *del = temp->next; // yukarda ki işlemleri geçip buraya gelirse temp artık silincek elemandan bir önceki elemanda duracak
                     temp->next = del->next;        // artık silinecek elemandan bir öncesi ve bir sonrasını bir birine bağlıyorum.
                     free(del);                     // daha sonra silinecek elemanı siliyorum
                     del = NULL;                    // bellek te herahngi bir sorun olmasın diye sildiğim yere NULL atıyorum.
                     return head;                   // listenin başını geri dönüyorum.
              }
       }
}
// tüm listeyi recursive olarak silen metodu yazalım
struct node *deleteAllNode(struct node *head) // silinecek listeyi parametre olarak alıyorum.
{
       if (head == NULL) // Eğer listenin ilk terimi NULL ise yanı liste boş ise listenin başını geriye dönüyorum.
       {
              return head;
       }
       else
       {
              deleteAllNode(head->next); // Liste boş değil ise listenin sonuna gidebilmek için head in next ini tekrar tekrar çağırıyorum.
              free(head);                // Listenin sonuna gelindiğinde head in next i NULL değeri üretecek ve bu sefer if in içerisine girip
              head = NULL;               // head değerini geri döndürüyorum ve dönene bu değer listenin son elemanı olacağı için onu siliyorum.
              return head;               // daha sonra bellek te kalıntı kalmasın diye sildiğim head değeri yerine NULL atıyorum.
                           // bu işlem sırayla gerçekleştikçe listedeki tüm elemanları siliyorum.
                           // En son return head içerisinde NULL değeri geriye dönüyor ve fonksiyon bitiyor.
       }
}
// tümlistenin elemanlarını silmek için daha kısa olan 2. bir metot yazalım
struct node *destroy_rec(struct node *head)      // silinecek listeyi parametre olarak alıyorum.
{
       if (head != NULL)    //listenin ilk elemanı eğer boş değil ise 
       {
              destroy_rec(head->next);    //Metoduma head in next ini gönderiyorum. Bu sayde listenin sonuna gidiyorum
              free(head);                 //Listenin son elanına ulaştığımda geriye return NULL dönüyor ve geriye doğru işlem başlıyor.
                                          //free komutumla geri geldikçe her bir düğümü siliyorum.
              head = NULL;                //daha sonra bellek te kalıntı kalmasın diye sildiğim head değeri yerine NULL atıyorum.

       }
       return NULL;
}

int main(int argc, char *argv[])
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
              case 5:
                     printf("List written backwards = ");
                     print_ters(head);
                     printf("\nDo you want to continue? Press 1 for yes. Hayir icin 0 i seciniz.");
                     scanf("%d", &checkpoint);
                     break;
              case 6:
                     printf("Enter the value you want to delete.");
                     scanf("%d", &data);
                     head = deletenode(head, data);
                     break;
              case 7:
                     head = destroy_rec(head);
                     break;
              default:
                     break;
              }
       }

       return 0;
}
