#include"Player.h"
#include<iostream>
#pragma once

namespace HLP2
{
  class Scout : public IPlayer
    {
    public:
        Scout();
        explicit Scout(const std::string& name, int health = 50, int primary_damage = 1,int secondary_damage = 5);
        explicit Scout(const Scout&rhs);
        std::string WhoAmI() const override;
        const char* GetType() const override;
        
        //Gave some damage to other player paramter is attack target 
        void PrimaryAttack(IPlayer& other) const override;
        void SecondaryAttack(IPlayer& other) const override;
        // Constructor declaration
        // Overriding virtual functions declarations
        void TakeDamage(int damage) override;
        //Declare the Clone function that returns a pointer to an IPlayer object.
        // This function should create a new Scout object by using the copy constructor and return a pointer to the newly created object: 
        IPlayer*            Clone() const override;
    private:
        // Implement private helper functions if necessary
    };
}
