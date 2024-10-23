#pragma once
#include "Context.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>

class Behaviour;

class Projectile
{
    sf::Vector2f mPosition;
    std::string mName;
    //int mAmmoCount, mMaxAmmo; 
    Context::State mState;
    Behaviour* mBehaviour;
    int mSpeed;
public:
    Projectile();
    Projectile(
        sf::Vector2f position,
        Behaviour* projectile_behaviour/*,
        int ammo_count*/);
    ~Projectile();

    void setState(Context::State state);
    Context::State getState() const;

    sf::Color getColor() const;
    sf::Vector2f getPosition() const;
    void Update();
};

