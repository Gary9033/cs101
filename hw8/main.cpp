#include <iostream>

using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node(int n) {
			data = n;
			next = NULL;
		}
};

class LinkedList {
	private:
		Node* head;

	public:
		LinkedList() {
			head = NULL;
		}

		~LinkedList() {
			Node* p;
			while(head) {
				p = head;
				head = head -> next;
				cout << "free([" << p->data << "])->";
				delete p;
			}
			cout << "null" << endl;
		}

		void append_node(int new_data) {
			Node* new_node = new Node(new_data);
			if(!head) {
				head = new_node;
				cout << "[" << head->data << "]" << endl;
				return;
			}
			Node* list = head;
			while(list->next != NULL) {
				list = list->next;
			}
			list->next = new_node;

			Node* current = head;
			while(current != NULL) {
				cout << "[" << current->data <<"]->";
				current = current->next;
			}
			cout << "null" << endl;
		}

		void del_node(int n) {
			Node* temp = head;
			for(int i=0;i<n-1;i++){
            temp=temp->next;
            }
			Node* deleteNode = temp->next;
			temp->next = temp->next->next;
			deleteNode->next=NULL;
			delete deleteNode;

			Node* current = head;
			while(current != NULL) {
				cout << "[" << current->data <<"]->";
				current = current->next;
			}
			cout << "null" << endl;
		}

};

int main() {
	LinkedList mylink;
	mylink.append_node(0);
	mylink.append_node(1);
	mylink.append_node(2);
	mylink.append_node(3);
	mylink.del_node(1);
	return 0;
}
