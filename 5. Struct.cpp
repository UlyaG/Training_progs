#include <iostream>
#include <fstream>
using namespace std;

struct Stud {
    void factorial() {
        cout << "asad" << endl;
        return;
    }
};

typedef struct {
    char name[60];
    bool sex;
    int group;
    int number;
    int marks[8];
    
} Student;

typedef struct {
    char name[60];
    bool isPerforming;
    bool isDoctor;
    char university[10];
    char title[100];
} Guest;


void fileReading(Student stud[]) {
    ifstream File;
    File.open("students.txt");
    int i = 0;
    while (!File.eof()) 
    {
        char s1[30], s2[30], s3[30];
        File >> s1;
        File >> s2;
        File >> s3;
        stud[i].name[0] = '\0';
        strcat_s(stud[i].name, s1);
        strcat_s(stud[i].name, " ");
        strcat_s(stud[i].name, s2);
        strcat_s(stud[i].name, " ");
        strcat_s(stud[i].name, s3);
        File >> stud[i].sex;
        File >> stud[i].group;
        File >> stud[i].number;
        for (int j = 0; j < 8; j++) 
        {
            File >> stud[i].marks[j];
        }
        i++;
        
    }
    File.close();
} 

void fileReadingIdz(Guest ppl[]) {
    ifstream File;
    File.open("guests.txt");
    int i = 0;
    while (!File.eof())
    {
        char s1[30], s2[30], s3[30];
        File >> s1;
        File >> s2;
        File >> s3;
        ppl[i].name[0] = '\0';
        strcat_s(ppl[i].name, s1);
        strcat_s(ppl[i].name, " ");
        strcat_s(ppl[i].name, s2);
        strcat_s(ppl[i].name, " ");
        strcat_s(ppl[i].name, s3);
        File >> ppl[i].isPerforming;
        File >> ppl[i].isDoctor;
        File >> ppl[i].university;
        File >> ppl[i].title;
        i++;
    }
    File.close();
}

void showGuest(Guest ppl[], int i) {
    cout << i << ". " << ppl[i].name << " (";
    if (ppl[i].isPerforming == 0) { cout << "listener"; }
    else { cout << "speaker"; }
    cout << "): ";
    if (ppl[i].isDoctor == 0) { cout << "Master's degree."; }
    else { cout << "Doctoral degree."; }
    cout << endl << "University: " << ppl[i].university;
    if (ppl[i].isPerforming == 1) {
        cout << endl << "The title of performing: " << ppl[i].title << endl;
    }
    cout << endl;
}

void showGuests(Guest ppl[]) {
    for (int i = 0; i < 15; i++)
    {
        if (((ppl[i].isDoctor == 0) || (ppl[i].isDoctor == 1)))
        {
            showGuest(ppl, i);
            cout << endl;
        }
    }
}

void showSpeakers(Guest ppl[]) {
    for (int i = 0; i < 15; i++) {
        if (ppl[i].isPerforming == 1)
        {
            showGuest(ppl, i);
        }
    }
}

void showLETI(Guest ppl[]) {
    for (int i = 0; i < 15; i++) {
        if ((ppl[i].university[0] == 'L') && (ppl[i].university[1] == 'E'))
        {
            showGuest(ppl, i);
        }
    }
}

void Idz() {
    Guest ppl[15];
    fileReadingIdz(ppl);
    cout << "Individual Homework #7" << endl;
    cout << "Guests of the scientigic conference." << endl;
    int oper = 0;
    while (oper!=4) {
        cout << "Choose an operation: " << endl
            << "1. Show guests" << endl
            << "2. Show speakers" << endl
            << "3. Show guests from LETI" << endl
            << "4. Stop working with individual homework" << endl;
        cin >> oper;
        switch (oper) {
        case 1:
            showGuests(ppl);
            break;
        case 2:
            showSpeakers(ppl);
            break;
        case 3:
            showLETI(ppl);
            break;
        case 4:
            break;
        default:
            cout << "Try again";
        }
        system("Pause");
        system("cls");
    }
}

void fileRecording(Student stud[]) {
    ofstream File;
    File.open("students.txt");
    int i = 0;
    while ((stud[i].sex == 0) || (stud[i].sex == 1))
    {
        File << stud[i].name << endl;
        File << stud[i].sex << endl;
        File << stud[i].group << endl;
        File << stud[i].number << endl;
        for (int j = 0; j < 8; j++)
        {
            File << stud[i].marks[j] << endl;
        }
        i++;
    }
    File.close();
}

