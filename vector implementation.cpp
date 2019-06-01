#include<iostream>
using namespace std;


class vector {

private:
	int cs;
	int ms;
	int *arr;
public:

	vector(int ms = 4)
	{
		cs = 0;
		this->ms = ms;
		arr = new int[ms];
	}
	void push_back(int data)
	{
		if (cs == ms)
		{
			int *oldarr = arr;
			//doubling array size
			ms = 2 * ms;
			arr = new int[ms];

			//copying into new array
			for (int i = 0; i < cs; i++)
			{
				arr[i] = oldarr[i];
			}

			//delete old array
			delete [] oldarr;
		}
		arr[cs] = data;
		cs++;

	}

	int getsize()
	{
		return cs;
	}

	int getmaxsize()
	{
		return ms;
	}
	void pop_back()
	{
		if(cs!=0);
       cs--;
	}
	void print()
	{
		for(int i=0;i<cs;i++)
		{
			cout<<arr[i]<<" ";
		}
	}

	int at(int i)
	{
		return arr[i];
	}

    int & operator[](int i)  //returning by reference ie.the box itself whose value can be changed in main
    {
        return arr[i];
    }
};

ostream & operator<<(ostream&os,vector v)
{
	v.print();
    return os;
}
int main()
{
     vector v;
     for(int i=0;i<10;i++)
     {
     	v.push_back(i*i);
     }
     v.print();
     v.getmaxsize();
     v.getsize();
     cout<<v[2];
     cout<<v;
     v[2]=0;//actual box was return and changed
     cout<<v[2];
}