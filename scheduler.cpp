#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>

using namespace std;

class list
{
public:
	string process;
	int time;
	int arrivaltime;

	list()	
	{
		process="";
		time=arrivaltime=0;
	}

	void setlistitems(string s,int t)
	{
		process=s;
		if(t<0)
			throw 5;
		else
			time=t;
	}

	string getprocess()
	{
		return process;
	}

	int gettime()
	{
		return time;
	}
};



class Scheduler
{
	list schedule[20];
	int count;
	int timer;

public:

	Scheduler()
	{
		count=-1;
		timer=0;
	}


	bool isempty()
	{
		return count==-1;
	}


	bool isfull()
	{
		return count==19;
	}

	void input()
	{
	ifstream in;
	ofstream out;
	in.open("readylist.txt");

	if(!in)
	{
		cout<<"file not found";
	}
	else
	{
		int i=0;
		if((isempty()||isfull()==false)&&filempty()==false)
		{

			while(!in.eof() && isfull()==false)
			{
				count++;
				in>>schedule[count].process;
				in>>schedule[count].time;
				schedule[count].arrivaltime=timer;
				
			}
		

			
		}
		in.close();
		out.open("readylist.txt");
		out<<"";
		out.close();

	}

	}


	void bubblesort( int a)
	{
		for(int i=a; i<=count; i++)
		{
			for(int j=i; j<=count; j++)
			{
				if(schedule[i].time < schedule[j].time)
				{
					swap(schedule[i],schedule[j]);
				}
			}
		}
		
	}

	bool filempty()
	{
		ifstream in;
		in.open("readylist.txt");
		if(in.is_open())
		{
			return in.peek()==EOF;
		}
		else
		{
			return true;
		}
	}
	void swap(list &a,list &b)
	{
		list c;
		c=a;
		a=b;
		b=c;
	}

	void print()
	{
		if(count>=0)
		{
			for(int i=0;i<=count;i++)
			{
				cout<<schedule[i].process;
				cout<<"  "<<schedule[i].gettime()<<endl;;

			}
		}
	}
	
void execution()
{
	cout<<" press any key to strat execution ";
	cin.get();
	system("cls");
	
	int wait=0;
	int turn=0;
	int counter=0;
	
 int i=0;
	while(count!=-1)
	{
		cout<<" prcoesses executing "<<endl;
		wait += timer-schedule[i].arrivaltime;

		for(int j=0;j<=schedule[i].time;j++)
		{
			cout<<  "                                                                "<<timer;

			Sleep(100);
			
			if(timer%15==0)
			{
				cout<<endl<<"press enter to continue ";
				cin.get();
				if(filempty()==false)
				{
					input();
					bubblesort(1);
				}
			}
			timer++;
			system("cls");
		}
		turn +=timer-schedule[i].arrivaltime;
	

		system("cls");
		
		cout<<"process executed !"<<endl;
		cout<<endl<<"PROCESS"<<"		 exe time "<<" waiting time "<<" turnaround time "<<endl<<endl;
		cout<<schedule[i].process<<"   " <<schedule[i].time<<"		 "<<timer-schedule[i].arrivaltime-schedule[i].time-1<<"	"<<timer-1<<endl;
		shifting();
		count--;
		Sleep(3000);
		counter++;
	}

	cout<< "average waiting time "<< wait/counter<<endl;
	cout<<" average turnaround time  "<<turn/counter<<endl;
}

	void shifting()
	{

		for(int i=0;i<count;i++)
		{
			schedule[i]=schedule[i+1];
		}
	}

	void start()
	{
		
	input();
	bubblesort(0);
	print();
	Sleep(1000);
	system("cls");
	execution();
	}
};

void main()
{
	Scheduler s;
	s.start();
	system("pause");
}