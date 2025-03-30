#include "version_api/version_api.h"
#include <iostream>
#include <map>
#include <vector>
#include <memory>

template <typename T, size_t ChunkSize = 1024>
class ChunkAllocator {
private:
    struct Chunk {
        T* data;
        size_t used;

        Chunk() : data(static_cast<T*>(operator new(ChunkSize * sizeof(T)))), used(0)
        {}
        ~Chunk()
        {
            operator delete(data);
        }
    };

    std::vector<std::unique_ptr<Chunk>> chunks;
    Chunk* current_chunk;

public:
    using value_type = T;

    ChunkAllocator() noexcept
    {
        allocate_new_chunk();
    }

    ChunkAllocator(const ChunkAllocator& other) noexcept
    {
        allocate_new_chunk();
    }
    ChunkAllocator(ChunkAllocator&& other) noexcept :
        chunks(std::move(other.chunks)), current_chunk(other.current_chunk)
    {
        other.current_chunk = nullptr;
    }

    template <typename U>
    ChunkAllocator(const ChunkAllocator<U, ChunkSize>&) noexcept : ChunkAllocator()
    {}

    T* allocate(size_t n)
    {
        std::cerr << "alloc new, n = " << n << std::endl;

        if(n != 1) {
            throw std::bad_alloc();
        }

        if(current_chunk->used == ChunkSize) {
            std::cerr << "need new chunk" << std::endl;
            allocate_new_chunk();
        }

        return &current_chunk->data[current_chunk->used++];
    }

    void deallocate(T*, size_t) noexcept
    {}

    void allocate_new_chunk()
    {
        chunks.emplace_back(std::make_unique<Chunk>());
        current_chunk = chunks.back().get();
    }

    template <typename U>
    struct rebind {
        using other = ChunkAllocator<U, ChunkSize>;
    };
};

template <typename T, typename U, size_t ChunkSize>
bool operator==(const ChunkAllocator<T, ChunkSize>&, const ChunkAllocator<U, ChunkSize>&)
{
    return true;
}

template <typename T, typename U, size_t ChunkSize>
bool operator!=(const ChunkAllocator<T, ChunkSize>& a, const ChunkAllocator<U, ChunkSize>& b)
{
    return !(a == b);
}

int factorial(int n)
{
    int result = 1;
    for(int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

template <typename T, typename Alloc = std::allocator<T>>
class MyList {
    struct Node {
        Node* next;
        T val;

        Node(Node* n, const T& v) : next(n), val(v)
        {}
    };

public:
    MyList() : head(nullptr)
    {}

    ~MyList()
    {
        while(head) {
            Node* temp = head;
            head       = head->next;
            nodeAlloc().deallocate(temp, 1);
        }
    }

    void push_back(const T& val)
    {
        typename Alloc::template rebind<Node>::other alloc = nodeAlloc();
        Node* newNode                                      = alloc.allocate(1);
        new(&newNode->val) T(val);

        if(!head) {
            head          = newNode;
            newNode->next = nullptr;
        }
        else {
            Node* current = head;
            while(current->next) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = nullptr;
        }
    }

    void print() const
    {
        Node* current = head;
        while(current) {
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    Node* head;

    typename Alloc::template rebind<Node>::other& nodeAlloc()
    {
        static typename Alloc::template rebind<Node>::other alloc;
        return alloc;
    }
};

int main()
{
    std::cout << "chunk allocator: " << VersionAPI::getVersion() << std::endl;


    // 1. Создание обычного std::map<int, int>
    std::map<int, int> standard_map;

    // Заполнение 10 элементами (ключ: 0-9, значение: факториал ключа)
    for(int i = 0; i < 10; ++i) {
        standard_map[i] = factorial(i);
    }

    // 2. Создание std::map с нашим аллокатором (ограничен 10 элементами)
    std::map<int, int, std::less<int>, ChunkAllocator<std::pair<const int, int>, 10>> custom_alloc_map;

    // Заполнение 10 элементами (ключ: 0-9, значение: факториал ключа)
    for(int i = 0; i < 10; ++i) {
        custom_alloc_map[i] = factorial(i);
    }

    std::cout << "Standard map (default allocator):\n";
    for(const auto& [key, value]: standard_map) {
        std::cout << key << " " << value << "\n";
    }

    std::cout << "\nCustom allocator map (chunk size = 10):\n";
    for(const auto& [key, value]: custom_alloc_map) {
        std::cout << key << " " << value << "\n";
    }

    //1. Создание MyList со стандартным аллокатором
    MyList<int> list1;
    for(int i = 0; i < 10; ++i) {
        list1.push_back(i);
    }

    // 2. Создание MyList с пользовательским аллокатором (ChunkSize = 10)
    MyList<int, ChunkAllocator<int, 10>> list2;
    for(int i = 0; i < 10; ++i) {
        list2.push_back(i);
    }

    // Вывод содержимого
    std::cout << "List with default allocator: ";
    list1.print();

    std::cout << "List with chunk allocator: ";
    list2.print();

    return 0;
}
