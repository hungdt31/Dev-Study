#include "main.cpp"

int main() {
    ListOfStudent* ls = ListOfStudent::getInstance();
    while (1)
    {
        Menu();
        int n;
        cin >> n;
        cin.ignore();
        if (n == 1)
        {
            string name;
            cout << "Enter the name of student added:\n";
            getline(cin, name);
            double score;
            cout << "Enter the score of this student:\n";
            cin >> score;
            ls->addStudent(name, score);
        }
        else if (n == 2)
        {
            ls->displayAllStudent();
        }
        else if (n == 3)
        {
            ls->displayBestStudent();
        }
        else if (n == 4)
        {
            string name;
            cout << "Enter the name of student deleted:\n";
            getline(cin, name);
            ls->deleteStudentByName(name);
        }
        else break;
    }
    return 0;
}