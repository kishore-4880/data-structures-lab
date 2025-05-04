//program to find area of square,cube,rectangle and cuboid
#include <iostream>

//defining the class
class Shape {
private:
    double side;
    double length, breadth, height;

public:
    void inputSquare() {
        printf("Enter the length of the side of the square: ");
        scanf("%lf", &side);
    }

    void inputCube() {
        printf("Enter the length of the side of the cube: ");
        scanf("%lf", &side);
    }

    void inputRectangle() {
        printf("Enter the length of the rectangle: ");
        scanf("%lf", &length);
        printf("Enter the breadth of the rectangle: ");
        scanf("%lf", &breadth);
    }

    void inputCuboid() {
        printf("Enter the length of the cuboid: ");
        scanf("%lf", &length);
        printf("Enter the breadth of the cuboid: ");
        scanf("%lf", &breadth);
        printf("Enter the height of the cuboid: ");
        scanf("%lf", &height);
    }

    double areaSquare() {
        return side * side;
    }

    double volumeCube() {
        return side * side * side;
    }

    double areaRectangle() {
        return length * breadth;
    }

    double volumeCuboid() {
        return length * breadth * height;
    }
};

//main function
int main() {
    Shape shape;
    char choice;

    do {
        printf("\nMenu\n");
        printf("a) Square\n");
        printf("b) Cube\n");
        printf("c) Rectangle\n");
        printf("d) Cuboid\n");
        printf("e) Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice); // Notice the space before %c to consume newline

        switch (choice) {
            case 'a': case 'A': {
                shape.inputSquare();
                double square_area = shape.areaSquare();
                printf("Area of the square: %lf\n", square_area);
                break;
            }
            case 'b': case 'B': {
                shape.inputCube();
                double cube_volume = shape.volumeCube();
                printf("Volume of the cube: %lf\n", cube_volume);
                break;
            }
            case 'c': case 'C': {
                shape.inputRectangle();
                double rectangle_area = shape.areaRectangle();
                printf("Area of the rectangle: %lf\n", rectangle_area);
                break;
            }
            case 'd': case 'D': {
                shape.inputCuboid();
                double cuboid_volume = shape.volumeCuboid();
                printf("Volume of the cuboid: %lf\n", cuboid_volume);
                break;
            }
            case 'e': case 'E':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 'e' && choice != 'E');

    return 0;
}
