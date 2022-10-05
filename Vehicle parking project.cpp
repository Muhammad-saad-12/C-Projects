#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<process.h>
#include<stdio.h>
#include<conio.h>  
using namespace std;
class login {
	string name, pass, p, un;
public:
	void reg() {
		cout << "Enter your user name:";
		cin >> name;
		cout << "Enter your pass:";
		cin >> pass;
		ofstream filw;   //file created.
		filw.open("filw.txt");    //file opened.
		filw << name << endl << pass << endl;
		filw.close();
	}
	bool logi() {
		cout << "Enter the user name:";
		cin >> name;
		cout << "Enter the password:";
		cin >> pass;
		ifstream filw("filw.txt");
	while(filw>>un>>p){
		if (un == name && p == pass) {
			return true;
		}
		else {
			return false;
		}
		}
	}
void forgot(){
		int ch;
		  cout<<"press 1 to Search your pasword by user name:"<<endl;
		  cout<<"press 2 to go on Main menu"<<endl;
		  cin>>ch;
		  	if(ch==1){
		  		int count=0;
		  		cout<<"Enter your user name:";
		  		cin>>name;
		  		ifstream searchpass("filw.txt");
		  		while(searchpass>>un>>p){
		  			if(un==name){
		  			count=1;
					  }
					  else{
					  	cout<<"Try again"<<endl;
					  } 
				  }
				  if(count==1){
				  	cout<<"Valid user name:"<<endl;
				  	cout<<"Your password:"<<p<<endl;
				  }
				  }
				  }
}l1;
class vehicle {
public:
	int vehicle_no;
	float count;
	char name[50],slot[50],type[50];
	void input() {
		int d=0;
		cout << "Enter your name:";
		cin >> name;
		cout << "Enter vehicle number:";
		cin >> vehicle_no;
		cout << "Enter the time slot(AM/PM)";
		cin >> slot;
		cout << "Enter the number of hours car will going to stay:";
		cin >> count;
		if (d < 20 && count<8) {
			cout << "parking avalible" << endl;
		}
		else {
			cout << "PArking is not avalible";
		}
	}
	void cal() {
		cout << "Total expences during parking:";
		count = count * 10;
		cout << count<<"Rs"<< endl;
	}
	void output() {
		cout << "The Driver Name : " << name << endl;
		cout << "The Car No : " << vehicle_no << endl;
		cout << "The Hours Of Stay : " << count << endl;
		cout << "The Time Slot Of Parking:" << slot << endl;
	}
		void del();
}p1;
void vehicle::del() {
	int n;
	system("CLS");
	cout << "Enter the car no you want to delete:";
	cin >> n;
	ifstream infile;
	infile.open("fill.dat", ios::binary);
	ofstream outfile;
	outfile.open("temp.dat", ios::out | ios::binary);
	while (infile.read((char*)&p1, sizeof(p1)))
	{
		if (p1.vehicle_no != n) {
			outfile.write((char*)&p1, sizeof(p1));
		}
	}
	cout << "Parking record Deleted";
	infile.close();
	outfile.close(); 
	remove("fill.dat");
	rename("temp.dat","fill.dat");
}
	int main() {
		int c,choi;
		cout << "Press 1 for Register:" << endl;
		cout << "Press 2 for login:" << endl;
		cout << "press 3 if you Forgot your password:" << endl;
		cout  <<"Press 4 to log out"<<endl;
		cin >> c;
		if (c == 1) {
			l1.reg();
			system("PAUSE");
			main();
	}
		if (c == 2) {
			system("CLS");
			bool r;
			r = l1.logi();
			if (!r) {
				system("CLS");
				cout << "False login" << endl;
				cout << "Try again" << endl;
				system("PAUSE");
				system("CLS");
				main();
			}
			else {
				system("CLS");
				cout << endl;
				cout << "You have logged in successfully";
				cout << endl;
				system("PAUSE");
				system("CLS");
			}
			}
			if (c == 3) {
				system("CLS");
          l1.forgot();
          system("PAUSE");
            main();
	}
	if(c==4){
		cout<<"You have been logged out"<<endl;
		system("PAUSE");
			exit(0);
	}
		while (true) {
			cout << "-----------------------------------" << "CAR PARKING RESERVATION SYSTEM" << "-------------------------------------------" << endl;
			cout << endl << endl;
			cout << "press 1 to enter Information:" << endl;
			cout << "press 2 to see total no of cars arrived:" << endl;
			cout << "press 3 to see total parking charges of all Vehicles (detailed):" << endl;
			cout << "press 4 to Delete vehicle informarion:" << endl;
			cout << "Press 5 to exit this software:" << endl;
			cout << "Enter your choice:" << endl;
			cin >> choi;
			system("CLS");
			switch (choi) {
			case 1:
			{
				system("CLS");
				ofstream f1("fill.dat",ios::binary | ios::out|ios::app);
				p1.input();
				f1.write((char*)&p1, sizeof(p1));
				break;
			}
			case 2:
			{
				system("CLS");
				cout << "View the records in parking DataBase:" << endl;
				ifstream infile("fill.dat", ios::binary | ios::in);
				int d = 1;
				while (infile.read((char*)&p1, sizeof(p1)))
				{
					system("CLS");
					cout << endl << "Car position in parking Lot:" << d<<endl;
					d++;
					p1.output();
					system("PAUSE");
					cout << endl;
				}
				break; 
			}
			case 4:
			{
				p1.del();
				break;
			}
			case 3:
			{
				system("CLS");
				ifstream infile("fill.dat", ios::binary | ios::in);
				while (infile.read((char*)&p1, sizeof(p1))) {
					p1.cal();
					p1.output();
					system("PAUSE");
					}
				break;
			}
			case 5:
			{
				system("CLS");
				cout << "\n\n\n\t\t\tBrought To You By:PAK-CODERS.ORG\n";
				exit(0);
				break;
			}
			default:
			{
				cout << "\n\n\t\t Invalid input";
				cout << "\n\n\t\tPress Enter to continue";
			}
			}
		}
	}
