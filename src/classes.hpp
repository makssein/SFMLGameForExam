#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

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


    class mySprite {
    public:
        mySprite(sf::Texture texture, float scale_x, float scale_y, int position_x, int position_y);
        ~mySprite();
        sf::Sprite* get(){return m_mySprite;}
    private:
        sf::Texture m_spriteTexture;
        float m_scale_x, m_scale_y;
        int m_position_x, m_position_y;
        sf::Sprite* m_mySprite;
    };

    class myText {
    public:
        myText(sf::Font font, std::string textString, int size, sf::Color color, int position_x, int poxition_y);
        ~myText();
        sf::Text* get() {return m_text;}
        void newString(std::string textString);
    private:
        sf::Font m_font;
        std::string m_textString;
        int m_size, m_position_x, m_position_y;
        sf::Color m_color;
        sf::Text* m_text;
    };
}
