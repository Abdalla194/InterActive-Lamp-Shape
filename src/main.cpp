#include <SFML/Graphics.hpp>
using namespace std;

class Shapes {
public:
    virtual void draw(sf::RenderWindow& window) = 0;
};

class Circle : public Shapes {
public:
    void draw(sf::RenderWindow& window) override {
        sf::CircleShape bulb(50);
        bulb.setPosition(350, 70);
        bulb.setFillColor(sf::Color(120, 120, 120));
        window.draw(bulb);
    }
};

class Rectangle : public Shapes {
public:
    void draw(sf::RenderWindow& window) override {
        sf::RectangleShape neck({35, 25});
        neck.setPosition(382, 165);
        neck.setFillColor(sf::Color(80, 80, 80));
        window.draw(neck);
    }
};

class Square : public Shapes {
public:
    void draw(sf::RenderWindow& window) override {
        sf::RectangleShape stand({12, 150});
        stand.setPosition(393, 190);
        stand.setFillColor(sf::Color(100, 100, 100));
        window.draw(stand);
    }
};

class Triangle : public Shapes {
public:
    void draw(sf::RenderWindow& window) override {
        sf::RectangleShape base({120, 15});
        base.setPosition(339, 340);
        base.setFillColor(sf::Color(60, 60, 60));
        window.draw(base);
    }
};

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 450), "Lamp");

    Circle bulb;
    Rectangle neck;
    Square stand;
    Triangle base;

    bool isOn = false;

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter)
                    isOn = !isOn;
            }
        }

        window.clear(sf::Color::White);

        if (isOn) {
            sf::CircleShape light(50);
            light.setPosition(350, 70);
            light.setFillColor(sf::Color::Yellow);
            window.draw(light);
        }
        else {
            bulb.draw(window);
        }

        neck.draw(window);
        stand.draw(window);
        base.draw(window);

        window.display();
    }

    return 0;
}