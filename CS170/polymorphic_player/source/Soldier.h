#pragma once
#include"Player.h"
#include<iostream>
namespace HLP2
{
   class Soldier :public IPlayer
   {
       public:
       explicit Soldier(const std::string& name, int health = 100, int primary_damage = 2, int secondary_damage = 10);
       std::string WhoAmI() const override;
       const char* GetType() const override;
       void PrimaryAttack(IPlayer& other) const override;
       void SecondaryAttack(IPlayer& other) const override;
       void TakeDamage(int damage) override;
       IPlayer* Clone() const override;
       private:
   };


}
