#include<bits/stdc++.h>
#include<fstream>
using namespace std;
ifstream fin;
ofstream fout;
class contact{
    string nameC;
    string numberC;
    string addressC;
public:
    contact(const string &name,const string &number,const string &address):nameC(name),numberC(number),addressC(address){}
    string name(){return nameC;}
    string number(){return numberC;}
    string address(){return addressC;}
    virtual void ID(){
        cout<<"no ID";
    }
    friend class favorite;
    friend class speedDial;
    friend class BlackList;
};
class favorite:public contact{
public:
    favorite(const string &name,const string &number,const string &address):contact(name,number,address){}
    string name(){return nameC;}
    string number(){return numberC;}
    string address(){return addressC;}
    void ID(){
        cout<<"favourites";
    }
};
class speedDial:public contact{
public:
    speedDial(const string &name,const string &number,const string &address):contact(name,number,address){}
    string name(){return nameC;}
    string number(){return numberC;}
    string address(){return addressC;}
    void ID(){
        cout<<"speedDy";
    }
};
class BlackList:public contact{
public:
    BlackList(const string &name,const string &number,const string &address):contact(name,number,address){}
    string name(){return nameC;}
    string number(){return numberC;}
    string address(){return addressC;}
    void ID(){
        cout<<"blacklisted";
    }
};

vector<contact*>C1;
vector<favorite*>F1;
vector<speedDial*>S1;
vector<BlackList*>B1;

int countC,countF,countS,countB;

void phonebook(){

    fin.open("phonebook.txt",ios::in);

    string name,address,number;
    int fav,spD,BL;

    while(fin){
        fin>>name>>number>>address>>fav>>spD>>BL;

        C1.push_back(new contact(name,number,address));
        if(fav) F1.push_back(new favorite(name,number,address));
        if(spD) S1.push_back(new speedDial(name,number,address));
        if(BL)  B1.push_back(new BlackList(name,number,address));
    }

    fin.close();
}
void init(){
    cout<<"\n\n\t\t\t\t"<<"===========================\n";
    cout<<"\t\t\t\t"<<"WELCOME TO PHONE DIRECTORY\n";
    cout<<"\t\t\t\t"<<"===========================\n\n\n";
    cout<<"\t\t\t\t"<<"Press Enter to continue";
    cin.ignore();
    std::system("clear");
}
int flag=0;
void searchCname(int x){		//Search According to Name
	string a;
	cout<<"Enter name to search :\n";
	cin>>a;
	switch(x){
		case 1: {vector<contact*>::iterator z;
			for(z=C1.begin();z<=C1.end()-1;z++){
				if((*z)->name()==a){
					string q=(*z)->name();
					cout<<"\t\t\t\t"<<a<<" found :)\n\n";
					cout<<"\t\t\t\t"<<"Name : "<<q<<endl;
					cout<<"\t\t\t\t"<<"Number : "<<(*z)->number()<<endl;
					cout<<"\t\t\t\t"<<"Address : "<<(*z)->address()<<endl;		
				}
			}}break;
		case 2: {vector<favorite*>::iterator z;
			for(z=F1.begin();z<=F1.end()-1;z++){
				if((*z)->name()==a){
					string q=(*z)->name();
					cout<<"\t\t\t\t"<<a<<" found :)\n\n";
					cout<<"\t\t\t\t"<<"Name : "<<q<<endl;
					cout<<"\t\t\t\t"<<"Number : "<<(*z)->number()<<endl;
					cout<<"\t\t\t\t"<<"Address : "<<(*z)->address()<<endl;		
				}
			}}break;
		case 3: {vector<speedDial*>::iterator z;
			for(z=S1.begin();z<=S1.end()-1;z++){
				if((*z)->name()==a){
					string q=(*z)->name();
					cout<<setw(70)<<a<<" found :)\n\n";
					cout<<setw(70)<<"Name : "<<q<<endl;
					cout<<setw(70)<<"Number : "<<(*z)->number()<<endl;
					cout<<setw(70)<<"Address : "<<(*z)->address()<<endl;		
				}
			}}break;
		case 4: {vector<BlackList*>::iterator z;
			for(z=B1.begin();z<B1.end();z++){
				if((*z)->name()==a){
					string q=(*z)->name();
					cout<<setw(70)<<a<<" found :)\n\n";
					cout<<setw(70)<<"Name : "<<q<<endl;
					cout<<setw(70)<<"Number : "<<(*z)->number()<<endl;
					cout<<setw(70)<<"Address : "<<(*z)->address()<<endl;		
				}
			}}break;
		default: break;		
	}
	char y;
	cout<<"Do you want to continue (y/n):\n";
	cin>>y;
	if(y=='y'){
		system("clear");
	}
	else exit(0);
	return;
}

