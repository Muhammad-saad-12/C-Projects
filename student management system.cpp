#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
using namespace std;
class login {
	int i=0;
	string name,n,pass,p;
public:
	void reg() {
		cout << "Enter UserName:";
		cin >> name;
		cout << "Enter Password(only in Alphabets):";
		cin >> pass;
		ofstream file;//created a file
		file.open("log.txt");//opened a file.
		file << name << endl << pass << endl;//stored data in file.
		file.close();//closed the file.
	}
	bool log() {
		cout << "Enter UserName:";
		cin >> name;
		cout << "Enter Password:";
		cin >> pass;
		ifstream infile;
		infile.open("log.txt");//open previous file for reading
		getline(infile, n);//
		getline(infile, p);//
		if (n==name && p == pass) {
			return true;
		}
		else {
			return false;
		}
		infile.close();
	}
	void search(string nem){
		int count=0;
	ifstream infile;
	infile.open("log.txt");
	while(infile>>name>>pass){
		if(nem==name){
			count=1;
		}
		else{
			cout<<"Try again"<<endl;
		}
	}
	if(count==1){
	cout<<"Entered user name is valid"<<endl;
	cout<<"Here is your password:"<<pass<<endl;	
	}	
	infile.close();
	}
};
class student{
	public:
	int roll;
	char name[50],n[50],add[50],field[50];
		void Addinput(){
			cout<<endl;
			cout<<"Enter your Personal information:"<<endl<<endl;
			cout<<"Enter Student Name:";
		    cin>>name;
			cout<<"Student Roll Number:";
			cin>>roll;
			cout<<"Enter student Gurdains (Mother/Father) Name:";
			cin>>n;
			cout<<"Enter address:";
			cin>>add;
			cout<<"Enter field:";
			cin>>field; 
		}
		void Showoutput(){
			cout<<endl;
		cout<<"student name:"<<name<<endl;
		cout<<"student Roll number:"<<roll<<endl;
		cout<<"student student Gurdains (Mother/Father) Name :"<<n<<endl;
		cout<<"student addderss:"<<add<<endl;
		cout<<"student Field:"<<field<<endl;
		}
		void update();
		void del();
		void search();
}s1;
void student::update(){
	loop:
		system("CLS");
	int num;
	cout<<endl;
	cout<<"Enter the roll number of the Student:";
	cin>>num;
ifstream stu_infile;
stu_infile.open("stu.dat",ios::binary|ios::in);
ofstream temp;
temp.open("temp.dat",ios::binary|ios::app);
while(stu_infile.read((char*)&s1,sizeof(s1))){
	if(s1.roll!=num){
		temp.write((char*)&s1,sizeof(s1));
	}
}
stu_infile.close();
temp.close();

remove("stu.dat");
rename("temp.dat","stu.dat");
cout<<"Enter the information again:";
ofstream stu_file;
  	stu_file.open("stu.dat",ios::binary|ios::app|ios::out);
  	s1.Addinput();
  	stu_file.write((char*)&s1,sizeof(s1));
  	stu_file.close();
	  }
