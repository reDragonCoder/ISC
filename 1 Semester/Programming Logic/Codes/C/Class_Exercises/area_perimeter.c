// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>

//MAIN
int main(){
    //variables
    float square_side, square_area, square_perimeter;
    float rectangle_base, rectangle_height, rectangle_area, rectangle_perimeter;
    float triangle_base, triangle_height, triangle_area, triangle_perimeter, triangle_side2, triangle_side3;

    //square
    printf("\nEnter the side of the square: ");
    scanf("%f", &square_side);
    square_area=square_side*square_side;
    square_perimeter=4*square_side;
    printf("The area of the square is: %.2f\n", square_area);
    printf("The perimeter of the square is: %.2f\n", square_perimeter);

    //rectangle
    printf("\nEnter the base of the rectangle: ");
    scanf("%f", &rectangle_base);
    printf("Enter the height of the rectangle: ");
    scanf("%f", &rectangle_height);
    rectangle_area=rectangle_base*rectangle_height;
    rectangle_perimeter=2*(rectangle_base+rectangle_height);
    printf("The area of the rectangle is: %.2f\n", rectangle_area);
    printf("The perimeter of the rectangle is: %.2f\n", rectangle_perimeter);

    //triangle
    printf("\nEnter the base of the triangle: ");
    scanf("%f", &triangle_base);
    printf("Enter the height of the triangle: ");
    scanf("%f", &triangle_height);
    printf("Enter the value of side 2 (different from the base): ");
    scanf("%f", &triangle_side2);
    printf("Enter the value of side 3 (different from the base): ");
    scanf("%f", &triangle_side3);
    triangle_area=(triangle_base*triangle_height)/2;
    triangle_perimeter=triangle_base+triangle_side2+triangle_side3;
    printf("The area of the triangle is: %.2f\n", triangle_area);
    printf("The perimeter of the triangle is: %.2f\n", triangle_perimeter);

    return 0;
}