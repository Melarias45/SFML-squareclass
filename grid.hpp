#ifndef grid_h
#define grid_h

#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Grid
{
    private:
    vector<vector<int>> tablero; // vector de vectores enteros.
    vector<vector<int>> siguiente; 
    int rows, cols, w ,h, tamX, tamY; 

    public:
    Grid(int n, int w, int h); 
    Grid(int rows, int cols);
    void drawTo(RenderWindow &window); 
    void toggle(int x, int y); 
    void update(); 
    int calcularVecinos(int i, int j); 
};

#endif