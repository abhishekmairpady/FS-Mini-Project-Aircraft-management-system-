#include <iostream>
#include<stdio.h>		//standard input/output c
#include<stdlib.h>		//standard library
#include<conio.h>		//getch function
#include<dos.h>			//delay function
#include<windows.h>		//Sleep,gotoxy coordinate functions
#include<iomanip>		//output manipulatons
#include<fstream>		//file handling
#include<string.h>		//string abstract datatype
#include<math.h>		//mathematical operations
#include<time.h>	
using namespace std;
char loc[20];
void gotoxy (int x, int y);	//handle output on screen
void frame ();			//frame for every dialog box
void frame_fix();
char *date_time ();
void scroll_note();		
void flow(char *ch);
COORD coord = {0, 0};
void menupage();
void login();

class date;
class date		//class current date and time of system
{		
	public:
		int aday,amonth,ayear,ahour,amin,asec;
	void date_times()
	{
		SYSTEMTIME t;		//pre defined in time.h header
 		GetLocalTime(&t);
		aday=t.wDay,amonth=t.wMonth,ayear=t.wYear,ahour=t.wHour,amin=t.wMinute,asec=t.wSecond;
		
	}
};
class airport{
	public:
		string airportid;
		string name;
		string managerid;
		string iata;
		string icao;
		string city;
		void main1();
		void read_data();
		void pack();
		void write_to_file();
		void unpack();
		int search1(string);
		void delete_item();
		void modify1(string);
		int delete_from_file1(string);
		string buffer1;
};
class airline: public airport{
	public:
		string airlineid;
		string name2;
		string iata2;
		string icao2;
		string buffer2;
		void main2();
		void read_data2();
		void pack2();
		void write_to_file2();
		void unpack2();
		int delete_from_file2(string);
		int search2(string);
		void modify2();
};
class aeroplane: public airline{
	public:
		string aeroplaneid;
		string model;
		string airlineid;
		string buffer3;
		string aeroid_list[100];
		string extract_aeroid3();
		int address_list[100];
		int count;
		int search_index3(string);
		void read_data3();
		void pack3();
		void write_to_file3();
		void create_index3();
		void remove3(string);
		void search3(string);
		void sort_index3();
		void main3();
};
class accomodation: public aeroplane{
	public:
		string aeroplaneid;
		string airportid;
		string laneno;
		string buffer4;
		
	
		void read_data4();
		void pack4();
		void write_to_file4();
		void display(string,string);
		void main4();
		int search4(string);
		void unpack4();
};
class sa: public accomodation{
	public:
	void main5();
};
class mainp : public airline{
	public:
	void login();
	void menupage();
};

