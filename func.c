#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "func.h"

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param message Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char message[])
{
    float aux;
    int check;

    printf("%s",message);
    check = scanf("%f",&aux);

    if (check != 1)
    {
        printf("El dato ingresado no es valido");
        getFloat("Ingrese nuevamente = ");
    }

   return aux;

}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param message Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char message[])
{
    int aux;
    int check;

    printf("%s",message);
    check = scanf("%d",&aux);

    if (check != 1)
    {
        printf("El dato ingresado no es valido");
        getInt("Ingrese nuevamente = ");
    }

   return aux;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param message Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char message[])
{
    char aux;
    printf("%s",message);
    fflush(stdin);
    gets(&aux);
    return aux;
}


/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int strInt(char str[])
{
   int i=0;

   while(str[i] != '\0' || strlen(str) == 0)
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int strLetter(char str[])
{
   int i=0;

   while(str[i] != '\0' || strlen(str) == 0)
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param message Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 *
 */
void getString(char message[],char input[])
{
    puts(message);
    fflush(stdin);
    gets(input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param message Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 *
 */
int getStringLetter(char message[],char input[])
{
    char aux[256];
    getString(message,aux);

    if(strLetter(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

 /**
 * \brief Le da formato al nombre de un array de Personas con el valor recibido
 * \param array Es el array a ser formateado
 * \param qty Indica la logitud del array
 * \return void
 *
 */
void formatName(person peopleArray[],int qty)
{
    int i, j, aux;

    for(i=0;i < qty; i++)
    {
        if (peopleArray[i].flag != -1)
        {
            strcpy(peopleArray[i].name, strlwr(peopleArray[i].name));
            peopleArray[i].name[0] = toupper(peopleArray[i].name[0]);
            aux = strlen(peopleArray[i].name);

            for(j=0; j<aux; j++)
            {
                if (peopleArray[i].name[j] == ' ')
                {
                    peopleArray[i].name[j+1] = toupper(peopleArray[i].name[j+1]);
                }
            }
        }

    }
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param message Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 *
 */
int getStringInt(char message[],char input[])
{
    char aux[256];
    getString(message,aux);

    if(strInt(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Limpia la pantalla e imprime el menú.
 *
 */
void menu ()
{
    system("cls");
    printf("1- Agregar persona\n");
    printf("2- Borrar una persona\n");
    printf("3- Imprimir lista ordenada\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Salir\n");
}


/**
 * \brief Ofrece la opción de volver a ingresar. Toma un Char y lo devuelve.
 * \param message Mensaje a imprimir.
 * \param cont toma un char.
 * \return char
 *
 */
char retry(char message[])
{
    puts(message);
    char cont;
    fflush(stdin);
    return cont = getch();
}

/**
 * \brief Inicializa un array de Personas con el valor recibido
 * \param array Es el array a ser inicializado
 * \param qty Indica la logitud del array
 * \param valor Es el valor que sera cargado en cada posición
 * \return void
 *
 */
void initArray(person peopleArray[],int qty,int valor)
{
    int i;
    for(i=0;i < qty; i++)
    {
        peopleArray[i].id = valor;
        peopleArray[i].flag = valor;
        peopleArray[i].age = 0;
    }
}


/**
 * \brief Busca la primer ocurrencia de un valor en un array de Personas
 * \param array Es el array en el cual buscar
 * \param qty Indica la logitud del array
 * \param valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 *
 */
int firstSpot(person peopleArray[],int qty,int valor)
{
    int i;
    for(i=0;i < qty; i++)
    {
        if(peopleArray[i].id == valor)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Verifica que la bandera este en un valor, sino devuelve -1
 * \param qty Indica la longitud del array
 * \param valor Es el valor que se busca
 * \return 1 si el valor de la bandera es el deseado, -1 cuando no.
 *
 */
int checkFlag(person peopleArray[],int qty,int valor)
{
    int i;
    for(i=0;i < qty; i++)
    {
        if(peopleArray[i].flag == valor)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Imprime un gráfico con tres valores en distintas columnas.
 * \param ageArray contiene las edades a analizar.
 * \param qty Indica la longitud del array.
 * \return void.
 *
 */
void printGraph(int ageArray[], int qty)
{
    int i, flag=0, highest, upTo18 = 0, from19to35 = 0, over35 = 0;

    printf("\n\n\n");

    for (i = 0; i<qty;i++)
    {
        if (ageArray[i] <= 18 && ageArray[i]>0)
            upTo18++;
        else if (ageArray[i] > 35)
            over35++;
        else if (ageArray[i]>18 && ageArray[i]<=35)
            from19to35++;
    }

    if(upTo18 >= from19to35 && upTo18 >= over35)
    {
        highest = upTo18;
    }
    else
    {
        if(from19to35 >= upTo18 && from19to35 >= over35)
        {
            highest = from19to35;
        }
        else{
        highest = over35;
        }
    }

    for(i=highest; i>0; i--){
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= upTo18){
            printf("*");
        }
        if(i<= from19to35){
            flag=1;
            printf("\t*");
        }
        if(i<= over35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t %d\t%d\n", upTo18, from19to35, over35);
}


/**
 * \brief Imprime un mensaje y pide presionar cualquier tecla para continuar.
 * \param str contiene el mensaje a imprimir.
 * \return void.
 *
 */
void pause(char str[])
{
    printf("\n%s\n", str);
    system("pause");
}
