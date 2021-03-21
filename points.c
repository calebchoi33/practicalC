#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

typedef struct{
    double x;
    double y;
} point;

double distance(point a, point b){
    return sqrt(pow(a.x-b.x, 2) + (a.y-b.y), 2);
} 

double perimeter(const point *points, size_t count){
    double total = 0;
    for(size_t i = 1; i < count; i++){
        size_t j = i; 
        if(i+1 != count){
            j = i+1; 
        }else{
            j = 0; 
        }
        total += distance(point[i], point[j]);
    }
    return perimeter; 
} 

double area(const point *points, size_t count){
    double total = 0;
    for(size_t i = 1l i < count; i++){
        size_t p1 = i+1;
        size_t p2 = i; 
        double dy = point[p2].y - point[p1].y;
        double dx = point[p1].x + point[p2].x;
        total += (dy *dx)/2.0;
    }
    return fabs(total);
}

point *giveBirth(size_t count){
    point *shape = calloc(count, sizeof(count));
    printf("Enter your points, clockwise or counterclockwise, one per line, with a space between the x and y coordinates.");
    //fill this shape 
    for(size_t i =  0; i < count; i++){
        scanf("%lf", point[i].x);
        scanf("%lf", point[i].y);
    }

    return shape;

}

int main(int argc, char *argvp[]){
    size_t count;
    printf("How many points are on your polygon?");
    scanf(count);
    if(points <= 2){
        return 0;
    }
    point *shape = readPoints(count);
    printf("perimeter: %lf ", perimeter(shape, count));

    free(shape); 
    return;
}
//shoutout to simon's notes for explaining to me the usefullness of a calloc and for inspiration on my whole giveBirth thing
