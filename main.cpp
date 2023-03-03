#include <iostream>
using namespace std;

void mostrarTablero(int tablero[][3]);

void player1Turn(int tablero[][3]);

void player2Turn(int tablero[][3]);

int checkGameFinish(int tablero[][3]);

//////////////////////

int main()
{
    //Hacemos el tablero para el tres en raya
    int tablero[3][3] ={{8, 8, 8}, {8, 8, 8}, {8, 8, 8}};
    bool gameOver = false;
    int resultado = 0;

    //Hacemos el bucle mundo, mientras siga activo el juego no termina
    for (int i = 0; i < 9; i++)
     {
        mostrarTablero(tablero);

        if (gameOver == false)
        {
            player1Turn(tablero);
            resultado = checkGameFinish(tablero);
            if (resultado == 1)
            {
                gameOver = true;
            }
        }

        else
        {
            cout << "Ha ganado el jugador 2";
            break;
        }

        mostrarTablero(tablero);

        if (gameOver == false)
        {
            player2Turn(tablero);
            resultado = checkGameFinish(tablero);
            if (resultado == 2)
            {
                gameOver = true;
            }
        }

        else
        {
            cout << "Ha ganado el jugador 1";
            break;
        }
    }
    return 0;
}

//Imprime el tablero en pantalla
void mostrarTablero(int tablero[][3])
{
    cout << "---------\n";
    cout << tablero[0][0] << " | " << tablero[0][1] << " | " << tablero[0][2] << endl;
    cout << "---------" << endl;
    cout << tablero[1][0] << " | " << tablero[1][1] << " | " << tablero[1][2] << endl;
    cout << "---------" << endl;
    cout << tablero[2][0] << " | " << tablero[2][1] << " | " << tablero[2][2] << endl;
    cout << "---------\n";
}

//Turno del Jugador 1
void player1Turn(int tablero[][3])
{
    //Declaramos las variables para las cordenadas
    int playerY;
    int playerX;
    //El Jugador indica las cordenadas
    cout << "¿En que fila esta la casilla que quieres marcar?\n";
    cin >> playerX;
    cout << "¿En que columna?\n";
    cin >> playerY;
    //Les restamos 1 para poder expresar los numeros como lo hacemos en el dia a dia y no desde el 0
    --playerY;
    --playerX;
    //Comprobamos si la casilla ya ha sido editada
    if (tablero[playerX][playerY] != 8)
    {
        cout << "Esta casilla ya esta marcada";
        player1Turn(tablero);
    }

    else
    {
        tablero[playerX][playerY] = 1;
    }
}

//Turno del jugador 2
void player2Turn(int tablero[][3])
{
    int playerY;
    int playerX;
    cout << "¿En que fila esta la casilla que quieres marcar?\n";
    cin >> playerX;
    cout << "¿En que columna?\n";
    cin >> playerY;
    --playerY;
    --playerX;

    if (tablero[playerX][playerY] != 8)
    {
        cout << "Esta casilla ya esta marcada";
        player2Turn(tablero);
    }

    else
    {
        tablero[playerX][playerY] = 2;
    }
}

//Funcion check ganador
int checkGameFinish(int tablero[][3])
{
    //Variable para el ganador, 0 = Sigue la partida, 1 = Gana Jugador 1, 2 = Gana Jugador 2
    int ganador = 0;

    //Todas las posibilidades para que haya tres en raya
    int tableroRow1 = tablero[0][0] + tablero[0][1] + tablero[0][2];
    int tableroRow2 = tablero[1][0] + tablero[1][1] + tablero[1][2];
    int tableroRow3 = tablero[2][0] + tablero[2][1] + tablero[2][2];
    int tableroCol1 = tablero[0][0] + tablero[1][0] + tablero[2][0];
    int tableroCol2 = tablero[0][1] + tablero[1][1] + tablero[2][1];
    int tableroCol3 = tablero[0][2] + tablero[1][2] + tablero[2][2];
    int tableroDia1 = tablero[0][0] + tablero[1][1] + tablero[2][2];
    int tableroDia2 = tablero[0][2] + tablero[1][1] + tablero[2][0];
    
    //Se comprueba si el primer jugador (valor 1) pone tres unos en raya comprobando si la suma de las tres casillas da tres
    if (tableroRow1 == 3 || tableroRow2 == 3 || tableroRow3 == 3 || tableroCol1 == 3 || tableroCol2 == 3 || tableroCol3 == 3 || tableroDia1 == 3 || tableroDia2 == 3)
    {
        ganador = 1;
    }
    //Lo mismo que arriba pero para el jugador 2 (Con valor 2) en el que la suma en vez de dar 3, da 6
    else if (tableroRow1 == 6 || tableroRow2 == 6 || tableroRow3 == 6 || tableroCol1 == 6 || tableroCol2 == 6 || tableroCol3 == 6 || tableroDia1 == 6 || tableroDia2 == 6)
    {
        ganador = 2;
    }
    
    return ganador;
}