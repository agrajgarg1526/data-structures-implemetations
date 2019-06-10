#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node*next;

	node(int d)
	{
		data = d;
	}
};

void insertathead(node*&head, int data)
{
	node*n = new node(data);       //new node
	node*temp = head;
	if (head != NULL)
	{
		n->next = head;                //new node ke next mein head
		while (temp->next != head)
		{
			temp = temp->next;          //jab tak temp ke next mein vaapas head nahi mil jata
		}
		temp->next = n;                 //jis node ke next mein head mila, uske next mein new node daal di
	}

	else
	{
		n->next = n;                    //agar head NULL hai toh new node ke next mein khud ko hi daal diya
	}
	head = n;                         //new node ko head kr diya
}

node*getnode(node*head, int data)
{
	node*temp = head;
	while (temp->next != head)
	{
		if (temp->data == data)
			return temp;
		temp = temp->next;
	}
	if (temp->data == data)
		return temp;
	return NULL;
}

void deletenode(node*&head, int data)
{
	node*del = getnode(head, data);
	if (del == NULL)
	{
		cout << "NODE NOT PRESENT" << endl;
		return;
	}

	if(del==head)
	{
        head=head->next;
        node*temp=head;
        while(temp->next!=del)
        {
        	temp=temp->next;
        }
        temp->next=head;
        delete del;
    }

    else
    {
    	node*temp=head;
    	while(temp->next!=del)
    	{
    		temp=temp->next;
    	}
    	temp->next=del->next;
    	delete del;
    }
}

void print(node*head)
{
	node*temp = head;
	while (temp->next != head)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data;             //last nonde will not get printed in loop, so it is printed here
}

int main()
{
	node*head = NULL;
	insertathead(head, 1);
	insertathead(head, 2);
	insertathead(head, 3);
	insertathead(head, 4);
	insertathead(head, 5);
	insertathead(head, 6);
	insertathead(head, 7);
	insertathead(head, 8);
	print(head);
	deletenode(head,1);
	cout<<endl;
    print(head);
}