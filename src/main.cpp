#include "raylib.h"

int main() {
    const int screenWidth = 1600;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "姜威玛传奇");
    InitAudioDevice();

    // 加载音频（旧版本兼容性检查）
    Sound click = LoadSound("../assets/aud/chibaola.mp3");
    if (click.frameCount == 0) { // 检查音效是否加载成功
        CloseAudioDevice();
        CloseWindow();
        return -1;
    }

    Music bgm = LoadMusicStream("../assets/aud/Mojito.mp3");
    if (bgm.ctxData == nullptr) {  // 检查音乐是否加载成功
        UnloadSound(click);
        CloseAudioDevice();
        CloseWindow();
        return -1;
    }

     // 启用循环
    PlayMusicStream(bgm);       // 播放音乐

    while (!WindowShouldClose()) {
        UpdateMusicStream(bgm); // 更新音乐流

        if (IsKeyPressed(KEY_SPACE)) {
            PlaySound(click);   // 按下空格播放音效
        }
    }

    // 释放资源
    UnloadSound(click);
    UnloadMusicStream(bgm);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}