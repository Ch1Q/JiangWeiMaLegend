//#include "raylib.h"
#include <iostream>
// #include "Node2D.h"
// #include "Component2D.h"
// #include "Scene2D.h"
#include "json.hpp"
#include <string>
#include <fstream>

using json = nlohmann::json;

json Loadjson(const std::string& path)
{
    std::ifstream file(path);
    if(!file.is_open()){std::cout<<"not open";return -1;}
    return json::parse(file);
}

int main() {

    json JsonTest = Loadjson("./scenes/test.json");
    int testWidth = JsonTest["window"]["width"].get<int>();
    
    std::cout<<testWidth;

    for(auto& tex : JsonTest["window"]["textures"])
    {
        std::cout<<tex["id"]<<std::endl;
        std::cout<<tex["path"]<<std::endl;
    }
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

