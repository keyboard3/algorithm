/**
 * 遍历将无序区域的第一个插入到有序数组中（逐个向前交互到适合的位置）
 * 缩小无序数组的范围直到空集
 */
function sort(array, asc) {
    for (let i = 1; i < array.length; i++)
        for (let j = i; j > 0; j--) {
            if (array[j - 1] > array[j] && asc)
                [array[j], array[j - 1]] = [array[j - 1], array[j]];
            if (array[j - 1] < array[j] && !asc)
                [array[j], array[j - 1]] = [array[j - 1], array[j]];
        }
}
const array = [3, 4, 5, 2, 9];
sort(array, false);
console.log(array);