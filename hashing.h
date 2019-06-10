#include<cstring>
using namespace std;

template<typename T>
class node{
public:
	string key;
	T value;
	node<T> *next;
	node(string k,T v)
	{
		key=k;
		value=v;
		next=NULL;
	}
	~node()
	{
		if(next!=NULL)
			delete next;
	}
};


template<typename T>
class hashtable{
	int cs;
	int ts;
	node<T>**buckets;

    void rehash()
    {
    	node<T>**oldbuckets=buckets;
    	int oldts=ts;
    	ts=ts*2;
    	cs=0;
    	buckets=new node<T>*[ts];
    	for(int i=0;i<ts;i++)
    	{
    		buckets[i]=NULL;
    	}

    	for(int i=0;i<oldts;i++)
    	{
    		node<T>*temp=oldbuckets[i];
    		while(temp!=NULL)
    		{
    			insert(temp->key,temp->value);
    			temp=temp->next;
    		}

    		delete oldbuckets[i];
    	}
    	delete [] oldbuckets;
    }
    
	int HashFn(string key)
	{
		int l=key.length();
		int ans=0;
		int p=1;

		for(int i=0;i<l;i++)
		{
			ans+=key[l-i-1]*p;

			p*=37;
			p%=ts;  //number wont get much big
			ans%=ts;
		}

		return ans;
	}

public:
	hashtable(int ds=7)
	{
		cs=0;
		ts=ds;
		buckets=new node<T>*[ts];

		for(int i=0;i<ts;i++)
		{
			buckets[i]=NULL;
		}
	}

	void insert(string k,int val)
	{
    ///funct find index where key value pair will be stored
		int i=HashFn(k);

		node<T>*n=new node<T>(k, val);
		n->next=buckets[i];
		buckets[i]=n;

		cs++;
		float load_factor=(float)cs/ts;
		if(load_factor>0.7)
		{
			cout<<"load_factor = "<<load_factor<<endl;
			rehash();
		}
	}

	void print()
	{
		for(int i=0;i<ts;i++)
		{
			node<T>*temp=buckets[i];
			cout<<"Bucket "<<i<<"->";
			while(temp!=NULL)
			{
				cout<<temp->key<<"->";
				temp=temp->next;
			}
			cout<<endl;
	    }
	}

	T* search(string key){
		int idx = HashFn(key);
		node<T>*temp = buckets[idx];
		while(temp!=NULL){
			if(temp->key ==key){
				return &temp->value;
			}
			temp= temp->next;
		}
		return NULL;
	}

	void erase(string key)
	{
		int idx=HashFn(key);
		node<T>*temp=buckets[idx];
			node<T>*prev=temp;
		if(temp->key==key)
		{
			buckets[idx]=temp->next;
			//delete temp;
			return;
		}
		else
		{
			temp=temp->next;
		}
		while(temp!=NULL)
		{
			if(temp->key==key)
			{
                prev->next=temp->next;
                //delete temp;
			}
			temp=temp->next;
			prev=prev->next;
		}
	}

	T&  operator[](string key)
	{
		T* val=search(key);
		if(val==NULL)
		{
			T obj;
			insert(key,obj);
			T* val=search(key);
			return *val;
		}
		return *val;
	}
};