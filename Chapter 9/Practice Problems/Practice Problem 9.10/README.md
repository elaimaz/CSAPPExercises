### ***Practice Problem 9.10***:  
Describe a reference pattern that results in severe external fragmentation in an allocator based on simple segregated storage.  

---  

### ***Answear***:  
The application makes numerous allocation and free requests to the ﬁrst size class, followed by numerous allocation and free requests to the second size class, followed by numerous allocation and free requests to the third size class, and so on. For each size class, the allocator creates a lot of memory that is never reclaimed because the allocator doesn’t coalesce, and because the application never requests blocks from that size class again.  
