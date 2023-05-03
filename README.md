# SchoolManagementSystem
This is a C++ program that simulates a school management system. It was developed as part of an object-oriented programming assignment for Object-Oriented Programming (Κ10) at NKUoA.
<br>You can find the pdf of exercise questions in:
https://cgi.di.uoa.gr/~izambo/OOPassgn2_2021.pdf

## Assignment Prompt ##

The program includes several classes, each with their specific responsibilities. At the core of the program, there is a <strong>Human</strong> class that serves as a parent to two child classes: <strong>Teacher</strong> and <strong>Student</strong>. The <strong>Student</strong> class is also a parent to two child classes: <strong>Junior</strong> and <strong>Senior</strong>.

The <strong>Teacher</strong> and <strong>Student</strong> classes are responsible for storing information about teachers and students, respectively, such as their name, floor, class number, whether they are in class or not, and their tiredness level. The <strong>Junior</strong> and <strong>Senior</strong> classes inherit the same properties as the Student class but also contain additional information specific to their class type.

The program also includes several other classes that manage different areas of the school, such as the <strong>Classroom</strong> and <strong>Floor</strong> classes. The <strong>Classroom</strong> class is responsible for managing students and teachers within a classroom, while the <strong>Floor</strong> class manages multiple classrooms on a single floor.

Other classes in the program include the <strong>Corridor</strong>, <strong>Stairs</strong>, and <strong>Yard</strong> classes that represent different areas of the school where students can move between classes or take breaks.

Finally, the <strong>School</strong> class serves as the main program interface, managing all the other classes and providing functions for adding students and teachers, running the school for a specified number of hours, and printing out the current state of the school.

Overall, the exercise is designed to test your understanding of object-oriented programming principles and your ability to implement a complex system with multiple interacting components.

### Usage
To run the program, you will need to have a C++ compiler installed on your system. Once you have the compiler set up, you can compile the program by running the following commands: <br>
$ <strong>g++ -c objects.cpp </strong><br>
$ <strong>g++ -c askisi3.cpp </strong> <br>
$ <strong>g++ objects.o askisi3.o </strong> <br>


Then, to start the program, run the following command:

$<strong> ./a.out 1 2 3 4 5 </strong>

<br>

*In my example (above) I used:*

*capacity of class = 1*

*level of tiredness (per hour) for junior students = 2*

*level of tiredness (per hour) for senior students = 3*

*level of tiredness (per hour) for the teacher = 4*

*number of operation hours of school = 5*

[You can change the values into the integers of your preference]

###



#
