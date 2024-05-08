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