#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Animal {
private:
    string name;
    string type;

public:
    Animal(string name, string type) : name(name), type(type) {}

    virtual ~Animal() {}

    string getName() const {
        return name;
    }

    string getType() const {
        return type;
    }

    void setName(string name) {
        this->name = name;
    }

    void setType(string type) {
        this->type = type;
    }

    virtual void feed() const {
        cout << "Animal " << name << " is eating" << endl;
    }

    virtual void call() const {
        cout << "Animal " << name << " is calling" << endl;
    }

    virtual void stroke() const {
        cout << "Animal " << name << " is being stroked" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string name) : Animal(name, "Cat") {}

    void purr() const {
        cout << "Cat " << getName() << " is purring" << endl;
    }

    void feed() const override {
        cout << "Cat " << getName() << " is eating cat food" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string name) : Animal(name, "Dog") {}

    void bark() const {
        cout << "Dog " << getName() << " is barking" << endl;
    }

    void feed() const override {
        cout << "Dog " << getName() << " is eating dog food" << endl;
    }
};

class Giraffe : public Animal {
public:
    Giraffe(string name) : Animal(name, "Giraffe") {}

    void stretchNeck() const {
        cout << "Giraffe " << getName() << " is stretching its neck" << endl;
    }

    void feed() const override {
        cout << "Giraffe " << getName() << " is eating leaves" << endl;
    }
};

class Zoo {
private:
    vector<Animal*> animals;

public:
    ~Zoo() {
        for (Animal* animal : animals) {
            delete animal;
        }
    }

    void addAnimal(Animal* animal) {
        animals.push_back(animal);
    }

    void deleteAnimal(string name) {
        for (auto it = animals.begin(); it != animals.end(); ++it) {
            if ((*it)->getName() == name) {
                delete *it;
                animals.erase(it);
                break;
            }
        }
    }

    void feedAll() const {
        for (const Animal* animal : animals) {
            animal->feed();
        }
    }

    void callAll() const {
        for (const Animal* animal : animals) {
            animal->call();
        }
    }

    void strokeAll() const {
        for (const Animal* animal : animals) {
            animal->stroke();
        }
    }
};

int main() {
    Zoo zoo;
    zoo.addAnimal(new Cat("Kitty"));
    zoo.addAnimal(new Dog("Doggy"));
    zoo.addAnimal(new Giraffe("Giraffy"));

    zoo.feedAll();
    zoo.callAll();
    zoo.strokeAll();

    cout << "\n\n";

    zoo.deleteAnimal("Doggy");

    zoo.feedAll();

    return 0;
}
