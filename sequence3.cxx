#include"sequence3.h"

using namespace main_savitch_5;

 sequence::sequence()
 {
	 phead = NULL;
	 pcur = NULL;
 }
 sequence::sequence(const sequence& source)
 {
     if(source.phead!=NULL)
     {
        phead = new node(source.phead->data());
        node* itr = phead;
        int curpos = 0;
        int pos = 0;
        for (node* ptr = source.phead->link(); ptr != NULL; ptr = ptr->link(), pos ++)
        {
            itr->set_link(new node (ptr->data()));
            itr = itr->link();
            if(ptr == source.pcur)
                curpos = pos;
        }
        pcur = phead;
        if(source.pcur != source.phead)
            for (int i =0; i <= curpos; i++)
                pcur = pcur->link();
        if (source.pcur == NULL)
            pcur = NULL;
     }


 }
 sequence::~sequence()
 {
     node* tmp = phead;
     while(tmp!= NULL)
     {
         tmp = tmp->link();
         delete phead;
         phead = tmp;
     }
     pcur = NULL;
 }
 void sequence::start()
 {
     pcur = phead;
 }
 void sequence::advance()
 {
     if (is_item())
     {
            pcur = pcur->link();
     }
 }
 void sequence::insert(const value_type& entry)
 {
     if(phead != pcur && is_item())
     {
         node* pinsrt = new node(entry,pcur);
         node* itr = phead;
         while(itr->link() != pcur)
            itr = itr->link();
         itr->set_link(pinsrt);
         pcur=itr->link();
     }
     else
     {
         phead = new node(entry, phead);
         pcur = phead;
     }
 }
 void sequence::attach(const value_type& entry)
 {
     if(is_item())
     {
        node* pinsrt = new node(entry, pcur->link());
        pcur->set_link(pinsrt);
        pcur = pcur->link();
     }
     else
     {
        node* pinsrt = new node(entry);
        node* itr = phead;
        if(itr != NULL)
        {
            while(itr->link() != NULL)
                itr = itr->link();
            itr->set_link(pinsrt);
            pcur = itr->link();
        }
        else
        {
            phead = new node(entry, phead);
            pcur = phead;
        }
     }
 }
 void sequence::remove_current()
 {
     if(is_item())
     {
         if(pcur == phead)
         {
             phead = pcur->link();
             delete pcur;
             pcur = phead;
         }
         else
         {
            node* itr = phead;
            while(itr->link() != pcur)
                itr = itr->link();
            itr->set_link(pcur->link());
            delete(pcur);
            pcur = itr->link();
         }
     }
 }
 // CONSTANT MEMBER FUNCTIONS
 size_t sequence::size( ) const
 {
     size_t count = 0;
     node* itr = phead;
     while(itr != NULL)
     {
         count++;
         itr = itr->link();
     }
     return count;
 }
 bool sequence::is_item( ) const
 {
     if(pcur != NULL)
        return true;
     else
        return false;
 }
