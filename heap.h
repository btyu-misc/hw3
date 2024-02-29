#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

//#include <iostream> //DELETE LATER

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  //debug, delete later
  /*void printArr() {
    for (size_t i = 0; i < heap_.size(); i++) {
      std::cout << heap_[i] << ", ";
    }
    std::cout << std::endl;
  }*/

private:
  /// Add whatever helper functions and data members you need below
  void trickleUp(size_t index);
  void trickleDown(size_t index);
  std::vector<T> heap_; //SHOULD I BE USING T& HERE?
  int m_;
  PComparator c_;

};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) {
    m_ = m;
    c_ = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {

}

template <typename T, typename PComparator> //is this how you do the template
void Heap<T, PComparator>::push(const T& item) {
    heap_.push_back(item);
    trickleUp(heap_.size() - 1);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return heap_.size() == 0;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return heap_.size();
}

//helper functions
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(size_t index) {
    if (index == 0);
    else {
        if (c_(heap_[index], heap_[(index-1) / m_])) {
            std::swap(heap_[index], heap_[(index-1) / m_]);
            trickleUp((index-1) / m_);
        }
    }
}
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(size_t index) {
    if (index*m_ + 1 >= heap_.size());
    else {
        size_t bestIndex = index*m_ + 1;
        if (bestIndex > heap_.size()); //no children
        else {
            for (int i = 2; i < m_ + 1; i++) {
                if (index*m_ + i >= heap_.size()) break;
                if (c_(heap_[index*m_ + i], heap_[bestIndex]))
                    bestIndex = index*m_ + i;
            }
            //printArr();
            if (c_(heap_[bestIndex], heap_[index])) {
                std::swap(heap_[index], heap_[bestIndex]);
                trickleDown(bestIndex);
            }
        }
    }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_.front();


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");

  }
  std::swap(heap_.front(), heap_[heap_.size() - 1]);
  //printArr();
  heap_.pop_back();
  trickleDown(0);


}



#endif

