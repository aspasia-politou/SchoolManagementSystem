#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

#include "people.hpp"

using namespace std;

class Human;
class Student;
class Junior;
class Senior;
class Teacher;

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
#endif // OBJECTS_HPP