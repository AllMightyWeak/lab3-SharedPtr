// Copyright by C-developers1488

#ifndef TEMPLATE_SP_COUNTER_HPP_
#define TEMPLATE_SP_COUNTER_HPP_

#include "ptr.hpp"

template<typename T>
class SPCounter {
 public:
  SPCounter(T* p) noexcept{
    count = 1;
    ptr = p;
  }
  void add() noexcept { ++count; }
  void release() noexcept {
    if (!--count) {
      ptr = nullptr;
      delete this;
    }
  }
  auto use_count() const noexcept -> size_t { return count.load(); }
  void unadd(){count--;}
  void add(size_t c){
    count = c;
  }
 private:
  std::atomic<size_t> count;
  T* ptr;
};

#endif  // TEMPLATE_SP_COUNTER_HPP_