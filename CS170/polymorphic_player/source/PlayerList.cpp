#include "PlayerList.h"
namespace HLP2
{
   PlayerList::PlayerList(bool owns_data):IPersistable(),ownsData{owns_data}
   {

   }

   PlayerList::PlayerList(const PlayerList&sa)
   {
       //have to use copy_list
       copy_list(sa.head);


   }


   void PlayerList::copy_list(const PLNode* source_ptr)
   {
      // i think source_ptr is head_node 
      

                
      //  [player pointer1 ] -> [] -> [] -> [] -> [] source list
           
      //  [Deep copy player1's pointer]                           destination_list 

     //Tod0 
     //1. If source list is empty then return early -> this mean if our destination is  empty then do not copy algorithm

     if(source_ptr==nullptr)
     {
        return;
     } 
     //2. Initialize head pointer to a new node with a cloned player (use the IPlayer's Clone function)
     else
     {
       head=new PLNode(source_ptr->Player->Clone());
       count++;
       //3.Initialize a cursor pointer with the new head pointer -> this mean we need to track our node 
       PLNode*current_node=head;  
      //4.Update the source pointer to the next node in the source list
      source_ptr=source_ptr->Next;
      while (source_ptr!=nullptr)
      {
          PLNode*new_head= new PLNode(source_ptr->Player->Clone());
          count++;
          current_node->Next=new_head;
          current_node=new_head;
          source_ptr=source_ptr->Next;
      }
      ownsData=true;
      //5 Update the count and set ownsData to true for the current object -> im not sure what is count private member function maybe :: object number in list 



     }






   }


}
