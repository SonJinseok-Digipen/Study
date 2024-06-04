#include "Scout.h"
namespace HLP2
{
    Scout::Scout(const std::string &name, int health, int primary_damage, int secondary_damage)
        : IPlayer(name, health, primary_damage, secondary_damage){};

    
    std::string Scout::WhoAmI() const
    {
        return "I'm a Scout named "+GetName();
    }

    const char *Scout::GetType() const
    {
        return "SCOUT";
    }

    void Scout::PrimaryAttack(IPlayer &other) const
    {
        int damage_amount = this->GetPrimaryDamage();
        other.TakeDamage(damage_amount);
        std::cout<<"pushed"<<'\n';
    }
    void Scout::SecondaryAttack(IPlayer &other) const
    {
        int damage_amount = this->GetSecondaryDamage();
        other.TakeDamage(damage_amount);
        std::cout<<"stabbed"<<'\n';
    }

    void Scout::TakeDamage(int damage)
    {
        // I feel so proud of this code
        IPlayer::setHealth(IPlayer::GetHealth() - damage);
    }

    IPlayer *Scout::Clone() const
    {
        //we have to do this return local variable is em not good situation i think       
        IPlayer* temp= new Scout(*this);
        return temp;
    }

}
