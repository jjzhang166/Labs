#ifndef TLIST_H
#define TLIST_H
#include <memory>
#include <iostream>

template <typename T> class TList {
 private:
  class TNode {
  public:
    TNode();
    TNode(const std::shared_ptr<T>&);
    auto GetNext() const;
    auto GetItem() const;
    std::shared_ptr<T> item;
    std::shared_ptr<TNode> next;

  };

  template <typename N, typename M>
    class TIterator {
  private:
    N nodePtr;
  public:
    TIterator(const N&);
    std::shared_ptr<M> operator* ();
    std::shared_ptr<M> operator-> ();
    void operator ++ ();
    bool operator == (const TIterator&);
    bool operator != (const TIterator&);
  };
 
  int length;
  
  std::shared_ptr<TNode> head;
  
 public:
  TList();
  bool PushFront(const std::shared_ptr<T>&);
  bool Push(const std::shared_ptr<T>&, const int);
  bool PopFront();
  bool Pop(const int);
  bool IsEmpty() const;
  int GetLength() const;

  TIterator<std::shared_ptr<TNode>, T> begin() {return TIterator<std::shared_ptr<TNode>, T>(head->next);};
  TIterator<std::shared_ptr<TNode>, T> end() {return TIterator<std::shared_ptr<TNode>, T>(nullptr);};

  template <typename A> friend std::ostream& operator<< (std::ostream&, TList<A>&);
};

#include "TList.hpp"
#include "TIterator.hpp"
#endif
