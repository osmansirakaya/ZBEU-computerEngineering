#include<stdio.h>
#include<stdlib.h>
 
//�kili arama a�ac� d���m yap�s� a�a��daki �ekildedir.
//key de�eri d���m�n alaca�� de�erdir.
//Her d���m�n 2 �ocu�u olabilece�i i�in left ve right i�aret�ilerini alm��t�r
struct node
{
    int key;
    struct node *left, *right;
};
   
// Bu fonksiyon verilen de�erde d���m olu�turur.
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    //Her yeni eklenen d���m leaf durumunda oldu�undan sol ve sa� i�aret�iler null de�erini g�sterir
    temp->left = temp->right = NULL;
    return temp;
}
   
//BST'yi traverse eden fonksiyon
//�zyinelemelidir.
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
   
// ekleme yapan esas fonksiyonumuz bu
struct node* insert(struct node* node, int key)
{
    /* E�er d���m NULL ise do�ru konum demektir ve insert i�lemi burada yap�l�r */
    if (node == NULL) return newNode(key);
  
    /* NULL de�eri bulunamad�ysa a�a��daki k�s�m �al���r */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
  
    /* de�i�tirilmemi� d���m� return eder */
    return node;
}
   
// test etme k�sm� istedi�iniz gibi de�erileri de�i�tirebilirsiniz
int main()
{
    /* a�a��daki a�a� yap�s�n� olu�tural�m
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
   
    // A�ac� yazd�r�yoruz
    inorder(root);
   
    return 0;
}
