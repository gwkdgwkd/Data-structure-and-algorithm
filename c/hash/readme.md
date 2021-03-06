# 散列表

### 一般想法

1. 散列表（散列）是一种用于以常数平均时间执行插入、删除和查找的技术。但需要元素间任何排序信息的操作（FindMin、FindMax）都不支持。
2. 理想的散列表数据结构只不过是一个包含关键字的具有固定大小的数组。
3. 每个关键字被映射到从0到TableSize-1这个范围中的某个数，并且放到合适的单元中。这个映射就叫散列函数，理想情况下它应该运算简单并且应该保证任何两个不同的关键字映射到不同的单元。不过，这不可能，单元有限，关键字用不完。该函数应该在单元之间均匀地分配关键字。
4. 剩下要做的要选择一个函数，决定当两个关键字散列到同一个值的时候（冲突），应该做什么以及如何确定散列表的大小。

### 分离链接法

1. 解决冲突第一种方法通常叫做分离链接法，将散列到同一个值的所有元素保留到一个表中。
2. 二叉树、另一个散列表、链表都可能用来解决冲突。如果表大，同时散列函数好，那么解决冲突的表就应该短，不用进行复杂的尝试。
3. 缺点：需要指针；给新单元分配地址需要时间，导致算法的速度多少有些减慢；需要另一种数据结构的实现，除使用链表解冲突外。
4. 散列表的装填因子：散列表中的元素个数与散列表大小的比值。

### 开发定址法

1. 如果有冲突发生，就要尝试另外的单元，直到找出空的单元为止。
2. 所有的数据都要置于表内，所以比分离链接散列用表大。
3. 装填因子应该低于0.5。
4. 线性探测法，F(i)=i，逐个探测每个单元（必要时可以绕回）以查找出一个空单元。让元素几乎填满不是个好主意。
5. 一次聚集，需要多次选单元才能解决冲突。
6. 平方探测法，F(i)=i的平方，是消除线性探测中一次聚集问题的冲突解决方法。一旦表被填满超过一半，当表的大小不是素数时甚至在表被填满一半之前，就不能保证一次找到一个空单元了。
7. 平方探测排除了一次聚集，但是散列到同一位置的那些元素将探测相同的备选单元，叫二次聚集（理论上的一个小缺憾）。
8. 在开发定址散列表中，标准的删除操作不能施行，因为相应的单元可能已经引起过冲突，元素绕过它存在了别处。
9. 双散列，F(i)=i*hash2(x)，hash2(x)选择不好将会是灾难的。

### 再散列

1. 对于平方探测的开发定址散列法，如果表的元素填的太满，那么操作的运行时间将开始消耗过长，切插入可能失败，可能发生在有太多的移动和插入混合的场合。
2. 一种解决方法是建立另外一个大约两倍大的表（而且使用一个相关的新散列函数），扫描整个原始表，计数每个（未删除）元素的新散列值并插入新表中。整个操作就叫做再散列。
3. 再散列可以用平方探测以多种方法实现。一种是填满一半就再散列，另一种极端的方法是只有插入失败时才再散列，第三种为途中策略，当达到某个装填因子时进行再散列。

### 可扩散列

1. 处理数据量太大以至于装不进主存的情况，此时主要考虑检索数据所需的磁盘存取次数。
2. 允许用两次磁盘访问执行一次Find，插入也需要很少的磁盘访问。