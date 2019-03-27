/*
* Author : Muhammad Iqbal Alif Fadilla
* NPM : 140810180020
* Kelas : B
* Deskripsi : Exercise-01
* Tgl : 27 03 2019
*/

#include<iostream>
#include<iomanip>

using namespace std;

struct Pembalap {
	int nomor;
	char nama;
	int waktu;
	Pembalap* next;
	Pembalap* prev;
};

void createNode(Pembalap* &p, int nomor, char nama) {
	p = new Pembalap;
	p->nama = nama;
	p->nomor = nomor;
	p->waktu = 0;
	p->next = NULL;
	p->prev = NULL;
}
void insertFirst(Pembalap* &head, Pembalap* node) {
	if (head == NULL)
		head = node;
	else {
		node->next = head;
		head->prev = node;
		head = node;
	}
}

void insertBefore(Pembalap* &head, int nomorKey, Pembalap* node) {
	Pembalap* pBantu=head;
	if(head->nomor==nomorKey){
		node->next=head;
		head->prev=node;
		head=node;
	}else{
		while(pBantu!=NULL){
			if(pBantu->nomor==nomorKey){
				node->next=pBantu;
				node->prev=pBantu->prev;
				pBantu->prev->next=node;
				pBantu->prev=node;
				break;
			}else{
				pBantu=pBantu->next;
			}
		}
	}
}

void search(Pembalap* &firstNode, int nomorKey, Pembalap* &pToUpdate) {
	pToUpdate = firstNode;
    while(pToUpdate != NULL && pToUpdate->nomor != nomorKey)
        pToUpdate = pToUpdate->next;

    if(pToUpdate->next == NULL && pToUpdate->nomor != nomorKey)
    {
        puts("Target Not Found!");
        pToUpdate = NULL;
    }
}

void deleteByKey(Pembalap* &head, int nomorKey, Pembalap* &deletedNode){
	search(head, nomorKey, deletedNode);
    if(deletedNode == NULL) return;

    deletedNode->prev->next = deletedNode->next;
    deletedNode->next->prev = deletedNode->prev;

    delete deletedNode;
}


void traversal(Pembalap* head) {
	Pembalap* pBantu = head;
	if (pBantu == NULL) {
		cout << "***LIST KOSONG***\n";
	}
	else {
		while (pBantu != NULL) {
			cout << "Nomor: " << pBantu->nomor << endl;
			cout << "Nama: " << pBantu->nama << endl;
			cout << "Waktu: " << pBantu->waktu << endl;
			cout << endl;
			pBantu = pBantu->next;
		}
	}
}
// sorting ascending
void sortingByNomor(Pembalap* &head){
	int swapped;
    Pembalap *ptr1;
    Pembalap *lptr = NULL;

    if (head == NULL)
        return;

    do
		{
			swapped = 0;
			ptr1 = head;

			while (ptr1->next != lptr)
			{
				if (ptr1->nomor > ptr1->next->nomor)
				{
					swap(ptr1->nomor, ptr1->next->nomor);
					swap(ptr1->nama, ptr1->next->nama);
					swap(ptr1->waktu, ptr1->next->waktu);
					swapped = 1;
				}
				ptr1 = ptr1->next;
			}
			lptr = ptr1;
		} while (swapped);
	}
}
// update Pembalap from user input
void update(Pembalap* firstNode, int nomorKey){
	Pembalap* pCari;

    search(firstNode, nomorKey, pCari);
    if(pCari == NULL) return;

    cout << "Nama: ";
    cin >> pCari->nama;

    cout << "Nomor: ";
    cin >> pCari->nomor;

    cout << "Waktu: ";
    cin >> pCari->waktu;
}

int main() {
	Pembalap* head = NULL;
	Pembalap* pBaru = NULL;
	Pembalap* pToUpdate = NULL;
	char nama = 'a';

	for (int i = 0; i < 4; i++) {
		createNode(pBaru, i + 1, nama++);
		insertFirst(head, pBaru);
	}

	cout << "\n>>> List" << endl;
	traversal(head);

	int keyNomor = 2;

	cout << "\n>>> Insert Before nomor " << keyNomor << endl;
	createNode(pBaru, 99, 'z');
	insertBefore(head, keyNomor, pBaru);
	traversal(head);

	cout << "\n>>> SortingByNomor" << endl;
	sortingByNomor(head);
	traversal(head);

	keyNomor = 3;
	cout << "\n>>> Delete nomor " << keyNomor << endl;
	Pembalap* pHapus = NULL;
	deleteByKey(head, keyNomor, pHapus);
	traversal(head);

	keyNomor = 4;
	cout << "\n>>> Update nomor " << keyNomor << endl;
	update(head, keyNomor);

	cout << "\n>>> Updated list\n";
	traversal(head);

	return 0;
}