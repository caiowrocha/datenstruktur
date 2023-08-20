const maxValue = numbers => {
    let max = -Infinity;

    for(let num of numbers) {
        if(num > max) max = num;
    };
    return max;
};

const Array = [1, 2, 5, -3, -20, -100, 1000];

let result = maxValue(Array);

console.log(result);

// Time: O(n);
// Space: O(1);