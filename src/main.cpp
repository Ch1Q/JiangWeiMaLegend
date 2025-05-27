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
    
    int screenWidth =500;
    int screenHeight = 250;
    InitWindow(screenWidth, screenHeight, "姜威玛传奇");
    Scene2D library("library");
    Node2D* node = new Node2D("XiaoBa");
    TextureComp2D* txr = new TextureComp2D("texture",node,1);
    txr->Load("../assets/img/bulaoshi.png");
    node->AddComponent(txr);
    library.AddNode(node);
    while (!WindowShouldClose()) {
    BeginDrawing();
    float delta = GetFrameTime();
    library.Update(delta);
    


    EndDrawing();
    }
    
    
    CloseWindow();
    return 0;
}

