#include <iostream>

using namespace std;

constexpr size_t MAX_LINES = 100;
constexpr size_t MAX_LINE_CHARS = 1024;

char text[MAX_LINES][MAX_LINE_CHARS + 1];
unsigned N;
unsigned M;

size_t myStrLen(const char* str)
{
    if (!str) return 0;

    size_t len = 0;
    while (*str)
    {
        len++;
        str++;
    }

    return len;
}

void myStrCpy(char* dest, const char* src)
{
    if (!dest || !src) return;

    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
}

int myStrCmp(const char* left, const char* right)
{
    while (*left && (*left == *right))
    {
        left++;
        right++;
    }

    return *left - *right;
}

bool lineIsValid(const char* line, unsigned maxLen)
{
    if (!line) return false;

    size_t len = 0;
    while (line[len] != '\0')
    {
        if (len >= maxLen)
            return false;
        len++;
    }

    return true;
}



// functionality functions below:

unsigned countLineWords(size_t n)
{
    if (n >= N) return 0;

    const char* line = text[n];
    unsigned wordsCount = 0;
    bool inWord = false;

    for (size_t i = 0; line[i] != '\0'; i++)
    {
        if (line[i] != ' ')
        {
            if (!inWord)
            {
                inWord = true;
                wordsCount++;
            }
        }
        else
        {
            inWord = false;
        }
    }

    return wordsCount;
}

unsigned count()
{
    unsigned totalWords = 0;

    for (size_t i = 0; i < N; i++)
        totalWords += countLineWords(i);

    return totalWords;
}

unsigned countLines()
{
    return N;
}

//helper func
void skipSpaces(const char* line, size_t& pos)
{
    while (line[pos] == ' ')
        pos++;
}

//helper func
bool getNextWord(const char* line, size_t& pos, char* buffer)
{
    skipSpaces(line, pos);

    if (line[pos] == '\0')
        return false;

    size_t b = 0;

    while (line[pos] != '\0' && line[pos] != ' ')
    {
        buffer[b++] = line[pos++];
    }

    buffer[b] = '\0';

    return true;
}

unsigned countWord(const char* word)
{
    if (!word) return 0;

    unsigned count = 0;

    for (size_t i = 0; i < N; i++)
    {
        const char* currLine = text[i];
        size_t pos = 0;

        char buffer[MAX_LINE_CHARS + 1];

        while (getNextWord(currLine, pos, buffer))
        {
            if (myStrCmp(buffer, word) == 0)
                count++;
        }
    }

    return count;
}

void lineByWord(const char* word, unsigned targetIndex)
{
    if (!word || targetIndex == 0)
    {
        cout << "ERROR! Invalid word or target index!" << endl;
        return;
    }

    unsigned occurrences = 0;

    for (size_t i = 0; i < N; i++)
    {
        const char* line = text[i];
        size_t pos = 0;

        char buffer[MAX_LINE_CHARS + 1];

        while (getNextWord(line, pos, buffer))
        {
            if (myStrCmp(buffer, word) == 0)
            {
                occurrences++;

                if (occurrences == targetIndex)
                {
                    cout << text[i] << endl;
                    return;
                }
            }
        }
    }

    cout << "ERROR! Word does not occur that many times!" << endl;
}

//helper func
unsigned countWordInLine(const char* line, const char* word)
{
    size_t pos = 0;
    char buffer[MAX_LINE_CHARS + 1];
    unsigned count = 0;

    while (getNextWord(line, pos, buffer))
    {
        if (myStrCmp(buffer, word) == 0)
            count++;
    }

    return count;
}

void lineByMostOccurances(const char* word)
{
    if (!word)
    {
        cout << "ERROR! Invalid word!" << endl;
        return;
    }

    int maxLine = -1;
    unsigned maxCount = 0;
    for (size_t i = 0; i < N; i++)
    {
        unsigned count = countWordInLine(text[i], word);

        if (count > maxCount)
        {
            maxCount = count;
            maxLine = i;
        }
    }

    if (maxLine == -1 || maxCount == 0)
    {
        cout << "ERROR! Word not found!" << endl;
        return;
    }

    cout << text[maxLine] << endl;
}

bool lineNumIsInvalid(unsigned n)
{
    return n == 0 || n > N;
}

void printLine(unsigned n)
{
    if (lineNumIsInvalid(n))
    {
        cout << "ERROR! Invalid line number!";
        return;
    }

    cout << text[n - 1] << endl;
}

void print()
{
    for (size_t i = 1; i <= N; i++)
        printLine(i);
}

//helper func
void appendWord(char* dest, size_t& destPos, const char* src)
{
    size_t i = 0;
    while (src[i] != '\0')
    {
        dest[destPos++] = src[i++];
    }
}

