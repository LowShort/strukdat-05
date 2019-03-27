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
		node->prev = node;
		head = node;
	}
}

void insertBefore(Pembalap* &head, int nomorKey, Pembalap* node) {
	pointer pBantu=head;
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

//void deleteByKey(Pembalap* &head, int nomorKey, Pembalap* &deletedNode);

void search(Pembalap* &firstNode, int nomorKey, Pembalap* &pToUpdate) {
	pToUpdate = firstNode;
	while (pToUpdate->nomor != nomorKey) {
		pToUpdate = pToUpdate->next;
	}
}
void traversal(Pembalap* head) {
	Pembalap* help;
	if (head == NULL) {
		cout << "***LIST KOSONG***\n";
	}
	else {
		help = head;
		while (help != NULL) {
			cout << "Nomor: " << help->nomor << endl;
			cout << "Nama: " << help->nama << endl;
			cout << "Waktu: " << help->waktu << endl;
			cout << endl;
			help = help->next;
		}
	}
}
// sorting ascending
void sortingByNomor(Pembalap* &head){
	pointer temp1, temp2;
	if(head==NULL){
		cout<<"List Kosong.";
	}else{
		pointer pBantu=head;
		while(pBantu!=NULL){
			if(pBantu->nomor>pBantu->next->nomor){
				if(pBantu->prev==NULL){
					temp1=pBantu->next->next;
					pBantu->next->next->prev=pBantu;
					pBantu->prev=pBantu->next;
					pBantu->next->prev=NULL;
					pBantu->next->next=pBantu;
					pBantu->next=temp1;
				}else if(pBantu->next==NULL){
					
				}else{
					pBantu->next->next->prev=pBantu; //1
					pBantu->prev->next=pBantu->next; //2
					pBantu->next=pBantu->next->next; //3
					pBantu->next->prev=pBantu->prev; //4
					pBantu->prev=pBantu->next; //5
					pBantu->prev->next=pBantu;
				}
			}
			pBantu=pBantu->next;
		}
	}
}
// update Pembalap from user input
//void update(Pembalap* firstNode, int nomorKey);

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

	/*cout << "\n>>> SortingByNomor" << endl;
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
	traversal(head);*/

	return 0;
}