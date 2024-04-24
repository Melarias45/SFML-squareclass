#include "Rectangle.hpp"

Rectangle::Rectangle(Vector2f size)
{
    this->shape = RectangleShape(size); // le pasamos un vector con variables tipo float, vector 2F es que hay 2 dimensiones.
    this->shape.setFillColor(Color::Blue);
    this->speed = Vector2f(3.f, 3.f);
    this->acc = Vector2f(0.f, 1.f);
}

Rectangle::Rectangle(Vector2f size, int x, int y)
{
    this->shape = RectangleShape(size); // le pasamos un vector con variables tipo float, vector 2F es que hay 2 dimensiones.
    this->shape.setFillColor(Color::Blue);
    this->speed = Vector2f(3.f, 3.f);
    this->acc = Vector2f(0.f, 1.f);
    this->shape.setPosition(Vector2f(x, y));
}

void Rectangle::update()
{

    this->speed += this->acc;
    this->shape.move(speed);

    // Vector2f position=this->shape.getPosition();
    // this->shape.setPosition(position + this->speed); *La funcion move suma el la posicion mas la velocidad, es igual.
    if (this->shape.getPosition().x + this->shape.getSize().x >= 800 || this->shape.getPosition().x < 0)
    {
        this->shape.setFillColor(Color::Blue);
        this->speed.x *= -1;
    }
    if (this->shape.getPosition().y + this->shape.getSize().y >= 600)
    {
        this->shape.setFillColor(Color::Blue);
        this->speed.y *= -1;
        Vector2f position = this->shape.getPosition();
        this->shape.setPosition(position.x, 600 - this->shape.getSize().y); // el alto de la ventana menos el ancho del rectangulo.
    }
    this->shape.move(this->speed); // para mover figura en x y en y
};

void Rectangle::drawTo(RenderWindow &window)
{
    window.draw(this->shape);
};

void Rectangle::click(int x, int y)
{
    bool cx = false;
    bool cy = false;

    if (x >= this->shape.getPosition().x && this->shape.getPosition().x < this->shape.getPosition().x + x)
    {
        cy = true;
    }
    if (y >= this->shape.getPosition().y && this->shape.getPosition().y < this->shape.getPosition().y + y)
    {
        cy = true;
    }
    if (cx==true&&cy==true)
    {
        this->shape.setFillColor(Color::Red);
    }
};