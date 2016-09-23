#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "func.h"
#define MAX 20

int main()
{
    person peopleArray[MAX];
    person auxPerson;

    char auxName[50];
    char auxIdStr[50];
    char auxAge[50];
    int ageArray[MAX];
    int auxIdInt, auxAgeInt, spotIndex, searchIndex, i, j;
    char option;
    char redo;

    initArray(peopleArray,MAX,-1);

    while(option != '5')
    {
         menu();
         option = getch();
         redo = 'n';
         switch(option)
         {
            case '1':

                menu();
                spotIndex = firstSpot(peopleArray,MAX,-1);
                if(spotIndex == -1)
                {
                    pause("Memoria llena");
                    break;
                }

                printf("\nAgregar Persona\n");
                if (!getStringLetter("Ingrese el nombre: ",auxName))
                {

                    redo = retry("Dato erroneo. Reingresar? S/N\n");
                    if (redo == 's')
                    {
                    if (!getStringLetter("Reingrese el nombre: ",auxName))
                        {
                        pause("El nombre debe estar compuesto solo por letras");
                        break;
                        }
                    }
                    else
                    {
                        pause("Accion cancelada");
                        break;
                    }
                }

                if (!getStringInt("Ingrese el DNI: ",auxIdStr))
                {

                    redo = retry("Dato erroneo. Reingresar? S/N\n");
                    if (redo == 's')
                    {
                    if (!getStringInt("Reingrese el DNI: ",auxIdStr))
                        {
                        pause("El DNI debe estar compuesto solo por numeros");
                        break;
                        }
                    }
                    else
                    {
                        pause("Accion cancelada");
                        break;
                    }
                }
                auxIdInt = atoi(auxIdStr);

                 if (!getStringInt("Ingrese la edad: ",auxAge))
                {

                    redo = retry("Dato erroneo. Reingresar? S/N\n");
                    if (redo == 's')
                    {
                    if (!getStringInt("Reingrese la edad: ",auxAge))
                        {
                        pause("La edad debe estar compuesta solo por numeros");
                        break;
                        }
                    }
                    else
                    {
                        pause("Accion cancelada");
                        break;
                    }
                }
                auxAgeInt = atoi(auxAge);

                if(firstSpot(peopleArray,MAX,auxIdInt) != -1)
                {
                    pause("El DNI ya fue ingresado");
                    break;
                }

                strcpy(peopleArray[spotIndex].name,auxName);
                peopleArray[spotIndex].id = auxIdInt;
                peopleArray[spotIndex].age = auxAgeInt;
                peopleArray[spotIndex].flag = 1;

                break;

            case '2':

                 if (checkFlag(peopleArray, MAX,1) == -1)
                {
                    pause("No hay ningun dato cargado\n");
                    break;
                }

                 if (!getStringInt("\nIngrese el DNI: ",auxIdStr))
                {

                    redo = retry("Dato erroneo. Reingresar? S/N\n");
                    if (redo == 's')
                    {
                    if (!getStringInt("Reingrese el DNI: ",auxIdStr))
                        {
                        pause("El DNI debe estar compuesto solo por numeros");
                        break;
                        }
                    }
                    else
                    {
                        pause("Accion cancelada");
                        break;
                    }
                }
                searchIndex = firstSpot(peopleArray,MAX,atoi(auxIdStr));

                if(searchIndex == -1)
                {
                    pause("DNI Incorrecto");
                    break;
                }

                redo = retry("Seguro que desea eliminar? S/N");
                    if (redo == 's')
                    {
                        pause("Persona eliminada con exito\n");
                        peopleArray[searchIndex].id=-1;
                        peopleArray[searchIndex].flag=-1;
                        peopleArray[searchIndex].age=-1;

                        break;
                        }

                    else
                    {
                        pause("Accion cancelada");
                        break;
                    }

                break;

            case '3':

            formatName(peopleArray, MAX);
            if (checkFlag(peopleArray, MAX,1) == -1)
                {
                    pause("No hay ningun dato cargado\n");
                    break;
                }

                for(i=0; i<MAX-1; i++)
                {
                    if(peopleArray[i].id == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < MAX; j++)
                    {
                        if(peopleArray[j].id == -1)
                        {
                            continue;
                        }
                        if(stricmp(peopleArray[i].name,peopleArray[j].name) > 0)
                        {
                            auxPerson = peopleArray[j];
                            peopleArray[j] = peopleArray[i];
                            peopleArray[i] = auxPerson;
                        }
                    }
                }

                for(i=0;i < MAX; i++)
                {
                    if(peopleArray[i].id != -1)
                    {
                        printf("\n%s - %d - %d\n",peopleArray[i].name, peopleArray[i].id, peopleArray[i].age);

                    }
                }
                system("pause");
                break;

            case '4':

                if (checkFlag(peopleArray, MAX,1) == -1)
                {
                    pause("No hay ningun dato cargado\n");
                    break;
                }
                for (i=0; i<MAX; i++)
                {
                    ageArray[i] = peopleArray[i].age;
                }
                printGraph(ageArray, MAX);
                system("pause");
                break;

            case '5':

                break;

            default:
                pause("No es una opcion valida");
                break;
         }
    }


    return 0;
}
