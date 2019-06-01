#include<iostream>
#include<set>
using namespace std;


//set is a data structure whihc stores unique elements in sorted order
int main()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(3);
	s.insert(2);
	s.insert(5);
	s.insert(4);
	for(auto x:s) 
	//range based for loops
	//auto is used when you dont know datatype of x
	//int can also be used
	//when auto is used, variable should be initialized  
	{
		cout<<x<<" ";
	}

    //set, vector all these classes contain a subclass called iterator which acts like a pointer
	for(set<int>::iterator it=s.begin();it!=s.end();i++)
	{
		cout<<(*it)<<" ";
	}
}