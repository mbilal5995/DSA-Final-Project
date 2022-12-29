#include<conio.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<string>
using namespace std;
bool check = true;
struct node    //structure of node //------using circular linked list---------//
{
 char name[20];
 char discipline[20];
 int rollNo;
 char section;
 node *next;
}*head,*lastptr;

void add()    //Adds record of student//
{
 node *p;
 p=new node;
 cout<<"Enter name of student:"<<endl;
 cin.ignore();
 gets(p->name);
 fflush(stdin);
 cout<<"Enter discipline of student:"<<endl;
 gets(p->discipline);
 fflush(stdin);
 cout<<"Enter Roll Number of student:"<<endl;
 cin>>p->rollNo;
 fflush(stdin);
 cout<<"Enter section of student:"<<endl;
 cin>>p->section;
 fflush(stdin);
 p->next=NULL;

 if(check)
 {
  head = p;
  lastptr = p;
  check = false;
 }
 else
 {
  lastptr->next=p;
  lastptr=p;
 }
 cout<<endl<<"Record Entered";
 getch();
}
void modify()   //modifies record of student//
{
 node *ptr;
 node *prev=NULL;
 node *current=NULL;
 int roll_no,flag=0;
 cout<<"Enter Roll Number to modify:"<<endl;
 cin>>roll_no;
 prev=head;
 current=head;
 node *f=head;
 while(f!=NULL)   //same search algo
 {
 if(current->rollNo==roll_no)
 {
 flag=1;
 ptr=new node;
 fflush(stdin);
 cout<<"Enter name of student:"<<endl;
 gets(ptr->name);
 fflush(stdin);
 cout<<"Enter discipline of student:"<<endl;
 gets(ptr->discipline);
 fflush(stdin);
 cout<<"Enter Roll Number of student:"<<endl;
 cin>>ptr->rollNo;
 fflush(stdin);
 cout<<"Enter section of student:"<<endl;
 cin>>ptr->section;
 fflush(stdin);
 ptr->next=current->next;
 prev->next=ptr;
 cout<<"Modified";
 getch();
 return;
  }
 else
 {
  prev=current;
  current=current->next;
 }
 f=f->next;
}
if(flag!=1)
{
	cout<<"such roll-no does not exist in our system";
}
}
void search()   //searches record of student//
{
 node *prev=NULL;
 node *current=NULL;
 node *f=head;
 int roll_no,flag=0;
 cout<<"Enter Roll Number to Search:"<<endl;
 cin>>roll_no;
 prev=head;
 current=head;
 while(f!=NULL)
 {
 	
 if(current->rollNo==roll_no)
 {
 
  flag=1;
 cout<<"\n--------Found Successfully---------\n";
 cout<<"\nname: ";
 puts(current->name);
 cout<<"\nRoll No:";
 cout<<current->rollNo;
 cout<<"\nDiscipline:";
 puts(current->discipline);
 cout<<"\nSection:";
 cout<<current->section;
 getch();
 return;
 }
 else
 {
  prev=current;
  current=current->next;	
 }
 f=f->next;	
 }
 if(flag!=1)
 {
 cout<<"such roll-no does not exist in our system";	
 }
 getch();
}
void del()    //deletes record of a student//
{
 
 node *prev=head;
 node *current=head;
 node *f=head;
 int roll_no,flag=0;
 cout<<"Enter Roll Number to Delete:"<<endl;
 cin>>roll_no;
 while(f!=NULL)
 {
 if(current->rollNo==roll_no)
 {
 flag=1;
 cout<<"\n--------Deleted Successfully---------\n";
 prev->next=current->next;
 current->next=NULL;
 delete current;
 
 getch();
 return;
 }
 else
 {
  prev=current;
  current=current->next;	
 }
 f=f->next;	
 }
 if(flag!=1)
 {
 cout<<"such roll-no does not exist in our system";	
 }
 getch();
 
}

int main()
{
 system("color 8B");
 char ans;
 start:
 cout<<"Are you a registered user ? Press y for Yes or n for No ";
 cin>>ans;
 if(ans=='Y'||ans=='y')
 {
 	
 	system("cls");
 	ifstream file("namepass.txt");  //create file for input
 	
 	while(!file.eof())              //as long as end of file is not encountered
 	{
 	     string s,p;
		getline(file,s,'\n');      //read a line of text and store in s
		getline(file,p,'\n');
		file.close();
		string name,pass;
		label:
		cout<<"Enter your name :";
		cin>>name;
		cout<<"Enter your password :";
		cin>>pass;
		if(name==s&&pass==p)
		{
			system("cls");
          char x;
          cout<<"\t\t _________________________ \t\t\t"<<endl;
          cout<<"\t\t STUDENT MANAGEMENT SYSTEM \t\t\t"<<endl;
          cout<<"\t\t _________________________ \t\t\t"<<endl;
          cout<<"\n\nPress Any Key To Continue . . . ."<<endl;
          getch();
          do
          {
             system("cls");
             cout<<"\t\t STUDENT MANAGEMENT SYSTEM \t\t\t"<<endl;
             cout<<"1--->Press '1' to add New record:"<<endl;
             cout<<"2--->Press '2' to search a record:"<<endl;
             cout<<"3--->Press '3' to modify a record:"<<endl;
             cout<<"4--->Press '4' to delete a record:"<<endl;
             cout<<"5--->Press '5' to exit:"<<endl;
             x=getch();
             if(x=='1')
              {
                 system("cls");
                 add();
              }
             else if(x=='2')
              {
                 system("cls");
                 search();
              }
             else if(x=='3')
              {
                 system("cls");
                 modify();
              }
             else if(x=='4')
              {
                 system("cls");
                  del();
              }
             else if(x=='5')
              {
                  exit(0);
              }
             else
              {
               }
          }while(x !=27);
        }
        else
        {
        	system("cls");
        	cout<<"You entered wrong name or password...Try again"<<endl;
        	goto label;
		}
    }
}
else
{
	char ch;
	system("cls");
	cin.ignore();
	string reg_name,reg_pass;
     cout<<"Enter a name :";
     cin>>reg_name;
     cout<<"Enter a pass :";
	cin>>reg_pass;
     ofstream file("namepass.txt",ios::app);  //create file for output
     file<<reg_name<<'\n'<<reg_pass;
     file.close();
     cout<<"Successfully registered"<<endl;
     cout<<"\t\tDo you want to start the system now?(y/n)";
     cin>>ch;
     if(ch=='Y'||ch=='y')
     goto start;
     else 
     exit(0);
}
 getch();
}

