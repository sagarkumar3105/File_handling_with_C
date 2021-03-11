/*This program is meant to be used a a reception of a hospital or any other place so that the hospital can maintain some record. Here a few of the
charges have been pre-fixed for increasing the easy of understandibilty. The charges which are fixed are as follow
1. Common Doctor's Charge : 500
2. Cost of Each Day in ICU : 300
3. Cost of Each Day in Patient's Ward : 250
This program offers a variety of functions to the user. Those functions are:
1. Adding a new record
2. searching a particular record
3. editing a record
4. generating bills and calculating payable amount
5. Checking the complete patient's database
6. checking the bill report
7. Deleting the complete database
Key features of the programs are:
*Only the concerned authority can delete the database as it requires a code verification
*The user only needs to maintain the Patients' database and database for doctor is automaticaly updated
*Doctor's database is depended on the patient
*One can easily make changes to the recorded information.  */
#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<iomanip.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>


//--------------------------------------------------|MISCELLANEOUS FUNCTIONS|------------------------------------------------------

 void clrscr()
{
    system("cls");
}

void head()     //PATIENT FRAME
{
  cout<<setw(64)<<"\n\tษ"<<"อออออออ"<<"ห"<<"อออออออออออออออออออออออออออออ"<<"ห"<<"อออออออออออ"<<"ห"<<"อออออออ"<<"ป";
  cout<<"\n\tบ"<<setw(4)<<"ID"<<setw(4)<<"บ"<<setw(15)<<"Name"<<setw(15)<<"บ"<<setw(8)<<"Gender"<<setw(4)<<"บ"<<setw(4)<<"Age"<<setw(4)<<"บ";
  cout<<setw(64)<<"\n\tฬอออออออฮอออออออออออออออออออออออออออออฮอออออออออออฮอออออออน";

}
void tail()    //PATIENT FRAME
{
    cout<<"\n\tศอออออออสอออออออออออออออออออออออออออออสอออออออออออสอออออออผ";
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void dhead()    //DOCTOR FRAME
{
  cout<<setw(84)<<"\nษ"<<"อออออออ"<<"ห"<<"อออออออออออออออออออออออออออออ"<<"ห"<<"ออออออออออออออ"<<"ห"<<"ออออออออ"<<"ห"<<"ออออออ"<<"ห"<<"ออออออ"<<"ป";
  cout<<"\nบ"<<setw(4)<<"ID"<<setw(4)<<"บ"<<setw(20)<<"Doctor's Name"<<setw(10)<<"บ"<<setw(10)<<"Disease"<<setw(5)<<"บ"<<setw(5)<<"ICU"<<setw(4)<<"บ"<<setw(4)<<" Ward"<<setw(2)<<"บ"<<setw(6)<<"CHARGE"<<"บ";
  cout<<"\nฬอออออออฮอออออออออออออออออออออออออออออฮออออออออออออออฮออออออออฮออออออฮออออออน";

}
void dtail()    //DOCTOR FRAME
{
   cout<<"\nศอออออออสอออออออออออออออออออออออออออออสออออออออออออออสออออออออสออออออสออออออผ";

}
//--------------------------------------------------------|RESET|--------------------------------------------------------------------
void wipeout()
{
 clrscr();
 remove("PATIENT.DAT");
 remove("DOCTOR.DAT");
 cout<<"\n\t\t\tSystem RESET Successful";
 getch();
}
//-----------------------------------------------|PATIENT CLASS|-------------------------------------------------------------------------
class Patient
{
    char name[30], gnd;
    int id, age;
public:

    void getInfo()      //To Take Values
    {
	cout<<"\nEnter Patient's Name:"; gets(name);
	cout<<"\nEnter Patient's ID:"; cin>>id;
	cout<<"\nEnter Patient's Gender[M/F/T]:"; cin>>gnd;
	cout<<"\nEnter Patient's Age:"; cin>>age;
    }
    int rId(){return id;}    //Accessor Function

    void showInfo() //Display Formate
    {
	char sx[7];
	if(toupper(gnd)=='M')
	    strcpy(sx,"MALE");
	else if(toupper(gnd)=='F')
		strcpy(sx,"FEMALE");
	    else if(toupper(gnd)=='T')
		strcpy(sx,"TRANS");
		 else
		strcpy(sx,"ERROR");


       cout<<setw(64)<<"\n \tฬ-------ฮ-----------------------------ฮ-----------ฮ-------น";

	   cout<<"\n\tบ"<<setw(4)<<id<<setw(4)<<"บ"<<setw(15)<<name<<setw(15)<<"บ"<<setw(8)<<sx<<setw(4)<<"บ"<<setw(4)<<age<<setw(4)<<"บ";

    }
    void modification();    //To Make changes in Data
}ob;

//--------------------------------------------------|DOCTOR CLASS|---------------------------------------------------------------------------
class Doctor : private Patient // Inheriting the class
{

    char dname[30], dsname[30];
    int NDICU, NDAD;
    float calCharge()
    {
	float charges=500+(NDICU*300)+(NDAD*250);
	return charges;
    }
public:

    void Enter()        //To Take Values
    {
	cout<<"\nEnter Consulting Doctor's Name:"; gets(dname);
	cout<<"\nEnter Name of Disease or C/O:"; gets(dsname);
	cout<<"\nEnter  Number of Days ICU Used [If Any]:"; cin>>NDICU;
	cout<<"\nEnter Number of Days Spent in Wards:"; cin>>NDAD;
	calCharge();
    }

    void Disp()     //Display Formate
    {
       cout<<setw(64)<<"\nฬ-------ฮ-----------------------------ฮ--------------ฮ--------ฮ------ฮ------น";

	   cout<<"\nบ"<<setw(4)<<ob.rId()<<setw(4)<<"บ"<<setw(15)<<dname<<setw(15)<<"บ"<<setw(10)<<dsname<<setw(5)<<"บ"<<setw(5)<<NDICU<<setw(4)<<"บ"<<setw(3)<<NDAD<<setw(4)<<"บ"<<setw(4)<<calCharge()<<setw(3)<<"บ";

    }

}od;
//----------------------------------------------|TO MODIFY RECORDS|-------------------------------------------------------------------------
void Patient::modification()
    {
    char choice;
    //-------------------------FOR NAME-----------------------
    cout<<"\nDo you want to change patient's name[Y/N]:";cin>>choice;
    if(toupper(choice)=='Y')
       {
	cout<<"\nEnter new name:"; gets(name);
       }
    else
	cout<<"\nName: No Change\n";
    //--------------------------FOR GENDER-----------------------
    cout<<"\nDo you want to change Gender[Y/N]:";cin>>choice;

    if(toupper(choice)=='Y')
	{
	 cout<<"\nEnter new Gender[M/F/T]:"; cin>>gnd;
	}
    else
	cout<<"\nGender: No Change\n";
    //-------------------------FOR AGE-----------------------------
    cout<<"\nDo you want to change age[Y/N]:";cin>>choice;
    if(toupper(choice)=='Y')
       {
	cout<<"\nEnter new Age:"; cin>>age;
       }
    else
	cout<<"\nAge: NO Change\n";
    cout<<"\n\t\t\tPress ENTER to SAVE.";
    getch(); //To take enter key

}
//----------------------------------------------------|TO ADD NEW RECORD|------------------------------------------------------------------------
void Add()
{   clrscr();
    ofstream fwrite("PATIENT.DAT", ios::app);
    if(!fwrite)
	cout<<"\n\t\t\t\tError: File not Present";
    else
    {
	char choice='Y';

	while(choice=='Y')
	{
	    clrscr();
	    ob.getInfo();
	    fwrite.write((char*)&ob,sizeof(ob));
	    cout<<"\nDo you want to ADD another record[Y-Yes/N-No]:";
	    cin>>choice;
	    choice=toupper(choice);

	}
    }
    fwrite.close();
    getch(); //To Take Enter Key
}
//---------------------------------------------|BILLING THE PAYABLE AMOUNT|----------------------------------------------------------------------------
void Billing()
{
    clrscr();
    ifstream fread("PATIENT.DAT");
    ofstream fwrite("DOCTOR.DAT", ios::app);
    if(!fread)
	cout<<"\n\t\t\t\tError: Data Not Found";
    else
    {
	char found='f';
	int ID;
	cout<<"\nEnter the ID to calculate the BILL:";
	cin>>ID;

	while(fread.read((char*)&ob,sizeof(ob)))
	{
	    if(ob.rId()==ID)

	    {

		found='t';
		head();
		ob.showInfo();
		cout<<endl;

		od.Enter();
		fwrite.write((char*)&od,sizeof(od));
	    }
	}

	if(found=='f')
	    cout<<"\n\t\t\t\tBILL Not Created";
	else
	    {
	     cout<<"\n\t\t\t\tBILL CREATED";
	     dhead();
	     od.Disp();
	     dtail();
	    }
    }
    fread.close();
    fwrite.close();
    getch();
}

//-----------------------------------------------------------|TO SEARCH A RECORD|-----------------------------------------------------------------------
void Srch()
{
    clrscr();
    ifstream fread("PATIENT.DAT");
    if(!fread)
	cout<<"\n\t\t\t\tError: Record not Present";
    else
    {
	char found='f';
	int ID;
	cout<<"\nEnter the ID to search for record:";
	cin>>ID;
	head();
	while(fread.read((char*)&ob,sizeof(ob)))
	{
	    if(ob.rId()==ID)
	    {
		found='t';
		ob.showInfo();
	    }
	}
	tail();
	if(found=='f')
	    cout<<"\n\t\t\t\tRecord not found";
	else
	    cout<<"\n\t\t\t\tRecord found";

    }
    fread.close();
    getch();
}
//---------------------------------------------------|TO DELETE A RECORD|--------------------------------------------------------------------------------
void Del()
{   clrscr();
    ifstream fread("PATIENT.DAT");
    ofstream fwrite("temp.DAT", ios::app);
    if(!fwrite && !fread)
	cout<<"\n\t\t\t\tError: Data is not Present";
    else
    {
	char found='f';
	int ID;
	cout<<"\nEnter the ID to be deleted from the records:";
	cin>>ID;
	while(fread.read((char*)&ob,sizeof(ob)))
	{
	    if(ID==ob.rId())
	    {
		found='t';
		head();
		ob.showInfo();
		tail();
		cout<<"\n\t\tPress ENTER to Confirm";getch();
	    }
	    else
	    {
	     fwrite.write((char*)&ob,sizeof(ob));
	    }
	}
	if(found=='t')
	   {
	    clrscr();
	    cout<<"\n\t\t\t\tRecord deleted";

	    remove("PATIENT.DAT");
	     rename("temp.DAT","PATIENT.DAT");
	    }
	else
	    {
	     cout<<"\n\t\t\t\tRecord Not Deleted";
	    }

    }
	fread.close();
	fwrite.close();
	getch(); //Taking Enter Key
}

//---------------------------------------------------|TO VIEW DATABASE|--------------------------------------------------------------------------
void view()
{
  clrscr();
  ifstream fread("PATIENT.DAT");
  if(!fread)
     cout<<"\n\t\t\t\tError: File is Empty";
  else
    {
	head();
	while(fread.read((char*)&ob,sizeof(ob)))
	    {
		ob.showInfo();

	    }
	tail();
    }
    fread.close();
    getch();    //Taking Enter Key
}

//-----------------------------------------------------------|To EDIT|-------------------------------------------------------------------
void Edit()
{   clrscr();
    fstream file("PATIENT.DAT",ios::in | ios::out);
     if(!file)
	cout<<"\n\t\t\t\tError: Data Not Present";
    else
	{
	    char found='f';
	int ID;
	cout<<"\nEnter ID to be Modified:";
	cin>>ID;
	int poss=0;
	while(file.read((char*)&ob,sizeof(ob)))
	{
	    if(ob.rId()==ID)
	    {
	     poss=-1*sizeof(ob);
	     file.seekp(poss,ios::cur);
	     found='t';
	     head();
	     ob.showInfo();
	     tail();
	     ob.modification();
	     file.write((char*)&ob,sizeof(ob));
	    }
	  }
	if(found=='f')
	{
	    cout<<"\n\t\t\t\tError in Modification";
	}
	else
	{
	 clrscr();
	 cout<<"\n\t\t\t\t Changes Saved";
	}
    }
	file.close();
    cout<<"\n\t\t\t\tPress 'ENTER' to go to main menu";
    getch();    //Taking Enter Key
}
//--------------------------------------------------|TO VIEW BILL REPORT|---------------------------------------------------------------
void Bill()
{  clrscr();
   ifstream dfread("DOCTOR.DAT"), fread("PATIENT.DAT");
  if(!fread)
     cout<<"\n\t\t\tError: Data not found";
  else
    {
	dhead();
	while(dfread.read((char*)&od,sizeof(od)) && fread.read((char*)&ob,sizeof(ob)))
	    {
		od.Disp();
	    }
	dtail();
    }
    fread.close();
    dfread.close();
    getch();    //Taking Enter Key
}
//---------------------------------------------------------|Login FOR RESET|------------------------------------------------------------------------
void Verify()
{
    clrscr();
    char code[20];
    char choice='n';
    cout<<"\n\t\tDo You Really Want to Reset the System[Y/N]:";cin>>choice;
    if(tolower(choice)=='y')
    {   clrscr();
	cout<<"\n\n\n\n\t\tฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ"<<"\n\t\tณ           ENTER MASTER KEY          ณ "<<"\n\t\tภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤู";

	cout<<"\n\n\t\tMASTER KEY : ";cin>>code;

	if(strcmp(code,"123")==0)
	{
	  wipeout();
	}
	else
	{
	  cout<<"\n\n \t\t\t\tIncorrect Key!!!.\nPlease Try Again Later.";
	}
    }
    else
    {   clrscr();
	cout<<endl<<endl<<"\n\t\t\t\tReseting Aborted";
	cout<<"\n\t\t\tPress Any key to Return Back";
    }
    getch();    //Taking Enter Key
}
//----------------------------------------------------------|Main Menu INTERFACE|--------------------------------------------------------------------------------

void main_menu()
{
    int m_choice;
    do
    {
	clrscr();
	cout<<"\n\n"<<setw(60)<<"ษออออออออออออออออออออออออออออออออออออป"<<endl<<setw(60)<<"บ                                    บ"<<endl<<setw(60)<<"บ         LIFE HOPE HOSPITAL         บ"<<endl<<setw(60)<<"บ                                    บ"<<endl<<setw(60)<<"ศออออออออออออออออออออออออออออออออออออผ"<<endl;
	cout<<"\n\t0. RESET THE SYSTEM";
	cout<<"\n\t1. Add New Patient";
	cout<<"\n\t2. Search A record";
	cout<<"\n\t3. Edit Patient's Details.";
	cout<<"\n\t4. Remove an Patient's Account.";
	cout<<"\n\t5. Generate Bill.";
	cout<<"\n\t6. View BILLING reports";
	cout<<"\n\t7. View Patient's Database.";
	cout<<"\n\t8. Exit";
	cout<<"\n\tEnter Your Choice[1-9]:\n";
	cin>>m_choice;
	switch(m_choice)
	{
	    case 0: Verify();
		break;

	    case 1: Add();
		break;

	    case 2: Srch();
	       break;

	    case 3: Edit();
		break;

	    case 4: Del();
		break;

	    case 5: Billing();
		break;

	   case 6: Bill();
	    break;

	    case 7: view();
		break;

	    case 8: cout<<"\n\t\t\t\tPress ENTER TO Exit";
		getch();    //taking Enter key
		exit(1);
		break;

	default:
	    cout<<"\nINVALID!!! selection Of Choice. \nEnter Correct Choice[1-9]";
	    break;
	}
    }
	while(m_choice!=9);
}
int main()
{
    main_menu();
    return 0;
}