void student::del(){
	int rol;
	cout<<endl;
	cout<<"Enter the roll number of the Student:";
	cin>>rol;
ifstream stu_infile;
stu_infile.open("stu.dat",ios::binary|ios::in);
ofstream temp;
temp.open("temp.dat",ios::binary|ios::app);
while(stu_infile.read((char*)&s1,sizeof(s1))){
	if(s1.roll!=rol){
		temp.write((char*)&s1,sizeof(s1));
	}
}
stu_infile.close();
temp.close();

remove("stu.dat");
rename("temp.dat","stu.dat");
}
void student::search(){
		int rol;
		cout<<"Enter the roll number of the Student:";
	cin>>rol;
	ifstream stu_infile;
stu_infile.open("stu.dat",ios::binary|ios::in);
while(stu_infile.read((char*)&s1,sizeof(s1))){ 
	if(rol==s1.roll){
		cout<<"The record has been found"<<endl;
	s1.Showoutput();
		system("PAUSE");
		break;
	}
}
stu_infile.close();	
cout<<"Could not open the file"<<endl;
}
void menu() {
	cout<<endl<<"To Run this Program you have to first loggin................."<<endl;
	cout << "press 1 to register" << endl;
	cout << "press 2 to login" << endl;
	cout<<  "Press 3 if you forgot your password"<<endl;
	cout << "Press 4 if you want to exit"<<endl;
}
void menuu(){
	cout<<"--------------1.ENTER NEW RECORDS..................."<<endl;
    cout<<"--------------2.SEE the ENTERED RECORDS..................."<<endl;
	cout<<"--------------3.MODIFY RECORDS..................."<<endl;
	cout<<"--------------4.DELETE RECORDS..................."<<endl;
	cout<<"--------------5.SEARCH AND VIEW RECORDS..................."<<endl;
	cout<<"--------------6.EXIT PROGRAM..................."<<endl;
}
void dec(){
	cout<<"------------------------------------------STUDENT MANAGEMENT SYSTEM--------------------------------------------------"<<endl;
}
int main() {
	int c;
	login p1;
	while (true) {
		system("CLS");
		menu();
		cin >> c;
		if (c == 1) {
			system("CLS");
			cout<<endl<<"Enter the input for registration................."<<endl;
			p1.reg();
			main();
		}
		if (c == 2) {
			system("CLS");
			ifstream infile("log.txt");
			if(infile.is_open()){
					cout<<endl<<"Enter the input for Login......................."<<endl;
			bool res;
			res = p1.log();
			if (!res) {
				cout << "Try Again" << endl;
				system("PAUSE");
				main();
			}
			else {
				cout <<endl<< "Congratulations you have been successfully logged in"<<endl;
				system("PAUSE");
				}
				break;
		}
		else{
			cout<<"You have first register to login"<<endl;
			system("PAUSE");
			main();
		}
			}

		if(c==3){
			string na;
			system("CLS");
			cout<<"Search your password by entering your name:";
		cin>>na;
		p1.search(na);
		system("PAUSE");
		main();
		}
		if(c==4){
			system("PAUSE");
			exit(0);
		}
		else{
			cout<<"Invalid number"<<endl;
			system("PAUSE");
			main();
		}
}
//---------------------------------------------------student management system start.------------------------------------------------------------------

while(1){
	again:
	lop:
system("CLS");
int cho;
	int cont=0;
cout<<endl;
cout<<endl;
	dec();
  menuu();
  cin>>cho;
  switch(cho){  
  case 1:{
  	string choice;
  	loop:
  	system("CLS");
  	ofstream stu_file;
  	stu_file.open("stu.dat",ios::binary|ios::app);
  	cont++;
  	s1.Addinput();
  	stu_file.write((char*)&s1,sizeof(s1));
  	stu_file.close();
  	cout<<"Do you want to enter more records(y/n):";
  	cin>>choice; 
  	if(choice=="y"){
  		goto loop;
	  }
	else{
	goto lop;
	}
  	break;
  }
  case 2:{
  	system("CLS");
  	ifstream infile;
	  infile.open("stu.dat");
  		if(infile.is_open()){
  			int count=1;
  	cout<<endl<<"Reading the data fromt he student record data base"<<endl;
     infile.close();
  	ifstream stu_infile;
  	stu_infile.open("stu.dat",ios::binary|ios::in);
while(stu_infile.read((char*)&s1, sizeof(s1))){
	system("CLS");
	cout<<"showing the record of student No"<<count<<endl<<endl;
	count++;
	s1.Showoutput();
	system("PAUSE");
	cout<<endl;
}	
stu_infile.close();
break;
  }
  else{
  	cout<<"You have to first input students information"<<endl;
    system("PAUSE");
    goto again;
  }
  }
  case 3:{
  		system("CLS");
  		ifstream infile;
		infile.open("stu.dat");
  		if(infile.is_open()){
  			infile.close();
  		s1.update();
  		cout<<endl<<"Your record got Updated"<<endl;
  		system("PAUSE");
		  }
  		else{
  				cout<<"You have to first input students information"<<endl;
  	system("PAUSE");
  	goto again;
	  }
		  break;	
  	}
  case 4:
  	{
  		system("CLS");
  		ifstream infile; 
		  infile.open("stu.dat");
  		if(infile.is_open()){
  			infile.close();
  		s1.del();
  		cout<<endl<<"Your record got deleted"<<endl;
  		system("PAUSE");
		  }
		  else{
  				cout<<"You have to first input students information"<<endl;
  	system("PAUSE");
  	goto again;
		  }
  		break;
}
case 5:{
	system("CLS");
		ifstream infile;
		infile.open("stu.dat");
  		if(infile.is_open()){
  			infile.close();
	s1.search();
	}
	 else{
  				cout<<"You have to first input students information"<<endl;
  	system("PAUSE");
  	goto again;
		  }	
break;
}
case 6:
	system("CLS");
		cout<<endl<<endl<<"------------------- Brought to you by PAK CODER -----------------------------------------"<<endl;
	system("PAUSE");
	exit(0);
break;
default:
cout<<"Invalid number"<<endl;
system("PAUSE");	
}
}
}
