# FAQ

Как се декларира статичен масив?
```c++
int arr[100];
```

Как се въвеждат данни в статичен масив?
```c++
int arr[10];
for(int i = 0; i < 10; i++) {
    std::cin >> arr[i];
}
```
Добра практика: декларираме масив с максимална големина MAX_SIZE и въвеждаме число `n`, което представлява размерността, с която ще работим в задачата. 
```c++
const int MAX_SIZE = 100;
int arr[MAX_SIZE], n;
std::cin >> n;
assert(n > 0 && n <= MAX_SIZE);
// or
do {
    std::cout << "Invalid Input. Try again."
    std::cin >> n;
} while (n > MAX_SIZE || n <= 0)
for(int i = 0; i < n; i++) {
    std::cin >> arr[i];
}
```

Как се инициализира статичен масив?
```c++
// uninitialized, bad practice
int arr[5];
// [1, 2, 3, 4, 5]
int arr[5] = { 1, 2, 3, 4, 5};
// [7, 7, 7, 7, 7]
int arr[5] = { 7 };
// [1, 2, 0, 0, 0]
int arr[5] = {1, 2};
// [1, 2]
int arr[] = {1, 2};
```

Как се намира големината на статичен масив?
```c++
const int MAX_SIZE = 5;
// we use MAX_SIZE as the size here
int arr[MAX_SIZE];

int arr[] = {1, 2, 3};
int size = sizeof(arr) / sizeof(int);
// works but a better practice is:
int size = sizeof(arr) / sizeof(arr[0]);
```

Как се предава масив като аргумент на функция?
```c++
void doWorkOnArray(int* array, int size) {

}

// ...
int arr[] = {1, 2, 3, 4, 5}, n = sizeof(arr) / sizeof(arr[0]);
doWorkOnArray(arr, n);

const int MAX_SIZE = 100;
int arr[MAX_SIZE], n;
std::cin >> n;
assert(n > 0 && n <= MAX_SIZE);
for(int i = 0; i < n; i++) {
    std::cin >> arr[i];
}
doWorkOnArray(arr, n);
``` 


# Задача 1
Напишете функция, която въвежда `n` числа в масиви ги извежда в прав и обратен ред.

**Example 1:**
```c++
Input: n = 6, [1, 7, 3, 6, 9, 0]
Output: 1, 7, 3, 6, 9, 0
        0, 9, 6, 4, 7, 1
```

# Задача 2
Напишете функция, която по подаден масив от числа с големина `n` извежда най-голямото.

**Example 1:**
```c++
Input: n = 6, [1, 7, 3, 6, 9, 0]
Output: 9
```

А ако искаме да намерим най-големите 3? Ами k?
# Задача 3
Да се напише програма, която въвежда естествено число n, по-малко от предварително избран MAX_SIZE, въвежда n на брой елемента в масив и изтрива всяко срещане на елемент k в масив (k се въвежда от клавиатурата).

**Example 1:**
```c++
Input: n = 6, [1, 7, 3, 6, 9, 0], k = 3
Output: [1, 7, 6, 9, 0]
```


**Example 2:**
```c++
Input: n = 7, [1, 2, 3, 4, 3, 4, 3], k = 3
Output: [1, 2, 4, 4]
```