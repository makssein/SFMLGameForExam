#include <classes.hpp>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;
namespace myClasses{
    dino::dino(sf::Texture texture, int x, int y) {
        m_x=x;
        m_y=y;
        m_dinotexture = texture;
        m_dino = new sf::Sprite;
        m_dino->setTexture(m_dinotexture);
        m_dino->setOrigin(m_dinotexture.getSize().x/2, m_dinotexture.getSize().y);
        m_dino->setPosition(m_x/2,m_y);
    }
    dino::~dino(){};
    void dino::jump(float t){
        m_y = 1620 + 100 * sin(30 ) * t + 9.8 * t * t/2;
        m_dino->setPosition(m_x/2,m_y);
    }
    void dino::onGround() {
        m_dino->setPosition(m_x/2,1620);
    }
}