//helper func
void replaceWordInLine(char* line, const char* word, const char* toReplace)
{
    char newLine[MAX_LINE_CHARS + 1];
    size_t newPos = 0;

    char buffer[MAX_LINE_CHARS + 1];
    size_t pos = 0;

    while (getNextWord(line, pos, buffer))
    {
        bool isMatch = (myStrCmp(buffer, word) == 0);

        if (isMatch)
        {
            if (toReplace[0] == '\0')
                continue;

            if (newPos > 0)
                newLine[newPos++] = ' ';

            appendWord(newLine, newPos, toReplace);
        }
        else
        {
            if (newPos > 0)
                newLine[newPos++] = ' ';

            appendWord(newLine, newPos, buffer);
        }
    }

    newLine[newPos] = '\0';
    myStrCpy(line, newLine);
}

void removeWord(const char* word)
{
    if (!word)
    {
        cout << "ERROR! Invalid word!" << endl;
        return;
    }

    for (size_t i = 0; i < N; i++)
        replaceWordInLine(text[i], word, "");
}

void replaceWord(const char* word, const char* toReplace)
{
    if (!word || !toReplace)
    {
        cout << "ERROR! Invalid word or replacement word!" << endl;
        return;
    }

    for (size_t i = 0; i < N; i++)
        replaceWordInLine(text[i], word, toReplace);
}

void addLine(unsigned n, const char* newLine)
{
    if (!newLine || !lineIsValid(newLine, M))
    {
        cout << "ERROR! Invalid new line!" << endl;
        return;
    }

    if (N == MAX_LINES)
    {
        cout << "ERROR! Cannot add more lines!" << endl;
        return;
    }

    if (n > N)
    {
        myStrCpy(text[N], newLine);
        N++;
        return;
    }

    for (int i = N; i >= n; i--)
    {
        myStrCpy(text[i], text[i - 1]);
        if (i == n) break;
    }

    myStrCpy(text[n - 1], newLine);
    N++;
}

void changeLine(unsigned n, const char* newLine)
{
    if (lineNumIsInvalid(n))
    {
        cout << "ERROR! Invalid line number!" << endl;
        return;
    }

    if (!newLine || !lineIsValid(newLine, M))
    {
        cout << "ERROR! Invalid new line!" << endl;
        return;
    }

    myStrCpy(text[n - 1], newLine);
}

void removeLine(unsigned n)
{
    if (lineNumIsInvalid(n))
    {
        cout << "ERROR! Invalid line number!" << endl;
        return;
    }

    for (size_t i = n - 1; i < N - 1; i++)
    {
        myStrCpy(text[i], text[i + 1]);
    }

    text[N - 1][0] = '\0';
    N--;
}

void swapLines(unsigned a, unsigned b)
{
    if (lineNumIsInvalid(a) || lineNumIsInvalid(b))
    {
        cout << "ERROR! Invalid line numbers!" << endl;
        return;
    }

    if (a == b)
        return;

    char temp[MAX_LINE_CHARS + 1];

    myStrCpy(temp, text[a - 1]);
    myStrCpy(text[a - 1], text[b - 1]);
    myStrCpy(text[b - 1], temp);
}

void concatLines(unsigned n, unsigned count)
{
    if (lineNumIsInvalid(n))
    {
        cout << "ERROR! Invalid line number!" << endl;
        return;
    }

    if (count == 0)
        return;

    unsigned start = n - 1;
    unsigned end = start + count;

    if (end >= N)
        end = N - 1;

    unsigned lastMerged = start;

    for (unsigned i = start + 1; i <= end; i++)
    {
        size_t currLen = myStrLen(text[start]);
        size_t nextLen = myStrLen(text[i]);

        if (currLen + 1 + nextLen > M)
            break;

        text[start][currLen] = ' ';
        text[start][currLen + 1] = '\0';

        myStrCpy(text[start] + currLen + 1, text[i]);

        lastMerged = i;
    }

    unsigned linesToRemove = lastMerged - start;

    if (linesToRemove == 0)
        return;

    for (unsigned i = start + 1; i + linesToRemove < N; i++)
        myStrCpy(text[i], text[i + linesToRemove]);

    for (unsigned i = N - linesToRemove; i < N; i++)
        text[i][0] = '\0';

    N -= linesToRemove;
}

