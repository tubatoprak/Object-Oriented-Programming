#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList
{
	Node* head;
	LinkedList()
	{
		head = NULL;
	}
	void reverse();
	void print();
	void push(int data);
};

void LinkedList:: print()
{
	struct Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data <<" ";
		temp = temp->next;
	}
}
void LinkedList::push(int data)
{
	Node* temp = new Node(data);
	temp->next = head;
	head = temp;
}
void LinkedList:: reverse()
{
	Node* current = head;
	Node *prev = NULL, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

int main()
{
	LinkedList ll;
	ll.push(10);
	ll.push(20);
	ll.push(30);
	ll.push(40);
	
	cout << "List before reversing"<<endl;
	ll.print();
	ll.reverse();
	cout<<endl << "List after reversing"<<endl;
	ll.print();
	cout<<endl;
	return 0;
}
