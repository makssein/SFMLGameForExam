#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

namespace myClasses{
    class dino{
    public:
       dino(sf::Texture texture, int x, int y);
       ~dino();
       sf::Sprite* get(){return m_dino;}
       void jump(float t);
       int getY(){return m_y;}
       void onGround();
    private:
        int m_x, m_y;
        sf::Texture m_dinotexture;
        sf::Sprite* m_dino;
    };
}
