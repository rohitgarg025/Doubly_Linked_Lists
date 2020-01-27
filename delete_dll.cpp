#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* head;
Node* tail;
int size=0;

void push(int data){

	Node* temp = new Node();
	temp->data = data;

	if(head == NULL){
		head= temp;
		tail= temp;
		size++;
		return ;
	}

	tail->next = temp;
	temp->prev = tail;
	tail = temp;
	size++;
	return ;

}


void delete_node(int pos){

	if(pos==0){

		Node* del = head;
		head = head->next;
		free(del);
		size--;
		return ;
	}

	if(pos == size-1){

		Node* del = tail;
		tail = tail->prev;
		free(del);
		size--;
		return ;
	}

	Node* p = head;

	for(int i=0;i<pos;i++){
		p = p->next;
	}

	Node* del = p;
	(p->prev)->next = p->next;
	(p->next)->prev = p->prev;
	free(del);
	size--;
	return;
}


void print_list(){
	Node* p = head;

	while(p != NULL){

		cout << p->data << " ";
		p = p->next;
	}

}
int main(){

	int n;
	cout << "Enter the number of Nodes" << endl;
	cin >> n;

	for(int i=0;i<n;i++){

		int data;
		cin >> data;
		push(data);

	}

	print_list();

	int pos ;
	cin >> pos;
	delete_node(pos);

	print_list();

	return 0;
}
