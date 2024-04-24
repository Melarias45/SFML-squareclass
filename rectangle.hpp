#ifndef rectangle_hpp
#define rectangle_hpp
#include <SFML/Graphics.hpp>
using namespace sf;


class Rectangle{
     
    private: 
    Vector2f speed; 
    Vector2f acc; 
    RectangleShape shape;

    public:
    Rectangle(Vector2f size);
    Rectangle(Vector2f size, int x, int y);

    void update (); 
    void drawTo (RenderWindow &window); 
    void click(int x, int y); 

}; 


#endif