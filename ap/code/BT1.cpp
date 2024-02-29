#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Student {
private:
    string name;
public:
    Student(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }
};
vector<Student>::iterator customFind(vector<Student>& st, const string& name) {
    for (auto it = st.begin(); it != st.end(); ++it) {
        if ((*it).getName() == name) {
            return it;  // Trả về iterator của phần tử nếu tìm thấy
        }
    }
    return st.end();  // Trả về iterator cuối nếu không tìm thấy
}
class ListOfStudent {
private:
    // Private constructor để ngăn chặn việc tạo đối tượng từ bên ngoài.
    ListOfStudent() {}
    vector <Student> st;
    // Biến static để lưu trữ thể hiện duy nhất của lớp.
    static ListOfStudent* instance;
public:
    static ListOfStudent* getInstance(){
        if (!instance) instance = new ListOfStudent();
        return instance;
    }
    // Phương thức mẫu của lớp.
    void addStudent(string name){
        Student k = Student(name);
        st.push_back(k);
    }
    void printAllStudent(){
        if (st.size() == 0) {
            cout << "No one" << endl;
            return;
        }
        for (auto x : st) cout << x.getName() << endl;
    }
    void removeStudent(string name){
        auto it = customFind(st, name);
        if (it == st.end()) cout <<"Not found" <<endl;
        st.erase(it);
    }
};

ListOfStudent* ListOfStudent:: instance = nullptr;
int main(){
    // Lấy thể hiện duy nhất của ListOfStudent
    ListOfStudent* ListOfStudentInstance = ListOfStudent::getInstance();
    while(1){
        stringstream ss;
        string dashes(50, '-');
        ss  << dashes << "\n"
            <<"[1] Add a new student to the list of all students \n"
            <<"[2] Display the list of all students \n"
            <<"[3] Remove a student from the list of all students \n"
            <<"[Other] Exit the program \n"
            << dashes << "\n";
        cout << ss.str();
        int choice = 0;
        cin >> choice;
        cin.ignore();
        if (choice == 1){
            string name;
            cout << "Enter the student's name to be added: ";
            getline(cin,name);
            ListOfStudentInstance->addStudent(name);
        }
        else if (choice == 2){
            ListOfStudentInstance->printAllStudent();
        }
        else if (choice == 3){
            string name;
            cout << "Enter the student's name to be deleted: ";
            getline(cin,name);
            ListOfStudentInstance->removeStudent(name);
        }
        else break;
    }
}