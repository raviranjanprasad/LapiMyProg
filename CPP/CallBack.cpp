#include<iostream>
#include<string>

using namespace std;

#define MSG_SIZE 300
#define ERR 1
#define WARN 2
#define CRICT 3

typedef string (*fun2ptr)(int,string);

string get_message(int severity,string who){

	cout<<"get_message() called by  "<<who<<endl;
	string msg = "";
	switch(severity){
		case ERR:
			msg = "Erro message";
			break;
		case WARN:
			msg = "Erro message";
			break;
		case CRICT:
			msg = "Erro message";
			break;
		default:
			msg = "Incorrect severity";
	}
        return msg;
}

void print_message( string error){
	string who="print_messge";
	/*
	   fun2ptr ptr;
	   ptr = &get_message;
	   error=ptr(ERR,who);*/
	error = (*(fun2ptr)get_message)(ERR,who);
	cout << error <<endl;

}

int main(int argc,char *argv[]){
	//string who="main";
	string error="";
	print_message(error);
	return 0;   
}
