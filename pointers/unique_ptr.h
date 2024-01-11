#include <cstddef>
#include <utility>

template<typename T, typename Deleter = void(*)(T*)>
class unique_ptr {
private:
    T* ptr;
    Deleter deleter;

    void deleter_call() {
        if (deleter) {
            deleter(ptr);
        } else {
            delete ptr;
        }
    }

public:
    explicit unique_ptr(T* p = nullptr, Deleter d = [](T* p){ delete p; }) : ptr(p), deleter(d) {}

    ~unique_ptr() {
        deleter_call();
    }

    unique_ptr(unique_ptr&& u) noexcept : ptr(u.ptr), deleter(std::move(u.deleter)) {
        u.ptr = nullptr;
    }

    unique_ptr& operator=(unique_ptr&& u) noexcept {
        if (this != &u) {
            deleter_call();
            ptr = u.ptr;
            deleter = std::move(u.deleter);
            u.ptr = nullptr;
        }
        return *this;
    }

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void reset(T* p = nullptr) {
        deleter_call();
        ptr = p;
    }

    T* get() const { return ptr; }
    Deleter get_deleter() const { return deleter; }

    T& operator[](std::size_t index) const {
        return ptr[index];
    }
};

template<typename T>
class unique_ptr<T[]> {
private:
    T* ptr;

public:
    explicit unique_ptr(T* p = nullptr) : ptr(p) {}

    ~unique_ptr() {
        delete[] ptr;
    }

    unique_ptr(unique_ptr&& u) noexcept : ptr(u.ptr) {
        u.ptr = nullptr;
    }

    unique_ptr& operator=(unique_ptr&& u) noexcept {
        if (this != &u) {
            delete[] ptr;
            ptr = u.ptr;
            u.ptr = nullptr;
        }
        return *this;
    }

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    T& operator[](std::size_t index) const {
        return ptr[index];
    }

    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void reset(T* p = nullptr) {
        if (ptr) {
            delete[] ptr;
        }
        ptr = p;
    }

    T* get() const { return ptr; }
};
