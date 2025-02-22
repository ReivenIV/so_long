
# Flood Fill explanation
_(done with GPT)_

```c
int	flood_fill(t_game *game, char **map, int x, int y)
{
	static int	collects; 											// Keeps track of the number of collected items
	static int	exits;    											// Keeps track of the number of exits reached

	if (y < 0 || x < 0 || y > game->amount_rows || x > game->amount_cols) // Check if out of bounds
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'X') 						// Stop if it's a wall ('1') or already visited ('X')
		return (0);
	if (map[y][x] == 'E') 											// If it's an exit ('E'), increase exit count
	{
		exits++; 
		map[y][x] = 'X'; 											// Mark the exit as visited
		return (0);
	}
	if (map[y][x] == 'C')											// If it's a collectible ('C'), increase the counter
		collects++;

	map[y][x] = 'X'; 												// Mark the current position as visited

	flood_fill(game, map, x + 1, y); 								// Move right
	flood_fill(game, map, x - 1, y); 								// Move left
	flood_fill(game, map, x, y + 1); 								// Move down
	flood_fill(game, map, x, y - 1); 								// Move up

	if (exits == 1 && collects == game->amount_c) 					// If one exit and all collectibles are found
		return (1); 												// Map is valid
	else
		return (0); 												// Map is invalid
}
```

### **What is it doing?**
The function explores the map like a flood, spreading in four directions (up, down, left, right). It keeps track of:
- How many collectibles (`C`) it finds.
- Whether it reaches the exit (`E`).

If the function finds **all** collectibles and reaches **exactly one exit**, it returns `1` (valid map). Otherwise, it returns `0` (invalid map).

---

### **Key concepts**
1. **Recursive exploration**  
   The function calls itself to explore the map in all four directions (like water flooding a maze).

2. **Stopping conditions (Base Cases)**  
   - It stops if it moves outside the map (`x` or `y` are out of bounds).
   - It stops if it hits a wall (`'1'`).
   - It stops if it has already visited the position (`'X'` is used to mark visited spots).
   - If it finds an exit (`'E'`), it increases the `exits` counter and marks it visited.

3. **Tracking collectibles**  
   - If it finds a collectible (`'C'`), it increases the counter.

4. **Checking validity**  
   - If it has found **exactly one exit** and **all collectibles**, the map is valid (`return 1`).

---

### **Example (small map)**
Imagine this simple map:
```
1111
1P01
1C01
1E11
1111
```
- `1` = Walls  
- `P` = Player start position  
- `C` = Collectible  
- `E` = Exit  

#### **How the function works**
1. It starts from `P` and moves in all four directions.
2. It marks visited spots with `'X'` so it doesn't visit them again.
3. It continues exploring until it reaches the exit and counts all collectibles.
4. If the exit and all collectibles are reachable, it returns `1`, meaning the map is good.

---

# More information, paralel context about "Flood Fill"

The `flood_fill` algorithm is much more than just a tool for validating maps in *so long*—it has broader applications and is part of a larger family of algorithms. Let’s explore its background and where else it’s used.

---

## **Flood Fill in a Larger Context**
### **1. Is it a Design Pattern?**
Flood fill itself is **not a formal design pattern** but rather a specific algorithm. However, it belongs to a larger family of **graph traversal algorithms**, specifically:
- **Depth-First Search (DFS)** (which it closely resembles)
- **Breadth-First Search (BFS)** (alternative approach)
- **Connected Component Labeling** (used in image processing)

The idea of "exploring a structure step by step" is common in algorithms that solve **search, pathfinding, and area coverage** problems.

---

## **2. Other Applications of Flood Fill**
Flood fill is widely used beyond *so long*! Here are some common applications:

### **a) Image Processing (Paint Bucket Tool in Photoshop)**
- If you’ve used a paint bucket in Photoshop, MS Paint, or any digital drawing tool, you’ve used flood fill.
- The tool fills an area of an image with a new color, stopping when it hits a boundary (different color or an edge).

### **b) Pathfinding and Maze Solving**
- In maze-solving problems, flood fill is useful to check if there is a path from the start to the exit.
- Unlike pathfinding algorithms like **A\***, flood fill doesn’t find the shortest path but rather **checks connectivity**.

### **c) Game Development (Procedural Map Generation)**
- In procedural dungeon generation (*like in Rogue-like games*), flood fill is used to check if all rooms in a randomly generated map are accessible.
- It prevents generating disconnected areas.

### **d) Artificial Intelligence (AI) in Games**
- AI uses flood fill in strategy games (like RTS games) to determine areas controlled by different players (territory control).

### **e) Cellular Automata (Game of Life)**
- Cellular automata models use flood fill to determine the spread of patterns based on rules.

### **f) Computational Geometry (Polygon Filling)**
- The **Scanline Fill Algorithm** used in computer graphics for filling polygons is a variant of flood fill.

---

## **3. Alternative Approaches**
Flood fill in *so long* uses **Depth-First Search (DFS)** recursion, but there are other ways to implement it:

### **a) Breadth-First Search (BFS) Approach (Using a Queue)**
Instead of recursion, BFS flood fill uses a queue. This is useful when you want to process pixels or cells **level by level** instead of diving deep into one direction first.

Example (using a queue instead of recursion):
```c
void flood_fill_bfs(t_game *game, char **map, int startX, int startY)
{
    int queue[10000][2]; // Simple queue to store (x, y) positions
    int front = 0, back = 0;
    queue[back][0] = startX;
    queue[back++][1] = startY;

    while (front < back)
    {
        int x = queue[front][0];
        int y = queue[front++][1];

        if (x < 0 || y < 0 || x >= game->amount_cols || y >= game->amount_rows || map[y][x] == '1' || map[y][x] == 'X')
            continue;

        map[y][x] = 'X'; // Mark visited

        queue[back][0] = x + 1; queue[back++][1] = y; // Right
        queue[back][0] = x - 1; queue[back++][1] = y; // Left
        queue[back][0] = x; queue[back++][1] = y + 1; // Down
        queue[back][0] = x; queue[back++][1] = y - 1; // Up
    }
}
```
BFS has the advantage of **avoiding stack overflow** issues that recursion might cause in large maps.

---

## **4. When Should You Use Flood Fill?**
You should use flood fill when:
- You need to determine **whether all areas of a structure are connected**.
- You need to check if **all objects (like collectibles) are reachable**.
- You need to **mark regions** dynamically based on conditions (e.g., coloring areas, labeling zones).
- Performance is not a major concern (flood fill can be inefficient for very large maps).

---

## **5. Limitations and Optimizations**
Flood fill can be inefficient for **very large maps** because:
- Recursive flood fill (DFS) can cause **stack overflow**.
- It explores **every possible path**, even if a solution is found early.

### **Optimizations**
- **Using BFS instead of DFS**: BFS prevents deep recursion issues.
- **Using a Disjoint Set (Union-Find)**: Instead of recursively checking, you can track connected regions efficiently.
- **Early Stopping**: If you find all required elements early, stop further exploration.
- **Bitmasking / Precomputed Tables**: For certain grid-based problems, precomputing reachable zones speeds up checks.

---

## **6. Final Thoughts**
Flood fill is a **versatile algorithm** with applications beyond *so long*. You might encounter it in:
- **Games** (map validation, pathfinding)
- **Graphics** (coloring, image segmentation)
- **AI** (territory control, connected component detection)
- **Mathematics** (graph theory, maze generation)
