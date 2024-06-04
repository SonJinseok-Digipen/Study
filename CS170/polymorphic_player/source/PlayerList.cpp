#include "PlayerList.h"
namespace HLP2
{
   PlayerList::PlayerList(bool owns_data):IPersistable(),ownsData{owns_data}
   {

   }

   PlayerList::PlayerList(const PlayerList&sa)
   {
       //have to use copy_list
       copy_list(head);


   }


}
