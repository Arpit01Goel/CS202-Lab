function fibb(n) {
    let a = 0, b = 1, c = 1;
    for (let i = 0; i < n; i++) {
        a = b;
        b = c;
        c = a + b;
    }
    // a is now nth fibb
    // console.log(a);
}

function tim() {
    const start = Date.now();
    for (let i = 0; i < 50; i++) {
        fibb(100);
    }
    const end = Date.now();
    return (end - start);
}

let totalTime = 0;
for (let i = 0; i < 200; i++) {
    totalTime += tim();
}

totalTime /= 200;
console.log(totalTime);