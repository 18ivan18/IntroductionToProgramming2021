# Задача 1
По даден символен низ, съдържащ цифрите от 2 до 9 включително постройте всички комбинации от букви, които можем да напишем от телефон с копчета.

Съпоставянето на цифра с буква е показано отдолу.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

**Example 1:**
```c++
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```
**Example 2:**

```c++
Input: digits = ""
Output: []
```
**Example 3:**
```c++
Input: digits = "2"
Output: ["a","b","c"]
 ```

**Constraints:**

- 0 <= digits.length <= 4
- digits[i] is a digit in the range ['2', '9'].

# Задача 2
По дадени `n` двойки от отваряща и затваряща скоба напишете функция, която генерира всички комбинации от правилни скоби.


 

**Example 1:**
```c++
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```
**Example 2:**

```c++
Input: n = 1
Output: ["()"]
 ```

**Constraints:**

- 1 <= n <= 8

# Задача 3
По даден масив от различни цели числа върнете всички възможни пермутации.


**Example 1:**
```c++
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```
**Example 2:**
```c++
Input: nums = [0,1]
Output: [[0,1],[1,0]]
```
**Example 3:**
```c++
Input: nums = [1]
Output: [[1]]
 ```

**Constraints:**

- 1 <= nums.length <= 6
- -10 <= nums[i] <= 10
- All the integers of nums are unique.

# Задача 4
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)

```c++
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
```
**Example 2:**



![](https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg)
```c++
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
```
**Example 3:**


![](https://assets.leetcode.com/uploads/2020/10/15/word3.jpg)
```c++
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 ```

**Constraints:**

- m == board.length
- n = board[i].length
- 1 <= m, n <= 6
- 1 <= word.length <= 15
- board and word consists of only lowercase and uppercase English letters.
 