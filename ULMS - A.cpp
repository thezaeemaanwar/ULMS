#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<stdio.h>
#include<cctype>

using namespace std;

	string codeList[10] = {"CS101", "CS201", "CS141", "CS142", "CS143", "CS163", "MA101", "EN182", "CS342", "0"};
	string nameList[10] = {"Computing Fundamentals", "Programming Fundamentals", "Introduction to Computing", "Artificial Intelligence", "Computer Architecture", "Workshop Practice", "Calculus", "Functional English", "Applied Physice", "0"};
	int crthrsList[10] = {3, 3, 3, 2, 3, 1, 3, 1, 2, 0};
	int semList[10] = { 1 , 1 , 1, 2, 5, 5, 1, 2, 3, 0};
	
// declared Functions
bool isValidCourseCode(string CourseCode);
bool isValidCourseName(string name);
bool isValidCreditHours(int hour);
bool isValidSemester(int smstr);
void AddCourse(string code, int hrs, int semstr, string sub);
void EditCourse(string code);
void DeleteCourse(string code);
void ViewCourses();
void ViewSemesterCourses(int semester);
int action();

int main()
{
	int CC, CN, SMS, CH;
	int act;
	string CourseCode,subject;
	int crdHrs,smstr;
	
do
{	
    act=action();
	switch(act)
	{case 1:             //Add Course
	
		{
		cout << "Enter the Course details" << endl;
		cout << "Enter the Course Code: ";
		cin >> CourseCode;
		cout << "Enter the credit hours: ";
		cin >> crdHrs;
		cout << "Please enter your semester here: ";
		cin >> smstr;
		cout << "Enter the Course name: ";
		cin.ignore();
		getline(cin,subject);
		
        cout << endl << CourseCode << " " << crdHrs << " " << smstr << " " << subject<<endl;
 
	// checking for validation of Course Code
	     CC = isValidCourseCode(CourseCode);
	
	// checking for the validation of Course Name
	     CN = isValidCourseName(subject);
	     
	//checing for validation of Semester
	     SMS = isValidSemester(smstr);
	        
	// checking for validation of Credit hours
		 CH = isValidCreditHours(crdHrs);
			
		if(CC==1 && CN==1 && CH==1 && SMS==1)
		{AddCourse(CourseCode, crdHrs, smstr, subject);
		cout << "The course has been added succesfully. \n \n" ;
		}
		else
		cout << "\n You are adding wrong course details. \n Recommended revising the details. Thank You. \n \n";
			
		break;
	}
	
			case 2:       // Edit Course
				{
					cout << " Enter the course code to edit: ";
					cin >> CourseCode;
					if(isValidCourseCode(CourseCode))
					{EditCourse(CourseCode);
					}
				else
				cout << "\n You are adding wrong course details. \n Recommended revising the details. Thank You. \n \n";
			
					break;
				}
				
				case 3:
					{
						cout << "Enter the Course Code to delete: ";
						cin >> CourseCode;
						CC = isValidCourseCode(CourseCode);
						if ( CC == 1)
						{DeleteCourse(CourseCode);
					     }
					     else
					     cout << " Please enter correct code.";
						break;
					}
					
					case 4:
						{
							ViewCourses();
							break;
						}
						
						case 5:
							{cout << " Enter the semester: ";
							 cin >> smstr ;
							 ViewSemesterCourses(smstr);
							 break;
							}
			
	}	

}while(act != 6);
	return 0;
}

//definition of all the functions;

bool isValidCourseCode(string CourseCode)						// valid course code
{
	int chck[5];
  for (int i=0;i<2;i++)
  {if (isalpha(CourseCode[i]))
    chck[i] = 1;
    else
    chck[i] = 0;
  }	
  for (int j=2;j<5;j++)
  {if (isdigit(CourseCode[j]))
    chck[j] = 1;
    else
    chck[j] = 0;
  }
  if(chck[0]==1 && chck[1]==1 && chck[2]==1 && chck[3]==1 && chck[4]==1)
  {return 1;
  }

}

        	bool isValidCourseName(string name)					// valid course name
         	{
         	int l=name.length();
       	 	int chk[50];
	     	for(int n=0;n<l;n++)
	     	{if(name[n]==' '|| isalpha(name[n]) )
	     	chk[n]=1;
	     	else 
			chk[n]=0;
	     	}
         	int sum=0;
	    	for(int n=0;n<l;n++)
	    	{	sum=sum+chk[n];
	    	}	
	    	if(sum==l && l<=50)
	    	return 1;
        	}

bool isValidCreditHours(int hour)								// valid credit hours
{	if(hour == 1 || hour ==2 || hour ==3)
    return 1;
}
        	bool isValidSemester(int smstr)    					//valid semester
        	{
			 if (smstr == 1 || smstr == 2 || smstr == 3 || smstr == 4 || smstr == 5 || smstr == 6 || smstr == 7 || smstr == 8)
			  return 1;	
        	}
