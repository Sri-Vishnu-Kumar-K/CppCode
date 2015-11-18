#include <process.h>
#include <dos.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#pragma pack(2)
struct CStudent
{
public:
    char name[64];
    int marks[5];
    int total;
};

struct CStudents
{
    #define MaxSz  100
    char m_fileName[1024];
    int m_nMaxStudents;
    CStudent m_studList[MaxSz];

    CStudents(const char *filename);

    void AddRecord(const char *name, int *marks);
    void EditRecord(int pos, const char *name, int *marks);
    void DeleteRecord(int pos);
    int ReadRecords();
    int WriteRecords();
};

CStudents::CStudents(const char *filename)
{
      m_nMaxStudents = 0;
      strcpy(m_fileName, filename);
}

void CStudents::AddRecord(const char *name, int *marks)
{
      int pos = m_nMaxStudents;
      strcpy(m_studList[pos].name,name);
      m_studList[pos].total = 0;
      for(int i = 0; i < 5; i++)
      {
            m_studList[pos].marks[i] = marks[i];
            m_studList[pos].total += marks[i];;
      }
      m_nMaxStudents++;
      WriteRecords();
}

void CStudents::EditRecord(int pos, const char *name, int *marks)
{
      strcpy(m_studList[pos].name,name);
      m_studList[pos].total = 0;
      for(int i = 0; i < 5; i++)
      {
            m_studList[pos].marks[i] = marks[i];
            m_studList[pos].total += marks[i];
      }
      WriteRecords();
}

void CStudents::DeleteRecord(int pos)
{
      m_nMaxStudents--;

      for(int i = pos; i < m_nMaxStudents; i++)
      {
          m_studList[i] = m_studList[i + 1];
      }
      WriteRecords();
}

int CStudents::ReadRecords()
{
      FILE *istream = fopen(m_fileName, "rb");

      if (istream == 0)
          return 0;

      char buf[4096];
      int nTotalRecordsRead = 0;

      for(int i = 0; i < MaxSz; i++)
      {
          if(feof(istream))
            break;
          int nBytesRead = fread(buf, 1, sizeof(CStudent), istream);
          if(nBytesRead < sizeof(CStudent))
            break;
          char *p = (char*)(&m_studList[i]);
          memcpy(p, buf, sizeof(CStudent));
          nTotalRecordsRead++;
      }

      fclose(istream);
      m_nMaxStudents = nTotalRecordsRead;

      return nTotalRecordsRead;
}

int CStudents::WriteRecords()
{
      FILE *ostream = fopen(m_fileName, "wb");

      if (ostream == 0)
          return 0;

      int nTotalRecordsWritten = 0;
      char buf[4096];
      for(int i = 0; i < m_nMaxStudents; i++)
      {
          fwrite((char*)&m_studList[i], 1, sizeof(CStudent), ostream);
          nTotalRecordsWritten++;
      }

      fclose(ostream);

      return nTotalRecordsWritten;
}


CStudents theStudents("c:\\marklist.bin");


int DisplayMainMenu()
{

    gotoxy(10,4);
    cout << "Welcome to Student MarkList Application";

    gotoxy(10,5);
    cout << "___________________________________________";

    gotoxy(10,6);
    cout << "1. Add Student Mark List";

    gotoxy(10,7);
    cout << "2. Edit Student Mark List";

    gotoxy(10,8);
    cout << "3. View Student Mark List";

    gotoxy(10,9);
    cout << "4. Delete Student Mark List";

    gotoxy(10,10);
    cout << "5. Exit";

    gotoxy(10,11);
    cout << "___________________________________________";

    gotoxy(10,13);
    cout << "Enter your Selection: ";
    int m = -1;
    cin >> m;

    return m;
}