void gotoxy (int x, int y)	//defining/initializing to predefined objects
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void frame()
{
	int i,j=117;
	for(i = 0;i<118,j>=0;i++,j--)
	{
		gotoxy(i,3);
		Sleep(2);
		cout<<"_";
		gotoxy(j,22);
		Sleep(2);
		cout<<"_";
	}
	gotoxy(90,2);
	char s[20];
	strcpy(s,date_time());
	cout<<s;		//every frame has date on the right top 
	
}
void frame1()	//instead of flow line fixing the frame
{
	int i,j=117;
	for(i = 0;i<118,j>=0;i++,j--)
	{
		gotoxy(i,3);
		cout<<"_";
		Sleep(2);
		gotoxy(j,22);
		cout<<"_";
		Sleep(2);
	}
	gotoxy(90,2);
	char s[20];
	strcpy(s,date_time());
	cout<<s;
}
char *date_time()
{
	time_t t;
	time(&t);
	char *loc=ctime(&t);
	return loc;	//returns local time and date
}
void scroll_note()	//welcome note
{
		system("color 0B");
	int j,i,x,y;
	
	
	gotoxy(39,12);cout<<"AIRLINE TRAFFIC MANAGEMENT SYSTEM";
	gotoxy(50,14);cout<<"WELCOMES YOU";
	for(int j=115;j>=0;j--)
	{
		
		gotoxy(j,4);cout<<"$";
		Sleep(10);
	}
	for(int j=0;j<=115;j++)
	{
		gotoxy(j,20);cout<<"$";
		
		Sleep(10);
	}
	gotoxy(86,23);cout<<"ABHISHEK MAIRPADY";
	gotoxy(86,24);cout<<"AKARSH C M";
	Sleep(2000);

}
void mainp::login(){
	char addname[30],pass[30];
	char adname[]="abhishek";
	char password[]="abhi";
	while(1)
	{
		system("cls");
		frame1();
		gotoxy(48,2);
		cout<<"LOGIN PAGE ";
		gotoxy(29,10);
		cout<<"Enter name of the admin : ";
		
		cin>>addname;
			if(strcmp(adname,addname)==0)
			{
				gotoxy(29,13);
				cout<<"Enter password : ";
				cin>>pass;
				if(strcmp(password,pass)==0)
				{
					
					menupage();					
						
				}
			}
	}
}
void mainp::menupage(){
	int op1;
	
	while(1)
	{
		system("cls");
		system("COLOR 1F");
		frame();
		gotoxy(48,8);
		cout<<"1.AIRPORT ";
		gotoxy(48,10);
		cout<<"2.AIRLINE COMPANY";
		gotoxy(48,12);
		cout<<"3.AIRCRAFT";
		gotoxy(48,14);
		cout<<"4.ACCOMODATION";
		gotoxy(48,16);
		cout<<"5.TRACK AIRCRAFT";
		gotoxy(48,18);
		cout<<"6.EXIT";
		gotoxy(48,20);
		cout<<"Select your option : ";
		op1=getch();
		if(op1=='1')
		{
			airport ap;
			ap.main1();
		}
		else if(op1=='2')		
		{
			airline ar;
			ar.main2();
		} 
		else if(op1=='3'){
			aeroplane ae;
			ae.main3();
		}
		else if(op1=='4'){
			accomodation ac;
			ac.main4();
		}
		else if(op1=='5'){
			sa s;
			s.main5();
		}		
		else if(op1=='6'){
			exit(0);
		}	
		else
		{
			gotoxy(50,16);cout<<"INVALID INPUT...TRY AGAIN!!!";
			Sleep(1000);			
			system("cls");						
		}
	}
}
//airport
//----------------------------------------------------------------------

void airport::main1(){
	int op1;
	airport a;
	while(1)
	{
		system("cls");
		system("COLOR 1F");
		frame();
		gotoxy(48,8);
		cout<<"1.ADD NEW AIRPORT ";
		gotoxy(48,10);
		cout<<"2.DELETE AIRPORT";
		gotoxy(48,12);
		cout<<"3.UPDATE AIRPORT DETAILS";
		gotoxy(48,14);
		cout<<"4.SEARCH AIRPORT DETAILS";
		gotoxy(48,16);
		cout<<"5.BACK";
		gotoxy(48,18);
		cout<<"Select your option : ";
		op1=getch();
		if(op1=='1')
		{
			a.read_data();
			a.pack();
			a.write_to_file();
		}
		
		else if(op1=='2')		
		{
			int i;
			string key;
			system("cls");
			system("COLOR 1F");
			frame();
			gotoxy(40,8);
			cout<<"enter the airport id to be deleted:";
			cin>>key;
			gotoxy(40,9);
			i=a.delete_from_file1(key);
			gotoxy(40,12);
			if(i==1)
			    cout<<"record deleted\n";
			else
				cout<<"record not deleted\n";
			
			Sleep(5000);
		}
		else if(op1=='3'){
			string key;
			system("cls");
			system("COLOR 1F");
			frame();
			gotoxy(40,8);
			cout<<"enter the airport id to be modified:";
			cin>>key;
			gotoxy(40,9);
			a.modify1(key);
			Sleep(5000);
		}
		else if(op1=='4'){
			string key;
			system("cls");
			system("COLOR 1F");
			frame();
			gotoxy(40,8);
			cout<<"enter the airport id to be searched:";
			cin>>key;
			gotoxy(40,9);
			a.search1(key);
			Sleep(5000);
			
		}	
		else if(op1=='5'){
			mainp p;
			p.menupage();
		}	
		else
		{
			gotoxy(50,16);cout<<"INVALID INPUT...TRY AGAIN!!!";
			Sleep(1000);			
			system("cls");						
		}
	}
}

