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
    point p1;
    point p2;
} line;

double distance(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double length(line a) {
    return distance(a.p1, a.p2);
}

double slope(line a) {
    return (a.p1.y - a.p2.y)/(a.p1.x - a.p2.x);
}

double yInt(line a) {
    return a.p1.y - slope(a) * a.p1.x;
}

int linepointthing(point a, line b) {
    return a.y == slope(b) * a.x + yInt(b);
}

int main( int argc, char *argv[]) {
    point a = {1, -1};
    point b = {2, -2};
    point c = {3, -3};
    line l = {a, b};
    printf("%d\n", linepointthing(c, l));

    return; 
}