void splitAt(unsigned n, unsigned i)
{
    if (lineNumIsInvalid(n))
    {
        cout << "ERROR! Invalid line number!" << endl;
        return;
    }

    if (i == 0)
    {
        cout << "ERROR! Invalid word index!" << endl;
        return;
    }

    char left[MAX_LINE_CHARS + 1];
    char right[MAX_LINE_CHARS + 1];

    size_t leftPos = 0;
    size_t rightPos = 0;

    char buffer[MAX_LINE_CHARS + 1];
    size_t pos = 0;

    unsigned wordIndex = 0;

    while (getNextWord(text[n - 1], pos, buffer))
    {
        wordIndex++;

        if (wordIndex <= i)
        {
            if (leftPos > 0)
                left[leftPos++] = ' ';
            appendWord(left, leftPos, buffer);
        }
        else
        {
            if (rightPos > 0)
                right[rightPos++] = ' ';
            appendWord(right, rightPos, buffer);
        }
    }

    left[leftPos] = '\0';
    right[rightPos] = '\0';

    myStrCpy(text[n - 1], left);

    if (rightPos > 0)
    {
        for (size_t k = N; k > n; k--)
            myStrCpy(text[k], text[k - 1]);

        myStrCpy(text[n], right);

        N++;
    }
}

int main()
{
    //reading text format
    for (size_t i = 0; i < MAX_LINES; i++)
        text[i][0] = '\0';

    cout << "Enter number of lines:" << endl;
    cin >> N;
    if (!(1 <= N && N <= MAX_LINES))
    {
        cout << "ERROR! Invalid number of lines!";
        return -1;
    }
    
    cout << "Enter number of characters per line:" << endl;
    cin >> M;
    cin.get(); //get rid of endl after M is read so it doesn't mess up getline
    if (!(50 <= M && M <= MAX_LINE_CHARS))
    {
        cout << "ERROR! Invalid number of characters per line!";
        return -1;
    }

    //reading text line by line
    unsigned linesRead = 0;
    for (size_t i = 0; i < N; i++)
    {
        char currLine[MAX_LINE_CHARS + 1];
        cin.getline(currLine, MAX_LINE_CHARS + 1);

        if (!lineIsValid(currLine, M))
        {
            cout << "ERROR! Invalid line entered!";
            return -1;
        }

        if (myStrCmp(currLine, "$end$") == 0)
            break;

        myStrCpy(text[linesRead], currLine);
        linesRead++;
    }

    N = linesRead;

    //reading commands
    cout << "Enter commands (exit to stop):" << endl;
    while (true)
    {
        char command[256];
        cin >> command;

        if (myStrCmp(command, "exit") == 0)
            break;

        if (myStrCmp(command, "count") == 0)
        {
            cout << count() << endl;
        }
        else if (myStrCmp(command, "countLines") == 0)
        {
            cout << countLines() << endl;
        }
        else if (myStrCmp(command, "countLineWords") == 0)
        {
            unsigned n;
            cin >> n;
            cout << countLineWords(n - 1) << endl;
        }
        else if (myStrCmp(command, "countWord") == 0)
        {
            char word[256];
            cin >> word;
            cout << countWord(word) << endl;
        }
        else if (myStrCmp(command, "lineByWord") == 0)
        {
            char word[256];
            unsigned idx;
            cin >> word >> idx;
            lineByWord(word, idx);
        }
        else if (myStrCmp(command, "lineByMostOccurances") == 0)
        {
            char word[256];
            cin >> word;
            lineByMostOccurances(word);
        }
        else if (myStrCmp(command, "print") == 0)
        {
            print();
        }
        else if (myStrCmp(command, "printLine") == 0)
        {
            unsigned n;
            cin >> n;
            printLine(n);
        }
        else if (myStrCmp(command, "removeWord") == 0)
        {
            char word[256];
            cin >> word;
            removeWord(word);
        }
        else if (myStrCmp(command, "replaceWord") == 0)
        {
            char word[256], toReplace[256];
            cin >> word >> toReplace;
            replaceWord(word, toReplace);
        }
        else if (myStrCmp(command, "addLine") == 0)
        {
            unsigned n;
            cin >> n;
            cin.get();
            char newLine[MAX_LINE_CHARS + 1];
            cin.getline(newLine, MAX_LINE_CHARS + 1);
            addLine(n, newLine);
        }
        else if (myStrCmp(command, "changeLine") == 0)
        {
            unsigned n;
            cin >> n;
            cin.get();
            char newLine[MAX_LINE_CHARS + 1];
            cin.getline(newLine, MAX_LINE_CHARS + 1);
            changeLine(n, newLine);
        }
        else if (myStrCmp(command, "removeLine") == 0)
        {
            unsigned n;
            cin >> n;
            removeLine(n);
        }
        else if (myStrCmp(command, "swapLines") == 0)
        {
            unsigned a, b;
            cin >> a >> b;
            swapLines(a, b);
        }
        else if (myStrCmp(command, "concatLines") == 0)
        {
            unsigned n, count;
            cin >> n >> count;
            concatLines(n, count);
        }
        else if (myStrCmp(command, "splitAt") == 0)
        {
            unsigned n, i;
            cin >> n >> i;
            splitAt(n, i);
        }
        else
        {
            cout << "ERROR! Unknown command!" << endl;
        }
    }
}