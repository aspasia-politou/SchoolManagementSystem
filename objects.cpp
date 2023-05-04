
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include "objects.hpp"

using namespace std;

Classroom::Classroom(int c_class){
	this->c_class=c_class;
	students=new Student*[c_class];
	for(int i=0;i<c_class;i++){
		students[i]=NULL;
	}
	teacher=NULL;
	cout<<"A New Classroom has been created!"<<endl;
}
Classroom::~Classroom(){
	cout<<"A Classroom to be destroyed!"<<endl;
	delete[] students;
}
void Classroom::enter(Student* student){
	for(int i=0;i<c_class;i++){
		if(students[i]==NULL){
			students[i]=student;
			students[i]->set_in_class(true);
			cout<<students[i]->get_name()<<" enters Classroom!"<<endl;
			break;
		}
	}
}
void Classroom::place(Teacher* teacher){
	this->teacher=teacher;
	teacher->set_in_class(true);
}
void Classroom::operate(int hours){
	if(teacher!=NULL){
		teacher->teach(hours);
		for(int i=0;i<c_class;i++){
			students[i]->attend(hours);
		}
	}
}
void Classroom::print(){
	for(int i=0;i<c_class;i++){
		if(students[i]!=NULL)
			cout<<students[i]->get_name()<<"  tiredness:"<<students[i]->get_tiredness()<<endl;
	}
	if(teacher!=NULL)
		cout<<"The teacher is :"<<teacher->get_name()<<"  tiredness:"<<teacher->get_tiredness()<<endl;
}
Area::Area(){
	students=NULL;
}
Area::~Area(){
	/*cout<<"An Area to be destroyed!"<<endl;*/
}
void Area::enter(Student* student){
	students=student;
	cout<<student->get_name()<<" enters ";
}
Student* Area::exit(){
	Student* student=NULL;
	if(students!=NULL){
		student=students;
		students=NULL;
		cout<<student->get_name()<<" exits ";
	}return student;
}
Corridor::Corridor(){
	cout<<"A corridor is created!"<<endl;
}
Corridor::~Corridor(){
	cout<<"A Corridor to be destroyed!"<<endl;
}
void Corridor::enter(Student* student){
Area::enter(student);
	cout<<"Corridor!"<<endl;
}
Student* Corridor::exit(){
	Student* student;
	student=Area::exit();
	cout<<" Corridor!"<<endl; 
	return student;
}
Floor::Floor(int c_class): cor(){
	for(int i=0;i<6;i++){
		classrooms[i]=new Classroom(c_class);
	}
	cout<<"A New floor has been created!"<<endl;
}
Floor::~Floor(){
	cout<<"A Floor to be destroyed!"<<endl;
	for(int i=0;i<6;i++){
		delete classrooms[i];
	}
}
void Floor::enter(Student* student){
	cout<<student->get_name()<<" enters "<<student->get_floor_number()<<"Floor"<<endl;
	cor.enter(student);
	classrooms[student->get_class_number()]->enter(cor.exit());
}
void Floor::place(Teacher* teacher){
	classrooms[teacher->get_class_number()]->place(teacher);
}
void Floor::operate(int hours){
	for(int i=0;i<6;i++){
		classrooms[i]->operate(hours);
	}
}
void Floor::print(){
	for(int i=0;i<6;i++){
		cout<<"People in Class "<<i<<" are:"<<endl;
		classrooms[i]->print();
	}
}
Stairs::Stairs(){
cout<<"Stairs have been created!"<<endl;
}
Stairs::~Stairs(){
	cout<<"Stairs to be destroyed!"<<endl;
}
void Stairs::enter(Student* student){
	Area::enter(student);
	cout<<"Stairs!"<<endl;
}
Student* Stairs::exit(){
	Student* student;
	student=Area::exit();
	cout<<" Stairs!"<<endl; 
	return student;
}
Yard::Yard(){
	cout<<"A Schoolyard has been creadted!"<<endl;
}
Yard::~Yard(){
	cout<<"A Schoolyard to be destroyed!"<<endl;
}
void Yard::enter(Student* student){
	Area::enter(student);
	cout<<"Schoolyard!"<<endl;
}
Student* Yard::exit(){
	Student* student;
	student=Area::exit();
	cout<<" Schoolyard!"<<endl; 
	return student;
}
School::School(int c_class):
yard(), stairs(){
	for(int i=0;i<3;i++){
		floors[i]=new Floor(c_class);
	}
	cout<<"A school has been created!"<<endl;
}
School::~School(){
	cout<<"A School to be destroyed!"<<endl;
	for(int i=0;i<3;i++){
		delete floors[i];
	}
}
void School::enter(Student** random_students, int total_students,int c_class, Teacher** random_teachers,int total_teachers){
	for(int i=0;i<total_students;i++){
		enter(random_students[i]);
	}
	for(int i=0;i<total_teachers;i++){
		place(random_teachers[i]);
	}
}
void School::enter(Student* student){
cout<<student->get_name()<<" enters Schoolbuilding!"<<endl;
yard.enter(student);
stairs.enter(yard.exit());
int n=student->get_floor_number();
floors[n]->enter(stairs.exit());

cout<<endl;
}
void School::place(Teacher* teacher){
	floors[teacher->get_floor_number()]->place(teacher);
}
void School::operate(int hours){
	for(int i=0;i<3;i++){
		floors[i]->operate(hours);
	}
}
void School::print(){
	cout<<"School life constists of:"<<endl;
	for(int i=0;i<3;i++){
		cout<<"Floor number "<<i<<"contains:"<<endl;
		floors[i]->print();
	}
}
