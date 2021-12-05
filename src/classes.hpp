#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <math.h>

namespace myClasses{
    class dino{
    public:
       dino(sf::Texture texture, int x, int y);
       ~dino();
       sf::Sprite* get(){return m_dino;}
       void jump(float t, bool& jump, int window_y);
       int getY(){return m_y;}
       int getX(){return m_x;}
       int sizeX(){return m_sizeX;}
       int sizeY(){return m_sizeY;}
       void newTexture(sf::Texture texture);
    private:
        int m_x, m_y, m_window_y, m_sizeX, m_sizeY;
        sf::Texture m_dinotexture;
        sf::Sprite* m_dino;
    };


    class tree{
    public:
        tree(sf::Texture texture, int x, int y);
        ~tree();
        sf::Sprite* get(){return m_tree;}
        void move();
        int getX(){return m_x;}
        int getY(){return m_y;}
        void setX(int x);
        int sizeX(){return m_sizeX;}
        int sizeY(){return m_sizeY;}
    private:
        int m_y, m_x, m_sizeX, m_sizeY;
        sf::Texture m_treetexture;
        sf::Sprite* m_tree;
    };
}
