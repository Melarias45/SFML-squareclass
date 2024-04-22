#ifndef square_h
#define square_h
#include <SFML/Graphics.hpp>
using namespace sf;


class Square{
    private:  
    Vector2f speed; 
    RectangleShape shape;

    public:
    Square(Vector2f size);
    void Update (); 
    void drawTo (RenderWindow &obj); 

}; 


#endif