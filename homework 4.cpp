#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

class Process
{
	string name;
	int arrivalTime;
	int serviceTime;
	int quantum;
	int turnaround;
	int wait;
	Process* next;
public:
	Process()
	{
		name="";
		arrivalTime=serviceTime=quantum=turnaround=wait=0;
		next=NULL;
	}
	Process(string n,int at,int st,int qt,Process* next1)
	{
		name=n;
		arrivalTime=at;
		serviceTime=st;
		quantum=qt;
		next=next1;
		turnaround=wait=0;
	}

	friend class roundRobin;

};

class roundRobin
{
	Process* head;

public:
	roundRobin()   //ctor
	{
		head =NULL;
	}

	bool isEmpty() const   //empty check
	{
		return head==NULL;
	
	}
	
	void input()   //input
	{
		ifstream in;
		in.open("input.txt");
		if(!in)
		{
			cout<<" file not found "<<endl;
		}
		else
		{
			int pcount=0;
			int quant=0;
			in>>pcount;
			in>>quant;
			for (int i=0;i<pcount;i++)
			{
				Process p;
				in>>p.name;
				in>>p.arrivalTime;
				in>>p.serviceTime;
				p.next=NULL;
				p.quantum=quant;
				insert(p);
			}
			sort(pcount);
		}
	}
	void insert(const Process p)   //insertion
	{
		Process* temp=new Process(p.name,p.arrivalTime,p.serviceTime,p.quantum,p.next);
		if(isEmpty())
		{
			head=temp;
			head->next=head;
		}
		else 
		{
			Process *cur=head;
			while(cur->next!=head)
			{
				cur=cur->next;
			}
			cur->next=temp;
			temp->next=head;
		}
	}

	void remove(string obj)  //remove
	{
		if(!isEmpty())
		{
			Process* cur=head;
			Process* pre=NULL;
		   while(cur->name!=obj&&cur->next!=head) 
		   {
			   pre=cur;
			   cur=cur->next;
		   }
			if(cur==head&&head->next==head)
			{
				Process*temp=head;
				head=NULL;
				delete temp;
			}
			else if(cur==head)
			{
				Process*temp=head;
				while(temp->next!=head)
				{
					temp=temp->next;
				}
				head=head->next;
				temp->next=head;
				delete cur;
			}
			else if(cur->name==obj)
			{
				pre->next=cur->next;
				delete cur;
			}
		}
	}

	void swap(Process &cur,Process &min) //swap
	{
		string n=cur.name;
		int at=cur.arrivalTime;
		int st=cur.serviceTime;
		int qt=cur.quantum;


		cur.arrivalTime=min.arrivalTime;
		cur.name=min.name;
		cur.quantum=min.quantum;
		cur.serviceTime=min.serviceTime;

		min.arrivalTime=at;
		min.name=n;
		min.quantum=qt;
		min.serviceTime=st;

	}

	void sort(int count)   //sort
	{
		if(!isEmpty())
		{
			if(head->next!=head)
			{
				Process* cur=head->next;
				Process* min=head;
				Process* temp=head;
				for(int i=0;i<count;i++)
				{
					do
					{
						if(min->arrivalTime>cur->arrivalTime)
						{
							min=cur;
						}
						else if(min->arrivalTime==cur->arrivalTime && min->serviceTime>cur->serviceTime)
						{
							min=cur;
						}
						cur=cur->next;
					}while(cur!=head);
					swap(*temp,*min);
					if(temp->next!=head)
					{
						temp=temp->next;
						cur=temp;
						min=temp;
					}
				}
			}
		}
	}

	void execution()     //EXECUTION
	{
		cout<<"Name "<<setw(5)<<"Arrival-time "<<setw(5)<<"quantum-time "<<setw(5)<<"finish-time "<<setw(5)<<"turnaround "<<setw(5)<<"waiting "<<endl;
		int timer=0;
		Process* cur=head;
		while(!isEmpty())
		{
			if(cur->arrivalTime<=timer)
			{
				if(cur->serviceTime  <=  cur->quantum)
				{

					timer += cur->serviceTime;
					cur->turnaround=timer-cur->arrivalTime;
					cur->wait=cur->turnaround-cur->serviceTime;
					display(*cur,timer);
					Process* temp=cur;
					cur=cur->next;
					remove(temp->name);
					
				}
				else if(cur->serviceTime > cur->quantum)
				{

					timer += cur->quantum;
					cur->serviceTime -= cur->quantum;
					cur->wait=cur->turnaround-cur->serviceTime;
					cur=cur->next;

				}

			}
			else
			{
				timer++;
			}

		}

	}

	void display(const Process &p1,int finish)
	{
		
		cout<<setw(5)<<p1.name<<setw(10)<<p1.arrivalTime<<setw(10)<<p1.quantum<<setw(10)<<finish<<setw(10)<<p1.turnaround<<setw(10)<<p1.wait<<endl;
	}

	void show()
	{
		Process* cur=head;
		
		do
		{
			cout<<cur->name<< "  ";
			cout<<cur->arrivalTime<< "  ";
			cout<<cur->serviceTime<< "  ";
			cout<<cur->quantum<< "  "<<endl;
			cur=cur->next;
		}
		 while(cur!=head);
	}

	~roundRobin()
	{
		if(!isEmpty())
		{
		Process *temp=head;
		Process * temp2 = NULL;
			do
			{
				temp2 = temp->next;
				head=temp2;
				delete temp;
				temp = temp2;
			}while (temp != head);
			delete head;
	
		}
	}

};
void main()
{
	roundRobin r;
	r.input();
	r.show();
	r.execution();
	system("pause");
}