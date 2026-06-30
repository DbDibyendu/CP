# Strategies for Reducing CPU Costs Associated with Hashtable Resizes and Rehashes

A hash table incurs resize and rehash costs primarily during **`insert` (put) operations** when the table crosses its **Load Factor threshold** (typically $\alpha = 0.75$).

When this threshold is breached, the table must allocate a completely new array (usually $2\times$ the original size) and **rehash everything**: iterate through every existing key, recalculate its hash code modulo the new capacity, and move it to its new bucket.

This causes massive $O(N)$ CPU spikes, disrupts the "p99 latency" for real-time applications, and triggers catastrophic CPU cache thrashing.

---

## High-Performance Architectural Strategies

Beyond custom bucketing logic, there are four major architectural strategies used in high-performance engineering to minimize or completely eliminate these CPU spikes:

### 1. Incremental / Amortized Rehashing (The Redis Approach)

Instead of rehashing all $N$ elements in a single, blocking $O(N)$ thread execution, the work is spread across subsequent operations.

- **Mechanism:** The system maintains **two** underlying bucket arrays: _Old_ and _New_.
- When a resize is triggered, the _New_ array is allocated but the bulk of the data is left in the _Old_ array.
- Every time an `insert`, `delete`, or `lookup` is called, the CPU migrates a small, fixed fraction of elements (e.g., 1 bucket or a few keys) from the _Old_ table to the _New_ table.
- **Result:** Flattening the $O(N)$ cost into a series of predictable, tiny $O(1)$ steps.

### 2. High-Precision Capacity Pre-allocation

The cheapest CPU cycle is the one that is never used. If the data volume can be predicted or estimated, resizing can be eliminated entirely.

- **Mechanism:** Initialize the hash table with an explicit capacity.
- **Rule of Thumb:** If you expect $K$ items, pre-allocate the capacity to:
  $$\text{Capacity} = \frac{K}{\text{Load Factor}}$$
  This ensures the table never reaches its limit and never triggers a single resize event throughout its lifecycle.

### 3. Hopscotch Hashing or Cuckoo Hashing (Open Addressing)

Instead of traditional chaining (linked lists in buckets), these open-addressing variants bound the search and displacement space.

- **Mechanism:** Cuckoo Hashing uses two hash functions and two tables. If a collision occurs, the old item is "kicked out" and moved to its alternative position.
- While it can still require a resize if a cyclic loop occurs, it boasts extremely high memory density and localized CPU cache lookups, making relocations fast compared to traveling down linked-list pointer chains.

### 4. Memory-Mapped Dynamic Segment Directories (Extendible Hashing)

This builds closely on custom bucketing logic by globalizing pointer maps rather than data structures.

- **Mechanism:** Instead of a single giant contiguous array, the hash table uses a shallow **Directory** of pointers that point to fixed-size **Data Buckets**.
- When a single bucket fills up, **only that specific bucket splits into two**. The other data buckets remain completely untouched.
- The only global operation is doubling the size of the _Directory_ array itself (which just contains lightweight memory pointers), requiring near-zero CPU computation compared to rehashing actual data elements.

---

## Engineering Tradeoffs for Architectural Evaluation

| Strategy               | CPU Impact                         | Memory Overhead                      | Implementation Complexity | Primary Use Case                       |
| :--------------------- | :--------------------------------- | :----------------------------------- | :------------------------ | :------------------------------------- |
| **Incremental Rehash** | Smooths p99 latency spikes         | Temporary $2\times$ memory footprint | High                      | Real-time caching (e.g., Redis)        |
| **Pre-allocation**     | Eliminates resize entirely         | High initial allocation              | Zero                      | Known batch data loads                 |
| **Extendible Hashing** | Localizes splits to single buckets | Extra indirection step               | Medium                    | Database storage engines, large scales |
