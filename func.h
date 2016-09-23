#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

typedef struct{
    char name[50];
    int age;
    int id;
    int flag;
}person;

int getInt(char message[]);
float getFloat(char message[]);
char getChar(char message[]);

int strInt(char str[]) ;
int strLetter(char str[]);

void getString(char message[],char input[]);
int getStringLetter(char message[],char input[]);
int getStringInt(char message[],char input[]);

void menu();
char retry(char[]);
void pause(char str[]);
void printGraph(int[], int);
void initArray(person peopleArray[],int qty,int valor);
int firstSpot(person peopleArray[],int qty,int valor);
int checkFlag(person peopleArray[],int qty,int valor);
void formatName(person peopleArray[],int qty);

#endif
