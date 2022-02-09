# fut: File-based Utilities: 文件工具

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [fut0fut.h](#fut0fut.h)                |    41 | 基于文件的工具 ||
| [fut0fut.ic](#fut0fut.ic)              |    48 |||
| [fut0lst.h](#fut0lst.h)                |   169 | 基于文件的列表工具 ||
| [fut0lst.ic](#fut0lst.ic)              |   151 |||
| [fut0fut.cc](#fut0fut.cc)  |    13 |||
| [fut0lst.cc](#fut0lst.cc)  |   465 |||

## fut0fut.h
<span id="fut0fut.h" />

`fut_get_ptr`的声明: 获取文件地址指针并在文件中页上加latch.

base节点和列表节点的类型:

``` c++
typedef	byte	flst_base_node_t;
typedef	byte	flst_node_t;
```

工具:

- `flst_init`: 初始化base节点
- `flst_add_last`: 在列表尾部加入节点
- `flst_add_first`: 在列表头部加入节点
- `flst_insert_after`: 在节点后插入节点
- `flst_insert_before`: 在节点前插入节点
- `flst_remove`: 移除节点
- `flst_get_len`: 获取列表长度
- `flst_get_first`: 获取第一个节点
- `flst_get_last`: 获取最后一个节点
- `flst_get_next_addr`: 获取下一个节点
- `flst_get_prev_addr`: 获取前一个节点
- `flst_write_addr`: 写入文件地址
- `flst_read_addr`: 读取文件地址
- `flst_validate`: 验证列表
- `flst_print`: 打印列表

## fut0fut.ic
<span id="fut0fut.ic" />

`fut_get_ptr`的实现.

## fut0lst.h
<span id="fut0lst.h" />

## fut0lst.ic
<span id="fut0lst.ic" />

## fut0fut.cc
<span id="fut0fut.cc" />

## fut0lst.cc
<span id="fut0lst.cc" />