void searchCcity(int x){		//Search According to City
	string a;
	int cnt=0;
	cout<<"Enter city :\n";
	cin>>a;
	switch(x){
		case 1:	{vector<contact*>::iterator z;
				for(z=C1.begin();z<C1.end();z++)
					if((*z)->address()==a)
						cnt++;
				cout<<"There are "<<cnt<<" people from city "<<a<<" in your contacts :)"<<endl;
				cnt=0;
				for(z=C1.begin();z<C1.end();z++){
					if((*z)->address()==a){
						cnt++;
						cout<<"["<<cnt<<"]"<<endl;
						cout<<setw(70)<<"Name : "<<(*z)->name()<<endl;
						cout<<setw(70)<<"Number : "<<(*z)->number()<<endl;
						cout<<setw(70)<<"Address : "<<(*z)->address()<<"\n"<<endl;		
					}
				}}break;
		case 2: {vector<favorite*>::iterator z;
				for(z=F1.begin();z<F1.end();z++)
					if((*z)->address()==a)
						cnt++;
				cout<<"There are "<<cnt<<" people from city "<<a<<" in your contacts :)"<<endl;
				cnt=0;
				for(z=F1.begin();z<F1.end();z++){
					if((*z)->address()==a){
						cnt++;
						cout<<"["<<cnt<<"]"<<endl;
						cout<<setw(70)<<"Name : "<<(*z)->name()<<endl;
						cout<<setw(70)<<"Number : "<<(*z)->number()<<endl;
						cout<<setw(70)<<"Address : "<<(*z)->address()<<"\n"<<endl;		
					}
				}}break;
		case 3: {vector<speedDial*>::iterator z;
				for(z=S1.begin();z<S1.end();z++)
					if((*z)->address()==a)
						cnt++;
				cout<<"There are "<<cnt<<" people from city "<<a<<" in your contacts :)"<<endl;
				cnt=0;
				for(z=S1.begin();z<S1.end();z++){
					if((*z)->address()==a){
						cnt++;
						cout<<"["<<cnt<<"]"<<endl;
						cout<<setw(70)<<"Name : "<<(*z)->name()<<endl;
						cout<<setw(70)<<"Number : "<<(*z)->number()<<endl;
						cout<<setw(70)<<"Address : "<<(*z)->address()<<"\n"<<endl;		
					}
				}}break;		
		case 4: {vector<BlackList*>::iterator z;
				for(z=B1.begin();z<B1.end();z++)
					if((*z)->address()==a)
						cnt++;
				cout<<"There are "<<cnt<<" people from city "<<a<<" in your contacts :)"<<endl;
				cnt=0;
				for(z=B1.begin();z<B1.end();z++){
					if((*z)->address()==a){
						cnt++;
						cout<<"["<<cnt<<"]"<<endl;
						cout<<setw(70)<<"Name : "<<(*z)->name()<<endl;
						cout<<setw(70)<<"Number : "<<(*z)->number()<<endl;
						cout<<setw(70)<<"Address : "<<(*z)->address()<<"\n"<<endl;		
					}
				}}break;
				default: break;	
	}
	char y;
	cout<<"Do you want to continue (y/n):\n";
	cin>>y;
	if(y=='y'){
		system("clear");
	}
	else exit(0);
	return;
}

