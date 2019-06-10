#include<iostream>
#include"hashing.h"

using namespace std;

int main()
{
	hashtable<int> h(11);
	h.insert("apple",4);
	h.insert("mango",6);
	h.insert("guava",2);
	h.insert("melon",1);
	h.insert("papapya",9);
	h.insert("hello",9);
	h.print();
	cout<<endl;
	h["hel"];
	h["mango"];
	h.print();
	cout<<endl;
	for(auto node<int>:h)
	{
		cout<<node->key<<" ";
	}
}