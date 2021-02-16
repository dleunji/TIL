// async & await
'use strict';
// 1. async
async function fetchUser() {
  //do network request in 10 secs...
  return 'ellie';
}

const user = fetchUser();
user.then(console.log);

//2. await
function delay(ms) {
  return new Promise((resolve) => setTimeout(resolve, ms));
}
// 3초 있다가 사과를 리턴하면 async라는 키워드 덕분에 apple이라는 promise 형성
//
async function getApple() {
  await delay(1000);
  return '🍎';
}
// 3초 있다가 사과를 리턴하면 async라는 키워드 덕분에 banana라는 promise 형성
async function getBanana() {
  await delay(1000);
  return '🍌';
}

//original
function getBanana2() {
  return delay(3000).then(() => '🍌');
}

function pickFruits() {
  return getApple().then((apple) => {
    return getBanana2().then((banana) => `${apple} + ${banana}`);
  });
}

pickFruits().then(console.log);

async function pickFruits2() {
  const apple = await getApple();
  const banana = await getBanana();
  return `${apple} + ${banana}`;
}

pickFruits2().then(console.log);

//사과와 바나나는 독립적이므로 기다릴 필요가 없음
async function pickFruits3() {
  //각각의 프로미스를 만들면 된다. 병렬적으로 진행
  const applePromise = getApple();
  const bananaPromise = getBanana();
  const apple = await applePromise;
  const banana = await bananaPromise;
  return `${apple} + ${banana}`;
}
pickFruits3().then(console.log);

// 더 간단히!!
function pickAllFruits() {
  return Promise.all([getApple(), getBanana()]).then((fruits) =>
    fruits.join(' + ')
  );
}
pickAllFruits().then(console.log);

function pickOnlyOne() {
  return Promise.race([getApple(), getBanana()]);
}

pickOnlyOne().then(console.log);