void AddCourse(string code, int hrs, int semstr, string sub)      // Add Course
{	
  static int y=0;
  codeList[y] = code;
  crthrsList[y] = hrs;
  semList[y] = semstr;
  nameList[y] = sub;  
}
void EditCourse(string code)                   				    // update course
{
	string ncode, sub;
	int counter = 0;
	int i = 0, n = 0, sms, hrs;
	bool CC, CN, SMS, CH;
	
	while(semList[i] != 0)
	{counter = counter + 1;
	  i = i+1 ;
	}
	
	for(int m=0 ; m<counter ; m++)
	{
		if(codeList[m] == code)
		{n = m;
		}
}
		if(n = 0)
		cout << " The course with the code "<<code<<" doesn't exist in your list.";
		
		cout << " Enter the new details of the course below: \n";
		cout << "Enter the new Course Code: ";
		cin >> ncode;
		cout << "Enter the credit hours: ";
		cin >> hrs;
		cout << "Please enter new semester here: ";
		cin >> sms;
		cout << "Enter the Course name: ";
		cin.ignore();
		getline(cin,sub);
					
	    cout << endl << ncode << " " << hrs << " " << sms << " " << sub <<endl;
 
	// checking for validation of Course Code:
	     CC = isValidCourseCode(ncode);
	
	// checking for the validation of Course Name
	     CN = isValidCourseName(sub);
	     
	//checing for validation of Semester
	     SMS = isValidSemester(sms);
	        
	// checking for validation of Credit hours
		 CH = isValidCreditHours(hrs);
			
			if(CC==1 && CN==1 && CH==1 && SMS==1)
		{
			codeList[n] = ncode;
			nameList[n] = sub;
			semList[n] = sms;
			crthrsList[n] = hrs;
			
			cout<<  " The course has been edited successfully. \n ";
		}
		else
		cout << " You are adding wrong details for the editing the Course. \n";
	
	
}
void DeleteCourse(string code)										// delete course
{
	int x = 0;
	for(int i=0 ; i<8 ; i++)
	{
		if(codeList[i] == code)
		x=i;
	}
	if( x != 0)
	{
		for(int n=x ; n<8 ; n++)
		{
			codeList[n] = codeList[n+1];
			nameList[n] = nameList[n+1];
			crthrsList[n] = crthrsList[n+1];
			semList[n] = semList[n+1];
			cout <<" The Course has been deleted successfully. \n \n";
		}
	}
	else
	cout<<"\n This Course doesn't exist in your code list. \n\n";
		
}
void ViewCourses()													// view courses
{
	cout << "\t All Courses \n ";
	cout << right << "Course Code \t Course Name \t \t Credit Hours" << setw(10) << "Semester" << endl<<endl;
	
	for(int n=0 ; n<8 ; n++)
	{
		cout << " " << codeList[n] << "\t \t" << nameList[n] << setw(20) << crthrsList[n] << setw(10) << semList[n] << endl;
	}
	cout<<endl;
	
}

