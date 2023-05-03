#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

using namespace std;
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