#include <stdio.h>
#include <stdlib.h>

int littleShip=2;
int mediumShip=3;
int bigShip=4;

int getX(char letra) {
    switch (letra) {
        case 'A':
            return 0;
        case 'B':
            return 1;
        case 'C':
            return 2;
        case 'D':
            return 3;
        case 'E':
            return 4;
        case 'F':
            return 5;
        case 'G':
            return 6;
        case 'H':
            return 7;
        default:
            break;
    }
}
int getY(char num) {
    switch (num) {
        case '1':
            return 0;
        case '2':
            return 1;
        case '3':
            return 2;
        case '4':
            return 3;
        case '5':
            return 4;
        case '6':
            return 5;
        case '7':
            return 6;
        case '8':
            return 7;
        default:
            break;
    }
}

void gameTable(int tabla[8][8]) {
    int empty_value = 0;
    for (int x = 0; x <= 7; x++) {
        for (int y = 0; y <= 7; y++) {
            tabla[x][y] = empty_value;
        }
    }
}
void printTable(int tabla[8][8]) {
    printf("        |A|     |B|     |C|     |D|     |E|     |F|     |G|     |H|");
    for (int x = 0; x <= 7; x++) {
        printf("\n");
        printf("|%i|\t", x + 1);
        for (int y = 0; y <= 7; y++) {
            printf("|%i|\t", tabla[x][y]);
        }
    }
}
void setValues(char X, char Y, int tabla[8][8], int value) {
    tabla[getY(Y)][getX(X)] = value;
}
void nickname1(char name1[20]) {

    printf("P1 INGRESA TU NICKNAME: ");
    gets(name1);
    printf("NICKNAME: %s\n", name1);

}
void nickname2(char name2[20]) {

    printf("\nP2 INGRESA TU NICKNAME: \n");
    scanf("%s",name2);
    printf("NICKNAME: %s\n", name2);

}
int position (char starPositionX,char finalPositionX,char starPositionY,char finalPositionY, int table[8][8], int shipT) {
    int x, y;
    int distance;
    int startIndexX = getX(starPositionX);
    int startIndexY = getY(starPositionY);
    int finalIndexX = getX(finalPositionX);
    int finalIndexY = getY(finalPositionY);

    if (startIndexX == finalIndexX || startIndexY == finalIndexY) {
        if (startIndexX == finalIndexX) {
            distance = abs(finalIndexY - startIndexY) + 1;

            if (distance == shipT) {
                if (startIndexY > finalIndexY) {
                    int in, fi;
                    in = startIndexY;
                    fi = finalIndexY;
                    startIndexY = fi;
                    finalIndexY = in;
                }
                for (y = startIndexY; y <= finalIndexY; ++y) {
                    if (table[y][startIndexX] == 1) {
                        printf("ya hay un barco");
                        printf("\nIngrese  coordenadainicial X, Y:");
                        scanf(" %c %c", &starPositionX, &starPositionY);
                        printf("\nIngrese  coordenada final X, Y:");
                        scanf(" %c  %c", &finalPositionX, &finalPositionY);
                        position(starPositionX, finalPositionX, starPositionY, finalPositionY, table, shipT);
                        return distance;
                    } else
                        table[y][startIndexX] = 1;
                }
            }
            if (distance != shipT) {
                printf("Asigne coordenadas con respecto al tamano del barco\n");
                printf("\nIngrese  coordenadainicial X, Y:");
                scanf(" %c %c", &starPositionX, &starPositionY);
                printf("\nIngrese  coordenada final X, Y:");
                scanf(" %c  %c", &finalPositionX, &finalPositionY);
                position(starPositionX, finalPositionX, starPositionY, finalPositionY, table, shipT);
                return distance;
            }
        }
        if (startIndexY == finalIndexY) {
            distance = abs(finalIndexX - startIndexX) + 1;
            if (distance == shipT) {
                if (startIndexX > finalIndexX) {
                    int in, fi;
                    in = startIndexX;
                    fi = finalIndexX;
                    startIndexX = fi;
                    finalIndexX = in;
                }
                for (x = startIndexX; x <= finalIndexX; ++x) {
                    if (table[startIndexY][x] == 1) {
                        printf("ya hay un barco\n");
                        printf("\nIngrese  coordenadainicial X, Y:");
                        scanf(" %c %c", &starPositionX, &starPositionY);
                        printf("\nIngrese  coordenada final X, Y:");
                        scanf(" %c  %c", &finalPositionX, &finalPositionY);
                        position(starPositionX, finalPositionX, starPositionY, finalPositionY, table, shipT);
                        return distance;
                    } else
                        table[startIndexY][x] = 1;
                }
            }
            if (distance != shipT) {
                printf("Asigne coordenadas con respecto al tamano del barco\n");
                printf("\nIngrese  coordenadainicial X, Y:");
                scanf(" %c %c", &starPositionX, &starPositionY);
                printf("\nIngrese  coordenada final X, Y:");
                scanf(" %c  %c", &finalPositionX, &finalPositionY);
                position(starPositionX, finalPositionX, starPositionY, finalPositionY, table, shipT);
                return distance;
            }
        }
    }
    if (startIndexX != finalIndexX && startIndexY != finalIndexY) {
        printf("No se permite en diagonal\n");
        printf("\nIngrese  coordenadainicial X, Y:");
        scanf(" %c %c", &starPositionX, &starPositionY);
        printf("\nIngrese  coordenada final X, Y:");
        scanf(" %c  %c", &finalPositionX, &finalPositionY);
        position(starPositionX, finalPositionX, starPositionY, finalPositionY, table, shipT);
        return starPositionX && finalPositionX && starPositionY && finalPositionY;
    }
    return 0;
}
void showTable (int tabla[8][8]){
    printf("        |A|     |B|     |C|     |D|     |E|     |F|     |G|     |H|");
    for (int x = 0; x <=7 ; ++x) {
        printf("\n");
        printf("|%i|\t", x + 1);
        for (int y = 0; y <=7 ; ++y) {
            if (tabla[x][y]==0||tabla[x][y]==1){
                printf("|+|\t");
            } else if (tabla[x][y]==-1){
                printf("|-|\t");
            }else if (tabla[x][y]==-2){
                printf("|x|\t");
            }
        }
        printf("\n");
    }
}
void shipsPosition (int b[8][8]){
    char starX=0, finalX=0, starY=0, finalY=0;
    int cantLShip=2,cantMShip=2,cantBShip=1;
    int ship;
    printf("\nIngresar coordenadas para barco pequeno (tamano 2)");
    do
    {
     ship=littleShip;

     printf("\nIngrese  coordenadainicial X, Y:");
     scanf(" %c %c",&starX,&starY);
     printf("\nIngrese  coordenada final X, Y:");
     scanf(" %c  %c",&finalX,&finalY);
     position(starX, finalX, starY, finalY,b,ship);
     printTable(b);
     cantLShip=cantLShip-1;


    } while (cantLShip!=0);

        printf("\ningresar coordenadas para barco mediano (tamano 3)");
        do {
            ship = mediumShip;

            printf("\nIngrese  coordenadainicial X, Y:");
            scanf(" %c %c",&starX,&starY);
            printf("\nIngrese  coordenada final X, Y:");
            scanf(" %c  %c",&finalX,&finalY);

            position(starX, finalX, starY, finalY, b, ship);
            printTable(b);
            cantMShip = cantMShip - 1;


        } while (cantMShip != 0);

            printf("\ningresar coordenadas para barco grande (tamano 4)");
            do {
                ship = bigShip;

                printf("\nIngrese  coordenadainicial X, Y:");
                scanf(" %c %c",&starX,&starY);
                printf("\nIngrese  coordenada final X, Y:");
                scanf(" %c  %c",&finalX,&finalY);

                position(starX, finalX, starY, finalY, b, ship);
                printTable(b);
                cantBShip = cantBShip - 1;


            } while (cantBShip != 0);
            printf("\nya no le quedan barcos por colocar\n");
}
int validateTable(int tabla[8][8]) {
    int stillAlive;
    for (int x = 0; x <= 7; ++x) {
        for (int y = 0; y <= 7; ++y) {
            if (tabla[y][x] == 1) {
                stillAlive = 1;
                return stillAlive;
            }
        }
    }
    stillAlive = 0;
    return stillAlive;
}
void shots(char coX, char coY,int table[8][8])
{
    int x, y;
    x= getX(coX);
    y= getY(coY);
    if (table[y][x]==1){
        table[y][x]=-2;
        printf("le distes a un barco\n");
        showTable(table);

    }
    else if(table[y][x]==0){
        table[y][x]=-1;
        printf("fallastes\n");
    }
    else if(table[y][x]==-2 || table[y][x]==-1){
        printf("ya usastes estas coordenadas\n");
    }
}
void giveShot (int shot[8][8],char nickname[20]){
    char startX,startY;
    printf("\n %s:Ingrese  coordenada X, Y para atacar:",nickname);
    scanf(" %c %c",&startX,&startY);
    shots(startX,startY,shot);
}

int main() {
    char name1[20], name2[20];
    int tabla_1[8][8],tabla_2[8][8];
    nickname1(name1);
    gameTable(tabla_1);
    //setValues('H', '2', tabla_1, 1);
    printTable(tabla_1);
    system("pause");
    system("cls");

    shipsPosition(tabla_1);

    system("pause");
    system("cls");

    nickname2(name2);
    gameTable(tabla_2);
    //setValues('B', '5', tabla_2, 1);
    printTable(tabla_2);
    system("pause");
    system("cls");

    shipsPosition(tabla_2);
    system("pause");
    system("cls");

    do {
        printf("\nP1: %s\n",name1);
        printTable(tabla_1);
        giveShot(tabla_2,name1);
        system("pause");
        system("cls");
        if (validateTable(tabla_2)==1){
            printf("\nP2: %s\n",name2);
            printTable(tabla_2);
            giveShot(tabla_1,name2);
            system("pause");
            system("cls");
        }

    } while (validateTable(tabla_2)==1 && validateTable(tabla_1)==1);
    if (validateTable(tabla_2)!=1){
        printf("\nGanador P1: %s\n",name1);
    } else
        printf("\nGanador P2: %s\n",name2);
    printf("Gracias por jugar");
}
