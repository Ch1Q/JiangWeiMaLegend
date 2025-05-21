#include "raylib.h"
class Node2D
{
    Node2D* parent;
    Texture2D texture;
    AudioStream Audio;
    bool show=false;

    public:
    void Start();
    void Process();
    void SetShow(bool showSet);
};