#include "Pyro.h"

namespace HLP2
{
   Pyro::Pyro(const std::string& name, int health, int primary_damage, int secondary_damage,
            int burning_damage):Soldier(name,health,primary_damage,secondary_damage),m_buring_damage(burning_damage){}

   void Pyro::Burn(IPlayer& other) const
   {
       other.TakeDamage(m_buring_damage);
   }
   void Pyro::Save(std::ostream&os) const
   {
     IPlayer::Save(os);
     os<<m_buring_damage;
   }

   void Pyro::Load(std::istream&is ) 
   {
     int temp_buring_damage;
     IPlayer::Load(is);
     is>>temp_buring_damage;
     m_buring_damage=temp_buring_damage;
   }

   std::string Pyro::WhoAmI() const
   {
      return "I'm a Pyro named "+IPlayer::GetName();
   }

   const char* Pyro::GetType() const
   {
    return "Pyro";
   }

   void Pyro::PrimaryAttack(IPlayer& other) const
   {
       int damage_amount=IPlayer::GetPrimaryDamage();
       other.TakeDamage(damage_amount);
   }

   void Pyro::SecondaryAttack(IPlayer& other) const
   {
       int damage_amount=IPlayer::GetSecondaryDamage();
       other.TakeDamage(damage_amount);
   }

   IPlayer* Pyro::Clone() const
   {
    IPlayer*temp=new Pyro(*this);
    return temp;
   }




}