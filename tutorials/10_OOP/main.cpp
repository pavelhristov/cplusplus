#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>
#include <algorithm>

class Animal {
private:
    std::string name;
    double height;
    double weight;

    static int numOfAnimals;

public:

    std::string GetName() {
        return name;
    }

    void SetName(std::string name) {
        this->name = name;
    }

    double GetHeight() {
        return height;
    }

    void SetHeight(double height) {
        this->height = height;
    }

    double GetWeight() {
        return weight;
    }

    void SetWeight(double weight) {
        this->weight = weight;
    }

    void SetAll(std::string name, double height, double weight);
    Animal(std::string name, double height, double weight);
    Animal();
    ~Animal();

    static int GetNumberOfAnimals() {
        return numOfAnimals;
    }
    void ToString();
};

int Animal::numOfAnimals = 0;

void Animal::SetAll(std::string name, double height, double weight) {
    this->name = name;
    this->height = height;
    this->weight = weight;
}

Animal::Animal(std::string name, double height, double weight) {
    this->name = name;
    this->height = height;
    this->weight = weight;

    Animal::numOfAnimals++;
}

Animal::Animal() {
    this->name = "";
    this->height = 0;
    this->weight = 0;

    Animal::numOfAnimals++;
}

Animal::~Animal() {
    std::cout << "Animal " << this->name << " destroyed" << std::endl;
    Animal::numOfAnimals--;
}

void Animal::ToString() {
    std::cout << this->name << " is " << this->height << " cms tall and " <<
            this->weight << " kgs in weight" << std::endl;
}

class Dog : public Animal {
private:
    std::string sound = "Woof";
public:

    void MakeSound() {
        std::cout << "The dog " << this->GetName() << " says " << this->sound <<
                std::endl;
    }

    Dog(std::string, double, double, std::string);

    Dog() : Animal() {
    };

    void ToString();
};

Dog::Dog(std::string name, double height, double weight, std::string sound) :
Animal(name, height, weight) {
    this->sound = sound;
}

void Dog::ToString() {
    std::cout << this->GetName() << " is " << this->GetHeight() <<
            " cms tall and " << this->GetWeight() <<
            " kgs in weight and says " << this->sound << std::endl;
}

class Warrior {
private:
    std::string name;
    int health;
    int damage;
    int block;

public:
    Warrior(std::string name, int health, int damage, int block);

    ~Warrior() {
        std::cout << this->name << " destroyed." << std::endl;
    }

    void TakeDamage(int damage) {
        this->health -= damage;
        if (this->health < 0) {
            this->health = 0;
        }
    }

    int GetHealth() {
        return this->health;
    }

    int GetDamage() {
        return this->damage;
    }

    int GetBlock() {
        return this->block;
    }

    std::string GetName() {
        return this->name;
    }
};

Warrior::Warrior(std::string name, int health, int damage, int block) {
    this->name = name;
    this->health = health;
    this->damage = damage;
    this->block = block;
}

class Battle {
private:

    static void Fight(Warrior& attacker, Warrior& defender) {
        int attack = std::max((std::rand() % attacker.GetDamage()) -
                (std::rand() % defender.GetBlock()), 0);

        std::cout << attacker.GetName() << " attacks " <<
                defender.GetName() << " for " << attack << " damage" <<
                std::endl;

        defender.TakeDamage(attack);
        std::cout << defender.GetName() << " is down to " <<
                defender.GetHealth() << " health" << std::endl;
    }

public:

    static void StartFigth(Warrior& war1, Warrior& war2) {
        std::cout << "Battle started" << std::endl;

        int round = 0;
        while (war1.GetHealth() > 0 && war2.GetHealth() > 0) {
            if (round % 2 == 0) {
                Battle::Fight(war1, war2);
            } else {
                Battle::Fight(war2, war1);
            }

            round++;
        }

        if (war1.GetHealth() <= 0) {
            std::cout << war1.GetName() << " has died and " << war2.GetName()
                    << " has victorious" << std::endl;
        } else {
            std::cout << war2.GetName() << " has died and " << war1.GetName()
                    << " has victorious" << std::endl;
        }

        std::cout << "Game Over" << std::endl;
    };
};

int main() {
    // 10.1 example
    //    Animal fred;
    //    fred.ToString();
    //    fred.SetHeight(33);
    //    fred.SetWeight(10);
    //    fred.SetName("Fred");
    //    fred.ToString();
    //
    //    Animal tom("Tom", 36, 15);
    //    tom.ToString();
    //
    //    Dog spot("Spot", 38, 16, "Woof");
    //    spot.ToString();
    //
    //    std::cout << "Number of Animals " << Animal::GetNumberOfAnimals() <<
    //            std::endl;
    //
    //10.2 Problem
    /*
     * Thor attacks Hulk and deals 12 damage
     * Hulk is down to 28 health
     * Hulk attacks Thor and deals 3 damage
     * Thor is down to 37 health
     * Thor attacks Hulk and deals 14 damage
     * Hulk is downto 14 health
     * Hulk attacks Thor and deals 0 damage
     * Thor is down to 37 health
     * Thor attacks Hulk and deals 14 damage
     * Hulk is down to 0 health
     * Hulk has died and thor is victorious
     * Game Over
     */

    srand(time(NULL));
    Warrior thor("Thor", 100, 30, 15);
    Warrior hulk("Hulk", 135, 25, 10);

    Battle::StartFigth(thor, hulk);


    return 0;
}

