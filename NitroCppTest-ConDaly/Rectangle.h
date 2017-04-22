//
//  Rectangle.h
//  NitroProject
//
//  Copyright © 2017 Con Daly. All rights reserved.
//

#ifndef Rectangle_h
#define Rectangle_h
#include "string"
#include<vector>
using namespace std;
#include "Point.hpp"


class Rectangle
{
private:
    Point TopLeft, BottomRight;
    vector<int> Ids;
public:
    Rectangle();
    static void GetIntersections(vector<Rectangle>& Rectangles,  vector<Rectangle> & Intersections);
    void SetIds(int Id);
    vector<int> GetIds() const;
    Rectangle(Point TL, Point BR,int Id);//Rectlange is defined by two points the Top Left  and Bottom Right
    bool IsIntersection(const Rectangle & Rect);
    Rectangle GetIntersectingRectangle(const Rectangle& Rect);
    string PrintRectangle();
    void PrintRectangle(const Rectangle & Rect);
    bool operator==(const Rectangle &r1);
    bool operator!=(const Rectangle &r1);
};

#endif /* Rectangle_h */
