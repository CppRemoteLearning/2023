#ifndef NAGARROREMOTELEARNING_CUSTOM_UNIQUE_PTR_H
#define NAGARROREMOTELEARNING_CUSTOM_UNIQUE_PTR_H

#include <memory>
#include <utility>

// Here I ran into a big problem for using the standard deleter that Marc used, when trying to push_back the unique pointer into a vector of unique pointers
// I was getting an error that the copy constructor was deleted. This was because the standard deleter was not copyable and the unique pointer was trying to copy the deleter,
// or at least that is what I think was happening, found something similar on stackoverflow.
struct DeviceDeleter {
    template<typename T>
    void operator()(T* ptr) const {
        delete ptr;
    }
};

namespace custom_memory {
    template <typename T,  typename Deleter = DeviceDeleter>
    class CustomUniquePtr {
    public:
        CustomUniquePtr(T* pointer, Deleter deleter = Deleter()): pointer_(pointer), deleter_(deleter) {}

        CustomUniquePtr(const CustomUniquePtr& other) = delete;

        CustomUniquePtr& operator=(const CustomUniquePtr& other) = delete;

        // It is wrong to have them as const because we are moving the pointer from one unique pointer to another
        CustomUniquePtr(CustomUniquePtr&& other);

        CustomUniquePtr& operator=(CustomUniquePtr&& other);

        ~CustomUniquePtr() {
            deleter_(pointer_);
        }

        template <typename U, typename std::enable_if_t<std::is_convertible<U*, T*>::value, int> = 0>
        CustomUniquePtr(CustomUniquePtr<U, Deleter>&& other) noexcept : pointer_(other.Release()), deleter_(std::move(other.GetDeleter())) {
            static_assert(std::is_convertible<U*, T*>::value, "U* must be implicitly convertible to T*");
        }


        inline T& operator*() {
            return *pointer_;
        }

        inline T* operator->() {
            return pointer_;
        }

        inline T& operator[](std::size_t i) {
            return pointer_[i];
        }

        explicit operator bool() const {
            if (pointer_ != nullptr) {
                return true;
            }

            return false;
        }

        inline T* Get() {
            return pointer_;
        }

        // overload for const needed in the User class
        inline const T* Get() const {
            return pointer_;
        }

        inline Deleter& GetDeleter() {
            return deleter_;
        }

        inline const Deleter& GetDeleter() const {
            return deleter_;
        }

        T* Release();

        void Swap(CustomUniquePtr& other);

        void Reset(T* newPointer = nullptr);

    private:
        T* pointer_;
        Deleter deleter_;
    };

    template <typename T, typename Deleter>
    CustomUniquePtr<T, Deleter>::CustomUniquePtr(CustomUniquePtr&& other): pointer_(std::move(other.pointer_)), deleter_(std::move(other.deleter_)) {
        other.pointer_ = nullptr;
    }

    template <typename T, typename Deleter>
    CustomUniquePtr<T, Deleter>& CustomUniquePtr<T, Deleter>::operator=(CustomUniquePtr&& other) {
        if (this != &other) {
            this->Reset(other.Release());
            deleter_ = std::move(other.deleter_);
        }

        return *this;
    }

    template <typename T, typename Deleter>
    T* CustomUniquePtr<T, Deleter>::Release() {
        T* temp = pointer_;
        pointer_ = nullptr;
        return temp;
    }

    template <typename T, typename Deleter>
    void CustomUniquePtr<T, Deleter>::Swap(CustomUniquePtr& other) {
        if (pointer_ != &other.pointer_) {
            T* temp = pointer_;
            pointer_ = other.pointer_;
            other.pointer_ = temp;
        }

        Deleter tempDeleter = deleter_;
        deleter_ = other.deleter_;
        other.deleter_ = tempDeleter;
    }

    template <typename T, typename Deleter>
    void CustomUniquePtr<T, Deleter>::Reset(T* newPointer) {
        if (pointer_ != newPointer) {
            if (pointer_ != nullptr) {
                deleter_(pointer_);
            }
            pointer_ = newPointer;
        }
    }

    // helper function to create a unique pointer, copied from std::unique_ptr
    template <typename T, typename... Args>
    CustomUniquePtr<T> MakeCustomUnique(Args&&... args) {
        return CustomUniquePtr<T>(new T(std::forward<Args>(args)...));
    }
}

#endif
