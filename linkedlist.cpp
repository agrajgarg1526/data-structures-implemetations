#include<iostream>
using namespace std;

class node {
public:
	int data;
	node*next;

	node(int d)
	{
		data = d;
		next = NULL;
	}
};

int length(node*head)
{
	int l = 0;
	while (head != NULL)
	{
		head = head->next;
		l++;
	}
	return l;
}
void insertathead(node*&head, int d)
{
	node*n = new node(d);
	n->next = head;
	head = n;
}

void insertattail(node*&head, int d)
{
	if (head == NULL)
	{
		insertathead(head, d);
		return;
	}
	node*n = new node(d);
	node*temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
}

void insertatmiddle(node*&head, int d, int pos)
{
	if (head == NULL or pos == 0)
	{
		insertathead(head, d);
		return;
	}

	else if (pos > length(head))
	{
		insertattail(head, d);
		return;
	}
	node*n = new node(d);
	node*temp = head;
	for (int i = 0; i < pos - 1; i++)
	{
		temp = temp->next;
	}
	n->next = temp->next;
	temp->next = n;
}

void deleteathead(node*&head)
{
	if (head == NULL)
		return;

	node*temp = head;
	head = head->next;
	delete temp;
}

void deleteattail(node*&head)
{
	if (head == NULL)
	{
		return;
	}
	node*temp2 = head;
	while (temp2->next->next != NULL)
	{
		temp2 = temp2->next;
	}

	node*temp = temp2->next;
	temp2->next = NULL;
	delete temp;
}

void deleteatmiddle(node*&head, int pos)
{
	if (head == NULL)
		return;

	else if (pos == 0)
	{
		deleteathead(head);
		return;
	}
	else if (pos > length(head))
	{
		deleteattail(head);
		return;
	}
	node*temp = head;
	for (int i = 0; i < pos - 1; i++)
	{
		temp = temp->next;
	}
	node*del = temp->next;
	temp->next = del->next;
	delete del;

}

bool searchrecursive(node*head, int key)
{
	if (head == NULL)
		return false;
	if (head->data == key)
		return true;
	return searchrecursive(head->next, key);
}

void buildlist(node*&head)
{
	int d;
	cin >> d;
	while (d != -1)
	{
		insertattail(head, d);
		cin >> d;
	}
	return;
}
void print(node*head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

void reverse(node*&head)
{
	node*p = NULL;
	node*c = head;
	node*n = head->next;
	while (c != NULL)
	{
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	head = p;
}

node* recursivereverse(node*head)
{
	if (head->next == NULL)
	{
		return head;
	}
	node*newhead = recursivereverse(head->next);
	node*c = head;
	c->next->next = c;
	c->next = NULL;
	return newhead;

}

node*midpoint(node*head)
{
	
	node*slow = head;
	node*fast = head->next;
	while (fast != NULL and fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

node*kthnodefromlast(node*head, int k)
{
	node*slow = head;
	node*fast = head;
	while (k--)
	{
		fast = fast->next;
	}
	while (fast != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;

}

node*merge2sortedlist(node*head1, node* head2)
{
	if (head1 == NULL)
	{
		return head2;
	}
	if (head2 == NULL)
	{
		return head1;
	}
	node*head;
	if (head1->data < head2->data)
	{
        head=head1;
		head->next = merge2sortedlist(head1->next, head2);
	}
	else
	{
		head=head2;
		head ->next= merge2sortedlist(head1, head2->next);
	}
		return head;

}

node* mergesort(node*head)
{
	if(head->next==NULL or head==NULL)
       return head;
    
    node*mid=midpoint(head);
    
    node*a=head;
    node*b=mid->next;
    mid->next=NULL;

    a=mergesort(a);
    b=mergesort(b);

    node*newhead = merge2sortedlist(a,b);
    return newhead;

}

void floyd_cycle(node*head){

	node* slow = head;
	node*fast = head;

	while(fast!=NULL and fast->next!=NULL){
		
		fast = fast->next->next;
		slow = slow->next;

		if(fast==slow){
			
			cout<<"First meeting "<<slow->data<<endl;
			slow = head;
			break;
		}
	}
	
	while(slow!=fast){
		slow = slow->next;
		fast = fast->next;
	}

	cout<<"Meeting point is "<<slow->data<<" ";

}

istream &operator >>(istream&is, node*&head)
{
	buildlist(head);
	return is;
}

ostream &operator <<(ostream&os, node*&head)
{
	print(head);
	return os;
}
int main()
{
	node*head=NULL;
	cin>>head;
	node*t=head;
	while(t->next!=NULL)
		t=t->next;
	t->next=head->next->next;

	floyd_cycle(head);
}