void airport::read_data(){
	system("cls");
		system("COLOR 1F");
		frame();
		gotoxy(40,8);
	cout<<"Enter theairport ID:";
	cin>>airportid;
	gotoxy(40,9);
	cout<<"Enter the airport name:";
	cin>>name;
	gotoxy(40,10);
	cout<<"IATA:";
	cin>>iata;
	gotoxy(40,11);
	cout<<"ICAO:";
	cin>>icao;
	gotoxy(40,12);
	cout<<"Enter the city:";
	cin>>city;
	gotoxy(40,13);
	cout<<"Enter the manager id:";
	cin>>managerid;
}
void airport::pack(){
	buffer1.erase();
	buffer1+=airportid+"|"+managerid+"|"+name+"|"+iata+"|"+icao+"|"+city+"$"+"\n";
}
void airport::write_to_file(){
	fstream f1;
	f1.open("airport.txt",ios::out|ios::app);
	f1<<buffer1;
	f1.close();
}
void airport::unpack(){
	int ch=1,i=0;
	airportid.erase();
	while(buffer1[i]!='|')
		airportid+=buffer1[i++];
		
	managerid.erase();
	i++;
	while(buffer1[i]!='|')
		managerid+=buffer1[i++];
	
	name.erase();
	i++;
	while(buffer1[i]!='|')
		name+=buffer1[i++];
	
	iata.erase();
	i++;
	while(buffer1[i]!='|')
		iata+=buffer1[i++];
		
	icao.erase();
	i++;
	while(buffer1[i]!='|')
		icao+=buffer1[i++];
		
	city.erase();
	i++;
	while(buffer1[i]!='$')
		city+=buffer1[i++];
}
int airport::search1(string key)
{
	ifstream file;
	int flag=0,pos=0;
	file.open("airport.txt",ios::in);
	while(!file.eof())
	{
		buffer1.erase();
		pos=file.tellg();
		getline(file,buffer1);
		unpack();
		if(key==airportid)
		{
			gotoxy(40,10);
			cout<<"found the key .the record is...";
			gotoxy(40,11);
			//cout<<buffer1;
			string a,b,c,d;
			int i=0;
			a.erase();
			while(buffer1[i]!='|')
				a+=buffer1[i++];
			cout<<"airportid:"<<a;
			b.erase();
			i++;
			while(buffer1[i]!='|')
				b+=buffer1[i++];
			cout<<"managerid:"<<b;
			c.erase();
			i++;
			while(buffer1[i]!='|')
				c+=buffer1[i++];
			cout<<"iata:"<<c;
			d.erase();
			i++;
			while(buffer1[i]!='|')
				d+=buffer1[i++];
			cout<<"icao:"<<d;
			flag=1;
			return pos;
		}
	}
	file.close();
	if(flag==0)
	{
		gotoxy(40,10);
		cout<<"not found..";
		return -1;
	}
}
int airport::delete_from_file1(string key)
{
	fstream file;
	int pos,flag=0;
	pos=search1(key);
	if(pos>=0)
	{
		file.open("airport.txt");
		file.seekp(pos,ios::beg);
		file.put('*');
		flag=1;
		file.close();
	}
	if(flag==1)
		return 1;
	else
		return 0;
}
void airport::modify1(string key)
{
	int c;
	if(delete_from_file1(key))
	{
		system("cls");
		system("COLOR 1F");
		frame();
		gotoxy(40,8);
		cout<<"\nwhat to modify \n 1:airportid 2:managerid  3:name  4:iata  5:icao  6:city:\t";
		cin>>c;
		switch(c)
		{
			case 1:gotoxy(40,13);
					cout<<"airportid:\t";
			       cin>>airportid;
			       gotoxy(40,15);
			       cout<<"Data updated";
			       break;
			case 2:gotoxy(40,13);
					cout<<"managerid:\t";
			       cin>>managerid;
			       gotoxy(40,15);
			       cout<<"Data updated";
			       break;
			case 3:gotoxy(40,13);
					cout<<"name:\t";
			       cin>>name;
			       gotoxy(40,15);
			       cout<<"Data updated";
			       break;
			case 4:gotoxy(40,13);
					cout<<"iata:\t";
			       cin>>iata;
			       gotoxy(40,15);
			       cout<<"Data updated";
			       break;
			case 5:gotoxy(40,13);
					cout<<"icao:\t";
			       cin>>icao;
			       gotoxy(40,15);
			       cout<<"Data updated";
			       break;
			case 6:gotoxy(40,13);
					cout<<"city:\t";
			       cin>>city;
			       gotoxy(40,15);
			       cout<<"Data updated";
			       break;
			default:gotoxy(40,13);
					cout<<"wrong choice\t";
		}
		buffer1.erase();
		pack();
		write_to_file();
	}
}


