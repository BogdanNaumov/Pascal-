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

    // ��������� �������� � ������� ������������
    pq.insert(10, 1);
    pq.insert(30, 3);
    pq.insert(20, 2);

    // ���������, ��� ��� �������� �� �����
    EXPECT_EQ(pq.pop(), 3);  // ������� � ����������� 30 ������ ���� ������
    EXPECT_EQ(pq.pop(), 2);  // ��������� - � ����������� 20
    EXPECT_EQ(pq.pop(), 1);  // ����� - � ����������� 10
}

// ���� ���������� ���������
TEST(PriorityQueueTest, Pop) {
    PriorityQueue<int> pq;

    pq.insert(10, 1);  // ��������� �������
    pq.insert(20, 2);

    // ���������, ��� �������� ����������� � ���������� �������
    EXPECT_EQ(pq.pop(), 2);  // ������� � ����������� 20 ������ ���� ������
    EXPECT_EQ(pq.pop(), 1);  // ������� � ����������� 10 ������ ���� ������
}

// ���� �������� �� �������
TEST(PriorityQueueTest, IsEmpty) {
    PriorityQueue<int> pq;

    EXPECT_TRUE(pq.isEmpty());  // ������� ������ ���� ������

    pq.insert(10, 1);  // ��������� �������

    EXPECT_FALSE(pq.isEmpty());  // ������ ������� �� ������
}

// ���� ������� ���������� ��� ���������� �� ������ �������
TEST(PriorityQueueTest, PopFromEmptyQueue) {
    PriorityQueue<int> pq;

    EXPECT_THROW(pq.pop(), std::out_of_range);  // ������ ������������� ����������
}

// ���� ���������� ��������� ������
TEST(PriorityQueueTest, OperatorOutput) {
    PriorityQueue<int> pq;

    pq.insert(10, 1);
    pq.insert(30, 3);
    pq.insert(20, 2);

    testing::internal::CaptureStdout();  // ������ ������ � stdout
    std::cout << pq;  // ���������� ������������� �������� ������
    std::string output = testing::internal::GetCapturedStdout();  // �������� ����������� �����

    EXPECT_NE(output.find("(Priority: 30, Value: 3)"), std::string::npos);  // ������� � ����������� 30 ������ ����
    EXPECT_NE(output.find("(Priority: 20, Value: 2)"), std::string::npos);  // ������� � ����������� 20 ������ ����
    EXPECT_NE(output.find("(Priority: 10, Value: 1)"), std::string::npos);  // ������� � ����������� 10 ������ ����
}

