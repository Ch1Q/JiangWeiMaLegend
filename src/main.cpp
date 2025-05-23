//#include "raylib.h"
#include <iostream>
#include "Node2D.h"
#include "Component2D.h"
#include "Scene2D.h"
#include "json.hpp"
#include <string>
#include <fstream>
using json = nlohmann::json;


int main() {
    Node2D* nodeptr;
    nodeptr = new Node2D("student");
    Scene2D library("library");
    library.AddNode(nodeptr);
    for(auto n : library.GetNodes())std::cout<<n->name<<std::endl;
    library.DelNode(nodeptr);
    
    // int screenWidth =500;
    // int screenHeight = 250;
    // InitWindow(screenWidth, screenHeight, "姜威玛传奇");
    
    // while (!WindowShouldClose()) {
    // BeginDrawing();
    
    // EndDrawing();
    // }
    
    
    // CloseWindow();
    return 0;
}

