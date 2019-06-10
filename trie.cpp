#include<iostream>
#include<unordered_map>
using namespace std;

class node{
public:
	char data;
	unordered_map<char,node*> h;
	bool isterminal;
	node(char d)
	{
		data=d;
		isterminal=false;
	}
};

class trie{
	node*root;
public:
	trie()
	{
		root=new node('\0');
	}

	void insert(char*word)
	{
		node*temp=root;
		for(int i=0;word[i]!='\0';i++)
		{
			char ch=word[i];
			if(temp->h.count(ch)==0)
			{
				node*n=new node(ch);
				temp->h[ch]=n;
				temp=n;
			}

			else
			{
				temp=temp->h[ch];
			}
		}
		temp->isterminal=true;
	}
    
    bool search(char *word){
		node*temp = root;
		
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];

			if(temp->h.count(ch)==0){
				return false;
			}
			temp = temp->h[ch];
		}
		return temp->isterminal;
	}
};


int main()
{
    char words[][10] = {"india","indian","no","news"};
	char w[10];
	cin>>w;

	trie t;
	for(int i=0;i<4;i++){
		t.insert(words[i]);
	}

	if(t.search(w)){
		cout<<w<<" ~ FOUND!";
	}
	else{
		cout<<w<<" NOT FOUND";
	}

	return 0;
}