#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Header {
    unsigned int Qnum;
} Header;

typedef struct Question {
    char question[300];
    char rightAns[100];
    char answers[4][100];
} Question;

typedef struct File {
    Header header;
    Question* questions;
} File;

File readFile(char* filename){
    File* file = malloc(sizeof(File));
    FILE *fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Error opening file!!!\n");
        exit(0);
    }

    fscanf(fp, "%d", &file->header.Qnum);
    
    file->questions = malloc(file->header.Qnum*sizeof(Question));
    for(int i = 0; i < file->header.Qnum; i++){
        fscanf(fp, "%[^:]", file->questions[i].question);
        for(int a = 0; a < 4; a++){
            fscanf(fp, "%s]", file->questions[i].answers[a]);
        }
        fscanf(fp, "%s", file->questions[i].rightAns);
    }

    return *file;
}

File addQuestion(File file, char* filename){
    file.header.Qnum++;
    file.questions = malloc(file.header.Qnum*sizeof(Question));
    printf("Enter the question:");
    scanf("%300[^\n]", file.questions[file.header.Qnum].question);
    printf("Enter the 4 posible anwers:");
    for(int i = 0; i < 4; i++){
        scanf("%s", file.questions[file.header.Qnum].answers[i]);
    }
    printf("Enter the right answer:");
    scanf("%s", file.questions[file.header.Qnum].rightAns);

    FILE *fp = fopen(filename, "a");

    //fprintf(fp, "%d\n", file.header.Qnum);
    fprintf(fp, "%s\t", file.questions[file.header.Qnum].question);
    for(int i = 0; i < 4; i++){
        fprintf(fp, "%s\t", file.questions[file.header.Qnum].answers[i]);
    }
    fprintf(fp, "%s\n", file.questions[file.header.Qnum].rightAns);

    return file;
}

void printInfo(File file){
    printf("Size: %d\n", file.header.Qnum);
    printf("Question: %s\n", file.questions[0].question);
    printf("A) %s\t", file.questions[0].answers[0]);
    printf("B) %s\n", file.questions[0].answers[1]);
    printf("C) %s\t", file.questions[0].answers[2]);
    printf("D) %s\n", file.questions[0].answers[3]);
    printf("Right Answer: %s\n", file.questions[0].rightAns);
}

int main(){
    File file = readFile("questions.txt");
    printInfo(file);
    addQuestion(file, "questions.txt");
}