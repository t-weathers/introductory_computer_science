#include "student_db.h"
using namespace std;

int main(int argc,char **argv){
  string a;
  fstream file (argv[1]);
  int *IDlist;
  string *LastNameList;
  int num_of_students;
  if(file.is_open()){
    file>>num_of_students;
    student *students;
    students = create_student_db(num_of_students);
    get_student_db_info(students, num_of_students, file);
    file.close();
    ofstream outputfile("student_db.txt");
    IDlist = create_list_of_ID(students,num_of_students);
    sort_ID(IDlist,num_of_students);
    outputfile<<"SORTED ID NUMBERS: "<<endl;
    for(int i = 0; i < num_of_students; i++){
      outputfile<< IDlist[i]<<endl;
    }
    outputfile<<"SORTED STUDENT NAMES"<<endl;
    LastNameList = create_list_of_names(students,num_of_students);
    alphebetically(LastNameList, num_of_students);
    for(int i = 0; i < num_of_students; i++){
      outputfile<<LastNameList[i]<<endl;
    }
    outputfile<<"NUM OF UNIQUE MAJORS"<<endl;
    outputfile<<num_of_unique_majors(students,num_of_students)<<endl;
    outputfile.close();
    delete_student_db_info(&students,num_of_students);
    delete [] IDlist;
    delete [] LastNameList;
  }
  else{
    cout<<"file failed to open"<<endl;
  }
  return 0;
}
