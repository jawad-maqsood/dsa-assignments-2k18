#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

struct v
{
	char ch[50];
	int integer[50];
};

template <class T>
	class Stack
	{
	public:

		//constructor
		Stack(const int MAX_SIZE = 5) : MAX_SIZE(MAX_SIZE)
		{
			top = -1;
			data = new T[MAX_SIZE];
		}


		//destructor
		~Stack()
		{
			delete[]data;
		}


		void push(T newItem)
		{
			if (isFull())
				cout << "stack full\n";
			else
				data[++top] = newItem;
		}


		T pop()
		{
			if (isEmpty())
				cout << "stack empty\n";
			else
				return data[top--];
		}


		T Top()
		{
			if (isEmpty())
			{}
				//cout << "stack empty\n";
			else
				return data[top];
		}


		void clear()
		{
			top = -1;
		}


		bool isEmpty() const
		{
			return (top == -1);
		}


		bool isFull() const
		{
			return top == MAX_SIZE - 1;
		}

		void showStructure() const
		{
			if (isEmpty())
			{}
			else
			{
				cout << "top  -->      "<<data[top]<<endl;
				for (int i = top-1; i >=0 ; i--)
				{
					cout << "      |      " << data[i] << "       |" << endl;
				}
				cout << "      |--------------|\n";
			}
		}

	private:

		//Data members 
		T *data;
		//array of data items

		int top;   //top of the stack

		const int MAX_SIZE;  //maximum capacity of the stack
	};


		Stack <char> sstack(70);
		Stack <char>  ostack(66);


	void results(string ss1)
	{
		cout<<ss1<<endl;
	}

	void postfix(string ss)
	{
		string s2="";
		ostringstream oss;

		for(int i=0;i<ss.length();i++)
		{
			if(ss[i]>='A'&&ss[i]<='Z')
			{
				oss<<s2+ss[i];
			}
			else if(ss[i]>='0'&&ss[i]<='9')
			{
				oss<<s2+ss[i];
			}
			else if(ss[i]=='/')
			{
				ostack.push(ss[i]);
			}
			else if(ss[i]=='*')
			{
				if(ostack.Top()=='/')
				{
					oss<<s2+ostack.pop();
					ostack.push(ss[i]);
				}
				else 
				{
					ostack.push(ss[i]);
				}
				
			}
			else if(ss[i]=='+'||ss[i]=='-')
			{
				if(ostack.Top()=='/'||ostack.Top()=='*')
				{
					oss<<s2+ostack.pop();
					ostack.push(ss[i]);
				}
				else 
				{
					ostack.push(ss[i]);
				}
			}
			else if(ss[i]=='=')
			{
				if(ostack.Top()=='/'||ostack.Top()=='*'||ostack.Top()=='+'||ostack.Top()=='-')
				{
					oss<<s2+ostack.pop();
					ostack.push(ss[i]);
				}
				else 
				{
					ostack.push(ss[i]);
				}
			}
			else if(ss[i]=='(')
			{
				ostack.push(ss[i]);
			}
			else if(ss[i]==')')			
			{
				while(1)
				{
					if(ostack.Top()=='(')
					{
						ostack.pop();
						break;
					}
					else
					{
						oss<<s2+ostack.pop();
					}
				}
				
			}
			else if(ss[i]=='~')
			{
				oss<<s2+ss[i];
			}

			
		}
		while(!ostack.isEmpty())
			{
				oss<<s2+ostack.pop();
			}
	string ss1=oss.str();
	results(ss1);

	}

void main()
{
	ifstream in;
	in.open("input.txt");
	if(!in)
	{
		cout<<" file not found "<<endl;

	}
	else
	{
		string ss;
		while(!in.eof())
		{
			getline(in,ss);
			postfix(ss);
		}
	}
	system("pause");
}