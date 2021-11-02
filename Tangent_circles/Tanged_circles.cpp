#include <iostream>
#include <math.h>

class Point{
public:

    double x;
    double y;
};

class Circle{
public:

    Point* center;
    double radius;

    void Print_data(){
        std::cout << "\nCircle center: (" << center->x << "," << center->y
        << ") Circle radius " << radius << "\n";
    }

    void Print_area(){
        std::cout << 3.1415926 * radius * radius;
    }
};

struct t_circl{
        Circle* tc1;
        Circle* tc2;
        Circle* tc3;
        Circle* tc4;
    };

class Tangent_circle{
public:

    Circle* c1;
    Circle* c2;

    double dist = Distance_circle();

    void Solver(){

        int location_type = Type_definitor();

        if (location_type == 1){

            std::cout << "\n\nCollision type: " << "I\n";

            double r_1 = (c1->radius + c2->radius + dist)/2;
            double r_2 = (c1->radius + c2->radius - dist)/2;
            double r_3 = c2->radius - r_2;
            double r_4 = c1->radius - r_2;


            Point Point_1 {(c1->center->x + c2->center->x +
                (c2->radius - c1->radius) * (c2->center->x - c1->center->x)
                /dist)/2, (c1->center->y + c2->center->y +
                (c2->radius - c1->radius) * (c2->center->y - c1->center->y)
                /dist)/2};

            Point Point_2 {c1->center->x + (c1->radius - r_2)/
                            (dist) * (c2->center->x - c1->center->x),
                            c1->center->y + (c1->radius - r_2)/
                            (dist) * (c2->center->y - c1->center->y)};

            Point Point_3 {c1->center->x + (dist + c2->radius - r_3)/
                            (dist) * (c2->center->x - c1->center->x),
                            c1->center->y + (dist + c2->radius - r_3)/
                            (dist) * (c2->center->y - c1->center->y)};

            Point Point_4 {c2->center->x + (dist + c1->radius - r_4)/
                            (dist) * (c1->center->x - c2->center->x),
                            c2->center->y + (dist + c1->radius - r_4)/
                            (dist) * (c1->center->y - c2->center->y)};


            Circle tmp_1 {&(Point_1), r_1};
            Circle tmp_2 {&(Point_2), r_2};
            Circle tmp_3 {&(Point_3), r_3};
            Circle tmp_4 {&(Point_4), r_4};

            std::cout << "\n\n----- Tanged circles data:-----" << "\n\n\n";

            std::cout << "First tangent circle data:\n";
            tmp_1.Print_data();
            std::cout << "\nSecond tangent circle data:\n";
            tmp_2.Print_data();
            std::cout << "\nThird tangent circle data:\n";
            tmp_3.Print_data();
            std::cout << "\nFourth tangent circle data:\n";
            tmp_4.Print_data();
        }
        if (location_type == 2){
            std::cout << "\n\nCollision type: " << "II";

            double r_1 = (c1->radius + c2->radius + dist)/2;


            Point Point_1 {(c1->center->x + c2->center->x +
                (c2->radius - c1->radius) * (c2->center->x - c1->center->x)
                /dist)/2, (c1->center->y + c2->center->y +
                (c2->radius - c1->radius) * (c2->center->y - c1->center->y)
                /dist)/2};


            Circle tmp_1 {&(Point_1), r_1};

            std::cout << "\n\n----- Tanged circles data:-----" << "\n\n\n";

            std::cout << "First tangent circle data:\n";
            tmp_1.Print_data();

        }
        if (location_type == 3){
            std::cout << "\n\nCollision type: " << "III";

            double r;
            double x_;
            double y_;

            if (c1->radius >= c2->radius){
                r = c1->radius - c2->radius;
                x_ = c2->center->x + (dist + c1->radius - r)/(dist) *
                    (c1->center->x - c2->center->x);
                y_ = c2->center->y + (dist + c1->radius - r)/(dist) *
                    (c1->center->y - c2->center->y);
            } else {
                r = c2->radius - c1->radius;
                x_ = c1->center->x + (dist + c2->radius - r)/(dist) *
                    (c2->center->x - c1->center->x);
                y_ = c1->center->y + (dist + c2->radius - r)/(dist) *
                    (c2->center->y - c1->center->y);
            }

            Point Point_ {x_, y_};

            Circle tmp_1 {&(Point_), r};

            std::cout << "\n\n----- Tanged circles data:-----" << "\n\n\n";

            std::cout << "First tangent circle data:\n";
            tmp_1.Print_data();

        }
        if (location_type == 4){
            std::cout << "\n\nCollision type: " << "IV";

            double r_1 = (dist - c1->radius - c2->radius)/2;
            double r_2 = (dist + c1->radius + c2->radius)/2;
            double r_3 = (dist + c1->radius - c2->radius)/2;
            double r_4 = (dist - c1->radius + c2->radius)/2;


            Point Point_1 {c1->center->x + (dist - c2->radius - r_1)/(dist) *
            (c2->center->x - c1->center->x), c1->center->y + (dist - c2->radius
            - r_1)/(dist) * (c2->center->y - c1->center->y)};

            Point Point_2
                {((c2->center->x + (dist + c1->radius)/(dist) *
                   (c1->center->x - c2->center->x)) +
                  (c1->center->x + (dist + c2->radius)/(dist) *
                   (c2->center->x - c1->center->x)))/2,
                 ((c2->center->y + (dist + c1->radius)/(dist) *
                   (c1->center->y - c2->center->y)) +
                  (c1->center->y + (dist + c2->radius)/(dist) *
                   (c2->center->y - c1->center->y)))/2};

            Point Point_3 {c1->center->x + ((dist - c2->radius - r_3)/(dist)) *
            (c2->center->x - c1->center->x),
                           c1->center->y + ((dist - c2->radius - r_3)/(dist)) *
            (c2->center->y - c1->center->y)};

            Point Point_4 {c2->center->x + ((dist - c1->radius - r_4)/(dist)) *
            (c1->center->x - c2->center->x),
                           c2->center->y + ((dist - c1->radius - r_4)/(dist)) *
            (c1->center->y - c2->center->y)};


            Circle tmp_1 {&(Point_1), r_1};
            Circle tmp_2 {&(Point_2), r_2};
            Circle tmp_3 {&(Point_3), r_3};
            Circle tmp_4 {&(Point_4), r_4};

            std::cout << "\n\n----- Tanged circles data:-----" << "\n\n\n";

            std::cout << "First tangent circle data:\n";
            tmp_1.Print_data();
            std::cout << "\nSecond tangent circle data:\n";
            tmp_2.Print_data();
            std::cout << "\nThird tangent circle data:\n";
            tmp_3.Print_data();
            std::cout << "\nFourth tangent circle data:\n";
            tmp_4.Print_data();
        }
        if (location_type == 5){
            std::cout << "\n\nCollision type: " << "V";

            double r_1;
            double r_2;
            double x_1;
            double y_1;
            double x_2;
            double y_2;

            if (c1->radius >= c2->radius){
                r_1 = (c1->radius + dist - c2->radius)/2;
                r_2 = (c1->radius - dist - c2->radius)/2;
                    if (dist == 0){
                        y_1 = c1->center->y;
                        y_2 = c1->center->y;
                        x_1 = c1->center->x + (c2->radius + r_2);
                        x_2 = c1->center->x - (c2->radius + r_2);
                    } else {
                        x_1 =c2->center->x + ((dist + c1->radius - r_1)/(dist))
                        * (c1->center->x - c2->center->x);
                        y_1 =c2->center->y + ((dist + c1->radius - r_1)/(dist))
                        * (c1->center->y - c2->center->y);
                        x_2 =c1->center->x + ((dist + c2->radius + r_2)/(dist))
                        * (c2->center->x - c1->center->x);
                        y_2 =c1->center->y + ((dist + c2->radius + r_2)/(dist))
                        * (c2->center->y - c1->center->y);
                    }
            } else {
                r_1 = (c2->radius + dist - c1->radius)/2;
                r_2 = (c2->radius - dist - c1->radius)/2;
                    if (dist == 0){
                        y_1 = c2->center->y;
                        y_2 = c2->center->y;
                        x_1 = c2->center->x + (c1->radius + r_2);
                        x_2 = c2->center->x - (c1->radius + r_2);
                    } else {
                        x_1 =c1->center->x + ((dist + c2->radius - r_1)/(dist))
                        * (c2->center->x - c1->center->x);
                        y_1 =c1->center->y + ((dist + c2->radius - r_1)/(dist))
                        * (c2->center->y - c1->center->y);
                        x_2 =c2->center->x + ((dist + c1->radius + r_2)/(dist))
                        * (c1->center->x - c2->center->x);
                        y_2 =c2->center->y + ((dist + c1->radius + r_2)/(dist))
                        * (c1->center->y - c2->center->y);
                    }
            }

            Point Point_1 {x_1, y_1};

            Point Point_2 {x_2, y_2};


            Circle tmp_1 {&(Point_1), r_1};
            Circle tmp_2 {&(Point_2), r_2};

            std::cout << "\n\n----- Tanged circles data:-----" << "\n\n\n";

            std::cout << "First tangent circle data:\n";
            tmp_1.Print_data();
            std::cout << "\nSecond tangent circle data:\n";
            tmp_2.Print_data();
        }
    }

private:

