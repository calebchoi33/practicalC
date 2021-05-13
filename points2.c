#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    size_t sides;
    point count[];
} polygon;

polygon *read_polygon(size_t point_count){

}

double distance(point a, point b){
    return sqrt(pow(a.x-b.x, 2) + (a.y-b.y), 2);
} 

double perimeter(const polygon *p){
    double total = 0;
    for(size_t i = 1; i < p->sides; i++){
        perimeter += distance(p -> count[i-1], p -> count[i]);
    }
    return perimeter; 
}

double area(const polygon *p){
    double area = 0; 
    for(size_t i = 1; i < p->sides; i++){
        area += (p -> count[i].x + p-> count[i-1].x)*(p-> count[i].y-p->count[i-1].y);        
    }
    area += (p-> count[0].x + p -> count[p->sides-1].x)*(p->corners[0].y - p->count[p->sides-1].y);
    return fabs(area/2);
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
    scanf("%lf", count);
    if(points <= 2){
        return 0;
    }
    point *shape = readPoints(count);
    printf("perimeter: %lf ", perimeter(shape, count));

    free(shape); 
    return;
}

//Credits to Parth and Simon for the help
