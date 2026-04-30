1/**
2 * @return {Generator<number>}
3 */
4var fibGenerator = function*() {
5    let a = 0, b = 1;
6
7    while(true) {
8        yield a;
9
10        let temp = a + b;
11        a = b;
12        b = temp;
13    }
14};
15
16/**
17 * const gen = fibGenerator();
18 * gen.next().value; // 0
19 * gen.next().value; // 1
20 */