#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template <typename T>
class DynamicArray
{
private:
  T *data;
  int size;
  int capacity;

public:
  // Constructor
  DynamicArray(int initialCapacity = 10) : size(0), capacity(initialCapacity)
  {
    data = new T[capacity];
  }

  // Destructor
  ~DynamicArray()
  {
    delete[] data;
  }

  // Function to add an element to the array
  void add(const T &element)
  {
    if (size == capacity)
    {
      resize();
    }
    data[size++] = element;
  }

  // Function to get the size of the array
  int getSize() const
  {
    return size;
  }

  // Function to get an element at a specific index
  T get(int index) const
  {
    if (index >= 0 && index < size)
    {
      return data[index];
    }
    else
    {
      throw std::out_of_range("Index out of bounds");
    }
  }

  // Function to resize the array when needed
  void resize()
  {
    capacity *= 2;
    T *newData = new T[capacity];
    for (int i = 0; i < size; ++i)
    {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
  }
};
class ListOfStudent
{
private:
  ListOfStudent(){};
  static ListOfStudent *instance;
  DynamicArray<string> nameStudent;
  DynamicArray<double> scoreStudent;

public:
  static ListOfStudent *getInstance()
  {
    if (!instance)
      instance = new ListOfStudent();
    return instance;
  }
  void addStudent(string name, double score)
  {
    nameStudent.add(name);
    scoreStudent.add(score);
  }
  void getAllStudent()
  {
    int sizeArray = nameStudent.getSize();
    for (int i = 0; i < sizeArray; i++)
    {
      cout << nameStudent.get(i) << " - " << scoreStudent.get(i) << endl;
    }
  }
  void getBestStudent()
  {
    double max = 0;
    int sizeArray = nameStudent.getSize();
    for (int i = 0; i < sizeArray; i++)
    {
      double temp = scoreStudent.get(i);
      if (max < temp)
      {
        max = temp;
      }
    }
    for (int i = 0; i < sizeArray; i++)
    {
      if (scoreStudent.get(i) == max)
      {
        cout << nameStudent.get(i) << " - " << scoreStudent.get(i) << endl;
      }
    }
  }
};
ListOfStudent *ListOfStudent::instance = nullptr;
void Menu()
{
  stringstream ss;
  ss << "----------------------\n"
    << "1. Add a new student \n"
    << "2. Display all students and their scores \n"
    << "3. Display the student with the best score \n"
    << "4. Exit the program \n"
    << "----------------------\n";
  cout << ss.str();
}
int main()
{
  int *arr = new int[4];
  ListOfStudent *list = ListOfStudent::getInstance();
  while (1)
  {
    Menu();
    int n;
    cin >> n;
    cin.ignore();
    if (n == 1)
    {
      string name;
      cout << "Enter the name of student added: ";
      getline(cin, name);
      double score;
      cout << "Enter the score of this student: ";
      cin >> score;
      list->addStudent(name, score);
    }
    else if (n == 2)
    {
      list->getAllStudent();
    }
    else if (n == 3)
    {
      list->getBestStudent();
    }
    else
      break;
  }
}