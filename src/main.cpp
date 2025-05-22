#include "raylib.h"
#include <iostream>
#include "Node2D.h"
#include "Component2D.h"
#include "Scene2D.h"
int main() {
    const int screenWidth = 1600;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "姜威玛传奇");
    std::cout<<"cialloWorld";
    InitAudioDevice();
    
    Component2D comp;
    Node2D Node;
    Scene2D scene;
    comp.parent = &Node;
    Node.Components.push_back(&comp);
    Node.inScene = &scene;
    scene.Nodes.push_back(&Node);
    Node.name = "节点";
    comp.name = "组件";
    scene.name = "场景";
    std::cout<<Node.Components.at(0)->name<<std::endl<<comp.parent->name<<std::endl;
    std::cout<<scene.Nodes.at(0)->name<<std::endl<<Node.inScene->name<<std::endl;

    while (!WindowShouldClose()) {
    BeginDrawing();
    
    EndDrawing();
    }
    
    // 释放资源
    
    CloseAudioDevice();
    CloseWindow();
    return 0;
}