/*
 * ============================================================================
 * INTERVIEW CHEAT SHEET: std::set vs. std::priority_queue (Under the Hood)
 * ============================================================================
 *
 * 1. std::set / std::map  -->  RED-BLACK TREE (Self-Balancing Binary Search Tree)
 * ------------------------------------------------------------------------
 * - Structure: Node-based. Every element is a dynamic node allocated on the heap.
 * - Memory Overhead: High pointer overhead. Each individual node stores:
 * * The actual data value
 * * Pointer to Left child
 * * Pointer to Right child
 * * Pointer to Parent node
 * * Metadata bit for tracking color (Red or Black)
 * - Sorting Rule: STRICT / TOTAL ORDERING. The entire container is kept 100%
 * sorted from smallest to largest at all times.
 * - Time Complexity: O(log N) for Search, Insertion, and Deletion.
 * - Best For: When you need to print everything in order, look up arbitrary 
 * elements, or use functions like lower_bound / upper_bound.
 *
 * 2. std::priority_queue  -->  ARRAY-BASED BINARY HEAP (Container Adapter)
 * ------------------------------------------------------------------------
 * - Structure: A complete binary tree packed tightly into a contiguous memory 
 * array (by default, it just wraps around a standard std::vector).
 * - Memory Overhead: ZERO pointer overhead. Pointers don't exist here. Instead,
 * parent-child relationships are calculated instantly via fast array-index math:
 * * Left Child Index  = 2 * i + 1
 * * Right Child Index = 2 * i + 2
 * * Parent Index      = (i - 1) / 2
 * - Sorting Rule: PARTIAL ORDERING. It does the absolute bare minimum amount 
 * of sorting required to keep the heap property valid. It only guarantees that 
 * a parent node is better than its immediate children. It has no idea if the 
 * left subtree is larger than the right subtree.
 * - Time Complexity: O(1) to view top, O(log N) for Push and Pop.
 * - Best For: Greedy algorithms (like Dijkstra's or building Schedulers) where 
 * you only care about repeatedly extracting the absolute "#1 best" element. 
 * Because it uses a flat vector, it is incredibly fast and CPU cache-friendly.
 *
 * ============================================================================
 * SUMMARY VERDICT FOR THE WHITEBOARD:
 * std::set maintains a fully ordered web of dynamic pointer nodes.
 * std::priority_queue is just a vector using clever array math to keep the best 
 * element resting at index 0.
 * ============================================================================
 */


/*
 * ============================================================================
 * THE ULTIMATE BALANCE OF POWER: AVL TREES VS. RED-BLACK TREES
 * ============================================================================
 * * ----------------------------------------------------------------------------
 * 1. THE AVL TREE (The Strict Perfectionist)
 * ----------------------------------------------------------------------------
 * Core Philosophy: Keep the tree as absolutely flat and perfectly balanced 
 * as mathematically possible to maximize lookup speeds.
 * * THE SACRED LAW:
 * For EVERY node in the tree, the height difference between its Left subtree 
 * and Right subtree can be AT MOST 1.
 * * Formula: Balance Factor (BF) = Height(Left Subtree) - Height(Right Subtree)
 * Allowed BF Values: {-1, 0, 1}
 *
 *
 *
 * Violating BF Values: {-2, 2} -> Triggers immediate rebalancing.
 *
 * * THE 4 BALANCING METHODS (Rotations):
 * When an insertion or deletion pushes a node's BF to -2 or 2, the tree
 * identifies the shape of the imbalance and executes one of four maneuvers:
 *
 *
 * * 1. Left Rotation (LL)   -> Single pivot left when right-child is right-heavy.
 * 2. Right Rotation (RR)  -> Single pivot right when left-child is left-heavy.
 * 3. Left-Right (LR)      -> Double rotation (Left then Right) to fix a left-child 
 * that is right-heavy (a zigzag shape).
 * 4. Right-Left (RL)      -> Double rotation (Right then Left) to fix a right-child 
 * that is left-heavy (a zigzag shape).
 *
 *
 * * PROS:  Blindingly fast lookups/searches because the tree height is minimal.
 * CONS:  High maintenance. Frequent, strict rotations make insertions and 
 * deletions slower compared to looser trees.
 *
 *
 *
 *
 *
 *
 *
 * * ----------------------------------------------------------------------------
 * 2. THE RED-BLACK TREE (The Practical Pragmatist)
 * ----------------------------------------------------------------------------
 * Core Philosophy: "Good enough" balance is better than perfect balance. Save
 * CPU cycles by rotating less and recoloring more.
 * * THE 5 SACRED LAWS:
 * 1. Node Identity: Every node is strictly painted either RED or BLACK.
 * 2. Root Guard   : The Root node is ALWAYS BLACK.
 * 3. Leaf Guard   : Every leaf node (the empty NULL pointers at bottom) is BLACK.
 * 4. Red Isolation: NO TWO RED NODES CAN TOUCH. If a node is RED, its 
 * children MUST be BLACK. (No consecutive REDs along a path).
 * 5. Black Height : Every path from a node to any of its descendant NULL 
 * leaves must contain the EXACT same number of BLACK nodes.
 *
 *
 * * THE 2 BALANCING METHODS:
 * Newly inserted nodes are ALWAYS painted RED (so they don't break Law #5). 
 * If they land next to another RED node, breaking Law #4, the tree checks 
 * the color of the "Uncle" node to pick a fix:
 * * Case A: The Uncle is RED
 * -> Method: RECOLORING. Flip the colors of the Parent and Uncle to BLACK, 
 * and flip the Grandparent to RED. Pass the check up the tree.
 * * Case B: The Uncle is BLACK (or NULL)
 * -> Method: ROTATION + RECOLOR. Perform a structural rotation (similar 
 * to AVL) around the Grandparent, then swap the colors of the 
 * old parent and new parent to restore structural peace.
 * * PROS:  Incredibly efficient insertions and deletions because recoloring bits 
 * is computationally dirt cheap compared to restructuring pointers.
 * CONS:  Slightly taller tree paths mean lookups can theoretically take a fraction 
 * of a microsecond longer than a strict AVL tree.
 * * ============================================================================
   *
   *
   *
   *
 * SUMMARY CHEAT SHEET FOR HIGH-SCALE ARCHITECTURE:
 * ============================================================================
 * Workload Trend          Winner             Real-World C++ Example
 * -----------------------------------------------------------------
 * Read-Heavy (99% Search)  AVL Tree           Databases, Dictionary lookups
 * Write-Heavy / Balanced   Red-Black Tree     std::set and std::map
 * ============================================================================
 */
