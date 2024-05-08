#include "grid.hpp"

Grid::Grid(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;

    for (int i = 0; i < rows; i++)
    {
        tablero.push_back({}); // le pasamos un vector vacio.
        for (int j = 0; j < cols; j++)
        {
            tablero[i].push_back(0);
        }
    }

    this->siguiente = vector<vector<int>>(rows, vector<int>(cols, 0)); // cada vector va ser un vector de tamaño cols que va a ser un vector de 0;
};

Grid::Grid(int n, int w, int h)
{
    // n es el numero de celdas que quieres en cada columna y fila, ej: (4x4), w es el ancho, h es el alto,
    this->w = w;
    this->h = h;

    //
    this->rows = n;
    this->cols = n;

    for (int i = 0; i < this->rows; i++)
    {
        tablero.push_back({}); // le pasamos un vector vacio.
        for (int j = 0; j < this->cols; j++)
        {
            tablero[i].push_back(rand() % 2);
        }
    }
    this->siguiente = vector<vector<int>>(rows, vector<int>(cols, 0));
};

void Grid::drawTo(RenderWindow &window)
{

    this->tamX = this->w / this->cols; // divides el ancho de cada cuadro entre el num de columnas que tienes.
    this->tamY = this->h / this->rows;

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            RectangleShape rect(Vector2f(tamX, tamY));
            rect.setPosition(Vector2f(j * tamX, i * tamY)); // cada uno por el tamaño del rectangulo, primero se ponen las columnas y luego las filas.
            rect.setOutlineThickness(1);
            rect.setOutlineColor(Color::Black);
            if (tablero[j][i] == 1)
            {
                rect.setFillColor(Color::Green);
            }
            window.draw(rect);
        }
    }
};

void Grid::toggle(int x, int y)
{
    this->tamX = this->w / this->cols;
    this->tamY = this->h / this->rows;

    int indexX = x / tamX; // para obtener la posicion donde se hizo click en x, se divide la cord en x entre el tamaño del cuadrito en x.
    int indexY = y / tamY; // lo mismo para y.

    /*
        if(tablero[indexY][indexX]==0)
            tablero[indexY][indexX]==1;
        else{
            tablero[indexY][indexX]==0;
        }*/

    //  tablero[indexY][indexX]=tablero[indexY][indexX]==0?1:0;si es igual a 0, si si le pones un uno, sino le pones un cero.

    tablero[indexX][indexY] = (tablero[indexX][indexY] + 1) % 2;
}

void Grid::update()
{
    /*
    1- Para cada celda calcular cuantos vecinos vivos tiene
    2- Ver si la celda estara viva o muerta en el siguiente a partir de los vecinos.
    */

    // para cada fila se va a checar cuantas filas tenemos.
    for (int i = 0; i < this->rows; i++) // i son filas
    {
        for (int j = 0; j < this->cols; j++) // j son cols.
        {
            int vecinos = this->calcularVecinos(i, j); // primero calculamos los vecinos
            if (this->tablero[i][j] == 1)
            {
                if (vecinos < 2 || vecinos > 3)
                { //
                    this->siguiente[i][j] = 0;
                }
                else
                {
                    this->siguiente[i][j] = 1;
                }
            }
            else
            {
                if (vecinos == 3)
                { // si tiene 3 vecinos sobrevive.
                    this->siguiente[i][j] = 1;
                }
                else
                {
                    this->siguiente[i][j] = 0;
                }
            }
        }
    }
    this->tablero = this->siguiente;
}

int Grid::calcularVecinos(int i, int j)
{
    int vecinos = 0;

    //8 ifs porque hay 8 casillas alrededor de cada vecino y tenemos que revisar cada 1 de estas, x es i y y es j, hacia arriba es -, hacia abajo es +.
    // arriba a la izquierda
    if (i > 0 && j > 0 && this->tablero[i - 1][j - 1] == 1)
        vecinos++;

    // arriba a la dereceha.
    if (i < this->rows - 1 && j > 0 && this->tablero[i + 1][j - 1] == 1)
        vecinos++;

    // arriba
    if (j > 0 && this->tablero[i][j - 1] == 1)
        vecinos++;

    // abajo
    if (j < this->cols - 1 && this->tablero[i][j + 1] == 1)
        vecinos++;

    // derecha
    if (i < this->rows - 1 && this->tablero[i + 1][j] == 1)
        vecinos++;

    // izquierda
    if (i > 0 && this->tablero[i - 1][j] == 1)
        vecinos++;

    // abajo a la izquierda
    if (j < this->cols - 1 && i > 0 && this->tablero[i - 1][j + 1] == 1)
        vecinos++;

    // abajo a la dereceha.
    if (j < this->cols - 1 && i < this->rows - 1 && this->tablero[i + 1][j + 1] == 1)
        vecinos++;

    return vecinos;
}