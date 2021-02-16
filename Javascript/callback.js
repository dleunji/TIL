'use strict';
// Javascript is synchronous
// Execute the code block by order after hoisting

console.log('1');
setTimeout(() => {
  console.log('2');
}, 2000);
console.log('3');
// Synchronous callback
function prinImmediately(print) {
  print();
}
prinImmediately(() => {
  console.log('hello');
});
// Asynchronous callback
function printWithDelay(print, timeout) {
  setTimeout(print, timeout);
}

printWithDelay(() => console.log('async callback'), 2000);
