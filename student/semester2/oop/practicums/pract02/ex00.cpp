#include <iostream>
#include <cstring>

class Student {
    int fn;
    char name[32];
    float grades[32];
    size_t gradesSize;

    public:

    Student(const char* name, int fn) : fn(fn), gradesSize(0) {
        if(strlen(name) < 32) {
            std::strcpy(this->name, name);
        }
    }

    float GetTermAverage()
    {
        if (gradesSize == 0) {
            return 0;
        }

        float res = 0;
        for (size_t i = 0; i < gradesSize; i++)
        {
            res += grades[i];
        }

        res /= gradesSize;

        return res;
    }

    // we assume grade is valid
    void addGrade(float grade) {
        if (gradesSize >= 32) {
            return;
        }

        grades[gradesSize++] = grade;
    }
};

int main() {
    return 0;
}