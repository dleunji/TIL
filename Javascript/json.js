'use strict';

// 1. Object to JSON
// stringfy(obj)

let json = JSON.stringify(true);
console.log(json);

json = JSON.stringify(['apple', 'banana']);
console.log(json);

const rabbit = {
  name: 'tori',
  color: 'white',
  size: null,
  birthDate: new Date(),
  jump: () => {
    console.log(`${this.name} can jump!`);
  },
};

json = JSON.stringify(rabbit);
console.log(json);

// 2. JSON to Object
// parse(json)
console.clear();

const obj = JSON.parse(json);
const obj2 = JSON.parse(json, (key, value) => {
  console.log(`key: ${key}, value : ${value}`);
  return key == 'birthDate' ? new Date(value) : value;
});
console.log(obj2);
