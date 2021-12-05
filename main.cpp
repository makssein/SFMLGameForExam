#include <SFML/Graphics.hpp>
#include <classes.hpp>
#include <fstream>

int main(){
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(2880, 1620), L"Dinoooooo!");
    window.setFramerateLimit(60);

    float t = 0;
    int score = 0;
    bool jump = false;
    bool isPlaying = true;
    int best_score = 0;

    std::fstream best_file("inc/files/best.txt");
    if(best_file) {
        best_file >> best_score;
    } else {
        std::ofstream best_file ("inc/files/best.txt");
        best_file << best_score;
    }


    //creating dino
    sf::Texture dinotx;
    if(!dinotx.loadFromFile("inc/img/dino.png")){
        std::cout << "ERROR: dino.png not found";
    }
    sf::Texture dino_gameover;
    if(!dino_gameover.loadFromFile("inc/img/dino_gameover.png")){
        std::cout << "ERROR: dino_gameover.png not found";
    }
    myClasses::dino dino(dinotx, window.getSize().x, window.getSize().y);

    //creating background
    sf::Texture back;
    back.setSmooth(true);
    sf::Sprite background;
    if(!back.loadFromFile("inc/img/back.jpg")){
        std::cout << "ERROR: back.jpg not found";
        return -1;
    }
    background.setTexture(back);
    background.setScale(window.getSize().x/background.getLocalBounds().width,
                        window.getSize().y/background.getLocalBounds().height
    );

    //creating road
    sf::Texture road;
    sf::Sprite roadsp;
    road.setSmooth(true);
    if(!road.loadFromFile("inc/img/road.png")){
        std::cout << "ERROR: road.png not found";
        return -1;
    }
    roadsp.setTexture(road);
    roadsp.setScale(1,
                    0.2
                    );
    roadsp.setPosition(0, window.getSize().y-roadsp.getLocalBounds().height*roadsp.getScale().y);

    //creating trees
    sf::Texture treetx;
    treetx.setSmooth(true);
    if(!treetx.loadFromFile("inc/img/tree.png")){
        std::cout << "ERROR: tree.png not found";
        return -1;
    }
    std::vector<myClasses::tree*> trees;
    for(int i = 0; i < 3; i++){
        trees.push_back(new myClasses::tree(treetx, window.getSize().x+(rand()%(1920-1080)+1080)*i, window.getSize().y));
    }

    //creating text
    sf::Font font;
    if (!font.loadFromFile("inc/fonts/font.otf")){
        std::cout << "ERROR: font was not loaded." << std::endl;
        return -1;
    }

    sf::Color color_Text = sf::Color(243, 118, 68);

    sf::Texture score_textTexture;
    sf::Sprite score_textSprite;
    if (!score_textTexture.loadFromFile("inc/img/score.png")) {
        std::cout << "ERROR: score.png was not loaded." << std::endl;
        return -1;
    }
    score_textTexture.setSmooth(true);
    score_textSprite.setTexture(score_textTexture);
    score_textSprite.setScale(0.2,0.2);
    score_textSprite.setPosition(20,0);


    sf::Texture bestScore_textTexture;
    sf::Sprite bestScore_textSprite;
    if (!bestScore_textTexture.loadFromFile("inc/img/best_score.png")) {
        std::cout << "ERROR: best_score.png was not loaded." << std::endl;
        return -1;
    }
    bestScore_textTexture.setSmooth(true);
    bestScore_textSprite.setTexture(bestScore_textTexture);
    bestScore_textSprite.setScale(0.2,0.2);
    bestScore_textSprite.setPosition(0,score_textTexture.getSize().y*score_textSprite.getScale().y);

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("");
    scoreText.setCharacterSize(100);
    scoreText.setFillColor(color_Text);
    scoreText.setPosition(score_textTexture.getSize().x*score_textSprite.getScale().x+50,10);

    sf::Text best_scoreText;
    best_scoreText.setFont(font);
    best_scoreText.setString("");
    best_scoreText.setCharacterSize(100);
    best_scoreText.setFillColor(color_Text);
    best_scoreText.setPosition(0, scoreText.getCharacterSize());
    best_scoreText.setPosition(bestScore_textTexture.getSize().x*bestScore_textSprite.getScale().x+50,
                               score_textTexture.getSize().y*score_textSprite.getScale().y+10);



    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Space){
                        if(!jump){
                            jump = true;
                            t=0;
                        }
                    }
                    if(event.key.code == sf::Keyboard::R){
                        if(!isPlaying){
                            for(const auto& tree : trees)
                                tree->setX(window.getSize().x+rand()%(7000-4000)+3000);
                            score = 0;
                            isPlaying = true;
                            dino.newTexture(dinotx);
                        }
                    }
            }
        }
        if(jump){
            dino.jump(t,jump, window.getSize().y);
        }
        for(const auto& tree : trees){
            if(isPlaying)
                tree->move();
            if(tree->getX() <= 0)
                tree->setX(window.getSize().x+rand()%(7000-4000)+3000);
        }

        for(int i = 0; i < trees.size(); i++){
            int x_dino  = dino.getX();
            int y_dino = dino.getY();
            int sizeX_dino = dino.sizeX();
            int sizeY_dino = dino.sizeY();

            int x_tree = trees[i]->getX();
            int y_tree = trees[i]->getY();
            int sizeX_tree = trees[i]->sizeX();
            int sizeY_tree = trees[i]->sizeY();
            if(isPlaying) {
                if ((sizeX_dino / 2 - 50 + sizeX_tree / 2 - 25 >= abs(x_tree - x_dino / 2)) &&
                    (sizeY_dino / 2 - sizeY_tree / 2 <= y_dino - y_tree)) {
                    dino.newTexture(dino_gameover);
                    isPlaying = false;
                    score = score;
                    if(score > best_score) {
                        best_score = score;
                        best_file << score;
                        best_file.close();
                    }
                    break;
                } else score++;
            }
        }
        window.clear();
        window.draw(background);
        window.draw(roadsp);
        for(const auto& tree : trees)
            window.draw(*tree->get());
        window.draw(*dino.get());
        scoreText.setString(std::to_string(score));
        best_scoreText.setString(std::to_string(best_score));
        window.draw(score_textSprite);
        window.draw(bestScore_textSprite);
        window.draw(best_scoreText);
        window.draw(scoreText);
        window.display();

        t+=0.7;
    }
    return 0;
}
