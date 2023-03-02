#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <set>
#include <iostream>

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

private:
  /// Add whatever helper functions and data members you need below
  void tUp(int position);
  void tDown(int position);

  int mm;
  PComparator com;
  std::vector<T> mArray;
};

// Add implementation of member functions here
template <typename T, typename Comparator>
Heap<T,Comparator>::Heap(int m, Comparator c)
: mm(m), com(c)
{}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
	mArray.push_back(item);
	tUp(mArray.size() - 1);
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
    throw std::underflow_error("No items in heap.");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  
  return mArray[0];
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
    throw std::underflow_error("No items in heap.");
  }

  mArray[0] = mArray[mArray.size()-1];
	mArray.pop_back();
	tDown(0);
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
	return mArray.size();
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
	return mArray.size() == 0;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::tUp(int position) 
{
	if (position == 0) return;
  int pPos = (position-1)/mm;
	if (pPos >= 0 && this->com(mArray[position], mArray[pPos])){
		std::swap(mArray[position], mArray[pPos]);
		tUp(pPos);
	}
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::tDown(int position) 
{
	unsigned int left = mm*position + 1;
	unsigned int right = mm*position + mm;

	if (left > mArray.size()) {
		return;
	}
	
	int min = left;	
	
	for (unsigned int current = left; current <= right &&  current < mArray.size(); current++){
		if (this->com(mArray[current], mArray[min])){ 
			min = current;
		}
	}
	
	if (this->com(mArray[min], mArray[position])){
		std::swap(mArray[min], mArray[position]);
		tDown(min);
	}
}

#endif

