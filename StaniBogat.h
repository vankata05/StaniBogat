#include<stdio.h>
// #include"Functions.c"

typedef struct Header {
    unsigned int Qnum;
} Header;

typedef struct Question {
    char* question;
    char* rightAns;
    char* answers[4];
} Question;

typedef struct File {
    Header header;
    Question* questions;
} File;

File readFile(char* filename);
File addQuestion(File file, char* filename);
void printInfo(File file, int num);
