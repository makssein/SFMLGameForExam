#include <SFML/Graphics.hpp>
#include <classes.hpp>
#include <iostream>


int main(){

    sf::RenderWindow window(sf::VideoMode(2880, 1620), L"Dinoooooo!");
    window.setFramerateLimit(300);

    float t = 0;
    bool jump = false;

    sf::Texture dinotx;
    if(!dinotx.loadFromFile("../inc/img/dino.png")){
        std::cout << "ERROR: dino.png not found";
    }
    myClasses::dino dino(dinotx, window.getSize().x, window.getSize().y);

    sf::Texture back;
    back.setSmooth(true);
    sf::Sprite background;
    if(!back.loadFromFile("../inc/img/back.jpg")){
        std::cout << "ERROR: back.jpg not found";
        return -1;
    }
    background.setTexture(back);
    background.setScale(window.getSize().x/background.getLocalBounds().width,
                        window.getSize().y/background.getLocalBounds().height
    );

    sf::Texture road;
    sf::Sprite roadsp;
    if(!road.loadFromFile("../inc/img/road.png")){
        std::cout << "ERROR: road.png not found";
        return -1;
    }
    roadsp.setTexture(road);
    roadsp.setScale(1,
                    0.2
                    );
    roadsp.setPosition(0, window.getSize().y-roadsp.getLocalBounds().height*roadsp.getScale().y);
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Space){
                        jump = true;
                        t=0;
                    }
            }
        }
        if(jump){
            dino.jump(t);
        }
        if(dino.getY()>=1620){
            dino.onGround();
        }
        window.clear();
        window.draw(background);
        window.draw(roadsp);
        window.draw(*dino.get());
        window.display();

        t+=0.07;
    }
    return 0;
}
