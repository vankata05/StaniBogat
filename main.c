#include<stdio.h>
#include"StaniBogat.h"

int main(){
    File file = readFile("questions.txt");
    printInfo(file, file.header.Qnum-1);
    addQuestion(file, "questions.txt");
}