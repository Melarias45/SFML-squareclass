#include "Grid.hpp"

Grid::Grid(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < rows; i++)
    {
        tablero.push_back({});
        for (int j = 0; j < cols; j++)
        {
            tablero[i].push_back(0);
        }
    }
    this->siguiente = vector<vector<int>>(rows, vector<int>(cols, 0));
}
Grid::Grid(int n, int w, int h)
{
    this->rows = n;
    this->cols = n;
    this->w = w;
    this->h = h;
    for (int i = 0; i < this->rows; i++)
    {
        tablero.push_back({});
        for (int j = 0; j < this->cols; j++)
        {

            tablero[i].push_back(0);
        }
    }
    this->siguiente = vector<vector<int>>(rows, vector<int>(cols, 0));
}

void Grid::drawTo(RenderWindow &window)
{
    int sizeX = this->w / this->cols;
    int sizeY = this->h / this->rows;

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            RectangleShape rect(Vector2f(sizeX, sizeY));
            rect.setPosition(Vector2f(j * sizeX, i * sizeY));
            rect.setOutlineThickness(1);
            rect.setOutlineColor(Color::Black);
            if (tablero[j][i] == 1)
            {
                rect.setFillColor(Color::Green);
            }
            window.draw(rect);
        }
    }
}

void Grid::toggle(int x, int y)
{
    int sizeX = this->w / this->cols;
    int sizeY = this->h / this->rows;

    int indexX = x / sizeX;
    int indexY = y / sizeY;

    tablero[indexX][indexY] = 1;
}

void Grid::update()
{
    for (int i = 0; i < this->rows; i++)
    {

        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                // Verifica si la celda actual está ocupada
                if (this->tablero[i][j] == 1)
                {
                    int vecinos = this->calcularVecinos(i, j);

                    if (vecinos == 1)
                    {
                        // La celda actual se vacía y la celda abajo se ocupa
                        this->siguiente[i][j] = 0;
                        this->siguiente[i][j + 1] = 1;
                    }

                    else if (vecinos == 2)
                    {
                        // La celda actual se vacía y la celda que está abajo 2 espacios y 1 a la izquierda se ocupa
                        this->siguiente[i][j] = 0;
                        this->siguiente[i - 1][j + 2] = 1;
                    }

                    else if (vecinos == 3)
                    {
                        // La celda actual se vacía y la celda que está abajo 2 espacios y 1 a la derecha se ocupa
                        this->siguiente[i][j] = 0;
                        this->siguiente[i + 1][j + 2] = 1;
                    }

                    else if (vecinos == 0)
                    {
                        // La celda actual se queda ocupada
                        this->siguiente[i][j] = 1;
                    }
                }
            }
        }
    }
    this->tablero = this->siguiente;
    /*
    (Cosas de la act de juego de la vida)

    int vecinos = this->calcularVecinos(i, j);
    if (this->tablero[i][j] == 1)
    {
        if (vecinos < 2 || vecinos > 3)
        {
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
        {
            this->siguiente[i][j] = 1;
        }
        else
        {
            this->siguiente[i][j] = 0;
        }
    }
    */
}

int Grid::calcularVecinos(int i, int j)
{
    int vecinos = 0;
    // revisamos que no se pase del limite y que este vacia
    if (j < this->cols - 1 && this->tablero[i][j + 1] == 0)
    {
        vecinos = 1;
    }
    else
    {
        // Si hay una casilla disponible dos espacios abajo y uno a la izquierda
        if (j < this->cols - 2 && i > 0 && this->tablero[i - 1][j + 2] == 0)
            vecinos = 2;

        // Si hay una casilla disponible dos espacios abajo y uno a la derecha
        if (j < this->cols - 2 && i < this->rows - 1 && this->tablero[i + 1][j + 2] == 0)
            vecinos = 3;
    }

    return vecinos;
    /*
    (Cosas de la act de juego de la vida)

    // arriba a la izquierda
    if (i > 0 && j > 0 && this->tablero[i - 1][j - 1] == 1)
        vecinos++;
    // arriba
    if (j > 0 && this->tablero[i][j - 1] == 1)
        vecinos++;
    // arriba a la derecha
    if (j > 0 && i < this->rows - 1 && this->tablero[i + 1][j - 1] == 1)
        vecinos++;

    // izquierda
    if (i > 0 && this->tablero[i - 1][j] == 1)
        vecinos++;
    // derecha
    if (i < this->rows - 1 && this->tablero[i + 1][j] == 1)
        vecinos++;

    // abajo a la izquierda
    if (i > 0 && j < this->cols - 1 && this->tablero[i - 1][j + 1] == 1)
        vecinos++;
    // // abajo
    if (j < this->cols - 1 && this->tablero[i][j + 1] == 1)
        vecinos++;
    // abajo a la derecha
    if (i < this->rows - 1 && j < this->cols - 1 && this->tablero[i + 1][j + 1] == 1)
        vecinos++;

    */
}