//airline
//-------------------------------------------------------------------------------------------------------------



void airline::main2(){
	int op1;
	airline a;
	while(1)
	{
		system("cls");
		system("COLOR 1F");
		frame();
		gotoxy(48,8);
		cout<<"1.ADD NEW AIRLINE COMPANY ";
		gotoxy(48,10);
		cout<<"2.DELETE AIRLINE COMPANY";
		gotoxy(48,12);
		
		cout<<"3.SEARCH AIRLINE DETAILS";
		gotoxy(48,14);
		cout<<"4.BACK";
		gotoxy(48,17);
		cout<<"Select your option : ";
		op1=getch();
		if(op1=='1')
		{
			a.read_data2();
			a.pack2();
			a.write_to_file2();
		}
		
		else if(op1=='2')		
		{
		int i;
			string key;
			system("cls");
			system("COLOR 1F");
			frame();
			gotoxy(40,8);
			cout<<"enter the airline id to be searched:";
			cin>>key;
			gotoxy(40,9);
			i=a.delete_from_file2(key);
			gotoxy(40,12);
			if(i==1)
			    cout<<"record deleted\n";
			else
				cout<<"record not deleted\n";
			
			Sleep(5000);
			}//data	 
		else if(op1=='3'){
			string key;
			system("cls");
			system("COLOR 1F");
			frame();
			gotoxy(40,8);
			cout<<"enter the airline id to be searched:";
			cin>>key;
			gotoxy(40,9);
			a.search2(key);
			Sleep(5000);
		}	
		else if(op1=='4'){
			mainp p;
			p.menupage();
		}	
		else
		{
			gotoxy(50,16);cout<<"INVALID INPUT...TRY AGAIN!!!";
			Sleep(1000);			
			system("cls");						
		}
	}
}

