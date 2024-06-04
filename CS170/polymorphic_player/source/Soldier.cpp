#include "Soldier.h"
namespace HLP2
{
    Soldier::Soldier(const std::string& name, int health, int primary_damage, int secondary_damage):
    IPlayer(name,health,primary_damage,secondary_damage){}
    
    std::string Soldier::WhoAmI() const
    {
        return "I'm a Soldier named "+GetName();
    }
    const char* Soldier::GetType() const
    {
        return "SOLDIER";
    }
    void Soldier::PrimaryAttack(IPlayer&other) const
    {
        int damage_amout=this->GetPrimaryDamage();
        other.TakeDamage(damage_amout);
    }

    void Soldier::SecondaryAttack(IPlayer& other) const
    {
        int damage_amout=this->GetSecondaryDamage();
        other.TakeDamage(damage_amout);
    } 

    void Soldier::TakeDamage(int damage)
    {
        IPlayer::setHealth(IPlayer::GetHealth()-damage);
    }

    IPlayer* Soldier::Clone() const
    {
        IPlayer*temp=new Soldier(*this);
        return temp;
    }
    

}

