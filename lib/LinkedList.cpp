/**
  * Doubley Linked List
  */

#include <iostream>
using namespace std ;

///////////////////////////////////////////////////////////////////////////////
class LinkedList
{
  private:
    struct node
    {
      int data ;
      node *next ;
      node *prev ;

      node () : _next( 0 ) , _prev( 0 ) {}
      node ( int data ) : _data( data ) , _next( 0 ) , _prev( 0 ) {}
      node ( int data , node next ) : _data( data ) , _next( next ) , _prev ( 0 ) {}
     ~node () {}

      node getData ()
      {
        return this.data ;
      }
      node getNext ()
      {
        return this.next ;
      }
      node getPrev ()
      {
        return this.prev ;
      }
      void setNext ( node n )
      {
        this.next = n ;
        n.prev    = this ;
      }
      void setPrev ( node n )
      {
        this.prev = n ;
        n.next    = this ;
      }
    } ;
    typedef node *link ;

    link head ;
    link tail ;
    int size ;

  public:
    LinkedList () : head( 0 ) , tail( 0 ) , size( 0 ) ; {}
   ~LinkedList () {}
    void add ( int data )
    {
      if ( size == 0 )
      {
        head = new link ( data ) ;
        tail = head ;
      }
      else
      {
        tail.setNext ( new link ( data ) ) ;
        tail = tail.getNext() ;
      }
      size ++ ;
    }
    void remove ( int data )
    {
      link n = search ( data ) ;
      if ( n == 0 )
        return ;
      if ( size == 1 )
      {
        head = 0 ;
        tail = 0 ;
      }
      else if ( n == head )
      {
        head = head.getNext() ;
        head.setPrev( 0 ) ;
      }
      else if ( n == tail )
      {
        tail = tail.getPrev() ;
        tail.setNext( 0 ) ;
      }
      else
      {
        n.getPrev().setNext( n.getNext ) ;
        n.getNext().setPrev( n.getPrev ) ;
        //need to delete n
      }
      size -- ;
    }
    link search ( int data )
    {
      link cursor = head ;
      while ( cursor )
      {
        if ( cursor.getData() == data )
          return cursor ;
        cursor = cursor.getNext() ;
      }
      return 0 ;
    }
} ;
///////////////////////////////////////////////////////////////////////////////