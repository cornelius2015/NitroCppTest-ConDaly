//
//  NitroUnitTest.cpp
//  NitroProject
//
//  Copyright © 2017 Con Daly. All rights reserved.
//

#include "NitroUnitTest.hpp"
#include "Rectangle.h"
#include <math.h>
#include <iostream>
#include <assert.h>
using namespace std;

void UnitTests::TEST_CASE_RECTANGLE_INTERSECTION()
{
    cout<<"TEST_CASE_RECTANGLE_INTERSECTION"<<endl;
    Rectangle rect1(Point(100,100),Point(350,180),1);
    Rectangle rect2(Point(140,160),Point(390,260),2);
    
    Rectangle ResultIntersection(Point(140,160),Point(350,180),3);
    Rectangle ResultNotIntersection(Point(140,160),Point(350,181),4);
    Rectangle intersection = rect1.GetIntersectingRectangle(rect2);
    
    assert(intersection == ResultIntersection);
    assert(intersection != ResultNotIntersection);
}


void UnitTests::TEST_CASE_PRINTOUT_INTERSECTIONS()
{
    cout<<"TEST_CASE_PRINTOUT_INTERSECTIONS"<<endl;
    vector<Rectangle> Rectangles;
    Rectangles.push_back( Rectangle(Point(100,100),Point(350,180),1));
    Rectangles.push_back( Rectangle(Point(120,200),Point(370,350),2));
    Rectangles.push_back( Rectangle(Point(140,160),Point(390,260),3));
    Rectangles.push_back( Rectangle(Point(160,140),Point(510,330),4));
    vector<Rectangle> Intersections;
    
    Rectangle::GetIntersections(Rectangles,Intersections);
    string a=Intersections[0].PrintRectangle();
    assert(string("      Between rectangles: 1 and 3 at (140,160), w=210, h=20.").compare(Intersections[0].PrintRectangle())==0);
    assert(string("      Between rectangles: 2 and 3 at (140,200), w=230, h=60.").compare(Intersections[1].PrintRectangle())==0);
    assert(string("      Between rectangles: 1 and 4 at (160,140), w=190, h=40.").compare(Intersections[2].PrintRectangle())==0);
    assert(string("      Between rectangles: 2 and 4 at (160,200), w=210, h=130.").compare(Intersections[3].PrintRectangle())==0);
    assert(string("      Between rectangles: 3 and 4 at (160,160), w=230, h=100.").compare(Intersections[4].PrintRectangle())==0);
    assert(string("      Between rectangles: 1, 3, 4 at (160,160), w=190, h=20.").compare(Intersections[5].PrintRectangle())==0);
    assert(string("      Between rectangles: 2, 3, 4 at (160,200), w=210, h=60.").compare(Intersections[6].PrintRectangle())==0);
    
}


void UnitTests::TEST_CASE_6_INTERSECTIONS()
{
    cout<<"TEST_CASE_6_INTERSECTIONS"<<endl;
    cout<<endl;
    vector<Rectangle> Rectangles;
    Rectangles.push_back( Rectangle(Point(100,100),Point(200,200),1));
    Rectangles.push_back( Rectangle(Point(125,125),Point(225,225),2));
    Rectangles.push_back( Rectangle(Point(175,175),Point(275,275),3));
    Rectangles.push_back( Rectangle(Point(180,180),Point(280,280),4));
    Rectangles.push_back( Rectangle(Point(185,185),Point(285,285),5));
    Rectangles.push_back( Rectangle(Point(190,190),Point(290,290),6));
    vector<Rectangle> Intersections;
    
    Rectangle::GetIntersections(Rectangles,Intersections);
    string a=Intersections[0].PrintRectangle();
    assert(string("      Between rectangles: 1 and 2 at (125,125), w=75, h=75.").compare(Intersections[0].PrintRectangle())==0);
    assert(string("      Between rectangles: 3, 1, 2 at (175,175), w=25, h=25.").compare(Intersections[15].PrintRectangle())==0);
    assert(string("      Between rectangles: 1, 2, 3, 4 at (180,180), w=20, h=20.").compare(Intersections[154].PrintRectangle())==0);
    assert(string("      Between rectangles: 1, 2, 3, 4, 5 at (185,185), w=15, h=15.").compare(Intersections[210].PrintRectangle())==0);
    assert(string("      Between rectangles: 1, 2, 3, 4, 5, 6 at (190,190), w=10, h=10.").compare(Intersections[435].PrintRectangle())==0);
    
}


void UnitTests::Run_Tests()
{
    TEST_CASE_RECTANGLE_INTERSECTION();
    TEST_CASE_PRINTOUT_INTERSECTIONS();
    TEST_CASE_6_INTERSECTIONS();
}

double squareroot(const double x)
{
    return sqrt(x);
}