void ViewSemesterCourses(int semester)								// view semester courses
{
	string sub1, sub2, sub3, sub4, sub5, sub6, sub7, sub8;
	string n1, n2, n3, n4, n5, n6, n7, n8;
	int h1, h2, h3, h4, h5, h6, h7, h8;
	
	switch(semester)
	{case 1:
		{ sub1 = "CS101"; sub2 = "CS102"; sub3 = "CS110"; sub4 = "CS112"; sub5 = "CS141";
		  sub6 = "CS142"; sub7 = "CS131"; sub8 = "CS132";
		  n1 = "Progrmming Fundamentals"; n2 = "Programing Fundamentals lab"; n3 = "Introduction to Computing"; n4 = "Introduction to Computing lab";
		  n5 = "Humanities"; n6 = "Applied Physics"; n7 = "Woekshop Practice"; n8 = "Physics lab";
		  h1 = 3; h2 = 2; h3 = 3; h4 = 3;
		  h5 = 2; h6 = 3; h7 = 1; h8 = 2;
		  break;
		}
		case 2:
			{sub1 = "FG567"; sub2 = "AD302"; sub3 = "RF231"; sub4 = "NP101"; sub5 = "DC333";
		  sub6 = "WE343"; sub7 = "NB100"; sub8 = "ER343";
		  n1 = "Ornithology"; n2 = "Herpetology"; n3 = "Mammalogy"; n4 = "fundamentals of science"; 
		  n5 = "Toxicology"; n6 = "Herpeology"; n7 = "Ethics"; n8 = "Islamiat";           
		  h1 = 2; h2 = 3; h3 = 1; h4 =2;
		  h5 = 3; h6 = 3; h7 = 2; h8 = 3;
		  
			break;
		}
		case 3:
			{ sub1 = "FG345"; sub2 = "CS553"; sub3 = "CS653"; sub4 = "CE462"; sub5 = "TY567";
		  sub6 = "RT453"; sub7 = "GH657"; sub8 = "CS556";
		  n1 = "Computing Fundamentals"; n2 = "Objece OP"; n3 = "Mechanics"; n4 = "Mechanics lab";
		  n5 = "CF lab"; n6 = "OOP lab"; n7 = "Islamic Studies"; n8 = "Pak Studies";
		  h1 = 2; h2 = 3; h3 = 3; h4 = 3;
		  h5 = 2; h6 = 3; h7 = 1; h8 = 2;
		  
		  break;
		}
		case 4:
			{ sub1 = "GH675"; sub2 = "HJ367"; sub3 = "TY654"; sub4 = "TY464"; sub5 = "FB647";
		  sub6 = "CS435"; sub7 = "CE536"; sub8 = "YU567";
		  n1 = "Cyber Security"; n2 = "Web Development"; n3 = "Visual Studio"; n4 = "Cyber Security lab";
		  n5 = "Humanities II"; n6 = "Web Development lab"; n7 = "Applied Mechaics"; n8 = "Mechanics lab";
		  h1 = 3; h2 = 2; h3 = 1; h4 = 3;
		  h5 = 2; h6 = 1; h7 = 3; h8 = 2;
		  
		  break;
		}
		case 5:
			{sub1 = "GH657"; sub2 = "GG647"; sub3 = "GH467"; sub4 = "YG647"; sub5 = "HK959";
		  sub6 = "TY356"; sub7 = "HN646"; sub8 = "TY566";
		  n1 = "fyjfmb"; n2 = "uzcsjm"; n3 = "chjhsbajv"; n4 = "cusjchg hvasj";
		  n5 = "udjvh hhjf"; n6 = "huj jhf"; n7 = "bfjhjm "; n8 = "dhfjhdjs fh";
		  h1 = 2; h2 = 3; h3 = 2; h4 = 3;
		  h5 = 3; h6 = 2; h7 = 1; h8 = 1;
		  
		  break;
		}
		case 6:
			{ sub1 = "GH466"; sub2 = "HJ647"; sub3 = "UJ647"; sub4 = "JN675"; sub5 = "JB765";
		  sub6 = "YU646"; sub7 = "GH678"; sub8 = "GH467";
		  n1 = "GJDG"; n2 = "jhfhs"; n3 = "fjfj"; n4 = "fjfjam";
		  n5 = "fhfba"; n6 = "njfh"; n7 = "jaefjna"; n8 = "fjfnawifk";
		  h1 = 2; h2 = 3; h3 = 1; h4 = 3;
		  h5 = 4; h6 = 3; h7 = 2; h8 = 1;
		  
		  break;
		}
		case 7:
			{ sub1 = "ER345"; sub2 = "RT564"; sub3 = "RG567"; sub4 = "TY567"; sub5 = "TH567";
		  sub6 = "TH566"; sub7 = "JN566"; sub8 = "HB567";
		  n1 = "hbjmnllk"; n2 = "yhvhjj"; n3 = "yhbnmn"; n4 = "ghfgj";
		  n5 = "hkjnvs"; n6 = "vzujnvz"; n7 = "duivjznf"; n8 = "cusjfn";
		  h1 = 2; h2 = 3; h3 = 1; h4 = 3;
		  h5 = 2; h6 = 1; h7 = 3; h8 = 2;
		  
		  break;
		}
		case 8:
			{ sub1 = "GH672"; sub2 = "GH467"; sub3 = "HJ467"; sub4 = "HJ647"; sub5 = "GH644";
		  sub6 = "JK467"; sub7 = "JJ446"; sub8 = "JH464";
		  n1 = "JHDVH"; n2 = "fjhf"; n3 = "fhuaf"; n4 ="fah";
		  n5 = "fhwaf"; n6 = "fjanf"; n7 = "snf"; n8 = "jfnad";
		  h1 = 2; h2 = 2; h3 = 3; h4 = 1;
		  h5 =3 ; h6 = 3; h7 = 1; h8 = 2;
		  
		  break;
		}
	}
	string code[8] = {sub1, sub2, sub3, sub4, sub5, sub6, sub7, sub8};
	string name[8] = {n1, n2, n3, n4, n5, n6, n7, n8};
	int hours[8] = {h1, h2, h3, h4, h5, h6, h7, h8};
	
	cout << right << "Course Code \t Course Name \t \t Credit Hours" << endl<<endl;
	
	for(int n=0 ; n<8 ; n++)
	{
		cout << " " << code[n] << "\t \t" << name[n] << setw(10) << hours[n] << endl;
	}
	cout<<endl;
}

int action()														// choosing action
{   // system("cls");
    int action,n=5;
    cout<<"** Welcome to University Learning Managment System ** \n \n";
	cout<<"1    Add Course"<<endl;
	cout<<"2    Update Course"<<endl;
	cout<<"3    Delete Course"<<endl;
	cout<<"4    View All Courses"<<endl;
	cout<<"5    View Course of a semester"<<endl;
	cout<<"6    Exit Program"<<endl;
	cout<<endl<<setw(5)<<" Enter the number of action you want to perform. \n ";
	cin>>action;
	
	if(action > 6 || action < 1)
    cout<<"\n Please choose from the given options. \n";	
	
	cout<<endl;
	return action;
}


