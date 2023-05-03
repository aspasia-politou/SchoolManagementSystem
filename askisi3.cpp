#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
using namespace std;
//class Corridor;
class Human{
	public:
		Human(string in_name,int in_class_floor,int in_class_number, int in_counter_tiredness=0);
		~Human();
		virtual void print();
		string get_name();
		int get_floor_number();
		int get_class_number();
		int get_tiredness()const;
		void set_in_class(bool in_class);
	protected:
		string name;
		int class_floor;
		int class_number;
		bool in_class;
		int counter_tiredness;
};
class Student: public Human{
	public:
		Student(string in_name,int in_class_floor,int in_class_number,int in_counter_tiredness=0);
		~Student();
		virtual void attend(int hours)=0;		
		/*void print();*/
};
class Junior: public Student{
	public:
		Junior(string in_name, int in_class_floor, int in_class_number,int in_Lj,int in_tiredness=0);
		~Junior();
		void attend(int hours);
		void print();
	private:
		int Lj;
};
class Senior: public Student{
	public:
		Senior(string in_name, int in_class_floor, int in_class_number,int in_Ls,int in_tiredness=0);
		~Senior();
		void attend(int hours);
		void print();		
	private:
		int Ls;
};
class Teacher: public Human{
	public:
		Teacher(string in_name,int in_class_floor,int in_class_number,int in_Lt,int in_counter_tiredness=0);
		~Teacher();
		void teach(int hours);
		void print();
	private:
	int Lt;
};
class Area{
	public:
		Area();
		~Area();
		virtual void enter(Student* student);
		virtual Student* exit();
	protected:
		Student* students;
};
class Classroom{
	public:
		Classroom(int c_class);
		~Classroom();
		void enter(Student* student);
		void place(Teacher* teacher);
		void operate(int hours);
		void print();
	private:
	int c_class;
	Teacher* teacher;
	Student** students;
};
class Corridor: public Area{
	public:
		Corridor();
		~Corridor();
		void enter(Student* student);
		Student* exit();
	private:

};
class Floor{
	public:
		Floor(int c_class);
		~Floor();
		void enter(Student* student);
		void place(Teacher* teacher);
		void operate(int hours);
		void print();
	private:
	Corridor cor;
	Classroom* classrooms[6];
};
class Stairs: public Area{
	public:
	Stairs();
	~Stairs();
	void enter(Student* student);
	Student* exit();
	private:
};
class Yard: public Area{
	public:
		Yard();
		~Yard();
		void enter(Student* student);
		Student* exit();
	private:

};
class School{
	public:
		School(int c_class);
		~School();
		void enter(Student* student);
		 void enter(Student** random_students, int total_students,int c_class, Teacher** random_teachers,int total_teachers);
		void place(Teacher* teacher);
		void operate(int hours);
		void print();
	private:
		Yard yard;
		Stairs stairs;
		Floor* floors[3];
};
int main(int argc,char* argv[]){
int c_class,Lj,Ls,Lt,N;
	c_class=atoi(argv[1]);
	Lj=atoi(argv[2]);
	Ls=atoi(argv[3]);
	Lt=atoi(argv[4]);
	N=atoi(argv[5]);	
	srand(time(NULL));
	//c_class=2;		//delete this later
	//Ls=2;			//delete this later
	//Lj=3;			//delete this later
	//Lt=4;			//delete this later
	School school1(c_class);
	Student** students;
	Student** random_students;
	Teacher** teachers;
	Teacher** random_teachers;
	string name_arr[20] = 	{"Liam","Olivia","Noah","Emma","Oliver","Ava","William","Sophia","Elijah","Isabella","James","Charlotte","Benjamin","Amelia","Lucas","Mia","Mason","Harper","Ethan","Evelyn"};
	string prof_array[21]={"ADOLFITO","ALBERTO ","ALEJANDRO","ALFONSO","ALFREDO","CARMEN","CAROLINA","CECILIA","CORNELIO","CRISTIAN","DALIA ","DANILO","DAVID","DIANA","DIEGO","EMILIO","ENRIQUE","ERNESTO","ESMERALDA","ESTEBAN","FEDERICO"};
	int total_students=6*3*c_class;
	int total_teachers=6*3; 
	//Allocating memory
	students=new Student*[total_students];
	random_students=new Student*[total_students];
	teachers=new Teacher*[total_teachers];
	random_teachers=new Teacher*[total_teachers];
	for(int i=0;i<total_students;i++){
		//students[i]=NULL;
		//random_students[i]=NULL;
	}
	for(int i=0;i<total_teachers;i++){
		//teachers[i]=NULL;
		//random_teachers[i]=NULL;
	}
	int count=0;
	
	for(int x=0;x<3;x++){
		for(int y=0;y<3;y++){
			for(int times=0;times<c_class;times++){
				students[count]=new Junior(name_arr[rand()%20],x,y,Lj);
				count++;
				
			}
		}		
	}
	for(int x=0;x<3;x++){
		for(int y=3;y<6;y++){
			for(int times=0;times<c_class;times++){
				students[count]=new Senior(name_arr[rand()%20],x,y,Ls);
				count++;
			}
		}		
	}
	count=0;
	for(int x=0;x<3;x++){
		for(int y=0;y<6;y++){
			teachers[count]=new Teacher(prof_array[rand()%20],x,y,Lt);
			count++;
		}
	}
	
	int n=rand()%total_students;
	for(int i=0;i<total_students;i++){
		if(i==total_students-1){
			for(int j=0;j<total_students;j++)
			{
				if(students[j]!=NULL){
				random_students[i]=students[j];
				students[j]==NULL;
				break;
				}
			}
		}
		while(students[n]==NULL && i!=total_students-1){
			n=rand()%total_students;
		}
		if(students[n]!=NULL){
			random_students[i]=students[n];
			students[n]=NULL;
		}
		
	}
	n=rand()%total_teachers;
	for(int i=0;i<total_teachers;i++){
		if(i==total_teachers-1){
			for(int j=0;j<total_teachers;j++)
			{
				if(teachers[j]!=NULL){
				random_teachers[i]=teachers[j];
				teachers[j]==NULL;
				break;
				}
			}
		}
		while(teachers[n]==NULL && i!=total_teachers-1){
			n=rand()%total_teachers;
		}
		if(teachers[n]!=NULL){
			random_teachers[i]=teachers[n];
			teachers[n]=NULL;
		}
		
	}
	
	
	school1.enter(random_students,total_students,c_class,random_teachers,total_teachers);
	
	
	cout<<"School before attending or teaching:"<<endl;
	school1.print();
	school1.operate(N);
	cout<<"School after attending or teaching:"<<endl;
	school1.print();
	
	
	//REALLOCATE MEMORY
	for(int i=0;i<total_teachers;i++){
		delete teachers[i];
		delete random_teachers[i];
	}
	delete[] teachers;
	delete[] random_teachers;
	
	for(int i=0;i<total_students;i++){
		delete students[i];
		delete random_students[i];
	}
	delete[] students;
	delete[] random_students;
	


}

