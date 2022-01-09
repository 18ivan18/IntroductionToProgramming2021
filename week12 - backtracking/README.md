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
 

## Подготовка за контролно:
### Задача 1
Напишете функция `char** letterCasePermutation(char* str)`, която приема низ и
връща масив от низове с всички възможни пермутации, където буквите са
трансформирани да бъдат малки или големи. Резултатът да бъде сортиран
лексикографски. В главната функция `main` извикайте `letterCasePermutation` и
отпечатайте резултата.

**Example 1:**

```c++
Input: a1b2
Output: a1b2 a1B2 A1b2 A1B2
```

**Example 2:**

```c++
Input: 3z4 
Output: 3z4 3Z4
```

**Example 3:**

```c++
Input: 12345
Output: 12345 
```
### Задача 2
Да се напише функция, `int replace(char *text, const char *const str1, const char *const
str2)`, която заменя всички срещания на `str1` в `text` със `str2`. Като резултат `replace` да
върне броя на извършените промени. Да се напише функция `main`, в която
програмата да прочете от стандартния вход низовете `text`, `str1` и `str2`, да изпълни
функцията replace върху тях и да изведе на стандартния изход броя на
извършените промени, както и низа text след промените.

**Constraints:**
- `str1` и `str2` няма да надвишават дължина `1KB`
- `text` в нито един момент няма да надвишава дължина `4KB`

**За пълнота на функцията:**

Ако `text` или `str1` или `str2` e невалиден указател, функцията да хвърли грешка с подходящ текст.

Ако `text` или `str1` сочи към празен низ, функцията да хвърли друга грешка с подходящ текст

**Example 1:**

```c++
Input: axc x b
Output: 1 abc
```

**Example 2:**

```c++
Input: My name is who?
       who?
       Chica-chica Slim Shady!
Output: 1
        My name is Chica-chica Slim Shady
```

**Example 3:**

```c++
Input: aabbaaaa
       aa
       bb
Output: 3
        bbbbbbbb 
```

### Задача 3
Напишете програма, която иска от потребителя число `Nϵ[3;1000]`, което
индикира колко числа ще бъдат въведени, след това се въвежда `N` пъти
число `nϵZ`.
Програмата да извежда на конзолата дали дадената редица от числа е
`hacksaw`.
`Hacksaw` редица ще наричаме редица, която отговаря на следното условие:
`x0 < x1 > x2 < x3 > x4 < x5 … xn` или `x0 > x1 < x2 > x3 < x4 > x5 … xn`
.

**Задачата да се реши с рекурсия**.

**Examples:**

```c++
Input: 3
       1 2 3
Output: no
```
```c++
Input: 5
       7 6 5 4 3
Output: no
```

```c++
Input: 0
Output: Invalid number of arguments
```

```c++
Input: 2
       2 3
Output: Invalid number of arguments
```

```c++
Input: 4
       3 4 2 5 
Output: yes
```

```c++
Input: 6
       10 2 9 3 8 7
Output: yes
```