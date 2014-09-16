#ifndef SCATTER_LINKEDLIST_H
#define SCATTER_LINKEDLIST_H


typedef char SCATTER_STATE;

const SCATTER_STATE SCATTER_FAIL    = 0;
const SCATTER_STATE SCATTER_SUCCESS = 1;

const SCATTER_STATE SCATTER_TRUE    = 1;
const SCATTER_STATE SCATTER_FASLE   = 0;


template<typename T>
class LinkList;

template<typename T>
class ListNode
{
	friend LinkList<T>;
public:	
	ListNode<T>() {}
	ListNode<T>(T d):data(d) {}
	T getData() const { return data; }
private:
	T data;
	ListNode* pNext;
};

template<typename T>
class LinkList
{
public:
	LinkList(ListNode<T>* head):m_head(head) {};
	LinkList(T a[], int n);
	~LinkList();

	ListNode<T>* getHead() const;
	int Length();
	void Reverse();

	void Insert(T data, int k, bool dir = true);

	ListNode<T>* Delete(int k, bool dir = true);

	ListNode<T>* Search(int k, bool dir = true);

	void PrintData();

private:
	ListNode<T>* m_head;
};

template<typename T>
LinkList<T>::LinkList(T a[], int n)
{
	ListNode<T>* last = NULL;
	for (int i = 0; i < n; i++)
	{
		ListNode<T>* node = new ListNode<T>;
		node->data = a[i];
		if (m_head) 
		{
			last->pNext = node;
			last = node;
		}
		else 
		{
			m_head = last = node;
		}
	}
	last->pNext = NULL;
}

template<typename T>
ListNode<T>* LinkList<T>::getHead() const 
{
	return m_head;
}

template<typename T>
void LinkList<T>::PrintData() 
{
	ListNode<T>* current = m_head;
	while (current != NULL) 
	{
		std::cout << current->data << " ";
		current = current->pNext;
	}
	std::cout << std::endl;
}

template<typename T>
int LinkList<T>::Length() 
{
	ListNode<T>* current = m_head;
	int len = 0;
	while (current != NULL) 
	{
		len++;
		current = current->pNext;
	}
	return len;
}

template<typename T>
void LinkList<T>::Reverse()
{
	ListNode<T>* pReverseNode = NULL;
	ListNode<T>* current = m_head;
	
	while (current != NULL)
	{
		ListNode<T>* temp = current;
		current = current->pNext;
		temp->pNext = pReverseNode;
		pReverseNode = temp;
	}
	m_head = pReverseNode;
}

template<typename T>
ListNode<T>* LinkList<T>::Search(int k, bool dir = true)
{
	if (k < 0)
		return NULL;
	if (dir) 
	{
		ListNode<T>* current = m_head;
		int index = 0;
		while (current != NULL)
		{
			if (index == k) 
			{
				return current;
			}
			else 
			{
				current = current->pNext;
				index++;
			}
		}
		return NULL;
	} 
	else 
	{
		ListNode<T>* first = m_head;
		ListNode<T>* second = m_head;
		while (k > 0 && first != NULL) 
		{
			first = first->pNext;
			k--;
		}
		while (first->pNext != NULL)
		{
			first = first->pNext;
			second = second->pNext;
		}
		return second;
	}
}

template<typename T>
void LinkList<T>::Insert(T data, int k, bool dir = true) 
{
	if (k < 0) 
		return;
	ListNode<T>* current = m_head;
	if (current == NULL)
	{
		ListNode<T>* node = new ListNode<T>(data);
		current->pNext = node;
		return;
	}
	int index = 0;
	while (current != NULL)
	{
		if (index == k)
		{
			
			ListNode<T>* node = new ListNode<T>(data);
			ListNode<T>* temp = current->pNext;
			current->pNext = node;
			node->pNext = temp;
			return;
		} 
		else 
		{
			index++;
			current = current->pNext;
		}	
	}
}

	

template<typename T>
ListNode<T>* LinkList<T>::Delete(int k, bool dir = true)
{
	if (k < 0 && m_head == NULL)
		return NULL;
	ListNode<T>* current = m_head;
	int index = 0;
	while (current != NULL)
	{
		if (index == k - 1)
		{
			
			ListNode<T>* node = current->pNext->pNext;
			current->pNext = node;
			//delete current->pNext;
			return current->pNext;
		}
		else 
		{
			index++;
			current = current->pNext;
		}
	}
}

#endif