    double Distance_circle(){
        double d;
        d = sqrt(((c1)->center->x - (c2)->center->x) *
                 ((c1)->center->x - (c2)->center->x) +
                 ((c1)->center->y - (c2)->center->y) *
                 ((c1)->center->y - (c2)->center->y));
    return d;
    };

    int Type_definitor(){
        if (dist > (c1->radius + c2->radius)){
            return 4;
        }
        if (dist == (c1->radius + c2->radius)){
            return 2;
        }

        if (dist < (c1->radius + c2->radius)){
            if (c1->radius >= c2->radius){
                if (dist == c1->radius - c2->radius){
                    return 3;
                }

                if (dist >= c1->radius- c2->radius){
                    return 1;
                }
                if (dist < c1->radius - c2->radius){
                    return 5;
                }
            }
            if (c1->radius < c2->radius){
                if (dist == c2->radius - c1->radius){
                    return 3;
                }
                if (dist > c2->radius- c1->radius){
                    return 1;
                }
                if (dist < c2->radius - c1->radius){
                    return 5;
                }
            }
        }
    }
};

int main(){

    double x1, x2, y1, y2, r1, r2;

    std::cout << "\nEnter first circle data:\n";
    std::cout << "x = ";
    std::cin  >> x1;
    std::cout << "y = ";
    std::cin  >> y1;
    std::cout << "r = ";
    std::cin  >> r1;

    Point cent_1 {x1, y1};
    Circle Circ_1 {&(cent_1), r1};

    Circ_1.Print_data();

    std::cout << "\nEnter second circle data:\n";
    std::cout << "x = ";
    std::cin  >> x2;
    std::cout << "y = ";
    std::cin  >> y2;
    std::cout << "r = ";
    std::cin  >> r2;

    Point cent_2 {x2, y2};
    Circle Circ_2 {&(cent_2), r2};

    Circ_2.Print_data();

    Tangent_circle Data {&Circ_1, &Circ_2};

    Data.Solver();

    return 0;
}
