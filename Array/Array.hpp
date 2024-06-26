#include <cstddef>	 // size_t
#include <stdexcept> // std::runtime_error
#include <string>	 // std::to_string
#include <iterator>	 // std::reverse_iterator
#define _LIBPENGCXX_THROW_OUT_OF_RANGE() throw std::runtime_error("out of range at index ")
template <class Tp, size_t N>
struct Array{
	Tp M_elements[N];

	Tp &operator[](size_t i) noexcept{
		return M_elements[i];
	}

	Tp const &operator[](size_t i) const noexcept{
		return M_elements[i];
	}

	Tp& at(size_t i){
		if(i>=N){
			throw std::runtime_error("Array::at: index out of range");
		}
		return M_elements[i];
	}

	Tp const &at(size_t i) const{
		if (i >= N)
		{
			throw std::runtime_error("Array::at: index out of range");
		}
		return M_elements[i];
	}

	void fill(const Tp &val) noexcept
		requires (std::is_nothrow_copy_assignable_v<Tp>)
	{
		for(size_t i=0; i<N; i++){
			M_elements[i] = val;
		}
	}

	void swap(Array& other) noexcept
		requires (std::is_nothrow_swappable_v<Tp>)
	{
		for(size_t i=0; i<N; i++){
			std::swap(M_elements[i], other.M_elements[i]);
		}
	}

	Tp& front() noexcept{
		return M_elements[0];
	}

	const Tp &front() const noexcept
	{
		return M_elements[0];
	}

	Tp& back() noexcept{
		return M_elements[N-1];
	}

	const Tp &back() const noexcept
	{
		return M_elements[N-1];
	}

	constexpr bool empty() noexcept{
		return false;
	}

	constexpr size_t size() noexcept{
		return N;
	}

	constexpr size_t max_size() noexcept{
		return N;
	}

	Tp const *cdata() const noexcept{
		return M_elements;
	}

	Tp const *data() const noexcept{
		return M_elements;
	}

	Tp* begin() noexcept{
		return M_elements;
	}

	const Tp* begin() const noexcept{
		return M_elements;
	}

	const Tp* cbegin() const noexcept{
		return M_elements;
	}

	Tp* end() noexcept{
		return M_elements+N;
	}

	const Tp* end() const noexcept{
		return M_elements+N;
	}

	const Tp* cend() const noexcept{
		return M_elements+N;
	}

	std::reverse_iterator<Tp*> rbegin() noexcept{
		return std::reverse_iterator<Tp*>(end());
	}

	std::reverse_iterator<const Tp *> rbegin()const noexcept
	{
		return std::reverse_iterator<Tp *>(end());
	}

	std::reverse_iterator<Tp *> rend() noexcept{
		return std::reverse_iterator<Tp *>(begin());
	}

	std::reverse_iterator<const Tp *> rend() const noexcept{
		return std::reverse_iterator<Tp *>(begin());
	}

	std::reverse_iterator<Tp const *> crbegin() const noexcept
	{
		return std::make_reverse_iterator(M_elements);
	}

	std::reverse_iterator<Tp const *> crend() const noexcept
	{
		return std::make_reverse_iterator(M_elements + N);
	}
};

template <class Tp>
struct Array<Tp,0>
{
	//Tp M_elements[N];

	Tp &operator[](size_t i) noexcept
	{
		_LIBPENGCXX_THROW_OUT_OF_RANGE();
	}

	Tp const &operator[](size_t i) const noexcept
	{
		_LIBPENGCXX_THROW_OUT_OF_RANGE();
	}

	Tp &at(size_t i)
	{
		_LIBPENGCXX_THROW_OUT_OF_RANGE();
	}

	Tp const &at(size_t i) const
	{
		_LIBPENGCXX_THROW_OUT_OF_RANGE();
	}

	void fill(const Tp &val) noexcept
		requires(std::is_nothrow_copy_assignable_v<Tp>)
	{
	}

	void swap(Array &other) noexcept
		requires(std::is_nothrow_swappable_v<Tp>)
	{
	}

	Tp &front() noexcept
	{
		_LIBPENGCXX_THROW_OUT_OF_RANGE();
	}

	const Tp &front() const noexcept
	{
		_LIBPENGCXX_THROW_OUT_OF_RANGE();
	}

	Tp &back() noexcept
	{
		_LIBPENGCXX_THROW_OUT_OF_RANGE();
	}

	const Tp &back() const noexcept
	{
		_LIBPENGCXX_THROW_OUT_OF_RANGE();
	}

	constexpr bool empty() noexcept
	{
		return true;
	}

	constexpr size_t size() noexcept
	{
		return 0;
	}

	constexpr size_t max_size() noexcept
	{
		return 0;
	}

	Tp const *cdata() const noexcept
	{
		return nullptr;
	}

	Tp const *data() const noexcept
	{
		return nullptr;
	}

	Tp *begin() noexcept
	{
		return nullptr;
	}

	const Tp *begin() const noexcept
	{
		return nullptr;
	}

	const Tp *cbegin() const noexcept
	{
		return nullptr;
	}

	Tp *end() noexcept
	{
		return nullptr;
	}

	const Tp *end() const noexcept
	{
		return nullptr;
	}

	const Tp *cend() const noexcept
	{
		return nullptr;
	}

	std::reverse_iterator<Tp *> rbegin() noexcept
	{
		return nullptr;
	}

	std::reverse_iterator<const Tp *> rbegin() const noexcept
	{
		return nullptr;
	}

	std::reverse_iterator<Tp *> rend() noexcept
	{
		return nullptr;
	}

	std::reverse_iterator<const Tp *> rend() const noexcept
	{
		return nullptr;
	}

	std::reverse_iterator<Tp const *> crbegin() const noexcept
	{
		return nullptr;
	}

	std::reverse_iterator<Tp const *> crend() const noexcept
	{
		return nullptr;
	}
};

template <class Tp, class ...Ts>
Array(Tp, Ts...) -> Array<Tp, 1 + sizeof...(Ts)>;