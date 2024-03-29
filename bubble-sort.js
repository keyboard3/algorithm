/**
 * 通过遍历数组的无序区域，对比交换到最后面
 * 然后不断缩小无序区域的范围，直至空集
 */
function sort(array, asc) {
    for (let i = 0; i < array.length; i++)
        for (let j = 1; j < array.length - i; j++) {
            if (array[j - 1] > array[j] && asc)
                [array[j], array[j - 1]] = [array[j - 1], array[j]];
            if (array[j - 1] < array[j] && !asc)
                [array[j], array[j - 1]] = [array[j - 1], array[j]];
        }
}

const array = [3, 10, 4, 2, 1];
sort(array, false);
console.log(array);