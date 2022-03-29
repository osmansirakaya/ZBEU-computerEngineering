#include<stdio.h>
#include<stdlib.h>
 
//Ýkili arama aðacý düðüm yapýsý aþaðýdaki þekildedir.
//key deðeri düðümün alacaðý deðerdir.
//Her düðümün 2 çocuðu olabileceði için left ve right iþaretçilerini almýþtýr
struct node
{
    int key;
    struct node *left, *right;
};
   
// Bu fonksiyon verilen deðerde düðüm oluþturur.
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    //Her yeni eklenen düðüm leaf durumunda olduðundan sol ve sað iþaretçiler null deðerini gösterir
    temp->left = temp->right = NULL;
    return temp;
}
   
//BST'yi traverse eden fonksiyon
//özyinelemelidir.
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
    /* Eðer düðüm NULL ise doðru konum demektir ve insert iþlemi burada yapýlýr */
    if (node == NULL) return newNode(key);
  
    /* NULL deðeri bulunamadýysa aþaðýdaki kýsým çalýþýr */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
  
    /* deðiþtirilmemiþ düðümü return eder */
    return node;
}
   
// test etme kýsmý istediðiniz gibi deðerileri deðiþtirebilirsiniz
int main()
{
    /* aþaðýdaki aðaç yapýsýný oluþturalým
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
   
    // Aðacý yazdýrýyoruz
    inorder(root);
   
    return 0;
}
