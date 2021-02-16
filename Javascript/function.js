// Function

// Default Parameters
function showMessage(message, from = 'unknown') {
  console.log(`${message} by ${from}`);
}
showMessage('Hi');

//Rest Parameters
function printAll(...args) {
  for (let i = 0; i < args.length; i++) {
    console.log(args[i]);
  }

  for (const args of args) {
    console.log(arg);
  }

  args.forEach((arg) => console.log(arg));
}
