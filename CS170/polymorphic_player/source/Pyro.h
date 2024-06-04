#pragma once
#include "Soldier.h"
namespace HLP2
{
    class Pyro : public Soldier
    {
    public:
        explicit Pyro(
        const std::string &name, int health = 150, int primary_damage = 3, int secondary_damage = 15,
        int burning_damage = 20);
        void Burn(IPlayer &other) const;
        void Save(std::ostream &os) const override;
        void Load(std::istream &is) override;
        std::string WhoAmI() const override;
        const char* GetType() const override;
        void PrimaryAttack(IPlayer& other) const override;
       void SecondaryAttack(IPlayer& other) const override;
       IPlayer* Clone() const override;

    private:
        int m_buring_damage;
    };
}
