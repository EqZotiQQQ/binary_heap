#include "binary_heap.h"
#include "gtest/gtest.h"

/*
 * It's just a template
 * */

TEST(binary_heap, create)
{
    BinaryHeap<int> heap;
    ///
}

TEST(binary_heap, push)
{
    std::vector expected {
                              91,
                         85,      63,
                      50,   42, 52, 19,
                    13, 40
    };
    BinaryHeap<int> heap;
    heap.append(52);
    heap.append(13);
    heap.append(91);
    heap.append(42);
    heap.append(85);
    heap.append(63);
    heap.append(19);
    heap.append(40);
    heap.append(50);

    auto f = heap.get_heap();
    for (int i = 0; i < f.size(); i++) {
        ASSERT_EQ(expected[i], f[i]);
    }
}

TEST(binary_heap, create_from)
{
    std::vector expected {
                              91,
                         85,      50,
                      63,   52, 42, 13,
                    4, 19
    };
    std::vector move_expected {
                              4,
                         85,      13,
                      19,   52, 42, 50,
                   63,   91
    };
    BinaryHeap<int> heap(std::move(move_expected));

    auto f = heap.get_heap();

    ASSERT_EQ(f.size(), expected.size());
    for (int i = 0; i < f.size(); i++) {
        ASSERT_EQ(expected[i], f[i]);
    }
}

TEST(binary_heap, max)
{
    std::vector expected {
                              85,
                        63 ,      50,
                      19,   52, 42, 13,
                    4
    };
    std::vector move_expected {
                              4,
                         85,      13,
                      19,   52, 42, 50,
                   63,   91
    };
    BinaryHeap<int> heap(std::move(move_expected));
    auto i = heap.max();

    ASSERT_EQ(i, 91);

    auto f = heap.get_heap();

    ASSERT_EQ(f.size(), expected.size());
    for (int i = 0; i < f.size(); i++) {
        ASSERT_EQ(expected[i], f[i]);
    }
}

TEST(binary_heap, heap_sort)
{
    std::vector expected {
                              85,
                        63 ,      50,
                      19,   52, 42, 13,
                    4
    };
    std::vector move_expected {
                              4,
                         85,      13,
                      19,   52, 42, 50,
                   63,   91
    };
//    BinaryHeap<int>::heap_sort(move_expected);

}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}