#include "raylib.h"
#include <iostream>
#include <cmath>

int main() {
    const int screenWidth = 2000;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "姜威玛传奇");

    // 加载图片（根据实际情况修改路径）
    Texture2D img = LoadTexture("../assets/img/bulaoshi.png");
    if (img.width == 0) { // 检查是否加载失败
        std::cout<<"错误：无法加载图片！请确认路径是否正确"<<std::endl;
        return 1;
    }

    float yOffset = 0.0f;       // 垂直偏移量
    float speed = 50.0f;         // 浮动速度
    float amplitude = 5.0f;   // 浮动幅度
    
    SetTargetFPS(240);

    while (!WindowShouldClose()) {
        // 更新逻辑：正弦曲线实现上下浮动
        yOffset = amplitude * sin(GetTime() * speed);
        yOffset = amplitude * sin(GetTime() * speed+3.1415926/2);
        Vector2 mousepos = GetMousePosition();
        BeginDrawing();
            ClearBackground(RAYWHITE);
            // 绘制图片（居中显示，加上偏移量）
            // DrawTexture(img, 
            //           (screenWidth - img.width) / 2, 
            //           (screenHeight - img.height) / 2 + (int)yOffset, 
            //           WHITE);
            DrawTexture(img, 
                      (mousepos.x - img.width/ 2) + (int)yOffset, 
                      (mousepos.y - img.height/ 2)  + (int)yOffset, 
                      WHITE);
        EndDrawing();
    }
    UnloadTexture(img); // 释放资源
    CloseWindow();
    return 0;
}