void searchContacts(){	    //Search according to name, city
	int Ch;flag=0;
	cout<<"Choose search category :\n\n\t\t1.Name:\n\t\t2.City\n\n";
	scbegin:
	cin>>Ch;
	switch(Ch){
		case 1: searchCname(1);break;
		case 2: searchCcity(1);break;
		default : cout<<"Enter correct choice !!"; goto scbegin;
	}

}
void searchFav(){
	int Ch;flag=0;
	scbegin:
	cout<<"Choose search category :\n\n\t\t1.Name:\n\t\t2.City\n\n";
	cin>>Ch;
	switch(Ch){
		case 1: searchCname(2);flag=1;break;
		case 2: searchCcity(2);flag=1;break;
		default : cout<<"Enter correct choice !!";break;
	}
	if(flag==0){
		goto scbegin;
	}
}	

void searchSPD(){
	int Ch;flag=0;
	cout<<"Choose search category :\n\n\t\t1.Name:\n\t\t2.City\n\n";
	scbegin:
	cin>>Ch;
	switch(Ch){
		case 1: searchCname(3);break;
		case 2: searchCcity(3);break;
		default : cout<<"Enter correct choice !!";goto scbegin;
	}
}

void searchBL(){
	int Ch;flag=0;
	cout<<"Choose search category :\n\n\t\t1.Name:\n\t\t2.City\n\n";
	scbegin:
	cin>>Ch;
	switch(Ch){
		case 1: searchCname(4);break;
		case 2: searchCcity(4);break;
		default : cout<<"Enter correct choice !!";goto scbegin;
	}
}

void search(){
    cout<<"\t\t\t\t"<<"1.Random Search:\n\n";
    cout<<"\t\t\t\t"<<"2.Search favorites:\n\n";
    cout<<"\t\t\t\t"<<"3.Search speedDials:\n\n";
    cout<<"\t\t\t\t"<<"4.Search BlackList:\n\n";

    sbegin:
    cout<<"\t\t\t\t"	<<"Enter choice:";
    int choice;
    cin>>choice;

    switch(choice){
        case 1:searchContacts();break;
        case 2:searchFav();break;
        case 3:searchSPD();break;
        case 4:searchBL();break;
        default:cout<<setw(70)<<"Wrong choice!!!\n";goto sbegin;
    }
}
void addContact(){
    string name;
    string number;
    int temp1,temp2;
    string address;

    cout<<"\t\t\t\t"<<"enter name:";
    cin>>name;
    cout<<"\t\t\t\t"<<"enter phone number:";
    cin>>number;
    cout<<"\t\t\t\t"<<"enter address:";
    cin>>address;

    cout<<"\t\t\t\t"<<"Add to Favorites?";
    cin>>temp1;
    cout<<"\t\t\t\t"<<"Add to SpeedDial?";
    cin>>temp2;

    fout<<endl<<name<<" "<<number<<" "<<address<<" "<<temp1<<" "<<temp2<<" "<<0;
    C1.push_back(new contact(name,number,address));
    if(temp1)   F1.push_back(new favorite(name,number,address));
    if(temp2)   S1.push_back(new speedDial(name,number,address));
    
    cout<<"new contact added\n";
}
void delet(){
}
void modify(){
}
int MainMenu(){

    cout<<"				"<<"=====================\n";
    cout<<"				"<<"******MAIN MENU******\n";
    cout<<"				"<<"=====================\n";

    cout<<"				"<<"1.SEARCH CONTACT\n\n";
    cout<<"				"<<"2.ADD CONTACT\n\n";
    cout<<"				"<<"3.DELETE CONTACT\n\n";
    cout<<"				"<<"4.MODIFY CONTACT\n\n";
    cout<<"				"<<"5.EXIT DIRECTORY\n\n";

    int choice;
    cout<<setw(45)<<"enter your choice: ";
    cin>>choice;

    return choice;
}
int main(){
    phonebook();

    init();

    fout.open("phonebook.txt",ios::app|ios::out);
	    while(1){
        std::system("clear");
        int choice=MainMenu();
        switch(choice){
            case 1:search();break;
            case 2:addContact();break;
            case 3:break;
            case 4:break;
            case 5:exit(0);
            default:cout<<"wrong choice";break;
        }
    }
}