void airline::read_data2(){
		system("cls");
		system("COLOR 1F");
		frame();
		gotoxy(40,8);
	cout<<"Enter the airline ID:";
	cin>>airlineid;
	gotoxy(40,9);
	cout<<"Enter the ailine name:";
	cin>>name2;
	gotoxy(40,10);
	cout<<"IATA:";
	cin>>iata2;
	gotoxy(40,11);
	cout<<"ICAO:";
	cin>>icao2;
}
void airline::pack2(){
	buffer2.erase();
	buffer2+=airlineid+"|"+name2+"|"+iata2+"|"+icao2+"$"+"\n";
}
void airline::write_to_file2(){
	fstream f2;
	f2.open("airline.txt",ios::out|ios::app);
	f2<<buffer2;
	f2.close();
}
void airline::unpack2()
{
	int ch=1,i=0;
	airlineid.erase();
	while(buffer2[i]!='|')
	airlineid+=buffer2[i++];
	name2.erase();
	i++;
	while(buffer2[i]!='|')
	name2+=buffer2[i++];
	iata2.erase();
	i++;
	while(buffer2[i]!='|')
	iata2+=buffer2[i++];
	icao2.erase();
	i++;
	while(buffer2[i]!='|')
	icao2+=buffer2[i++];
}

int airline::search2(string key)
{
	ifstream file;
	int flag=0,pos=0;
	file.open("airline.txt",ios::in);
	while(!file.eof())
	{
		buffer2.erase();
		pos=file.tellg();
		getline(file,buffer2);
		unpack2();
		if(key==airlineid)
		{
			gotoxy(40,10);
			cout<<"found the key .the record is...";
			gotoxy(40,11);
			cout<<buffer2;
			flag=1;
			return pos;
		}
	}
	file.close();
	if(flag==0)
	{
		gotoxy(40,10);
		cout<<"not found..";
		return -1;
	}
}
int airline::delete_from_file2(string key)
{
	fstream file;
	int pos,flag=0;
	pos=search2(key);
	if(pos>=0)
	{
		file.open("airline.txt");
		file.seekp(pos,ios::beg);
		file.put('*');
		flag=1;
		file.close();
	}
	if(flag==1)
		return 1;
	else
		return 0;
}


