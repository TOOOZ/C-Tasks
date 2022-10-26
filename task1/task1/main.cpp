#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
//////////////////////////////////////////////////////////////
void task1()
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
void task2()
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
void task3() {
    double a, b, c, d,x1, x2, x;
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
        d = pow(b,2) - (4 * a * c);
        std::cout << "d= " << d << std::endl;
        if (d == 0) {
            x = (b*(-1)) / (2 * a);
            std::cout <<"x= " << x << std::endl;
        }
        else {
            x1 = ((b*(-1))+sqrt(d)) / (2 * a);
            x2 = ((b*(-1))-sqrt(d)) / (2 * a);
            std::cout << "x1 = " << x2 << std::endl;
            std::cout << "x2 = " << x1 << std::endl;

        }
    }
}
/////////////////////////////////////////////////////////////
void task4() {
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
void task5() {
    for (int i = 1; i < 11; i++) {
        std::cout << pow(i, 2) << std::endl;
    }
}
///////////////////////////////////////////////////////////
void task6() {
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

void task7() {
    int x = 0;
    double i = -4,y=0;
    while (i <= 4) {
        y = (-2) * pow(i, 2) - 5 * i - 8;
        std::cout << "y= " << y << std::endl;
        i += 0.5;
    }
}

///////////////////////////////////////////////////////////
void setNums(int inputArr[5][5]) {
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

int getMax(int inputArr[5][5]) {
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

int getMin(int inputArr[5][5]) {
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


void task8() {
    int nums[5][5];
    setNums(nums);
    int max = getMax(nums);
    int min = getMin(nums);
    std::cout << "Max = " << max << " Min = " << min << std::endl;

}

///////////////////////////////////////////////////////////////////

struct student {
    std::string surname;
    std::string initials;
    int groupNum;
    int mark[5];
};

student sortStudent(student(&students)[10]) {
    std::cout << students[0].surname;
    return &students;


}


void task9() {
    static std::mt19937_64 gen{
    static_cast<unsigned long long>(
                std::chrono::system_clock::now().time_since_epoch().count()) };
    std::uniform_int_distribution<int> dis(2, 5);
    std::uniform_int_distribution<int> rGrNum(100, 999);

    std::string snames[10] = { "Petrov","Makarova","Davidova","Romanov","Pavlov","Sokolov","Alexandrov","Grigoreva","Kazakova","Ivanov" };
    std::string inita[10] = { "A.B","A.D","A.A","V.M","I.M","E.D","F.E","V.D","E.D","A.D" };
    int grNum[10];
    int marks[10];
    //bool print = true;
    
    for (int i = 0; i < 10; i++) {
        grNum[i] = rGrNum(gen);
    }

    student students[10];
    for (int i = 0; i < 10; i++) {
        students[i].surname = snames[i];
        students[i].initials = inita[i];
        students[i].groupNum = grNum[i];

        for (int j = 0; j < 5; j++) {
            students[i].mark[j] = dis(gen);
        }
    }
}
////////////////////////////////////////////////////////////

struct train {
    std::string endpoint;
    int trainNum;
    std::string startTime;
};

//void task10(){

//}



int main()
{
    //task1();
    //task2();
    //task3();
    //task4();
    //task5();
    //task6();
    //task7();
    //task8();
    task9();
    //task10();
}