#include <SFML/Graphics.hpp>
#include "rectangle.hpp"
#include <vector>
using namespace sf;
using namespace std; 


Vector2f speed={5.f,5.f};

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60); //para que no se mueva tan rapido, porque la compu ejecuta muchisimos frames por segundo de texto. 
    Rectangle shape (Vector2f(50.f,70.f)); 
    vector<Rectangle>rectangulos; 

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if(event.type == Event::MouseButtonPressed){ //dar click a un boton del mouse es un evento. 
                if(event.mouseButton.button == Mouse::Left){
                    int w=rand()%50; //da unas dimensiones aleatorias
                    int h=rand()%50; 
                    int x=event.mouseButton.x; //toma las coordenadas x y y del evento y se las pasa al rectangulo
                    int y=event.mouseButton.y; 

                    Rectangle rec(Vector2f(w,h),x,y); //x y y son la posicion 
                    rectangulos.push_back(rec);     
                }
                if(event.mouseButton.button == Mouse::Right){
               
                    int x=event.mouseButton.x; 
                    int y=event.mouseButton.y;

                    for (auto &r: rectangulos){
                        r.click(x,y);
                    }  
                }
            }
            

        }

        // window.clear(); //si podemos antes lo de mover, se va a ver como barrido y no irse borrando para dar la ilusion de que se esta moviendo la figura. 
        
        window.clear(); //si se quita quedaria un rastro de la figura. 
        shape.update(); //actualiza
        shape.drawTo(window); //dibuja la ventana 
        for(auto &r : rectangulos){ //auto - detecta de que tipo es cada elemento del vector, en este caso rectangulos, cada variable es r. 
            r.update(); //ya no se pone rectangulos[i], no se usa this; 
            r.drawTo(window); 
        }
        window.display();
    }

    return 0;
}