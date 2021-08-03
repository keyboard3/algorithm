/**
 * 遍历数组无序区域，找到最小/最大的，然后与第一个交换
 * 缩小无序区域的范围直到空集
 */
function sort(array, asc) {
    for (let i = 0; i < array.length; i++) {
        let compIndex = i;
        for (let j = i + 1; j < array.length; j++) {
            if (array[compIndex] > array[j] && asc)
                compIndex = j;
            if (array[compIndex] < array[j] && !asc)
                compIndex = j;
        }
        [array[compIndex], array[i]] = [array[i], array[compIndex]];
    }
}
const array = [3, 4, 5, 2, 9];
sort(array, false);
console.log(array);