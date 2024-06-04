
#include "Player.h"
#include <typeinfo> //for use bad_cast
#include <iostream>
namespace HLP2
{
    IPlayer::IPlayer(std::string the_name, int the_health, int primary_damage, int secondary_damage)
        : name(the_name), health(the_health), primaryDamage(primary_damage), secondaryDamage(secondary_damage)
    {
        NumCreated++;
        if (this->IsAlive() == true)
        {
            NumActive++;
        }
    }

    IPlayer::IPlayer(const IPlayer &rhs)
    {
        name = rhs.GetName();
        health = rhs.GetHealth();
        primaryDamage = rhs.GetPrimaryDamage();
        secondaryDamage = rhs.GetSecondaryDamage();
        NumCreated++;
        if (this->IsAlive() == true)
        {
            NumActive++;
        }
    }
    IPlayer::~IPlayer()
    {
        if (this->IsAlive() == true)
        {
            NumActive--;
        }
    }

    int IPlayer::CompareTo(const IComparable &other) const
    {
        try
        {
            const IPlayer &temp = dynamic_cast<const IPlayer &>(other);
            if (this->GetName() == temp.GetName())
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        catch (const std::bad_cast &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void IPlayer::Save(std::ostream &os) const
    {

        os << this->GetName() << " " << this->GetHealth() << " " << this->GetPrimaryDamage() << " " << this->GetSecondaryDamage() << '\n';
    }

    void IPlayer::Load(std::istream &is)
    {
        std::string temp_name;
        int temp_health;
        int temp_primaryDamage;
        int temp_secondaryDamage;
        is >> temp_name >> temp_health >> temp_primaryDamage >> temp_secondaryDamage;

        name = temp_name;
        health = temp_health;
        primaryDamage = temp_primaryDamage;
        secondaryDamage = temp_secondaryDamage;
    }

    bool IPlayer::IsAlive() const
    {
        if (this->health > 0)
        {
            return 0;
        }
        else
        {
            return false;
        }
    }

    const std::string &IPlayer::GetName() const
    {
        return name;
    }
    int IPlayer::GetHealth() const
    {
        return health;
    }
    int IPlayer::GetPrimaryDamage() const
    {
        return primaryDamage;
    }

    int IPlayer::GetSecondaryDamage() const
    {
        return secondaryDamage;
    }

    void IPlayer::setName(const std::string &the_name)
    {
        name = the_name;
    }
    void IPlayer::setHealth(int the_health)
    {
        health = the_health;
    }
    void IPlayer::setPrimaryDamage(int damage)
    {
        primaryDamage = damage;
    }
    void IPlayer::setSecondaryDamage(int damage)
    {
        secondaryDamage = damage;
    }

    

};
