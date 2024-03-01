#include <iostream>
using namespace std;
class Node {
public:
	int deger;
	Node* next;
	Node* prev;
	Node(int deger) {
		this->deger = deger;
		next = NULL;
		prev = NULL;
	}
};
class DoublyLinkedList {
private:
	Node* head;
	Node* tail;
	int count;

public:
	DoublyLinkedList(int deger) {
		Node* node = new Node(deger);
		head = node;
		tail = node;
		count = 1;
	}
	~DoublyLinkedList() {
		// Destructor(memory leak icin)
		Node* tmp = head;
		while (head) {
			head = head->next;
			delete tmp;
			tmp = head;
		}
	}
	void printlist() {
		Node* tmp = head;
		while (tmp != NULL) {
			cout << tmp->deger << " , ";
			tmp = tmp->next;
		}
		cout << endl;
	}
	void printhead() {
		if (head != NULL)
			cout << "Head: " << head->deger << endl;
	}
	void printtail() {
		if (tail != NULL)
			cout << "Tail: " << tail->deger << endl;
	}
	void getcount() {
		cout << "count: " << count << endl;
	}
	void appentlist(int deger) {
		Node* node = new Node(deger);
		if (count == 0) {
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
		count++;
	}
	void deletelastnode() {
		if (count == 0)
			return;
		Node* temp = tail;
		if (count != 1) {
			tail = tail->prev;
			tail->next = NULL;
		}
		else if (count == 1) {
			head = NULL;
			tail = NULL;
		}
		delete temp;
		count--;
	}
	void addfirstnode(int deger) {
		Node* newNode = new Node(deger);
		if (count == 0) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		count++;
	}
	void deletefirstnode() {
		if (count == 0) {
			return;
		}
		Node* temp = head;
		if (count == 1) {
			head = NULL;
			tail = NULL;
		}
		else {
			head = head->next;
			head->prev = NULL;
		}
		delete temp;
		count--;
	}
	Node* getnode(int index) {
		if (index < 0 || index >= count)
			return NULL;
		Node* temp = head;
		if (index < count / 2) {
			for (int i = 0; i < index; i++)
			{
				temp = temp->next;
			}
		}
		else {
			temp = tail;
			for (int i = count - 1; i > index; i--) {
				temp = temp->prev;
			}
		}

		return temp;
	}
	bool setnode(int i, int deger) {
		Node* tmp = getnode(i);
		if (tmp != NULL) {
			tmp->deger = deger;
			return true;
		}
		else {
			return false;
		}
	}
	bool insertnode(int index, int deger) {
		if (index < 0 || index > count)
			return false;
		if (index == 0) {
			addfirstnode(deger);
			return true;
		}
		if (index == count) {
			appentlist(deger);
			return true;
		}
		Node* yeninode = new Node(deger);

		Node* leftnode = getnode(index - 1);
		Node* rightnode = getnode(index);
		yeninode->next = rightnode;
		yeninode->prev = leftnode;
		leftnode->next = yeninode;
		rightnode->prev = yeninode;
		count++;
		return true;
	}
	void deletenode(int index) {
		if (index >= 0 && index < count) {
			if (index == 0)
				deletefirstnode();
			else if (index == count - 1)
				deletelastnode();
			else {
				Node* del = getnode(index);
				del->next->prev = del->prev;
				del->prev->next = del->next;
				delete del;
				count--;
			}

		}
	}

};
int main() {
	cout << "------------------------------" << endl;
	cout << "DoublyLinkedList" << endl;
	cout << "------------------------------" << endl;
	DoublyLinkedList* doublylinkedlist1 = new DoublyLinkedList(1);

	doublylinkedlist1->getcount();//1
	doublylinkedlist1->printhead();//1
	doublylinkedlist1->printtail();//1
	doublylinkedlist1->printlist();// 1
	cout << "------------------------------" << endl;
	cout << "Appenlist metodu ile deneme" << endl;
	cout << "------------------------------" << endl;
	doublylinkedlist1->appentlist(2);
	doublylinkedlist1->appentlist(3);
	doublylinkedlist1->appentlist(4);
	doublylinkedlist1->appentlist(5);
	doublylinkedlist1->getcount();//5
	doublylinkedlist1->printhead();//1
	doublylinkedlist1->printtail();//5
	doublylinkedlist1->printlist();// 1-2-3-4-5 
	cout << "------------------------------" << endl;
	cout << "deletelastnode metodu ile deneme" << endl;
	cout << "------------------------------" << endl;
	doublylinkedlist1->deletelastnode();
	doublylinkedlist1->getcount();//4
	doublylinkedlist1->printhead();//1
	doublylinkedlist1->printtail();//4
	doublylinkedlist1->printlist();// 1-2-3-4-
	cout << "------------------------------" << endl;
	cout << "addfirstnode metodu ile deneme" << endl;
	cout << "------------------------------" << endl;
	doublylinkedlist1->addfirstnode(0);
	doublylinkedlist1->getcount();//5
	doublylinkedlist1->printhead();//0
	doublylinkedlist1->printtail();//4
	doublylinkedlist1->printlist();// 0- 1-2-3-4-
	cout << "------------------------------" << endl;
	cout << "deletefirstnode metodu ile deneme" << endl;
	cout << "------------------------------" << endl;
	doublylinkedlist1->deletefirstnode();
	doublylinkedlist1->getcount();//4
	doublylinkedlist1->printhead();//1
	doublylinkedlist1->printtail();//4
	doublylinkedlist1->printlist();// 1-2-3-4-
	cout << "------------------------------" << endl;
	cout << "getnode metodu ile deneme" << endl;
	cout << "------------------------------" << endl;
	cout << doublylinkedlist1->getnode(2)->deger << endl;;
	cout << "------------------------------" << endl;
	cout << "setnode metodu ile deneme" << endl;
	cout << "------------------------------" << endl;
	doublylinkedlist1->setnode(0, 0);
	doublylinkedlist1->getcount();//5
	doublylinkedlist1->printhead();//0
	doublylinkedlist1->printtail();//4
	doublylinkedlist1->printlist();// 0-1-2-3-4-
	cout << "------------------------------" << endl;
	cout << "insert metodu ile deneme" << endl;
	cout << "------------------------------" << endl;
	doublylinkedlist1->insertnode(3, 55);
	doublylinkedlist1->insertnode(2, 44);
	doublylinkedlist1->getcount();//6
	doublylinkedlist1->printhead();//0
	doublylinkedlist1->printtail();//4
	doublylinkedlist1->printlist();// 0-1-44-55-2-3-4-
	cout << "------------------------------" << endl;
	cout << "index ile node silme metodu ile deneme" << endl;
	cout << "------------------------------" << endl;
	doublylinkedlist1->deletenode(3);
	doublylinkedlist1->deletenode(2);
	doublylinkedlist1->getcount();//4
	doublylinkedlist1->printhead();//0
	doublylinkedlist1->printtail();//4
	doublylinkedlist1->printlist();// 0-1-2-3-4-

}