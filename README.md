# SchoolManagementSystem
This is a C++ program that simulates a school management system. It was developed as part of an object-oriented programming assignment for Object-Oriented Programming (Κ10) at NKUoA.

## Assignment Prompt ##

The objective of this assignment is to implement a school management system using C++ and object-oriented programming principles. The system should allow users to manage student and teacher data, as well as enroll and drop students from courses.

### Requirements 

Your program must meet the following requirements:

    The program must allow users to add and remove students from the system.
    The program must allow users to add and remove teachers from the system.
    The program must allow users to add and remove courses from the system.
    The program must allow users to enroll and drop students from courses.
    The program must provide a command-line interface for users to interact with the system.
    The program must store data in text files for persistence across multiple runs of the program.
    The program must be implemented using object-oriented programming principles.
    The program must be able to handle errors and exceptions appropriately.
###
### Usage
To run the program, you will need to have a C++ compiler installed on your system. Once you have the compiler set up, you can compile the program by running the following command:

$ g++ askisi3.cpp -o school_system

Then, to start the program, run the following command:

$ ./school_system 1 2 3 4 5

<br>

*In my example (above) I used:*

*capacity of class = 1*

*level of tiredness (per hour) for junior students = 2*

*level of tiredness (per hour) for senior students = 3*

*level of tiredness (per hour) for the teacher = 4*

*number of operation hours of school = 5*

[You can change the values into the integers of your preference]

###

### Implementation Details

The program is implemented using the following classes:
<ul>
    <li><strong>Human</strong>: Represents a human in the system. Contains information such as the human's name, class floor, class number, if he\she is in class and counter of tiredness.</li>
    <li><strong>Student</strong>: Represents a student in the system. Inherits from <strong>Human</strong> and contains additional information such as the student's grade level and enrolled courses.</li>
    <li><strong>Junior</strong>: Represents a junior student in the system. Inherits from <strong>Student</strong> and contains additional information such as the level of tiredness per hour for Juniors(Lj).</li>
    <li><strong>Senior</strong>: Represents a senior student in the system. Inherits from <strong>Student</strong> and contains additional information such as the the of tiredness per hour for seniors(Ls).</li>
    <li><strong>Teacher</strong>: Represents a teacher in the system. Inherits from <strong>Human</strong> and contains additional information such as the information such as the the of tiredness per hour for teachers (Lt).</li>
    <li><strong>Area</strong>: Represents an area in the school where students can enter and exit. Contains an array of <strong>Student</strong> objects, which can be added to and removed from the area. Implements two virtual methods: <strong>enter(Student* student)</strong> and <strong>exit()</strong>. These methods can be overridden by child classes to implement different behaviors.</li>
   
   <li><strong>School</strong>: Represents the school management system. Contains a collection of students, teachers, and courses.</li>
   <li><strong>Classroom</strong>: Represents a classroom in the school with a specified class number. Contains a <strong>Teacher</strong> object and an array of <strong>Student</strong> objects. Implements several methods:</li>
    <ul>
        <li><strong>Classroom(int c_class): Constructor that sets the class number of the classroom. Allocates memory for the students array.</strong></li>
        <li><strong>~Classroom(): Destructor that deallocates memory used by the students array.</strong></li>
        <li>void enter(Student* student): Adds a Student object to the classroom's students array. If the array is full, the Student object is not added.</li>
        <li>void place(Teacher* teacher): Sets the Teacher object for the classroom. If a Teacher object has already been set for the classroom, it is replaced by the new Teacher object.</li>
        <li>void operate(int hours): Simulates the classroom operating for a specified number of hours. During this time, the Teacher object instructs the Student objects in the classroom. Each Student object's tiredness level is increased by the amount of time spent in the classroom.</li>
        <li>void print(): Prints information about the Student objects and Teacher object in the classroom. If a Student object has been added to the students array, prints its name and tiredness level. If a Teacher object has been set for the classroom, prints its name and tiredness level.</li>
    </ul>
</ul> 
    
###

#
