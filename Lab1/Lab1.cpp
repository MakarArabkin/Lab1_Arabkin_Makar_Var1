#include <iostream>
using namespace std;

class List
{
public:

	List();//Сonstructor
	~List();//Destructor
	bool isEmpty();//Checking the list for emptiness
	int GetSize(); //Method that returns the size of the list
	void push_back(int data_);// Inserting an element at the end of the list
	void push_front(int data_);//Inserting an element to the top of the list
	void pop_front();//Deleting the first element
	void pop_back();//Deleting the last element
	void remove(int index);//Deleting an element with the specified index
	void insert(int index, int data_);//Inserting a new element into the list before the specified one
	void set(int index, int data_);//Replacing an element by index with the transmitted element
	void clear();//Deleting all list elements
	int at(int index);//Getting an element by index
	void push_front(const List& data_);
	friend ostream& operator<< (ostream& out, const List& data_);//Operator overload <<

private:
	class Node//Node Implementation
	{
	public:
		int data;
		Node* pNext;
		Node(int data_, Node* pNext_ = nullptr)
		{
			data = data_;
			pNext = pNext_;
		}
	};
	int Size;
	Node* head;
};
List::List()
{
	Size = 0;
	head = nullptr;
}

List::~List()
{
	clear();
}

bool List::isEmpty()//Implementation of the void check
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int List::GetSize()//Implementing list size return
{
	return Size;
}
void List::push_back(int data_)//Implementation of inserting an element to the end of the list
{
	if (isEmpty())
	{
		head = new Node(data_);
	}
	else
	{
		Node* p = head;
		while (p->pNext != nullptr)
		{
			p = p->pNext;
		}
		p->pNext = new Node(data_);
	}
	Size++;
}
void List::push_front(int data_)//Implementation of inserting an element to the top of the list
{
	if (isEmpty())
	{
		head = new Node(data_);
	}
	else
	{
		Node* temp = new Node(data_);
		temp->pNext = head;
		head = temp;
	}
	Size++;
}
void List::pop_front()//Implementation of deleting the first element of the list
{
	if (isEmpty()) return;
	else
	{
		Node* p = head;
		head = p->pNext;
		delete p;
		Size--;
	}
}
void List::pop_back()//Implementation of deleting the last list element
{
	if (isEmpty()) return;
	Node* p = head;
	if (p->pNext == nullptr)
	{
		head = p->pNext;
		delete p;
		Size--;
		return;
	}
	while (p != nullptr)
	{
		p = p->pNext;
	}
	delete p;
	Size--;
}
void List::remove(int index)//Implementation of deleting a given list element
{
	if (isEmpty() || index >= Size || index < 0)
	{
		cout << "Invalid index value\n";
		return;
	}
	else
	{
		Node* p = head;
		if (index == 0)
		{
			this->pop_front();
			return;
		}
		int i = 0;
		while (i < Size)
		{
			if (i == index - 1)
			{
				Node* temp = p->pNext;
				p->pNext = temp->pNext;
				delete temp;
				Size--;
				return;
			}
			else
			{
				p = p->pNext;
				i++;
			}
		}

	}
}
void List::insert(int index, int data_)//Implementation of element insertion
{
	if (isEmpty() || index >= Size || index < 0)
	{
		cout << "Invalid index value\n";
		return;
	}
	else
	{
		int i = 0;
		Node* p = head;
		if (index == 0)this->push_front(data_);
		else
		{
			while (i == index - 2)
			{
				p = p->pNext;
				i++;
			}
			Node* temp = new Node(data_);
			temp->pNext = p->pNext;
			p->pNext = temp;
			Size++;
		}

	}
}
void List::set(int index, int data_)//Implementation of replacing an element by an index with a transmitted element
{
	if (isEmpty() || index >= Size || index < 0)
	{
		cout << "Invalid index value\n";
		return;
	}
	else
	{

		int i = 0;
		Node* p = head;
		while (p != nullptr)
		{
			if (i == index)
			{
				p->data = data_;
				return;
			}
			else
			{
				p = p->pNext;
				i++;
			}
		}
	}
}

void List::clear()//Implementation of deleting all list elements
{
	if (isEmpty()) return;
	else
	{
		Node* p = head;
		while (p != nullptr)
		{
			head = p->pNext;
			delete p;
			p = head;
		}
		Size = 0;
	}
}
int List::at(int index)//Implementation of returning the value of an element by index
{
	int i = 0;
	Node* p = head;
	try
	{
		if (index >= Size || index < 0)throw - 1;
		while (p != nullptr)
		{
			if (i == index) return p->data;
			else
			{
				p = p->pNext;
				i++;
			}
		}
	}
	catch (int)
	{
		cerr << "Invalid index value\n";
		return -1;
	}
}

void List::push_front(const List& data_) //Inserting a list at the begginnig of another
{
	Node* p_dop = data_.head;
	for(int i = 0; i < data_.Size; i++)
	{	
		this->insert(i,p_dop->data);
		p_dop = p_dop->pNext;
	}
}
ostream& operator<<(ostream& out, const List& data_)//Implementation of operator overload <<
{
	List::Node* p = data_.head;
	int N_element = 0;
	while (N_element < data_.Size)
	{
		out << N_element << " - element " << p->data << endl;
		p = p->pNext;
		N_element++;
	}
	return out;
}
int main()
{
	cout << "Create a list, then add two or three elements to the end of the list\n";
	List lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	cout << lst;
	cout << "Get the size of this list: " << lst.GetSize() << endl;
	cout << "Insert an element at the top of the list\n";
	lst.push_front(4);
	cout << lst;
	cout << "Checking for an empty list: " << lst.isEmpty() << endl;
	cout << "Delete the first element\n";
	lst.pop_front();
	cout << lst;
	cout << "Delete the last element\n";
	lst.pop_back();
	cout << lst;
	cout << "Let's try to insert an element with an invalid index\n";
	lst.insert(-1, 100);
	cout << "Let's try to insert an element before the second element\n";
	lst.insert(1, 100);
	cout << lst;
	cout << "Let's try to remove an element with an invalid index\n";
	lst.remove(5);
	cout << "Let's try to remove the second element\n";
	lst.remove(1);
	cout << lst;
	cout << "Change the value of the first element\n";
	lst.set(0, 100);
	cout << lst;
	cout << "Let's get the value of the second element: " << lst.at(1) << endl;
	cout << "Completely cleaning up the list\n";
	lst.clear();
	cout << "Let's insert one list into another\n";
	List lst2;
	lst.push_back(6);
	lst.push_back(6);
	lst.push_back(6);
	lst2.push_back(1);
	lst2.push_back(2);
	lst2.push_back(3);
	lst.push_front(lst2);
	cout << lst;
}