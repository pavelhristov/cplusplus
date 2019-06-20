#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>

//struct Shape {
//    double length, width;
//
//    Shape(double l = 1, double w = 1) {
//        length = l;
//        width = w;
//    }
//
//    double Area() {
//        return length * width;
//    }
//
//private:
//    int id;
//};
//
//struct Circle : Shape {
//
//    Circle(double width) {
//        this->width = width;
//    }
//
//    double Area() {
//        return 3.14159 * std::pow((width / 2), 2);
//    }
//};
//
//class Customer {
//private:
//    friend class GetCustomerData;
//    std::string name;
//public:
//
//    Customer(std::string name) {
//        this->name = name;
//    }
//};
//
//class GetCustomerData {
//public:
//
//    static std::string GetName(Customer& customer) {
//        return customer.name;
//    }
//};

//class Shape {
//protected:
//    double height;
//    double width;
//public:
//
//    Shape(double length) {
//        this->height = length;
//        this->width = length;
//    }
//
//    Shape(double h, double w) {
//        this->height = h;
//        this->width = w;
//    }
//
//    virtual double Area() {
//        return height * width;
//    }
//};
//
//class Circle : public Shape {
//public:
//
//    Circle(double w) : Shape(w) {
//    }
//
//    double Area() {
//        return 3.14159 * std::pow((width / 2), 2);
//    }
//};

class Shape {
public:
    virtual double Area() = 0;
};

class Circle : public Shape {
protected:
    double width;
public:

    Circle(double w) {
        this->width = w;
    }

    double Area() override {
        return 3.14159 * std::pow((width / 2), 2);
    }
};

class Rectangle : public Shape {
protected:
    double height, width;
public:

    Rectangle(double h, double w) {
        this->height = h;
        this->width = w;
    }

    double Area() override {
        return this->height * this->width;
    }
};

void ShowArea(Shape& shape) {
    std::cout << "Area " << shape.Area() << std::endl;
}

int main() {
    // 11.1 structs
    //    Shape shape(10,10);
    //    std::cout << "Square Area: " << shape.Area() << std::endl;
    //    
    //    Circle circle(10);
    //    std::cout << "Circle Area: " << circle.Area() << std::endl;
    //    
    //    Shape rectangle{10,15};
    //    std::cout << "Rectangle Area: " << rectangle.Area() << std::endl;
    //
    //-------------------------------------------------------------------------
    // 11.2 Friend classes
    //    Customer tom("Tom");
    //    GetCustomerData data;
    //    std::cout << "Name: " << data.GetName(tom) << std::endl;
    //
    //-------------------------------------------------------------------------
    // 11.3 Polymorphism
    //    Shape rectangle(10, 5);
    //    Circle circle(10);
    //    ShowArea(rectangle);
    //    ShowArea(circle);
    //
    //-------------------------------------------------------------------------
    // 11.4 Abstract classes
    Rectangle rectangle(10, 5);
    Circle circle(10);
    ShowArea(rectangle);
    ShowArea(circle);

    return 0;
}

