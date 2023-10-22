# Code Wars solution
The solution is in:
```
/CodeWarsSolution/solution.cpp
```
You can find both the function and the test cases there. Apart from the given examples of test cases, I have included a few of my own. I changed the function declaration to:
```cpp
int material(const std::vector<int>& spaceship);
```
Instead of:
```cpp
int material(int[] spaceShip)
```
In C++, the latter one would require an additional parameter for the size of the array. I hope this change is fine. In the **main.cpp** file, there is a main method with **testMaterial()** invocation.
