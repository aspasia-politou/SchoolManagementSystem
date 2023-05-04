
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

#include "people.hpp"

using namespace std;
Human::Human(string in_name,int in_class_floor,int in_class_number, int in_counter_tiredness){
	name=in_name;
	class_floor=in_class_floor;
	class_number=in_class_number;
	in_class=false;
	counter_tiredness=in_counter_tiredness;
}
Human::~Human(){

}
void Human::print(){
	cout<<"|Name: "<<name<<" |ClassFloor:"<<class_floor<<" |Class Number:"<<class_number<<" |in_class:";
	if(in_class) cout<<"Yes ";
	else cout<<"No ";
	cout<<"|Counter_Tiredness:"<<counter_tiredness;
}
string Human::get_name(){	return name;}
int Human::get_floor_number(){	return class_floor;}
int Human::get_class_number(){	return class_number;}
int Human::get_tiredness()const{	return counter_tiredness;}
Student::Student(string in_name,int in_class_floor,int in_class_number,int in_counter_tiredness):
Human(in_name,in_class_floor,in_class_number,in_counter_tiredness){

}
void Human::set_in_class(bool in_class){	this->in_class=in_class;}
Student::~Student(){
	cout<<"Student to destroy."<<endl;
	print();
	cout<<endl;
}

Junior::Junior(string in_name, int in_class_number, int in_class_floor,int in_Lj,int in_counter_tiredness):
Student(in_name,in_class_floor,in_class_number,in_counter_tiredness){
	Lj=in_Lj;
	cout<<"A Junior Student has been created"<<endl;
	print();
	cout<<endl;
}
Junior::~Junior(){
	cout<<"A Junior Student to destroy"<<endl;
	print();
	cout<<endl;
}
void Junior::attend(int hours){
	counter_tiredness+=(Lj*hours);
}
void Junior::print(){
	Human::print();
	cout<<" |Lj="<<Lj;
}
Senior::Senior(string in_name, int in_class_floor, int in_class_number,int in_Ls,int in_counter_tiredness):
Student(in_name,in_class_floor,in_class_number,in_counter_tiredness){
	Ls=in_Ls;
	cout<<"A Senior Student has been created"<<endl;
	print();
	cout<<endl;
}
Senior::~Senior(){
	cout<<"A Senior Student to destroy"<<endl;
	print();
	cout<<endl;
}
void Senior::attend(int hours){
	counter_tiredness+=(Ls*hours);
}
void Senior::print(){
	Human::print();
	cout<<" |Ls="<<Ls;
}
Teacher::Teacher(string in_name,int in_class_floor,int in_class_number,int in_Lt,int in_counter_tiredness):
Human(in_name,in_class_floor,in_class_number,in_counter_tiredness){
	Lt=in_Lt;
	cout<<"A Teacher has been created!"<<endl;
	print();
	cout<<endl;
}
Teacher::~Teacher(){
	cout<<"A Teacher to be destroyed!"<<endl;
	print();
	cout<<endl;
}
void Teacher::teach(int hours){
	counter_tiredness+=(Lt*hours);
}
void Teacher::print(){
	Human::print();
	cout<<" |Lt="<<Lt;
}