void newStud(Student stud[]) {
    char name1[20], name2[20], name3[20];
    int k = 15;
    for (int i = 0; i < 15; i++)
    {
        if ((stud[i].sex != 0) && (stud[i].sex != 1))
        {
            k = i;
            break;
        }
    }
    if (k == 15) { cout << "The memory is full." << endl; }
    else {
        cout << "Enter full name of the student: ";
        stud[k].name[0] = '\0';
        cin >> name1; 
        cin >> name2;
        cin >> name3;
        strcat_s(stud[k].name, name1);
        strcat_s(stud[k].name, " ");
        strcat_s(stud[k].name, name2);
        strcat_s(stud[k].name, " ");
        strcat_s(stud[k].name, name3);
        cout << endl << "Enter the gender of the student (0 - male, 1 - female): ";
        cin >> stud[k].sex;
        cout << endl << "Enter the student's group number: ";
        cin >> stud[k].group;
        stud[k].number = 1;
        for (int i = 0; i < k; i++)
        {
            if ((stud[i].group == stud[k].group) && (stud[i].number >= stud[k].number))
            {
                stud[k].number = stud[i].number + 1;
            }
        }
        for (int i = 0; i < 8; i++)
        {
            while (!((stud[k].marks[i] > 1) && (stud[k].marks[i] < 6)))
            {
                cout << endl << "Enter the student's mark for the " << i+1 << " exam: ";
                cin >> stud[k].marks[i];
            }
        }
    }
    fileRecording(stud);
}

void showStud(Student stud[], int i) {
    cout << i << ". " << stud[i].name << " (";
    if (stud[i].sex == 0) { cout << "male"; }
    else { cout << "female"; }
    cout << ") " << stud[i].group << ' ' << stud[i].number << endl;
    cout << "Exam`s marks: ";
    for (int j = 0; j < 8; j++)
    {
        cout << stud[i].marks[j];
        if (j == 7) { cout << ';'; }
        else { cout << ", "; }
    }
    cout << endl;
}

void showStuds(Student stud[]) {
    for (int i = 0; i < 15; i++)
    {
        if (!((stud[i].sex != 0) && (stud[i].sex != 1)))
        {
            showStud(stud, i);
            cout << endl;
        }
    }
}

void editStud(Student stud[]) {
    cout << "Choose the student: " << endl;
    showStuds(stud);
    char name1[20], name2[20], name3[20];
    int i, j = 0, c, a=0, b = 0;
    bool er = 1;
    cin >> i;
    while (er)
        if ((stud[i].sex != 0) && (stud[i].sex != 1))
        {
            cout << "Try again." << endl;
        }
        else {
            er = 0;
            cout << "Choose the characteristic: " << endl
                << "1. Name" << endl
                << "2. Group" << endl
                << "3. Number in group list" << endl
                << "4. Sex" << endl
                << "5. Mark" << endl;
            while (!((j > 1) && (j < 6)))
            {
                cin >> j;
                switch (j) {
                case 1:
                    cout << "Enter full name of the student: ";
                    stud[i].name[0] = '\0';
                    cin >> name1;
                    cin >> name2;
                    cin >> name3;
                    strcat_s(stud[i].name, name1);
                    strcat_s(stud[i].name, " ");
                    strcat_s(stud[i].name, name2);
                    strcat_s(stud[i].name, " ");
                    strcat_s(stud[i].name, name3);
                    break;
                case 2:
                    cout << "Enter the group number: ";
                    cin >> stud[i].group;
                    for (int k = 0; k < 15; k++)
                    {
                        if ((stud[k].group == stud[i].group) && (stud[k].number >= stud[i].number))
                        {
                            stud[i].number = stud[k].number + 1;
                        }
                    }
                    break;
                case 3:
                    cout << "Enter the number in the group list: ";
                    cin >> c;
                    for (int k = 0; k < 15; k++)
                    {
                        if ((stud[k].group == stud[i].group) && (stud[k].number == c))
                        {
                            stud[k].number = stud[i].number;
                            stud[i].number = c;
                        }
                    }
                    break;
                case 4:
                    stud[i].sex = !(stud[i].sex);
                    break;
                case 5:
                    while (!((a > 0) && (a < 9)))
                    {
                        cout << "Which mark do you want to edit? (its number) ";
                        cin >> a;
                        cout << endl;
                    }
                    while (!((b > 2) && (b < 6)))
                    {
                        cout << "Enter correct mark: ";
                        cin >> b;
                        cout << endl;
                    }
                    stud[i].marks[a - 1] = b;
                    break;
                default:
                    cout << "Try again.";

                }
            }
        }
    fileRecording(stud);
}

