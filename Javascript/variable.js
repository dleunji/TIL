// 1. Use strict
'use strict';

// 2. Variable
// let(added in ES6)
let name = 'ellie';
console.log(name);
name = 'hello';
console.log(name);

// var(don't ever use this)
// var hoisting(move, declaration from bottom to top)
// has no block scope

// 3. Constants
// favor immutable data type always for a few reasons:
// - security
// - thread safety
// - reduce human mistakes

// 4. Variable types
// primitive single item : number, string, boolean, null, undefined, symbol
// object, box container
// function, first-class function
// big Int : n

//object
const ellie = { name: 'ellie', age: 20 };

// 5. Dynamic typing : dynamically typed language
let text = 'hello';
console.log(`value: ${text}, type: ${typeof text}`);

// Logical operator: || && !
// Equality == , ===(type까지 고려한 strict equality)