Human::Human(string in_name,int in_class_floor,int in_class_number, int in_counter_tiredness){
	name=in_name;
	class_floor=in_class_floor;
	class_number=in_class_number;
	in_class=false;
	counter_tiredness=in_counter_tiredness;
	/*cout<<"A Human has been created "<<endl;
	print();
	cout<<endl;*/
}
Human::~Human(){
	/*cout<<"A Human to destroy."<<endl;
	print();
	cout<<endl;*/
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
//	cout<<"A Student has been created"<<endl;
//	print();
//	cout<<endl;
}
void Human::set_in_class(bool in_class){	this->in_class=in_class;}
Student::~Student(){
	cout<<"Student to destroy."<<endl;
	print();
	cout<<endl;
}

/*void Student::print(){
	
	cout<<"|Name: "<<name<<" |ClassFloor:"<<class_floor<<" |Class Number:"<<class_number<<" |in_class:";
	if(in_class) cout<<"Yes ";
	else cout<<"No ";
	cout<<"|Counter_Tiredness:"<<counter_tiredness<<endl<<endl;
}*/
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
	/*cout<<"New Area is created!"<<endl;*/
}
Area::~Area(){
	/*cout<<"An Area to be destroyed!"<<endl;*/
}
void Area::enter(Student* student){
	students=student;
	cout<<student->get_name()<<" enters ";
	//students->print();
}
Student* Area::exit(){
	Student* student=NULL;
	if(students!=NULL){
		student=students;
		students=NULL;
		cout<<student->get_name()<<" exits ";
		//return student;
		//break;
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
	//student->print();
	//cout<<endl;
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
	//student->print();
	//cout<<endl;
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
//	student->print();
	//cout<<endl;
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
//student->print();
//cout<<endl;
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
