#include <iostream>

using namespace std;

class AbstractAcademy {
    public:
    string Name;
    int NumberOfStudents;
    int NumberOfTeachers;
    bool IsFree;
    
    virtual void teach()=0;
    void getDescription(){
        cout << " This is a description for abstract academy" << endl;
    }
};

class Subject{
    public:
    string name;
    int PassingGrade;
    
    void getDescription() {
        cout << "This is a class for " << name << " subject" << endl; 
    }
};

class University: public AbstractAcademy {
    public:
      void teach(){
          cout << "Contucting a lecture" << endl;
      }
      
      void teach (Subject subject){
          cout << " University is conducting a " << subject.name << " lecture " << endl;
      }
      
      //overriding getDescription
      void getDescription(){
          cout << " Name: " << Name <<endl;
          cout << " Number Of Students: " << NumberOfStudents << endl;
          cout << " Number od professors : " << NumberOfTeachers<< endl;
      }
};

class Abstractstudent {
    public:
    string FirstName;
    string LastName;
    int age;
    
    virtual void attentLesson ()=0;
    void getDescription() {
        cout << "This is a description for abstract Student" <<endl;
    }
};

class UniversityStudent: public Abstractstudent {
    public:
    University university;
    Subject subject;
    
    void attentLesson(){
        cout << FirstName << " " << LastName << " is attending " << subject.name << "lecture" << endl;
    }
   
    void attendLesson(string subjectName) {
        cout << FirstName << " " << LastName << " is attend a " << " lecture" << endl; 
    }
    
    void attendLesson(Subject subject) {
        cout << FirstName << LastName << " is attend a " << subject.name << " lecture" << endl; 
    }
    
    //overriding getDescription
    void getDescription() {
        cout << "First name: " << FirstName << endl;
        cout << "Last name: " << LastName << endl;
        cout << "Age: " << age << endl;
        cout << "University: " << university.Name << endl;
        cout << "Subject: " << subject.name << endl;
    }
};

int main()
{
   University freeUni;
    freeUni.Name = "Free University";
    freeUni.NumberOfStudents = 2000;
    freeUni.NumberOfTeachers = 150;
    freeUni.IsFree = false;
    
   // freeUni.getDescrption();
   // freeUni.teach();
   
   Subject math;
   math.name = "Mathematics";
   math.PassingGrade = 70;

    Subject computerScience;
    computerScience.name = "Computer science";
    computerScience.PassingGrade = 51;
    
    UniversityStudent Student1;
    Student1.FirstName ="Alexander";
    Student1.LastName = "kutaladze";
    Student1.age= 23;
    Student1.university = freeUni;
    Student1.subject = math;
    
    
  Student1.attendLesson(computerScience);
    
    return 0;
}