void showGroup(Student stud[]) {
    int gr, st = 0;
    cout << "Enter group number: ";
    cin >> gr;
    for (int i = 0; i < 15; i++)
    {
        if (stud[i].group == gr)
        {
            showStud(stud, i);
            cout << endl;
            st++;
        }
    }
    if (st == 0) { cout << "There is no such group." << endl; }
}

void topStuds(Student stud[]) {
    float scoreSort[15], score[15]{};
    int end=14, begin = 1;
    bool stop = true;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (!((stud[i].sex != 0) && (stud[i].sex != 1)))
            {
                score[i] += stud[i].marks[j];
            }
            else { score[i] = 0; }
        }
        score[i] /= 8;
    }
    for (int i = 0; i < 15; i++)
    {
        scoreSort[i] = score[i];
    }
    while (stop)
    {
        stop = false;
        for (int i = begin; i < end; i++)
        {
            if (scoreSort[i] > scoreSort[i - 1])
            {
                float c = scoreSort[i];
                scoreSort[i] = scoreSort[i - 1];
                scoreSort[i - 1] = c;
                stop = true;
            }
        }
        end--;
        if (!stop) { break; }
        stop = false;
        for (int i = end - 1; i >= begin; i--)
        {
            if (scoreSort[i] > scoreSort[i - 1])
            {
                float c = scoreSort[i];
                scoreSort[i] = scoreSort[i - 1];
                scoreSort[i - 1] = c;
                stop = true;
            }
        }
        begin++;
    }
    for (int i = 0; i <=2; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (scoreSort[i] == score[j]) 
            {
                cout << "Average score: " << score[j] << endl;
                showStud(stud, j);
                cout << endl;
            }
        }
    }
}

int showGend(Student stud[], bool sex) {
    int res = 0;
    for (int i = 0; i < 15; i++)
    {
        if (stud[i].sex == sex)
        {
            res++;
        }
    }
    return res;
}

void allMarks(Student stud[]) {
    int mar=0;
    while (!((mar > 0) && (mar < 4)))
    {
        cout << "Choose mark`s status: " << endl
            << "1. 3-5 marks" << endl
            << "2. 4-5 marks" << endl
            << "3. 5 marks only" << endl;
        cin >> mar;
    }
    for (int i = 0; i < 15; i++)
    {
        bool four = 0, three = 0;
        for (int j = 0; j < 8; j++)
        {
            if (stud[i].marks[j] == 3) { three = 1; }
            if (stud[i].marks[j] == 4) { four = 1; }
        }
        switch (mar) {
        case 1: 
            if (three) 
            {
                showStud(stud, i);    
                cout << endl;
            }
            break;
        case 2:
            if (!three && four)
            {
                showStud(stud, i);
                cout << endl;
            }
            break;
        case 3:
            if (!(three || four))
            {
                showStud(stud, i);
                cout << endl;
            }
            break;
        }
    }
}

void showId(Student stud[]) {
    int id;
    cout << "Enter the id: ";
    cin >> id;
    for (int i = 0; i < 15; i++)
    {
        if (id == stud[i].number)
        {
            showStud(stud, i);
            cout << endl;
        }
    }
}


int main()
{
    Student stud[15];
    fileReading(stud);

    int op = 0;
    while (op!=10)
    {
        cout << "Choose an operation: " << endl
            << "1. Show students" << endl
            << "2. Add a student" << endl
            << "3. Edit a student" << endl
            << "4. Show students of group" << endl
            << "5. Show top 3 of students." << endl
            << "6. Show the number of male/female students" << endl
            << "7. Show studends with 3 marks/4-5 marks/5 marks only." << endl
            << "8. Show students with id." << endl
            << "9. Individual Homework." << endl
            << "10. Stop working with code." << endl;
        cin >> op;
        switch (op) {
        case 1:
            showStuds(stud);
            break;
        case 2: 
            newStud(stud);
            break;
        case 3: 
            editStud(stud);
            break;
        case 4:
            showGroup(stud);
            break;
        case 5: 
            topStuds(stud);
            break;
        case 6:
            bool sex;
            cout << "Enter gender of students: " << endl
                << "0 - male" << endl
                << "1 - female" << endl;
            cin >> sex;
            cout << "The number of students this gender: " << showGend(stud, sex) << endl;
            break;
        case 7:
            allMarks(stud);
            break;
        case 8:
            showId(stud);
            break;
        case 9:
            Idz();
            break;
        case 10:
            break;
        default: 
            cout << "Try again";
        }
        system("Pause");
        system("cls");
    }
    return 0;
}
