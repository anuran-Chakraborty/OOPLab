#include<iostream>
#include"library.h"

using namespace std;

class Library;

int main(){
	Library l;
	int c,ch,flag;
	do{
		cout<<"1. Enter new"<<endl;
		cout<<"2. Issue"<<endl;
		cout<<"3. Return"<<endl;
                cout<<"4. Display"<<endl;
                cout<<"5. Increase quantity of books"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Enter choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"1. Student\n2. Faculty\n3. Book\n 4. Journal\n Enter choice\n";
				do{
					flag=1;
					cin>>c;
					switch(c){
						case 1:
							l.addStudent();
							break;
						case 2:
							l.addFaculty();
							break;
						case 3:
							l.addBook();
							break;
						case 4:
							l.addJournal();
							break;
						default:
							flag=0;
							cout<<"Wrong choice...Enter again\n";
					}
				}while(flag==0);
				break;
			case 2:
				cout<<"1.Book\n2.Journal\nEnter choice\n";
				do{
					flag=1;
					cin>>c;
					switch(c){
						case 1:
							l.issueBook();
							break;
						case 2:
							l.issueJournal();
							break;
						default:
							cout<<"Wrong choice...Enter again\n";
							flag=0;
					}
				}while(flag==0);
				break;
			case 3:
				cout<<"1.Book\n2.Journal\nEnter choice\n";
				do{
					flag=1;
					cin>>c;
					switch(c){
						case 1:
							l.returnBook();
							break;
						case 2:
							l.returnJournal();
							break;
						default:
							cout<<"Wrong choice...Enter again\n";
							flag=0;
					}
				}while(flag==0);
				break;
                               
                        case 4:
                            cout<<"\t\t*****STUDENT LIST*****"<<endl;
                            l.dispStudents();
                            cout<<"\t\t*****FACULTY LIST*****"<<endl;
                            l.dispFaculty();
                            cout<<"\t\t*****BOOK LIST*****"<<endl;
                            l.dispBooks();
                            cout<<"\t\t*****JOURNAL LIST*****"<<endl;
                            l.dispJournals();
                            cout<<"\t\t*****TRANSACTION LIST*****"<<endl;
                            l.dispTrans();
                            break;
                        case 5:
                            l.addQuantityBook();
                            break;
                        
			case 6:
				cout<<"Exiting...Thank you!!!\n";
				break;
			default:
				cout<<"Wrong choice...Enter again\n";
		}
	}while(ch!=6);
}