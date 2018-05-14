//#include<iostream>
//#include<fstream>
//#include<string>
//#include<Windows.h>
//
//using namespace std;
//
//class list
//{
//public:
//	string process;
//	int time;
//	int arrivaltime;
//
//	list()	
//	{
//		process="";
//		time=arrivaltime=0;
//	}
//};
//
//
//
//class Scheduler
//{
//	list schedule[20];
//	int count;
//	int timer;
//
//public:
//
//	Scheduler()
//	{
//		count=-1;
//		timer=0;
//	}
//
//
//	bool isempty()
//	{
//		return count==-1;
//	}
//
//
//	bool isfull()
//	{
//		return count==19;
//	}
//
//	void input()
//	{
//	ifstream in;
//	ofstream out;
//	in.open("readylist.txt");
//
//	if(!in)
//	{
//		cout<<"file not found";
//	}
//	else
//	{
//		int i=0;
//		if(isfull()==false)
//		{
//
//			while(!in.eof())
//			{
//				count++;
//				in>>schedule[count].process;
//				in>>schedule[count].time;
//				schedule[count].arrivaltime=timer;
//				
//			}
//		
//
//			
//		}
//		in.close();
//		out.open("readylist.txt");
//		out<<"";
//		out.close();
//
//	}
//
//	}
//
//
//	void bubblesort( int a)
//	{
//		for(int i=a; i<=count; i++)
//		{
//			for(int j=i; j<=count; j++)
//			{
//				if(schedule[j].time < schedule[j+1].time)
//				{
//					swap(schedule[j],schedule[j+1]);
//				}
//			}
//		}
//		
//	}
//
//
//	void swap(list &a,list &b)
//	{
//		list c;
//		c=a;
//		a=b;
//		b=c;
//	}
//
//	void print()
//	{
//		if(count>=0)
//		{
//			for(int i=0;i<=count;i++)
//			{
//				cout<<schedule[i].process;
//				cout<<"  "<<schedule[i].time<<endl;;
//
//			}
//		}
//	}
//	
//void execution()
//{
//
//	
//	int wait=0;
//	int turn=0;
//	int counter=0;
//	
// int i=0;
//	while(count!=-1)
//	{
//		
//
//		for(int j=0;j<=schedule[i].time;j++)
//		{
//			cout<<timer;
//
//			Sleep(100);
//			
//			if(timer%15==0)
//			{
//				cout<<endl<<"press enter to continue ";
//				cin.get();
//	
//					input();
//					bubblesort(1);
//			}
//			timer++;
//		}
//		turn +=timer-schedule[0].arrivaltime;
//	
//		wait += timer-schedule[0].arrivaltime;
//	
//		cout<<schedule[0].process<<"  " <<schedule[0].time<<" "<<timer-schedule[0].arrivaltime-schedule[0].time-1<<" "<<timer-1<<endl;
//		shifting();
//		count--;
//		Sleep(3000);
//		counter++;
//	}
//
//	cout<< "average waiting time "<< wait/counter<<endl;
//	cout<<" average turnaround time  "<<turn/counter<<endl;
//}
//
//	void shifting()
//	{
//
//		for(int i=0;i<count;i++)
//		{
//			schedule[i]=schedule[i+1];
//		}
//	}
//
//	void startexecution()
//	{
//		
//	input();
//	bubblesort(0);
//	print();
//	execution();
//	}
//};
//
//void main()
//{
//	Scheduler s;
//	s.startexecution();
//	system("pause");
//}