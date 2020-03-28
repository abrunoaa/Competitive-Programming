'use strict'

var input = [];
require('readline')
.createInterface({
    input: process.stdin,
    terminal: true
})
.on('line', (line) => input.push(line))
.on("close", () => main());

const next = () => input.shift();
const nextInt = () => parseInt(next());
const nextFloat = () => parseFloat(next());

function main() {
    while (input.length > 0) {
        var n = next();
        if (n === '42') {
            break;
        }
        console.log(n);
    }
}
