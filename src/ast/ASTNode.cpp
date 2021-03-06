/*
Simple Python Interpreter implementation by cpp
Copyright (C) 2018 LCC,ZZH,HZL,CYH

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see http://www.gnu.org/licenses.
*/
#include "ASTNode.h"
#include <iostream>

ASTNode::ASTNode(int number)
{
    max_child_number=number;
}

void ASTNode::add(std::shared_ptr<ASTNode> child)
{
    if(getChildNumber()<max_child_number)
    {
        if(child)
            childlist.push_back(child);
        else
        {
            //NOTE
            //all the runtimeerror caused by wrong use within the program will lead to exit
            //
            //TODO
            //make use of cpp's error feature to throw more useful information
            std::cout<<"RuntimeError:Children nullptr."<<std::endl;
            exit(1);
        }
    }
    else
    {
        std::cout<<"RuntimeError:Children outnumbered the limit."<<std::endl;
        exit(1);
    }
}

std::shared_ptr<ASTNode> ASTNode::getChild(int index)
{
    return childlist[index];
}

inline int ASTNode::getChildNumber()
{
    return childlist.size();
}

ASTNode::~ASTNode()
{
}

//const std::shared_ptr<ASTNode>& ASTNode::clone(){
    //return shared_from_this();
//}
