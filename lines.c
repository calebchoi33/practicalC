#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
/* thanks to simon for help or something something credit to him but to me too but like cool */

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point point1;
    point point2;
} line;

double distance(point a, point b) {
    double distance;
    distance = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    return distance; 
}

double length(line a) {
    return distance(a.point1, a.point2);
}

double slope(line a) {
    return (a.point1.y - a.point2.y)/(a.point1.x - a.point2.x);
}

double yInt(line a) {
    return a.point1.y - slope(a) * a.point1.x;
}

int linepointthing(point a, line b) {
    return a.y == slope(b) * a.x + yInt(b);
}

int main( int argc, char *argv[]) {
    point a = {4, 2};
    point b = {4, 1};
    point c = {4, 0};
    line l = {a, b};
    printf("%d\n", linepointthing(c, l));
    return 0; 
}
