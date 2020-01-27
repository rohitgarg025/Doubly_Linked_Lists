#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node* prev;
	Node* next;
};

Node* head = NULL;
Node* tail = NULL;
int size = 0;

void push(int data){

	Node* temp = new Node();
	temp->data = data;

	if(head == NULL){
		head = temp;
		tail = temp;
		size++;
		return ;
	}

	tail->next = temp;
	temp->prev = tail;
	tail = temp;
	size++;

}

void insert(int data , int pos){

	Node* temp = new Node();
	temp->data = data;


	if(pos<0 || pos>=size)
		return ;

	//insert after start

	if(pos ==0){
		temp->prev = head;
		temp->next = head->next;
		(head->next)->prev = temp;
		head->next = temp;
		size++;
		return ;
	}

	//insert at end
	if(pos == size-1){

		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		size++;
		return;
	}

	//insert in middle

	Node * p = head;

	for(int i=0;i<=pos-1;i++){
		p = p->next;
	}

	temp->prev = p;
	temp->next = p->next;
	(p->next)->prev = temp;
	p->next = temp;

	size++;


}




void print_list(){

if(head == NULL){

	return ;
}
else{

	Node* p = head;

	while(p != NULL){

		cout << p->data << " " ;
		p = p->next;

	}

}




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

		int pos=0,val=0;
		cin >> pos >> val;
		insert(val,pos);

        print_list();



	return 0;
}
