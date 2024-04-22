#include <SFML/Graphics.hpp>
using namespace sf;


Vector2f speed={5.f,5.f};

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    RectangleShape shape({50.f, 30.f}); //le pasamos un vector con variables tipo float, vector 2F es que hay 2 dimensiones. 
    shape.setFillColor(Color::Magenta);
    window.setFramerateLimit(60); //para que no se mueva tan rapido, porque la compu ejecuta muchisimos frames por segundo de texto. 

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // window.clear(); //si podemos antes lo de mover, se va a ver como barrido y no irse borrando para dar la ilusion de que se esta moviendo la figura. 
        if (shape.getPosition().x+shape.getSize().x>=800||shape.getPosition().x<0){
        shape.setFillColor(Color::Magenta);  
        speed.x*=-1; 
        }
        if (shape.getPosition().y+shape.getSize().y>=600||shape.getPosition().y<0){
        shape.setFillColor(Color::Yellow);  
        speed.y*=-1;  
        }
        shape.move(speed); //para mover figura en x y en y 
        window.draw(shape);
        window.display();
    }

    return 0;
}