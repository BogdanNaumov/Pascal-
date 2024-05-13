#include "..//gtest/gtest-all.cc"
#include "../skip_list/skip_list.h"
#include "../priority_queue/priority_queue.h"

//SKIPLIST

TEST(SkipListTest, Insert) {
    SkipList<int> skipList(5, 0.5);

    skipList.insert(5);
    skipList.insert(10);
    skipList.insert(15);

    EXPECT_TRUE(skipList.search(5));
    EXPECT_TRUE(skipList.search(10));
    EXPECT_TRUE(skipList.search(15));
}

TEST(SkipListTest, Remove) {
    SkipList<int> skipList(5, 0.5);

    skipList.insert(5);
    skipList.insert(10);
    skipList.insert(15);

    skipList.remove(10);

    EXPECT_FALSE(skipList.search(10));
    EXPECT_TRUE(skipList.search(5));
    EXPECT_TRUE(skipList.search(15));
}

TEST(SkipListTest, Search) {
    SkipList<int> skipList(5, 0.5);

    skipList.insert(5);
    skipList.insert(10);
    skipList.insert(15);

    EXPECT_TRUE(skipList.search(10));
    EXPECT_FALSE(skipList.search(20));
}

TEST(SkipListTest, InsertST) {
    SkipList<string> skipList(5, 0.5);

    skipList.insert("apple");
    skipList.insert("bbb");
    skipList.insert("ququ");

    EXPECT_TRUE(skipList.search("apple"));
    EXPECT_TRUE(skipList.search("bbb"));
    EXPECT_TRUE(skipList.search("ququ"));
}

TEST(SkipListTest, RemoveST) {
    SkipList<string> skipList(5, 0.5);

    skipList.insert("apple");
    skipList.insert("bbb");
    skipList.insert("ququ");

    skipList.remove("apple");

    EXPECT_FALSE(skipList.search("apple"));
    EXPECT_TRUE(skipList.search("bbb"));
    EXPECT_TRUE(skipList.search("ququ"));
}

TEST(SkipListTest, SearchST) {
    SkipList<string> skipList(5, 0.5);

    skipList.insert("apple");
    skipList.insert("bbb");
    skipList.insert("ququ");

    EXPECT_TRUE(skipList.search("apple"));
    EXPECT_FALSE(skipList.search("pppppp"));
}

//priority_queue

TEST(PriorityQueueTest, Insert) {
    PriorityQueue<int> pq;

    // Вставляем элементы с разными приоритетами
    pq.insert(10, 1);
    pq.insert(30, 3);
    pq.insert(20, 2);

    // Проверяем, что все элементы на месте
    EXPECT_EQ(pq.pop(), 3);  // Элемент с приоритетом 30 должен быть первым
    EXPECT_EQ(pq.pop(), 2);  // Следующий - с приоритетом 20
    EXPECT_EQ(pq.pop(), 1);  // Затем - с приоритетом 10
}

// Тест извлечения элементов
TEST(PriorityQueueTest, Pop) {
    PriorityQueue<int> pq;

    pq.insert(10, 1);  // Вставляем элемент
    pq.insert(20, 2);

    // Проверяем, что элементы извлекаются в правильном порядке
    EXPECT_EQ(pq.pop(), 2);  // Элемент с приоритетом 20 должен быть первым
    EXPECT_EQ(pq.pop(), 1);  // Элемент с приоритетом 10 должен быть вторым
}

// Тест проверки на пустоту
TEST(PriorityQueueTest, IsEmpty) {
    PriorityQueue<int> pq;

    EXPECT_TRUE(pq.isEmpty());  // Очередь должна быть пустой

    pq.insert(10, 1);  // Вставляем элемент

    EXPECT_FALSE(pq.isEmpty());  // Теперь очередь не пустая
}

// Тест выброса исключения при извлечении из пустой очереди
TEST(PriorityQueueTest, PopFromEmptyQueue) {
    PriorityQueue<int> pq;

    EXPECT_THROW(pq.pop(), std::out_of_range);  // Должно выбрасываться исключение
}

// Тест перегрузки оператора вывода
TEST(PriorityQueueTest, OperatorOutput) {
    PriorityQueue<int> pq;

    pq.insert(10, 1);
    pq.insert(30, 3);
    pq.insert(20, 2);

    testing::internal::CaptureStdout();  // Захват вывода в stdout
    std::cout << pq;  // Используем перегруженный оператор вывода
    std::string output = testing::internal::GetCapturedStdout();  // Получаем захваченный вывод

    EXPECT_NE(output.find("(Priority: 30, Value: 3)"), std::string::npos);  // Элемент с приоритетом 30 должен быть
    EXPECT_NE(output.find("(Priority: 20, Value: 2)"), std::string::npos);  // Элемент с приоритетом 20 должен быть
    EXPECT_NE(output.find("(Priority: 10, Value: 1)"), std::string::npos);  // Элемент с приоритетом 10 должен быть
}

