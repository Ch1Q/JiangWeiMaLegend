#include "TextureComp2D.h"



TextureComp2D::~TextureComp2D()
{
    if(texture.id != 0)UnloadTexture(texture);
}

TextureComp2D::TextureComp2D(std::string path)
{
    if(!Load(path))std::cout<<"TextureComp2D: fail to load"<<std::endl;
}

TextureComp2D::TextureComp2D(bool _vis): Visibility(_vis)
{
    
}

TextureComp2D::TextureComp2D(std::string path, bool _acti):Component2D(_acti)
{
    if(!Load(path))std::cout<<"TextureComp2D: fail to load"<<std::endl;
}
TextureComp2D::TextureComp2D(bool _vis, bool _acti): Visibility(_vis),Component2D(_acti)
{
    
}
TextureComp2D::TextureComp2D(std::string path, bool _vis, bool _acti): Visibility(_vis),Component2D(_acti)
{
    if(!Load(path))std::cout<<"TextureComp2D: fail to load"<<std::endl;
}


std::unique_ptr<TextureComp2D> TextureComp2D::create(std::string path)
{
    return std::unique_ptr<TextureComp2D>(new TextureComp2D(path));
}
std::unique_ptr<TextureComp2D> TextureComp2D::create(bool _vis)
{
    return std::unique_ptr<TextureComp2D>(new TextureComp2D(_vis));
}
std::unique_ptr<TextureComp2D> TextureComp2D::create(std::string path, bool _acti)
{
    return std::unique_ptr<TextureComp2D>(new TextureComp2D(path,_acti));
}
std::unique_ptr<TextureComp2D> TextureComp2D::create(bool _vis, bool _acti)
{
    return std::unique_ptr<TextureComp2D>(new TextureComp2D(_vis,_acti));
}
std::unique_ptr<TextureComp2D> TextureComp2D::create(std::string path, bool _vis, bool _acti)
{
    return std::unique_ptr<TextureComp2D>(new TextureComp2D(path,_vis,_acti));
}


void TextureComp2D::Start()
{

}

void TextureComp2D::Update(float _delta)
{
    if (!Visibility || texture.id == 0) return;

    // 安全获取父节点指针
    if (auto ownerNode = getOwner().lock()) 
    {
        transform2D trans = ownerNode->getTransform();
        
        // 计算纹理中心作为旋转原点
        Vector2 origin = {
            texture.width / 2.0f,
            texture.height / 2.0f
        };
        
        // 源矩形（整个纹理）
        Rectangle srcRec = {
            0, 0,
            (float)texture.width,
            (float)texture.height
        };
        
        // 目标矩形（应用变换后）
        Rectangle destRec = {
            trans.position.x,
            trans.position.y,
            texture.width * trans.scale.x,
            texture.height * trans.scale.y
        };
        
        // 高级绘制（支持旋转/缩放/原点）
        DrawTexturePro(
            texture,
            srcRec,
            destRec,
            origin,
            trans.rotation,
            WHITE
        );
    }
    else 
    {
        // 处理节点无效的情况
        std::cerr << "TextureComp2D: Owner node expired!" << std::endl;
    }
}


bool TextureComp2D::Load(std::string _path)
{
    texture = LoadTexture(_path.c_str());
    return texture.id;
}
void TextureComp2D::setVisibility(bool _vis)
{
    Visibility = _vis;
}
bool TextureComp2D::isVisible() const
{
    return Visibility;
}