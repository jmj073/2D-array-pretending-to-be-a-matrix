#ifndef DELETER_FOR_ALLOCATOR_H
#define DELETER_FOR_ALLOCATOR_H

#include <memory>

template<typename VT, typename _Alloc = std::allocator<VT>>
struct DeleterForAllocator
{
    size_t elem_size;

    DeleterForAllocator(size_t size)
        : elem_size{ size } {}

    void operator()(VT* ptr)
    {
        for (size_t i = elem_size; i-- > 0;)
            ptr[i].~VT();
        _Alloc allocator{};
        allocator.deallocate(ptr, elem_size);
        std::cout << "deleted!\n";
    }
};

#endif // DELETER_FOR_ALLOCATOR_H