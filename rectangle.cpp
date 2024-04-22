#include "Rectangle.hpp"

Rectangle::Rectangle(Vector2f size){
    this->shape=RectangleShape(size); //le pasamos un vector con variables tipo float, vector 2F es que hay 2 dimensiones. 
    this->shape.setFillColor(Color(199,10,45))
    this->speed=Vector2f(3.f,3.f); 
}

void Rectangle::update(){
    if (this->shape.getPosition().x+this->shape.getSize().x>=800||this->shape.getPosition().x<0){
        this->shape.setFillColor(Color::Magenta);  
        this->speed.x*=-1; 
        }
        if (this->shape.getPosition().y+this->shape.getSize().y>=600||this->shape.getPosition().y<0){
        this->shape.setFillColor(Color::Yellow);  
        this->speed.y*=-1;  
        }
        this->shape.move(this->speed); //para mover figura en x y en y 
}; 

void Rectangle:: drawTo (RenderWindow &window){
    window.draw(this->shape);
}; 
