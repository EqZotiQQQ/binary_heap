#include <vector>
#include <concepts>

/*
 * Проще всего бинарную кучу считать массивом.
 * Левый потомок вершины имеет индекс 2*i+1
 * Правый 2*i+2
 * Корень дерева имеет индекс 0.
 * Высота двоичной кучи равна высоте дерева, т.е. log2N.
 *
 * */

template <class T>
concept Eq = requires(T a, T b) {
    { a == b } -> std::convertible_to<bool>;
    { a != b } -> std::convertible_to<bool>;
};

template <class T>
concept Ordering = Eq<T> && requires(T a, T b) {
    { a <= b } -> std::convertible_to<bool>;
    { a < b } ->  std::convertible_to<bool>;
    { a > b } ->  std::convertible_to<bool>;
    { a >= b } -> std::convertible_to<bool>;
};

template <class T> requires Ordering<T>
class BinaryHeap {
protected:
    std::vector<T> data {};
public:
    BinaryHeap() {
        //
    }

    constexpr std::size_t size() const noexcept {
        return data.size();
    }

    constexpr void append(T&& value) noexcept {
        data.emplace_back(std::move(value));
        int new_element_pos = size() - 1; // place to the end
        int parent_node_pos = (new_element_pos - 1) / 2; // get parent pos

        while (new_element_pos > 0 && data[parent_node_pos] < data[new_element_pos]) { // while not root and bigger then parent
            std::swap(data[parent_node_pos], data[new_element_pos]); // place to parent

            new_element_pos = parent_node_pos;
            parent_node_pos = (new_element_pos - 1) / 2;
        }
    }

    constexpr const std::vector<T>& get_heap() const noexcept {
        return data;
    }
};
