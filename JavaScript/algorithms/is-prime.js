const isPrime = n => {

  if (n < 2) return false;

  const sqrt = Math.sqrt(n);

  for (let i = 2; i <= sqrt; i++) {
    if (n % i === 0) return false;
  };
  return true;
};

const test_0 = isPrime(1337);
const test_1 = isPrime(21234);

console.log(test_0);
console.log(test_1);
