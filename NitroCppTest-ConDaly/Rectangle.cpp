//
//  Rectangle.cpp
//  NitroProject
//
//  Copyright © 2017 Con Daly. All rights reserved.
//

#include <stdio.h>
#include "Rectangle.h"
#include "Point.hpp"
#include "string"
#include <math.h>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;


Rectangle::Rectangle()
{
    TopLeft.X=0;
    TopLeft.Y=0;
    BottomRight.X=0;
    BottomRight.Y=0;
    Ids.clear();
}

void Rectangle::SetIds(int Id)
{
    Ids.push_back(Id);
}

void Rectangle::GetIntersections(vector<Rectangle> & Rectangles,  vector<Rectangle>  & Intersections)
{
    int len=Rectangles.size();
    //Find the intersection between 2 or more rectangles;
    for(int i=1;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if( (i != j) && (i>j) && Rectangles[i].IsIntersection(Rectangles[j])  )
            {
                Rectangle intersection = Rectangles[i].GetIntersectingRectangle(Rectangles[j]);
                Rectangles.push_back(intersection);
                Intersections.push_back(intersection);
                len=Rectangles.size();
                if(len>=3628800)//Factorial 10 = 3628800 = max number of intersection for 10 rectangles.
                    break;
            }
        }
    }
}

vector<int> Rectangle::GetIds() const
{
    return Ids;
}

Rectangle::Rectangle(Point TL, Point BR,int Id=0)//Rectlange is defined by two points the Top Left  and Bottom Right
{
    this->TopLeft.X=TL.X;
    this->TopLeft.Y=TL.Y;
    this->BottomRight.X=BR.X;
    this->BottomRight.Y=BR.Y;
    Ids.push_back(Id);
}

bool Rectangle::IsIntersection(const Rectangle & Rect)
{
    
    vector<int> RectIds=Rect.GetIds();
    sort(RectIds.begin(),RectIds.end());
    sort(Ids.begin(),Ids.end());
    
    std::vector<int> v_intersection;
    std::set_intersection(Ids.begin(), Ids.end(), Rect.Ids.begin(), Rect.Ids.end(), back_inserter(v_intersection));
    
    if ((( ((TopLeft.X <= Rect.TopLeft.X) && (Rect.TopLeft.X <= BottomRight.X)) || ((TopLeft.X <= Rect.BottomRight.X) && (Rect.BottomRight.X <= BottomRight.X))) &&
        (  ((TopLeft.Y <= Rect.TopLeft.Y)&&(Rect.TopLeft.Y <= BottomRight.Y)) || ((TopLeft.Y <= Rect.BottomRight.Y) && (Rect.BottomRight.Y <= BottomRight.Y) ))) 
     && v_intersection.size()==0)
        return true;
    else
        return false;
}

Rectangle Rectangle::GetIntersectingRectangle(const Rectangle& Rect)
{
    Rectangle IntersectingRect;
    if (IsIntersection(Rect))
    {
        IntersectingRect.TopLeft.X = max(TopLeft.X, Rect.TopLeft.X);
        IntersectingRect.TopLeft.Y = max(TopLeft.Y,Rect.TopLeft.Y);
        IntersectingRect.BottomRight.X = min(BottomRight.X, Rect.BottomRight.X);
        IntersectingRect.BottomRight.Y = min(BottomRight.Y,Rect.BottomRight.Y);
        vector<int> RectIds = Rect.GetIds();
        
        for(auto x: RectIds)
            IntersectingRect.SetIds(x);
        for(auto y:this->Ids)
            IntersectingRect.SetIds(y);
    }
    return IntersectingRect;
}

string Rectangle::PrintRectangle()
{
    ostringstream result;
    int len = Ids.size();
    
    if(len==1)
    {
        result<<"      "<<Ids[0]<<": Rectangle at ("<<TopLeft.X<<","<<TopLeft.Y<<"), w="<<BottomRight.X - TopLeft.X<<", h="<<BottomRight.Y - TopLeft.Y<<".";
    }
    else if(len==2)
    {
       result<<"      Between rectangles: "<<Ids[0]<<" and "<<Ids[1]<<" at ("<<TopLeft.X<<","<<TopLeft.Y<<"), w="<<BottomRight.X - TopLeft.X<<", h="<<BottomRight.Y - TopLeft.Y<<".";
    }
    else if(len>2)
    {
        string rectIDstr="";
        for(int i=2;i<len;i++)
        {
            if(i==len-1)
                rectIDstr+=to_string(Ids[i]);
            else
                rectIDstr+=to_string(Ids[i])+", ";
        }
        
        result<<"      Between rectangles: "<<Ids[0]<<", "<<Ids[1]<<", "<<rectIDstr<<" at ("<<TopLeft.X<<","<<TopLeft.Y<<"), w="<<BottomRight.X - TopLeft.X<<", h="<<BottomRight.Y - TopLeft.Y<<".";
    }
    
    //cout<<result.str();
    return result.str();
    //cout<<"Top Left= ("
}

void Rectangle::PrintRectangle(const Rectangle & Rect)
{
    cout<<"Top Left= ("<<Rect.TopLeft.X<<","<<Rect.TopLeft.Y<<"), w ="<<Rect.BottomRight.X - Rect.TopLeft.X<<", h="<<Rect.BottomRight.Y - Rect.TopLeft.Y<<"."<<endl;
}

bool Rectangle::operator==(const Rectangle &r1)
{
    return(TopLeft.X == r1.TopLeft.X && TopLeft.Y == r1.TopLeft.Y && BottomRight.X == r1.BottomRight.X && BottomRight.Y == r1.BottomRight.Y);
}

bool Rectangle::operator!=(const Rectangle &r1)
{
    return(TopLeft.X != r1.TopLeft.X || TopLeft.Y != r1.TopLeft.Y || BottomRight.X != r1.BottomRight.X || BottomRight.Y != r1.BottomRight.Y);
}

