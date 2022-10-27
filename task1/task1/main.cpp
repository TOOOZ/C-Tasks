#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <time.h>
//////////////////////////////////////////////////////////////
void Task1()
{
    std::cout << "Input two number \n";
    int num1;
    int num2;
    std::cin >> num1;
    std::cin >> num2;

    if (num1 == num2) {
        std::cout << "Numbers is equal";
    }
    else if (num1 > num2) {
        std::cout << num1;
    }
    else {
        std::cout << num2;
    }
}
/////////////////////////////////////////////////////////////
void Task2()
{
    std::cout << "input year\n";

    int year;

    std::cin >> year;

    if (year % 4 == 0) {
        std::cout << "yes";
    }
    else {
        std::cout << "no";
    }
}
/////////////////////////////////////////////////////////////
void Task3() {
    double a, b, c, d, x1, x2, x;
    std::cout << "input variable for (ax^2 + bx + c = 0): ";
    std::cout << "a= ";
    std::cin >> a;
    std::cout << "b= ";
    std::cin >> b;
    std::cout << "c= ";
    std::cin >> c;
    if (b == 0) {
        std::cout << "second coefficient is 0" << std::endl;
        return;
    }
    else {
        d = pow(b, 2) - (4 * a * c);
        std::cout << "d= " << d << std::endl;
        if (d == 0) {
            x = (b * (-1)) / (2 * a);
            std::cout << "x= " << x << std::endl;
        }
        else {
            x1 = ((b * (-1)) + sqrt(d)) / (2 * a);
            x2 = ((b * (-1)) - sqrt(d)) / (2 * a);
            std::cout << "x1 = " << x2 << std::endl;
            std::cout << "x2 = " << x1 << std::endl;

        }
    }
}
/////////////////////////////////////////////////////////////
void Task4() {
    int num;
    std::cout << "input number " << std::endl;
    std::cin >> num;
    if (num % 2 == 0) {
        std::cout << "even number";
    }
    else {
        std::cout << "odd number";
    }
}
////////////////////////////////////////////////////////////
void Task5() {
    for (int i = 1; i < 11; i++) {
        std::cout << pow(i, 2) << std::endl;
    }
}
///////////////////////////////////////////////////////////
void Task6() {
    std::vector<int> nums = {};
    std::string num = "";
    int max = 0;

    std::cout << "Input nums , type 'stop' for end subsequence" << std::endl;
    while (true) {
        std::cin >> num;
        if (num == "stop") {
            break;
        }
        else {
            nums.push_back(std::stoi(num));
        }
    }
    int i = 0;
    do
    {
        if (nums[i] > max) {
            max = nums[i];
        }
        i++;
    } while (i < nums.size());

    std::cout << max << std::endl;

}
//////////////////////////////////////////////////////////

void Task7() {
    int x = 0;
    double i = -4, y = 0;
    while (i <= 4) {
        y = (-2) * pow(i, 2) - 5 * i - 8;
        std::cout << "y= " << y << std::endl;
        i += 0.5;
    }
}

///////////////////////////////////////////////////////////
void SetNums(int inputArr[5][5]) {
    static std::mt19937_64 gen{
    static_cast<unsigned long long>(
                std::chrono::system_clock::now().time_since_epoch().count()) };
    std::uniform_int_distribution<int> dis(20, 60);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            inputArr[i][j] = dis(gen);
        }
    }
}

int GetMax(int inputArr[5][5]) {
    int max = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (inputArr[i][j] > max) {
                max = inputArr[i][j];
            }
        }
    }
    return max;
}

int GetMin(int inputArr[5][5]) {
    int min = 100;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (inputArr[i][j] < min) {
                min = inputArr[i][j];
            }
        }
    }
    return min;
}


void Task8() {
    int nums[5][5];
    SetNums(nums);
    int max = GetMax(nums);
    int min = GetMin(nums);
    std::cout << "Max = " << max << " Min = " << min << std::endl;

}

///////////////////////////////////////////////////////////////////
//С быстрой сортировкой
struct student {
    std::string surname;
    std::string initials;
    int groupNum;
    int mark[5];
};

double SortStruct(struct student studs) {
    double markAvg = 0;
    for (int j = 0; j < 5; j++) {
        markAvg += studs.mark[j];
    }
    markAvg = markAvg / 5;
    return markAvg;
}

void CheckMarks(struct student* studs) {
    bool print = true;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (studs[i].mark[j] < 4) {
                print = false;
            }
        }
        if (print) {
            std::cout << studs[i].surname << " " << studs[i].groupNum << std::endl;
        }
        print = true;
    }
}

void SortSwap(struct student* studs, int x, int y) {
    student t = studs[x];
    studs[x] = studs[y];
    studs[y] = t;
}

int FindPivot(struct student* studs, int i, int j) {
    int pivot = i - 1;
    for (int i1 = i; i1 < j; i1++) {
        if (SortStruct(studs[i1]) < SortStruct(studs[j])) {
            pivot += 1;
            SortSwap(studs, pivot, i1);
        }
    }

    pivot += 1;
    SortSwap(studs, pivot, j);
    return pivot;
}

void QuickSort(struct student* studs, int i, int j) {
    if (i > j) {
        return;
    }
    int pivot = FindPivot(studs, i, j);
    QuickSort(studs, i, pivot - 1);
    QuickSort(studs, pivot + 1, j);
}


