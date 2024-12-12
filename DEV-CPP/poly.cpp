#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Shape {
    public :
        virtual float get_area() {
            return 0;
        }
};

class Rectangle : public Shape {
        int length;
        int height;
    public :
        Rectangle(int length, int height): length(length), height(height) {}

        float get_area()override {
            return length * height;
        }
};

class Circle : public Shape {
    int rayon;
    public :
        Circle(int rayon): rayon(rayon) {}

        float get_area()override {
            return M_PI * rayon * rayon;
        }
};

float get_area(Shape* shape) {
    return shape->get_area();
}

int main() {
    Rectangle rect(2, 4);
    Shape* rect_as_shape = &rect;
    get_area(rect_as_shape);

    printf("Rectangle area: %f\n", get_area(rect_as_shape));
    
    Circle circle(5);
    Shape* circle_as_shape = &circle;
    get_area(circle_as_shape);

    printf("Circle area: %f\n", get_area(circle_as_shape));
}