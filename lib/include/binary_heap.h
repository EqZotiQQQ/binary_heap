#include <vector>
#include <concepts>

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
    constexpr BinaryHeap() noexcept {
        //
    }

    /***
     * O(N)
     */
    constexpr BinaryHeap(std::vector<T>&& vec) {
        data.reserve(vec.size());
        data.clear();
        data = std::move(vec);
        for (int i = size()/2; i >= 0; i--) {
            balance(i);
        }
    }



    inline constexpr std::size_t size() const noexcept {
        return data.size();
    }

    /***
     * Complexity O(LogN)
     */
    constexpr void append(T&& value) {
        data.emplace_back(std::move(value));
        int new_element_pos = size() - 1; // place to the end
        int parent_node_pos = (new_element_pos - 1) / 2; // get parent pos

        while (new_element_pos > 0 && data[parent_node_pos] < data[new_element_pos]) { // while not root and bigger then parent
            std::swap(data[parent_node_pos], data[new_element_pos]); // place to parent

            new_element_pos = parent_node_pos;
            parent_node_pos = (new_element_pos - 1) / 2;
        }
    }

    /***
     * Complexity O(LogN)
     */
    constexpr void balance(int i) noexcept {
        int right_child {};
        int left_child {};
        int largest_child {};

        while (true) {
            left_child = 2 * i + 1;
            right_child = 2 * i + 2;
            largest_child = i;

            if (left_child < size() && data[left_child] > data[largest_child]) {
                largest_child = left_child;
            }

            if (right_child < size() && data[right_child] > data[largest_child]) {
                largest_child = right_child;
            }

            if (largest_child == i) {
                break;
            }

            std::swap(data[i], data[largest_child]);
            i = largest_child;
        }
    }

    constexpr T& max() noexcept {
        std::swap(data[0], data[size() - 1]);
        T&& max = std::move(data[size() - 1]);
        data.pop_back();
        balance(0);
        return max;
    }

    inline constexpr const std::vector<T>& get_heap() const noexcept {
        return data;
    }
};
