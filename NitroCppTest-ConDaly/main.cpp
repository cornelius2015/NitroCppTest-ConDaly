//
//  main.cpp
//  NitroProject
//
//  Copyright � 2017 Con Daly. All rights reserved.
//

#ifdef _MSC_VER
#include <boost/config/compiler/visualc.hpp>
#endif
#include"Point.hpp"
#include"Rectangle.h"
#include <iostream>
#include  <map>
#include<vector>
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"
#include "NitroUnitTest.hpp"



#include <boost/foreach.hpp>
using namespace boost::property_tree;
using boost::property_tree::ptree;
using namespace std;
//The Boost/JSON works fine on both Windows and Apple Mac
//pt.get_child("challenges")



int main(int argc, char* argv[])
{

    UnitTests::Run_Tests();
    
    if (argc < 2)
    {
        // Tell the user how to run the program
        std::cerr << "Usage: " << argv[0] << " should have 1 argument as the name of teh JSON file" << std::endl;
        return 1;
    }
    //cout<<argv[1]<<endl;
    std::ifstream jsonFile(argv[1]);
    
    ptree pt;
    vector<Rectangle> Rectangles;
    
    
    int Id=1;
    try
    {
        read_json(jsonFile, pt);//throws exception if there is a validation error in the JSON file
        for (auto & array_element: pt.get_child("rects"))
        {
            int coordinates[4];
            int coordinateIndex=0;
            for (auto & property: array_element.second)
            {
                //std::cout << property.first << " = " << property.second.get_value < std::string > () << "\n";
                coordinates[coordinateIndex]=property.second.get_value<int>();
                coordinateIndex++;
            }
            if(Id>10)//Only read in 10 rectangles
                break;
            Rectangles.push_back(Rectangle(Point(coordinates[0],coordinates[1]), Point(coordinates[2]+coordinates[0],coordinates[3]+coordinates[1]),Id));
            Id++;
            //cout<<endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    
    ///////////
    
    vector<Rectangle> Intersections;
    
    cout<<"Input:"<<endl;
    int index=1;
    
    for(auto &rect:Rectangles)
        cout<<rect.PrintRectangle()<<endl;
    
    cout<<endl<<"Intersections:"<<endl;
    index=0;
    
    Rectangle::GetIntersections(Rectangles,Intersections);
    
    vector<vector<int>> VectorOfIds;
    for(auto & intersection: Intersections)
    {
        cout<<intersection.PrintRectangle()<<endl;
    }
    cout<<endl<<endl<<"Enter character and press return:"<<endl;
    char ch;
    cin>>ch;
    return 0;
}