void Task9() {
    static std::mt19937_64 gen{
    static_cast<unsigned long long>(
                std::chrono::system_clock::now().time_since_epoch().count()) };
    std::uniform_int_distribution<int> dis(2, 5);
    std::uniform_int_distribution<int> rGrNum(100, 999);

    std::string snames[10] = { "Petrov","Makarova","Davidova","Romanov","Pavlov","Sokolov","Alexandrov","Grigoreva","Kazakova","Ivanov" };
    std::string inita[10] = { "A.B","A.D","A.A","V.M","I.M","E.D","F.E","V.D","E.D","A.D" };


    student students[10];
    for (int i = 0; i < 10; i++) {
        students[i].surname = snames[i];
        students[i].initials = inita[i];
        students[i].groupNum = rGrNum(gen);

        for (int j = 0; j < 5; j++) {
            students[i].mark[j] = dis(gen);
        }
    }

    for (int i = 0; i < 10; i++) {
        std::cout << SortStruct(students[i]) << std::endl;
    }

    QuickSort(students, 0, 9);

    std::cout << "------------------" << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << SortStruct(students[i]) << std::endl;
    }

    CheckMarks(students);
}
////////////////////////////////////////////////////////////

struct train {
    std::string endpoint;
    int trainNum;
    struct tm startTime;
};


void SortSwap(struct train* arr, int x, int y) {
    train t = arr[x];
    arr[x] = arr[y];
    arr[y] = t;
}

int FindPivot(struct train* arr, int i, int j) {
    int pivot = i - 1;
    for (int i1 = i; i1 < j; i1++) {
        if (arr[i1].trainNum < arr[j].trainNum) {
            pivot += 1;
            SortSwap(arr, pivot, i1);
        }
    }

    pivot += 1;
    SortSwap(arr, pivot, j);
    return pivot;
}

int FindPivotEndpoint(struct train* arr, int i, int j) {
    int pivot = i - 1;
    for (int i1 = i; i1 < j; i1++) {
        if (arr[i1].endpoint < arr[j].endpoint) {
            pivot += 1;
            SortSwap(arr, pivot, i1);
        }
        else if (arr[i1].endpoint == arr[j].endpoint) {
            if (arr[i1].startTime.tm_hour < arr[j].startTime.tm_hour) {
                pivot += 1;
                SortSwap(arr, pivot, i1);
            }
        }
    }

    pivot += 1;
    SortSwap(arr, pivot, j);
    return pivot;
}


void QuickSortEndpoint(struct train* arr, int i, int j) {
    if (i > j) {
        return;
    }
    int pivot = FindPivotEndpoint(arr, i, j);
    QuickSortEndpoint(arr, i, pivot - 1);
    QuickSortEndpoint(arr, pivot + 1, j);
}


void QuickSort(struct train* arr, int i, int j) {
    if (i > j) {
        return;
    }
    int pivot = FindPivot(arr, i, j);
    QuickSort(arr, i, pivot - 1);
    QuickSort(arr, pivot + 1, j);
}


void FillArr(struct train* arr) {
    arr[0].endpoint = "point2";
    arr[1].endpoint = "point2";
    arr[2].endpoint = "point2";
    arr[3].endpoint = "point4";
    arr[4].endpoint = "point5";
    arr[0].trainNum = 513;
    arr[1].trainNum = 531;
    arr[2].trainNum = 123;
    arr[3].trainNum = 532;
    arr[4].trainNum = 326;
    arr[0].startTime.tm_hour = 12;
    arr[1].startTime.tm_hour = 15;
    arr[2].startTime.tm_hour = 23;
    arr[3].startTime.tm_hour = 12;
    arr[4].startTime.tm_hour = 13;
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i].endpoint << " " << arr[i].startTime.tm_hour << " " << arr[i].trainNum << std::endl;
    }
}

void Task10() {
    train trains[5];

    FillArr(trains);

    for (int i = 0; i < 5; i++) {
        std::cout << trains[i].trainNum << " " << trains[i].startTime.tm_hour << " " << trains[i].endpoint << std::endl;
    }

    QuickSort(trains, 0, 4);

    std::cout << "------------------" << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << trains[i].trainNum << " " << trains[i].startTime.tm_hour << " " << trains[i].endpoint << std::endl;
    }

    int num = 0;

    while (true) {
        std::cout << "Get train info by train number, 1) input train number for traint info " << std::endl << "2) type -1 for exit " << std::endl << "3) Type -2 for sorting by endpoint " << std::endl;
        std::cin >> num;

        for (int i = 0; i < 5; i++) {
            if (num == trains[i].trainNum) {
                std::cout << "Train info: " << trains[i].trainNum << " " << trains[i].startTime.tm_hour << " " << trains[i].endpoint << std::endl;
            }
        }

        if (num == -2) {
            QuickSortEndpoint(trains, 0, 4);
            for (int i = 0; i < 5; i++) {
                std::cout << trains[i].trainNum << " " << trains[i].startTime.tm_hour << " " << trains[i].endpoint << std::endl;
            }
        }

        if (num == -1) {
            break;
        }
    }

}



int main()
{
    //Task1();
    //Task2();
    //Task3();
    //Task4();
    //Task5();
    //Task6();
    //Task7();
    //Task8();
    //Task9();
    Task10();
}