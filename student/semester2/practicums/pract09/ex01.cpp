#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

class FileVector : public std::vector<int>
{
public:
    FileVector(std::string fileName) : fileName(fileName)
    {   
        std::ifstream read(fileName);
        if (!read)
        {
            std::cerr << "File " << fileName << " could not be opened!" << std::endl;
            return;
        }

        int currNum;
        while ((read) >> currNum)
        {
            push_back(currNum);
        }
    }

    ~FileVector()
    {
        std::ofstream write(fileName);

        for (int num : *this)
        {
            write << num << " ";
        }
    }

private:
    std::string fileName;
};

int main()
{
    FileVector fv = FileVector("vector.txt");
    fv.push_back(123);
}