//--------------------------------------------------------------------------
//aeroplane
//-----------------------------------------------------------------------------------------------------------
void aeroplane::main3(){
	int op1;
	string key;
	aeroplane a;
	a.create_index3();
	while(1)
	{
		system("cls");
		system("COLOR 1F");
		frame();
		gotoxy(48,8);
		cout<<"1.ADD NEW AIRCRAFT ";
		gotoxy(48,10);
		cout<<"2.DELETE AIRCRAFT";
		gotoxy(48,12);
		
		cout<<"3.SEARCH AIRCRAFT DETAILS";
		gotoxy(48,14);
		cout<<"4.BACK";
		gotoxy(48,16);
		cout<<"Select your option : ";
		op1=getch();
		if(op1=='1')
		{
			a.read_data3();
			a.pack3();
			a.write_to_file3();
			
		}
		
		else if(op1=='2')		
		{
			system("cls");
			system("COLOR 1F");
			frame();
			gotoxy(48,8);
			cout<<" enter the aeroplaneid:";
			cin>>key;
			
			gotoxy(48,9);
			a.remove3(key);
			
		} 
		
		else if(op1=='3'){
			system("cls");
		system("COLOR 1F");
		frame();
		gotoxy(40,8);
			cout<<"enter the aeroplane id:";
				cin>>key;
				
				a.search3(key);
				Sleep(5000);
				
		}	
		else if(op1=='4'){
			mainp p;
			p.menupage();
		}	
		else
		{
			gotoxy(50,16);cout<<"INVALID INPUT...TRY AGAIN!!!";
			Sleep(1000);			
			system("cls");						
		}
	}
}
void aeroplane::read_data3()
{
	system("cls");
	system("COLOR 1F");
	frame();
	gotoxy(40,8);
	cout<<"AIRCRAFT id:";
	cin>>aeroplaneid;
	gotoxy(40,9);
	cout<<"model:";
	cin>>model;
	gotoxy(40,10);
	cout<<"airlinE id:";
	cin>>airlineid;
	
}
void aeroplane::pack3()
{
	string temp;
	buffer3.erase();
	buffer3+=aeroplaneid+'|'+model+'|'+airlineid+'$'+'\n';
}
void aeroplane :: write_to_file3()
{
	int pos;
	fstream file;
	file.open("aeroplane.txt",ios::out|ios::app);
	pos=file.tellp();
	file<<buffer3;
	file.close();
	aeroid_list[++count]=aeroplaneid;
	address_list[count]=pos;
	sort_index3();
}
string aeroplane::extract_aeroid3()
{
	string aeroplaneid;
	int i=0;
	aeroplaneid.erase();
	while(buffer3[i]!='|')
	aeroplaneid+=buffer3[i++];
	return aeroplaneid;
}
void aeroplane:: create_index3()
{
	fstream file;
	int pos;
	string aeroplaneid;
	count=-1;
	file.open("aeroplane.txt",ios::in);
	while(!file.eof())
	{
		pos=file.tellg();
		buffer3.erase();
		getline(file,buffer3);
		if(buffer3[0]!='*')
		{
			if(buffer3.empty())
			break;
			aeroplaneid=extract_aeroid3();
			aeroid_list[++count]=aeroplaneid;
			address_list[count]=pos;
		}
	}
	file.close();
	sort_index3();
	buffer3.erase();
	
}
void aeroplane::sort_index3()
{
	int i,j,temp_address;
	string temp_aero;
	for(int i=0;i<=count;i++)
	{
		for(int j=i+1;j<count;j++)
		{
			if(aeroid_list[i]>aeroid_list[j])
			{	
				temp_aero=aeroid_list[i];
				aeroid_list[i]=aeroid_list[j];
				aeroid_list[j]=temp_aero;
				temp_address=address_list[i];
				address_list[i]=address_list[j];
				address_list[j]=temp_address;
			}
		}
	}
	for(i=0;i<=count;i++)
	{
		cout<<aeroid_list[i]<<"\t"<<address_list[i]<<"\n";
	}
}
int aeroplane::search_index3(string key)
{
	int low=0,high=count,mid=0,flag=0,pos;
	while(low<=high)
	{
		
		mid=(low+high)/2;
		
		if(aeroid_list[mid]==key){
			flag=1;
			break;
			
		}
		
		if(aeroid_list[mid]>key)
			high=mid-1;
		if(aeroid_list[mid]<key)
			low=mid+1;
	}
		
	
	if(flag)
		return mid;
	else
		return -1;
	
}
void aeroplane::search3(string key)
{
	int pos=0,add;
	fstream file;
	buffer3.erase();
	
	pos=search_index3(key);
	gotoxy(40,9);
		cout<<pos;
	
	gotoxy(40,10);
	if(pos==-1)
		cout<<endl<<"record NOT found"<<endl;
	else if(pos>=0)
	{
		file.open("aeroplane.txt");
		add=address_list[pos];
		file.seekp(add,ios::beg);
		getline(file,buffer3);
		//gotoxy(40,10);
		cout/*<<"record found...."*/<<buffer3;
		file.close();
	}
}
void aeroplane::remove3(string key)
{
	int pos=0,i,address;
	fstream file;
	pos=search_index3(key);
	if(pos>=0)
	{
		file.open("aeroplane.txt",ios::out|ios::in);
		address=address_list[pos];
		file.seekp(address,ios::beg);
		file.put('*');
		file.close();
		cout<<"\n record deleted";
		for(i=pos;i<count;i++)
		{
			aeroid_list[i]=aeroid_list[i+1];
			address_list[i]=address_list[i+1];
		}
		count--;
	}
	else
	cout<<"record not found\n";
}


//-------------------------------------------------------------------------------------------------------------------------------------------------
//accomodation
//---------------------------------------------------------------------------------------------------------------------------------------------------------


