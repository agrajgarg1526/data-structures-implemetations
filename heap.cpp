#include<iostream>
#include<vector>
using namespace std;
class Heap{

	vector<int> v;
	bool minH;

	bool cmp(int a,int b){
		if(minH)
			return a>b;
		else
			return b>a;
	}
	void heapify(int i){
		int left = 2*i;;
		int right = 2*i+1;

		int ptr = i;
		if(left<v.size() and cmp(v[i],v[left])){
			ptr = left;
		}
		if(right<v.size() and cmp(v[ptr],v[right])){
			ptr = right;
		}

		if(i!=ptr){
			swap(v[ptr],v[i]);
			heapify(ptr);
		}
	}

public:
	Heap(bool mH=true){
		//Block 0th position
		v.push_back(-1);
		minH = mH;
	}
	void push(int d){

		v.push_back(d);
		int idx = v.size() -1;

		while(idx>1){
			int parent = idx/2;
			if(cmp(v[parent],v[idx])){
				swap(v[parent],v[idx]);
				idx = parent;
			}
			else{
				break;
			}
		}
	}

	void pop(){
		//Swap first and the last element
		int last = v.size()-1;
		swap(v[1],v[last]);
		v.pop_back();
		heapify(1);
	}

	bool empty(){
		return v.size()==1;
	}
	int top(){
		return v[1];
	}
};

int main()
{
    Heap h(false);
    h.push(5);
    h.push(15);
    h.push(2);
    h.push(20);
    h.push(3);
    while(!h.empty())
    {
        cout<<h.top()<<endl;
        h.pop();
    }

}