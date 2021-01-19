#include "../src/queue.h"



TEST(QueueTest, Constructor) {
    Queue<int> q;
    ASSERT_EQ(0, q.size());
}

TEST(QueueTest, push_two_int){
  Queue<int> q;
  q.push(1);
  q.push(2);
  ASSERT_EQ(2, q.size());
  ASSERT_EQ(1, q.at(0));
  ASSERT_EQ(2, q.at(1));
}

TEST(QueueTest, push_one_double){
  Queue<double> q;
  q.push(3.1415);
  ASSERT_EQ(1, q.size());
  ASSERT_NEAR(3.1415, q.at(0), 0.0001);
}

TEST(QueueTest, push_one_char){
  Queue<double> q;
  q.push('a');
  ASSERT_EQ(1, q.size());
  ASSERT_EQ('a', q.at(0));
}

TEST(QueueTest, pop_one_int){
  Queue<int> q;
  q.push(1);
  ASSERT_EQ(1, q.pop());
  ASSERT_EQ(0, q.size());
}

TEST(QueueTest, pop_two_double){
  Queue<double> q;
  q.push(3.1415);
  q.push(4.14);
  ASSERT_EQ(2, q.size());
  ASSERT_NEAR(3.1415, q.pop(), 0.0001);
  ASSERT_EQ(1, q.size());
  ASSERT_NEAR(4.14, q.pop(), 0.0001);
  ASSERT_EQ(0, q.size());
}

TEST(QueueTest, pop_one_char){
  Queue<double> q;
  q.push('a');
  ASSERT_EQ('a', q.pop());
  ASSERT_EQ(0, q.size());
}

TEST(QueueTest, pop_original_empty_exception){
  Queue<std::string> q;
  ASSERT_THROW(q.pop(), std::string);
}

TEST(QueueTest, pop_empty_exception_out_of_range){
  Queue<int> q;
  q.push(1);
  ASSERT_EQ(1, q.pop());
  ASSERT_THROW(q.pop(), std::string);
}

TEST(QueueTest, push_5_int_and_pop_them){
  Queue<int> q;
  for(int i=0 ; i<5 ; i++){
    q.push(i);
    ASSERT_EQ(i+1, q.size());
  }
  for(int i=0 ; i<5 ; i++){
    ASSERT_EQ(5-i, q.size());
    ASSERT_EQ(i, q.pop());
    ASSERT_EQ(4-i, q.size());
  }
}

TEST(QueueTest, at_exception){
  Queue<int> q;
  q.push(1);
  q.push(2);
  ASSERT_THROW(q.at(-1), std::string);
  ASSERT_THROW(q.at(2), std::string);
}

TEST(QueueTest, clear_queue){
  Queue<int> q;
  q.push(1);
  q.push(2);
  ASSERT_EQ(2, q.size());
  q.clear();
  ASSERT_EQ(0, q.size());
}

TEST(QueueTest, call_10000_times){
  Queue<int> q;
  for (int i = 0; i < 10000; i++){
    ASSERT_NO_THROW(q.push(1));
  }
  for (int i = 0; i < 10000; i++){
    ASSERT_NO_THROW(q.pop());
  }
}

