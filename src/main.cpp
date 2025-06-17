#include "raylib.h"
#include <iostream>
#include "Node2D.h"
#include "Component2D.h"
#include "json.hpp"
#include <string>
#include <fstream>
#include "TextureComp2D.h"
using json = nlohmann::json;


int main() {
    
    
    InitWindow(800, 600, "一枚姜传奇");
    SetTargetFPS(60);

    
    std::shared_ptr<Node2D> testNode = Node2D::create("testNode");
    testNode->addComponent(TextureComp2D::create(".\\assets\\img\\bulaoshi.png",1,1),"texture");
    testNode->setPosition({400, 300}); // 设置到屏幕中心
    while (!WindowShouldClose()) 
    {
    BeginDrawing();
    float delta = GetFrameTime(); // 获取帧时间
    
    ClearBackground(RAYWHITE);
    testNode->Update(delta);


    EndDrawing();
    }
    
    
    CloseWindow();
    return 0;
}

