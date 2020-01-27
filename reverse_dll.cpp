#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* head = NULL;
Node* tail = NULL;
int size=0;

void print_list(){
if(head == NULL)
	return ;

Node* p = head;

while(p!=NULL){
	cout << p->data << " ";
	p = p->next;
}


}


void push(int data){
	Node *temp = new Node();
	temp->data = data;

	if(head == NULL){
		head = temp;
		tail = temp;
		size++;
		return ;
	}

	tail->next  = temp;
	temp->prev = tail;
	tail = temp;
	size++;
	return ;
}

void reverse_dll(){

Node* temp = NULL;
Node* p =head;

while(p != NULL){

	temp = p->prev;
	p->prev = p->next;
	p->next = temp;

	p = p->prev;
}

	tail = head;
		if(temp != NULL)
		head= temp->prev;
}


int main(){

int n;
		cout << "Enter number of nodes" << endl;
		cin >> n;

		for(int i=0;i<n;i++){

			int data;
			cin >> data;
			push(data);

		}

		print_list();
		cout << endl;

		reverse_dll();

		print_list();
		cout << endl;

}
