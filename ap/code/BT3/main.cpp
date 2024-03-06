#include "main.h"
class Student{
private:
    string name;
    double score;
public:
    Student(): name(""), score(0) {};
    ~Student(){};
    Student(string newName, double newScore): name(newName), score(newScore){};
    double getScore() {
        return score;
    }
    string getName(){
        return name;
    }
};
template <class T>
class DynamicArray{
private:
    T *element;
    int capacity;
    int size;
public:
    DynamicArray(){
        capacity = 10;
        size = 0;
        element = new T[capacity];
    }
    ~DynamicArray() {
        delete[] element;
    }
    void addElement(T data){
        if (size + 1 > capacity) {
            capacity += 10;
            T* newArray = new T[capacity];
            for (int i = 0; i < size; i++) newArray[i] = element[i];
            delete[] element;
            element = newArray;
        }
        element[size] = data;
        size++;
    }
    T getElement(int index){
        return element[index];
    }
    int getSize(){
        return size;
    }
    void deleteElement(int index){
        if (size != 0) {
            T* newArray = new T[capacity];
            for (int i = 0; i < index; i++) newArray[i] = element[i];
            for (int i = index + 1; i < size; i++) newArray[i - 1] = element[i];
            delete[] element;
            element = newArray;
            size--;
        }
    }
};
class ListOfStudent{
private:
    static ListOfStudent* instance;
    DynamicArray<Student> st;
    ListOfStudent(){};
public:
    static ListOfStudent* getInstance(){
        if (!instance) instance = new ListOfStudent();
        return instance;
    }
    void addStudent(string name, double score){
        Student x = Student(name, score);
        st.addElement(x);
    }
    void printStudent(int index){
        cout << st.getElement(index).getName() << " - " << st.getElement(index).getScore() << endl;
    }
    void displayAllStudent(){
        int size = st.getSize();
        for (int j = 0; j < size; j++){
            printStudent(j);
        }
    }
    int findStudentByName(string name){
        int size = st.getSize();
        for (int j = 0; j < size; j++){
            if (st.getElement(j).getName() == name) return j;
        }
        return -1;
    }
    void deleteStudentByName(string name){
        cout << "Deleted: ";
        while(findStudentByName(name) != -1){

            printStudent(findStudentByName(name));
            st.deleteElement(findStudentByName(name));
        }
    }
    void displayBestStudent(){
        int size = st.getSize();
        int maxScore = 0;
        for (int i = 0; i < size; i++){
            double temp = st.getElement(i).getScore();
            if (maxScore < temp) maxScore = temp;
        }
        cout << "The best student:" << endl;
        for (int j = 0; j < size; j++){
            if (st.getElement(j).getScore() == maxScore) {
                printStudent(j);
            }
        }
    }
};
ListOfStudent* ListOfStudent:: instance = nullptr;
void Menu()
{
    stringstream ss;
    ss << "--------- Choose the feature --------------\n"
       << "1. Add a new student \n"
       << "2. Display all students and their scores \n"
       << "3. Display the student with the best score \n"
       << "4. Delete the student with the input name \n"
       << "5. Exit the program \n"
       << "-------------------------------------------\n";
    cout << ss.str();
}
