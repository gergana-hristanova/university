#include <iostream>
#include <cstring>

const size_t ST_MAX_GRADES = 32;
const size_t ST_MAX_NAME_SIZE = 32;
const size_t ST_MAX_SEMS = 8;

class Student {
    unsigned fn;
    char name[ST_MAX_NAME_SIZE + 1]; // + 1 for '/0'
    float grades[ST_MAX_SEMS][ST_MAX_GRADES];
    size_t gradesSize[8];
    size_t semsSize;
    size_t currSem;

    public:

    Student(const char* name, unsigned fn, size_t currTerm) : fn(fn), gradesSize({0}) {
        if(strlen(name) < ST_MAX_NAME_SIZE) {
            std::strcpy(this->name, name);
        }
    }

    float getTermAverage(size_t sem)
    {
        if (sem > currSem) {
            return 0;
        }

        if (semsSize == 0) {
            return 0;
        }

        float res = 0;
        for (size_t i = 0; i < gradesSize[sem - 1]; i++)
        {
            res += grades[sem - 1][i];
        }

        res /= gradesSize[sem - 1];

        return res;
    }

    float getAverage()
    {
        if (semsSize == 0) {
            return 0;
        }

        float res = 0;
        for (size_t i = 0; i < semsSize; i++) {
            res += getTermAverage(i);
        }

        res /= semsSize;

        return res;
    }

    // we assume grade is valid
    void addGrade(float grade, size_t sem) {
        if (currSem != sem) {
            return;
        }
        if (gradesSize[sem - 1] >= ST_MAX_GRADES) {
            return;
        }

        grades[sem - 1][gradesSize[sem - 1]++] = grade;
    }
};

int main() {
    return 0;
}