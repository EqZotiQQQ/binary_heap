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

    int j = 1;
    auto f = heap.get_heap();
    for (int i = 0; i < f.size(); i++) {
        std::cout << f[i] << ' ';
//        if ((i & (i-1))== 0) {
//            j *= 2;
//        }
    }

    std::cout << '\n';
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}