void ViewRecords()
{
    theStudents.ReadRecords();

    gotoxy(10,4);
    cout << "Welcome to Student Mark List Application";

    gotoxy(10,5);
    cout << "_______________________________________________________________";

    gotoxy(10,6);
    cout << "SNo Student Name       Sub1   Sub2   Sub3   Sub4   Sub5   Total";

    gotoxy(10,7);
    cout << "_______________________________________________________________";

    int pos = 8;
    // Enable Paging
    for(int i = 0; i < theStudents.m_nMaxStudents; i++)
    {
      gotoxy(10,pos);
      cout << i + 1;
      gotoxy(14,pos);
      cout << theStudents.m_studList[i].name;
      gotoxy(33,pos);
      cout << theStudents.m_studList[i].marks[0];
      gotoxy(40,pos);
      cout << theStudents.m_studList[i].marks[1];
      gotoxy(47,pos);
      cout << theStudents.m_studList[i].marks[2];
      gotoxy(54,pos);
      cout << theStudents.m_studList[i].marks[3];
      gotoxy(61,pos);
      cout << theStudents.m_studList[i].marks[4];
      gotoxy(68,pos);
      cout << theStudents.m_studList[i].total;
      cout<<endl;cout<<endl;cout<<endl;
      if(theStudents.m_studList[i].total>90)
	{
	cout<<"you have secured an excellent score \n";
	cout<<"ANALYST PREDICTION :\n ";
	cout<<"PROCEED WITH HIGHER STUDIES  ";
	cout<<"YOU HAVE A BRIGHT FUTURE ";
	}

	 if((theStudents.m_studList[i].total>70) && (theStudents.m_studList[i].total<90))
	{
	cout<<"you have secured a good score \n";
	cout<<"ANALYST PREDICTION :\n ";
	cout<<"PROCEED WITH HIGHER STUDIES IF YOU ARE GOOD AT YOUR CORE SUBJECTS  ";
	cout<<"YOU HAVE A BRIGHT FUTURE ";
	}

	 if((theStudents.m_studList[i].total<70) && (theStudents.m_studList[i].total>50 ) )
	{
	cout<<"you have secured a moderate score \n";
	cout<<"ANALYST PREDICTION :\n ";
	cout<<"GO FOR A JOB  ";
	cout<<"YOU HAVE A BRIGHT FUTURE ";
	}

	 if(theStudents.m_studList[i].total<50)
	{
	cout<<"you have secured a below par score \n";
	cout<<"ANALYST PREDICTION :\n ";
	cout<<"GO FOR A JOB AND STUDY HARD ";

	}


      pos++;
    }
    gotoxy(10,pos++);
    cout << "_______________________________________________________________";
    pos++;
    gotoxy(10,pos++);
}


void InputRecords()
{
    while(1)
    {

      gotoxy(10,4);
      cout << "Welcome to Student Mark List Application";

        gotoxy(10,5);
      cout << "__________________________________________________________";

      gotoxy(10,6);
      cout << "Student Name: ";

      gotoxy(10,7);
      cout << "Sub1 Mark: ";

      gotoxy(10,8);
      cout << "Sub2 Mark: ";

      gotoxy(10,9);
      cout << "Sub3 Mark: ";

      gotoxy(10,10);
      cout << "Sub4 Mark: ";

      gotoxy(10,11);
      cout << "Sub5 Mark: ";

      gotoxy(10,12);
      cout << "__________________________________________________________";

      gotoxy(23,6);
      char name[64];
      cin >> name;

      int marks[5];
      for(int i = 0; i < 5; i++)
      {
            gotoxy(23,7 + i);
            cin >> marks[i];
      }

      theStudents.AddRecord(name, marks);

      gotoxy(10,14);
      cout << "Do you want to add another record (Y/N)? ";
        char ch = getchar();

      if(ch == 'Y' || ch == 'y')
          continue;
      else
          break;
    }
}


void EditRecords()
{
    ViewRecords();
    cout << "Enter the serial number you want to edit: ";
    int m;
    cin >> m;

    if(m >= 1 && m <= theStudents.m_nMaxStudents)
    {
      gotoxy(10,4);
      cout << "Welcome to Student Mark List Application";

      gotoxy(10,5);
      cout << "__________________________________________________________";

      gotoxy(10,6);
      cout << "Student Name: ";

      gotoxy(10,7);
      cout << "Sub1 Mark: ";

      gotoxy(10,8);
      cout << "Sub2 Mark: ";

      gotoxy(10,9);
      cout << "Sub3 Mark: ";

      gotoxy(10,10);
      cout << "Sub4 Mark: ";

      gotoxy(10,11);
      cout << "Sub5 Mark: ";

      gotoxy(10,12);
      cout << "__________________________________________________________";

      gotoxy(23,6);
      char name[64];
      cin >> name;

      int marks[5];
      for(int i = 0; i < 5; i++)
      {
            gotoxy(23,7 + i);
            cin >> marks[i];
      }

      theStudents.EditRecord(m - 1, name, marks);
      gotoxy(10,12);
      cout << "Record updated. Press any key to return to Main Menu";
    }
    else
    {
      gotoxy(10,12);
      cout << "Invalid Entry. Press any key to return to Main Menu";
    }

}

void DeleteRecords()
{
    ViewRecords();
    cout << "Enter the serial number you want to delete: ";
    int m;
    cin >> m;
    if(m >= 1 && m <= theStudents.m_nMaxStudents)
    {
        theStudents.DeleteRecord(m - 1);
      cout << "Record deleted. Press any key to return to Main Menu";
    }
    else
    {
      cout << "Invalid Entry. Press any key to return to Main Menu";
    }
}

int main()
{
    theStudents.ReadRecords();
    string username,password;
    cout<<"Enter your username"<<endl;
    cin>>username;
    cout<<"Enter your password"<<endl;
    cin>>password;
    if(username == "TechStu" && password == "group1"){
    while(1)
    {
        int selection = DisplayMainMenu();

      switch(selection)
      {
        case 1:
            InputRecords();
          break;
      case 2:
            EditRecords();
            break;
      case 3:
            {
          ViewRecords();
          cout << "Press any key to return to Main Manu: ";
          }
            break;
        case 4:
          DeleteRecords();
            break;

        case 5:
      default:
          return 0;
        };
    }
    }
    return 0;
}
