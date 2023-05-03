#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include "objects.hpp"
using namespace std;
//class Corridor;

int main(int argc,char* argv[]){
int c_class,Lj,Ls,Lt,N;
	c_class=atoi(argv[1]);
	Lj=atoi(argv[2]);
	Ls=atoi(argv[3]);
	Lt=atoi(argv[4]);
	N=atoi(argv[5]);	
	srand(time(NULL));
	
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
    	delete random_teachers[i];
	}
	delete[] random_teachers;
	delete[] teachers;
	
	for(int i=0;i<total_students;i++){
		delete random_students[i];
	}
	delete[] students;
	delete[] random_students;
	


}
