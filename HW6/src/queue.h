#ifndef QUEUE_H
#define QUEUE_H

template<class T>
class Queue{
public:
  Queue() {
    _queue = nullptr;
    _size = 0;
  }

  ~Queue() {
    if (_queue != nullptr){
        delete [] _queue;
    }
  }

  void push(T item) {
    T *new_q = new T[_size+1];
    for (int i=0; i<_size; i++){
      new_q[i] = _queue[i];
    }
    new_q[_size] = item;
    delete [] _queue;
    _size += 1;
    _queue = new_q;
    // _queue = new T[_size];
    // for (int i=0; i<=_size; i++){
    //   _queue[i] = new_q[i];
    // } 
    
  }

  T pop() {
    if (_queue == nullptr){
        throw std::string("Queue is empty.");
    }
   
    T value = _queue[0];
    if (_size == 1){
        delete [] _queue;
        _queue = nullptr;
    }
    else{
        T *new_q = new T[_size-1];
        for (int i = 1; i < _size; i++){
            new_q[i-1] = _queue[i];
        }
        delete [] _queue;
    _queue = new_q;
    }
     _size --;
    // delete [] _queue;
    // _queue = new_q;
    //_queue = new T[_size];
    // for (int i=0; i<_size; i++){
    //   _queue[i] = new_q[i];
    // }
    return value;
  }

  int size() {
    return _size;
  }

  T at(int i) {
    if (i >= _size or i < 0){
        throw std::string("index out of range");
    }
    return _queue[i];
  }

  void clear() {
    _queue = nullptr;
    _size = 0;
  }
private:
  T *_queue;
  int _size;
};

#endif