void accomodation::main4(){
	int op1;
	accomodation a;
	while(1){
		system("cls");
		system("COLOR 1F");
		frame();
		gotoxy(48,8);
		cout<<"1.ACCOMODATE AIRCRAFT IN AIRPORT ";
		gotoxy(48,10);
		cout<<"2.BACK";
		gotoxy(48,12);
		cout<<"Select your option : ";
		op1=getch();
		if(op1=='1')
		{
			a.read_data4();
			a.pack4();
			a.write_to_file4();
			gotoxy(40,15);
			cout<<"Accomodation done for the selected aircraft....";
			Sleep(1000);
		}
		else if(op1=='2'){
			mainp p;
			p.menupage();
		}	
		else
		{
			gotoxy(50,16);cout<<"INVALID INPUT...TRY AGAIN!!!";
			Sleep(1000);			
			system("cls");						
		}
	}
}
void accomodation::read_data4(){
	system("cls");
	system("COLOR 1F");
	frame();
	gotoxy(40,8);
	cout<<"Aircraft id:";
	cin>>aeroplaneid;
	gotoxy(40,9);
	cout<<"Airport id:";
	cin>>airportid;
	gotoxy(40,10);
	cout<<"Lane Number:";
	cin>>laneno;
}
void accomodation::pack4()
{
	string temp;
	buffer4.erase();
	buffer4+=aeroplaneid+'|'+airportid+'|'+laneno+'$'+'\n';
}
void accomodation :: write_to_file4()
{
	int pos;
	fstream file;
	file.open("accomodation.txt",ios::out|ios::app);
	pos=file.tellp();
	file<<buffer4;
	file.close();
	
}
/*void accomodation::display4(string acid,string aiid)
{
	accomodation a;
	acid=a.aeroplaneid;
	aiid=a.airportid;
	cout<<"Airport details";
}*/
void accomodation::unpack4()
{
	int ch=1,i=0;
	aeroplaneid.erase();
	while(buffer4[i]!='|')
	aeroplaneid+=buffer4[i++];
	airportid.erase();
	i++;
	while(buffer4[i]!='|')
	airportid+=buffer4[i++];
	laneno.erase();
	i++;
	while(buffer4[i]!='$')
	laneno+=buffer4[i++];
	
}
int accomodation::search4(string key)
{
	ifstream file;
	int flag=0,pos=0;
	file.open("accomodation.txt",ios::in);
	while(!file.eof())
	{
		buffer4.erase();
		pos=file.tellg();
		getline(file,buffer4);
		unpack4();
		if(key==aeroplaneid)
		{
			gotoxy(40,10);
			cout<<"found the key .the record is...";
			gotoxy(40,11);
			cout<<buffer4;
			flag=1;
			return pos;
		}
	}
	file.close();
	if(flag==0)
	{
		gotoxy(40,10);
		cout<<"not found..";
		return -1;
	}
}
//------------------------------------------------------------------------------------
//search aeroplane
//-------------------------------------------------------------------------
void sa::main5(){
	int op1;
	accomodation a;
	string key;
	while(1){
		system("cls");
		system("COLOR 1F");
		frame();
		gotoxy(48,8);
		cout<<"1.TRACK AIRCRAFT ";
		gotoxy(48,10);
		cout<<"2.BACK";
		gotoxy(48,12);
		cout<<"Select your option : ";
		op1=getch();
		if(op1=='1')
		{
			system("cls");
			system("COLOR 1F");
			frame();
			gotoxy(40,8);
			cout<<"enter the aircraft id:";
			cin>>key;
				
			a.search4(key);
			Sleep(5000);
		}
		else if(op1=='2'){
			mainp p;
			p.menupage();
		}	
		else
		{
			gotoxy(50,16);cout<<"INVALID INPUT...TRY AGAIN!!!";
			Sleep(1000);			
			system("cls");						
		}
	}
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
//main page
//---------------------------------------------------------------------------------------------------------------------------------------------------

int main() {//int argc, char** argv
	mainp q;
	scroll_note();
	Sleep(10);
	q.login();
	
	return 0;
}
