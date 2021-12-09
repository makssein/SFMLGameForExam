#include <classes.hpp>

namespace myClasses{
    dino::dino(sf::Texture texture, int x, int y) {
        m_x=x;
        m_y=y;
        m_dinotexture = texture;
        m_dino = new sf::Sprite;
        m_sizeX = m_dinotexture.getSize().x;
        m_sizeY = m_dinotexture.getSize().y;
        m_dino->setTexture(m_dinotexture);
        m_dino->setOrigin(m_dinotexture.getSize().x/2, m_dinotexture.getSize().y);
        m_dino->setPosition(m_x/2,m_y);
    }
    dino::~dino(){ delete m_dino; };
    void dino::jump(float t, bool& jump, int window_y){
        m_window_y = window_y;
        m_y = m_window_y + 110 * sin(30 ) * t + 9.8 * t * t/2;
        if(m_y>=m_window_y+1){
            m_y=m_window_y;
            jump=false;
        }
        m_dino->setPosition(m_x/2,m_y);
    }
    void dino::newTexture(sf::Texture texture) {
        m_dinotexture = texture;
        m_dino->setTexture(m_dinotexture);
    }


    tree::tree(sf::Texture texture, int x, int y){
        m_treetexture = texture;
        m_tree = new sf::Sprite;
        m_x = x;
        m_y = y-m_treetexture.getSize().y/2;
        m_tree->setScale(1.3,1.3);
        m_tree->setTexture(m_treetexture);
        m_sizeX = m_treetexture.getSize().x;
        m_sizeY = m_treetexture.getSize().y;
        m_tree->setOrigin(m_treetexture.getSize().x/2, m_treetexture.getSize().y/2);
        m_tree->setPosition(m_x, m_y-m_treetexture.getSize().y/2);
    }
    tree::~tree(){ delete m_tree; }
    void tree::move(){
        m_x-=30;
        m_tree->setPosition(m_x, m_y);
    }
    void tree::setX(int x){
        m_x = x;
        m_tree->setPosition(m_x, m_y);
    }


    mySprite::mySprite(sf::Texture texture, float scale_x, float scale_y, int position_x, int position_y) {
        m_spriteTexture = texture;
        m_scale_x = scale_x;
        m_scale_y = scale_y;
        m_position_x = position_x;
        m_position_y = position_y;

        m_mySprite = new sf::Sprite;
        m_mySprite->setTexture(m_spriteTexture);
        m_mySprite->setScale(m_scale_x,m_scale_y);
        m_mySprite->setPosition(m_position_x, m_position_y);
    }
    mySprite::~mySprite() {delete m_mySprite;}


    myText::myText(sf::Font font, std::string textString, int size, sf::Color color, int position_x, int position_y) {
        m_font = font;
        m_textString = textString;
        m_size = size;
        m_color = color;
        m_position_x = position_x;
        m_position_y = position_y;

        m_text = new sf::Text;
        m_text->setFont(m_font);
        m_text->setString(m_textString);
        m_text->setCharacterSize(m_size);
        m_text->setFillColor(m_color);
        m_text->setPosition(m_position_x,m_position_y);
    }
    myText::~myText() {delete m_text;}

    void myText::newString(std::string textString) {
        m_textString = textString;
        m_text->setString(m_textString);
    }
}