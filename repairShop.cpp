#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
class customer
{
	public:
	int cno,total;
	string name;
	string adress;
	string cname;
	int a,b,c,n,x;
	float i;
	public:
		void give_details()
		{
			system("cls");
			system("color F5");
			fflush(stdin);
			cout<<"Enter Your Name :";
			getline(cin,name);
			cout<<"Enter your address:";
			getline(cin,adress);
			cout<<"Enter the name of your laptop:";
			getline(cin,cname);
			cout<<"Enter Your Id number -"<<endl;
			cin>>cno;
			
		}
		void display()
		{
			
			cout<<"Name:"<<name;
			cout<<endl<<"Address:"<<adress<<endl;
			cout<<"Name of your laptop:"<<cname<<endl;
			cout<<"Unique-Id:"<<cno;
			cout<<endl<<"Plz remember this Id for further details!!"<<endl;
			
		}
		void damage()
		{
			system("color E5");
			total=0;
			cout<<"Enter the number of components which you want to get repaired :";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				cout<<endl<<"Choose from the list:";
				cout<<endl<<"1)display  2)Hard disk 3)Usb ports:";
				cout<<endl<<"4)Graphic card  5)Mother board  6)Windows:";
				cout<<endl<<"7)Keypad  8)Ram  9)Anti-Virus:"<<endl;		
				cin>>x;	
				switch(x)
				{
					case 1:
						cout<<endl<<"Cost of display is 3000 Rs"<<endl;
						total+=3000;
						break;
					case 2:
						cout<<endl<<"cost of Hard disk is 4000 Rs"<<endl;
						total+=4000;
						break;
					case 3:
						cout<<endl<<"cost of Usb port is 500 Rs"<<endl;
						total+=500;
						break;
					case 4:
						cout<<endl<<"cost of Graphic card is 10000 Rs"<<endl;
						total+=10000;
						break;
					case 5:
						cout<<endl<<"cost of Mother board is 8000 Rs"<<endl;
						total+=8000;
						break;
					case 6:
						cout<<endl<<"cost of Windows is 3000 Rs"<<endl;
						total+=3000;
						break;
					case 7:
						cout<<endl<<"cost of key pad is 1200 Rs"<<endl;
						total+=1200;
						break;
					case 8:
						cout<<endl<<"cost of Ram is 1000 Rs"<<endl;
						total+=1000;
						break;	
					case 9:
						cout<<endl<<"cost of Anti-virus is 800 Rs"<<endl;
						total+=800;
						break;
				}
			}	
		}
		void bill()
		{
			cout<<endl<<"Your total bill to be paid  is:"<<total<<endl;
		}	
		int store_data();
		void search_data();
		void delete_data();
		void modify_data();
};
int  customer::store_data()
{
	
	ofstream  fout;
	fout.open("project.txt",ios::app|ios::binary);
	fout.write((char *)this,sizeof(*this));
	fout.close();
	return 1;
}
void customer::search_data()
{
	int  temp;
	cout<<"Enter your personal id:";
	cin>>temp;
	ifstream fin;
	fin.open("project.txt",ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(cno==temp)
		{
			display();
			break;  
		}
		else
		{
			fin.read((char*)this,sizeof(*this));
		}
	
	}
	cout<<endl<<"this is your record!!";
}
void customer::delete_data()
{
	ifstream fin;
	ofstream fout;
	int temp;
	cout<<"Enter your personal  id :";
	cin>>temp;
	fin.open("project.txt",ios::binary);
	fout.open("temp.txt",ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(temp!=cno)
			fout.write((char*)this,sizeof(*this));
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	fout.close();
	remove("project.txt");
	rename("temp.txt","project.txt");
}
void  customer::modify_data()
{
	fstream file;
	file.open("project.txt",ios::in|ios::out|ios::ate|ios::binary);
	file.seekg(0);
	file.read((char*)this,sizeof(*this));
	int temp;
	cout<<"\nEnter your personal id:";
	cin.ignore();
	cin>>temp;
	while(!file.eof())
	{
		if(temp==cno)
		{
			give_details();
			damage();
			file.seekp(file.tellp()-sizeof(*this));
			file.write((char*)this,sizeof(*this));
		}
		file.read((char*)this,sizeof(*this));
	}
	file.close();
}
class pBar
 {
public:
    void update(double newProgress) {
        currentProgress += newProgress;
        amountOfFiller = (int)((currentProgress / neededProgress)*(double)pBarLength);
    }
    void print() {
        currUpdateVal %= pBarUpdater.length();
        cout << "\r"
            << firstPartOfpBar; 
        for (int a = 0; a < amountOfFiller; a++) { 
            cout << pBarFiller;
        }
        cout << pBarUpdater[currUpdateVal];
        for (int b = 0; b < pBarLength - amountOfFiller; b++) {
            cout << " ";
        }
        cout << lastPartOfpBar
            << " (" << (int)(100*(currentProgress/neededProgress)) << "%)"
            << flush;
        currUpdateVal += 1;
    }
    string firstPartOfpBar = "[",
        lastPartOfpBar = "]",
        pBarFiller = "|",
        pBarUpdater = "/-\\|";
    
private:
    int amountOfFiller,
        pBarLength = 50,
        currUpdateVal = 0;
    double currentProgress = 0,
        neededProgress = 100; 
};
void pay()
{
 pBar bar;
    //Main loop:
    for (int i = 0; i < 100; i++) 
	{ 
        bar.update(1); 
        bar.print(); 
        Sleep(100);
       
	}
 cout<<endl<<"Your payment is succesfull!!";
 getch();
}
int main()
{
	customer c1;
	while(1)
	{
		system("cls");
		int d;
		cout<<"  \t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
		cout<<"\n\n\t\t\t*     1.NEW CUSTOMER              *";
		cout<<"\n\n\t\t\t*     2.pay the bill              *";
		cout<<"\n\n\t\t\t*     3.DELETE A RECORD           *";
		cout<<"\n\n\t\t\t*     4.MODIFY A RECORD           *";
		cout<<"\n\n\t\t\t*     5.DISPLAY RECORDS           *";
		cout<<"\n\n\t\t\t*     0.EXIT                      *\n";
		cout<<"\n\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
		cout<<"\n\n\n\n\t Enter your choice :\t";
		cin>>d;
		switch(d)
		{
			case 0 :
				exit(0);
			case 1:
				c1.give_details();
				c1.damage();
				cout<<"Your  data  is going to be save.Press any Key to continue:";
				getch();
				c1.store_data();
				cout<<endl<<"Your data is stored.";
				c1.bill();
				cout<<"Do u  want to pay bill now (y/n)";
				char a;
				cin>>a;
				if(a=='y')
				{
					pay();
					cout<<"thanks for the payment.  Have a nice day!!";
					getch();
				}
				else
				{
					cout<<endl<<"Have  a nice day sir. We will try to repair ASAP !!";
					getch();
				}
				break;
			case 2:
				cout<<"Enter the amount to be paid:";
				int temp;
				cin>>temp;
				pay();
				cout<<endl<<"its  glad to help u sir.";
				getch();
				break;
			case 3:
				c1.delete_data();
				cout<<"\nYour data has been  deleted!!\nPress any key to continue:";
				getch();
				break;
			case 4:
				c1.modify_data();
				cout<<"\nYour data has been modified";
				getch();
				break;	
			case 5:
				c1.search_data();
				cout<<"Do you want to pay yout bills?(y/n):";
				char b;
				cin>>b;
				if(b=='y')
				{
					pay();
					cout<<"\nthanks for the payment.  Have a nice day!!";
					getch();
				}
				else
				{
					cout<<"\nhave a nice day !!";
				}
				getch();
				break;
				
			default:
				cout<<"\nEnter a valid number:";
		}
	}
}

