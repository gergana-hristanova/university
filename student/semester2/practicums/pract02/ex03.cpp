#include <iostream>
#include <cstring>
#include "ex02.cpp" // so we can use class Student directly

const size_t ST_MAX_TERMS = 8; // copied from ex02.cpp cause static hasn't been taught yet and we can't put it in class Student
const size_t UNI_MAX_NAME_SIZE = 32;

class University {
    char* name;
    Student<char>* students;
    size_t studentsSize;
    size_t currTerm;

    public:

    University(const char* name, size_t currSem) : students(nullptr), currTerm(currTerm) {
        if(strlen(name) < UNI_MAX_NAME_SIZE) {
            std::strcpy(this->name, name);
        }
    }

    University(const char* name, size_t currTerm, Student<char>* students, size_t studentsSize) : currTerm(currTerm), students(students), studentsSize(studentsSize) {
        for (size_t i = 0; i < studentsSize; i++) {
            this->students[i] = *(students++);
        }
    }



    float getТеrmAverage(size_t term) {
        float res = 0;

        for (size_t i = 0; i < studentsSize; i++) {
            res += students[i].getTermAverage(term);
        }

        res /= studentsSize;

        return res;
    }

    float getAverage() {
        float res = 0;
        for (size_t i = 0; i < ST_MAX_SEMS; i++) {
            res += getТеrmAverage(i);
        }

        res /= ST_MAX_TERMS;

        return res;
    }
};

int main() {
    return 0;
}