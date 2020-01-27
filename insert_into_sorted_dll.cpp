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

void insert_node(int data){


	Node* temp = new Node();
	temp->data = data;

	if((temp->data) <= (head->data)){

		temp->next = head;
		head->prev = temp;
		head = temp;
		size++;
		return ;
	}

	Node* p = head;

	while(p->next != NULL){
		p = p->next;

		//Now check if the element is smaller than the pth element . if yes then insert before p;

		if(temp->data <=(p->data)){
			temp->prev = (p->prev);
			temp->next = p;
			(p->prev)->next = temp;
			p->prev = temp;
			size++;
			return ;
		}
	}

	//now since both conditions have been checked hence, insert at end

	tail->next = temp;
	temp->prev = tail;
	tail = temp;
	size++;
	return ;




}

void print_list(){
	Node* p = head;

	while(p != NULL){

		cout << (p->data) << " ";
		p = p->next;
	}
}

int main(){

	int n;
	cout << "Enter the number of nodes" << endl;
	cin >> n;

	for(int i=0;i<n;i++){

		int data;
		cin >> data;
		push(data);


	}

	print_list();

	 int val;
	cin >> val;

	insert_node(val);

	print_list();
	return 0;
}
