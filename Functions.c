#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"StaniBogat.h"

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
        fscanf(fp, "%m[^:]", &file->questions[i].question);
        fgetc(fp);
        for(int a = 0; a < 4; a++){
            fscanf(fp, "%m[^:]", &file->questions[i].answers[a]);
            fgetc(fp);
        }
        fscanf(fp, "%m[^\n]", &file->questions[i].rightAns);
        fgetc(fp);
    }

    return *file;
}

File addQuestion(File file, char* filename){
    file.header.Qnum++;
    file.questions = malloc(file.header.Qnum*sizeof(Question));
    printf("Enter the question:\n");
    getchar();
    //purvi scanf
    scanf("%m[^\n]", &file.questions[file.header.Qnum].question);
    getchar();
    printf("Enter the 4 posible anwers:\n");
    for(int i = 0; i < 4; i++){
        //vtori scanf
        scanf("%m[^\n]", &file.questions[file.header.Qnum].answers[i]);
        getchar();
        // printf("%d\n", i);
    }
    printf("Enter the right answer:\n");
    scanf("%m[^\n]", &file.questions[file.header.Qnum].rightAns);
    getchar();

    printf("%s\n", file.questions[file.header.Qnum].question);
    for(int i = 0; i < 4; i++){
        printf("%s:", file.questions[file.header.Qnum].answers[i]);
    }
    printf("%s", file.questions[file.header.Qnum].rightAns);
    

/*
    FILE *fp = fopen(filename, "a");

    //fprintf(fp, "%d\n", file.header.Qnum);
    printf( "%s:", file.questions[file.header.Qnum].question);
    for(int i = 0; i < 4; i++){
        fprintf(fp, "%s:", file.questions[file.header.Qnum].answers[i]);
    }
    fprintf(fp, "%s", file.questions[file.header.Qnum].rightAns);

    return file;*/
}

void printInfo(File file, int num){
    printf("Size: %d\n", file.header.Qnum);
    printf("Question: %s\n", file.questions[num].question);
    printf("A) %s\n", file.questions[num].answers[0]);
    printf("B) %s\n", file.questions[num].answers[1]);
    printf("C) %s\n", file.questions[num].answers[2]);
    printf("D) %s\n", file.questions[num].answers[3]);
    printf("Right Answer: %s\n", file.questions[num].rightAns);
}