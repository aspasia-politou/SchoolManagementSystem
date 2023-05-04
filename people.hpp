
#ifndef PEOPLE_HPP
#define PEOPLE_HPP
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include "objects.hpp"

using namespace std;


class Area;
class Classroom;
class Corridor;
class Floor;
class Stairs;
class Yard;
class School;

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
#endif // PEOPLE_HPP