#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


using namespace std;
struct dugum {

	int v;
	struct dugum *sol, *sag;
}*agac=NULL, *root=NULL, *yd=NULL, *lroot=NULL;

struct dugum * dugumal()
{
	yd = (struct dugum *)malloc(sizeof(struct dugum));
	yd->sol = NULL;
	yd->sag = NULL;
	return yd;
}



void ekle(int);
void gosterinorder(struct dugum *);
void gosterpostorder(struct dugum *);
void gosterpreorder(struct dugum *);


int height(struct dugum * d)
{
	
	if (d==NULL)
	return -1;
	else
	{
	int solh=height(d->sol);	
	int sagh=height(d->sag);
	
	if (solh>sagh)
		return solh+1;
		else
		return sagh+1;
	
	}

}

struct dugum* minbul(struct dugum* d)
{
    struct dugum* p = d;
 
    
    while (p && p->sol != NULL)
        p = p->sol;
 
    return p;
}

struct dugum* makbul(struct dugum* d)
{
    struct dugum* p = d;
 
    
    while (p && p->sag != NULL)
        p = p->sag;
 
    return p;
}
 

struct dugum* sil(struct dugum* root, int veri)
{
	

    if (root == NULL)         return root;
 

    if (veri < root->v)
	  root->sol = sil(root->sol, veri);
     else if (veri > root->v)
        root->sag = sil(root->sag, veri);
     else {//eþitse
        if (root->sol == NULL) {// tek sað çocuðu var
            struct dugum* temp = root->sag;
            free(root);
            return temp;
        }
        else if (root->sag == NULL) {// tek sol çocuk var
            struct dugum* temp = root->sol;
            free(root);
            return temp;
        }
 
        // 2 çocuk var
        // saðýn en küçüðü alýnacak
        struct dugum* temp = minbul(root->sag);
 
        root->v = temp->v;
 
        root->sag = sil(root->sag, temp->v);
    }
    return root;
}
 



struct dugum *ara(struct dugum *root, int veri) 
{ 
	if (root == NULL) return NULL;
   
    if (root->v == veri) 
       return root; 
     
  
    if (root->v < veri) 
       return ara(root->sag, veri); 
  
    else return ara(root->sol, veri); 
}

int main() {
	agac = NULL;
	char c='x';
	int sayi;
	while (c != 'e' || c != 'E') {

		cout <<endl<< "1. ekle" << endl; cout << "2. inorder" << endl; cout << "3. postorder" << endl; cout << "4. preorder"<< endl;cout <<"5. Yukseklik" <<endl; cout <<"6. Ara" <<endl;cout <<"7. Sil" <<endl;
		c = getchar();
		if (c == '1')
		{
			cout << endl << "Yeni Sayi Giriniz:";
			cin >> sayi;
			ekle(sayi);
			cout << endl ;
		}
		if (c == '2')
		{
			agac = root;
			cout << "----------"<<endl ;
			gosterinorder(agac);
		}
			if (c == '3')
		{
			agac = root;
			cout << "----------"<<endl ;
			gosterpostorder(agac);
		}
			if (c == '4')
		{
			agac = root;
			cout << "----------"<<endl ;
			gosterpreorder(agac);
		}
			if (c == '5')
		{
			agac = root;
		cout<<height(agac)<<"----"<<endl;
		}
		
		if (c == '6')
		{
			agac = root;
			cout << endl << "Yeni Sayi Giriniz:";
			cin >> sayi;
			yd=ara(agac,sayi);
		if (yd==NULL) cout<<"Aranýlan veri aðacta yok"<<endl;
		else 	cout<<yd<<"----"<<yd->v<<endl;
		}
		if (c == '7')
		{
			agac = root;
			cout << endl << "Yeni Sayi Giriniz:";
			cin >> sayi;
			yd=sil(agac,sayi);
		if (yd==NULL) cout<<"Aranýlan veri aðacta yok"<<endl;
		else 	cout<<yd<<"----"<<yd->v<<endl;
		}
		cout << endl<<"Cikmak istiyormusunuz-(e/h):";
		c = getchar();
	}

	return 0;

}

void ekle(int veri)
{
	agac = root;
	if (agac == NULL)
	{
		agac = dugumal();
		agac->v = veri;
		root = agac;
	}
	else
	{
		while (agac != NULL)
		{
			lroot = agac;//önceki düðüm parent düðüm
			if (veri < agac->v) 
			agac = agac->sol;
			else	
			agac = agac->sag;
		}
		if (veri < lroot->v)
		{
			lroot->sol = dugumal();
			lroot = lroot->sol;
			lroot->v = veri;
		}
		else
		{
			lroot->sag = dugumal();
			lroot = lroot->sag;
			lroot->v = veri;
		}


	}// else


}



void gosterinorder(struct dugum * a)
{
	if (a == NULL) return;
	else
	{
		gosterinorder(a->sol);
		cout << a->v << endl;
		gosterinorder(a->sag);
	}
}

void gosterpostorder(struct dugum * a)
{
	if (a == NULL) return;
	else
	{
		gosterpostorder(a->sol);
		gosterpostorder(a->sag);
		cout << a->v << endl;
	}
}
void gosterpreorder(struct dugum * a)
{
	if (a == NULL) return;
	else
	{
		cout << a->v << endl;
		gosterpreorder(a->sol);
		gosterpreorder(a->sag);
	}
}