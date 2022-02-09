# mem: 内存管理

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [mem0mem.h](#mem0mem.h)                |   498 |||
| [mem0mem.ic](#mem0mem.ic)              |   596 |||
| [mem0mem.cc](#mem0mem.cc)  |   462 |||


## mem0mem.h
<span id="mem0mem.h" />

### data structures

`typedef struct mem_block_info_t mem_block_t`: 内存堆中的块由info结构后接一个内存区域构成.

`typedef mem_block_t mem_heap_t`: 内存堆是内存块`mem_block_t`的非空线性列表.


`struct mem_block_info_t`: 内存堆中的块的头部信息结构

``` c++
struct mem_block_info_t {
	ulint	magic_n;													// 用于调试的魔法数
	char	file_name[8];											// 创建内存堆的文件名称(调试用)
	ulint	line;															// 创建内存堆的文件行号(调试用)
	UT_LIST_BASE_NODE_T(mem_block_t) base;	// TODO(zhoujiagen) restart here
	UT_LIST_NODE_T(mem_block_t) list;				//
	ulint	len;															//
	ulint	total_size;												//
	ulint	type;															//
	ulint	free;															//
	ulint	start;														//
	void*	free_block;												//
	void*	buf_block;												//
};
```

``` c++
/** A C++ wrapper class to the mem_heap_t routines, so that it can be used
as an STL allocator */
template<typename T>
class mem_heap_allocator
{
public:
	typedef		T		value_type;
	typedef		size_t		size_type;
	typedef		ptrdiff_t	difference_type;
	typedef		T*		pointer;
	typedef		const T*	const_pointer;
	typedef		T&		reference;
	typedef		const T&	const_reference;

	mem_heap_allocator(mem_heap_t* heap) : m_heap(heap) { }

	mem_heap_allocator(const mem_heap_allocator& other)
		:
		m_heap(other.m_heap)
	{
		// Do nothing
	}

	template <typename U>
	mem_heap_allocator (const mem_heap_allocator<U>& other)
		:
		m_heap(other.m_heap)
	{
		// Do nothing
	}

	~mem_heap_allocator() { m_heap = 0; }

	size_type max_size() const
	{
		return(ULONG_MAX / sizeof(T));
	}

	/** This function returns a pointer to the first element of a newly
	allocated array large enough to contain n objects of type T; only the
	memory is allocated, and the objects are not constructed. Moreover,
	an optional pointer argument (that points to an object already
	allocated by mem_heap_allocator) can be used as a hint to the
	implementation about where the new memory should be allocated in
	order to improve locality. */
	pointer	allocate(size_type n, const_pointer hint = 0)
	{
		return(reinterpret_cast<pointer>(
			mem_heap_alloc(m_heap, n * sizeof(T))));
	}

	void deallocate(pointer p, size_type n) { }

	pointer address (reference r) const { return(&r); }

	const_pointer address (const_reference r) const { return(&r); }

	void construct(pointer p, const_reference t)
	{
		new (reinterpret_cast<void*>(p)) T(t);
	}

	void destroy(pointer p)
	{
		(reinterpret_cast<T*>(p))->~T();
	}

	/** Allocators are required to supply the below template class member
	which enables the possibility of obtaining a related allocator,
	parametrized in terms of a different type. For example, given an
	allocator type IntAllocator for objects of type int, a related
	allocator type for objects of type long could be obtained using
	IntAllocator::rebind<long>::other */
	template <typename U>
	struct rebind
	{
		typedef mem_heap_allocator<U> other;
	};

private:
	mem_heap_t*	m_heap;
	template <typename U> friend class mem_heap_allocator;
};
```

### values

堆内存的分配类型:

- `MEM_HEAP_DYNAMIC`: 从C编译器的动态内存池中分配;
- `MEM_HEAP_BUFFER`: 从缓冲池中分配;
- `MEM_HEAP_BTR_SEARCH`: 用于很大的堆.

### operations

`mem_heap_xxx`: `mem_heap_t`上的操作函数声明.



## mem0mem.ic
<span id="mem0mem.ic" />

部分`mem_heap_xxx`的实现.

部分`mem_block_xxx`的实现.

## mem0mem.cc
<span id="mem0mem.cc" />

部分`mem_heap_xxx`的实现.
