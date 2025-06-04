#include "raylib.h"
#include <iostream>
#include "Node2D.h"
#include "Component2D.h"
#include "Scene2D.h"
#include "json.hpp"
#include <string>
#include <fstream>
#include "TextureComp2D.h"
using json = nlohmann::json;


int main() {
    
    
    InitWindow(800, 600, "一枚姜传奇");
    SetTargetFPS(60);

    
    while (!WindowShouldClose()) 
    {
    BeginDrawing();

    
    ClearBackground(RAYWHITE);
    


    EndDrawing();
    }
    
    
    CloseWindow();
    return 0;
}

