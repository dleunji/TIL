const fs = require('fs');

/* 먼저 createStream으로 읽기 스트림을 만든다. 첫 번째 인수로 읽을 파일 경로를 넣고, 
두 번째 인수는 옵션 객체인데 highWaterMark라는 옵션이 버퍼의 크기를 정할 수 있다. */
const readStream = fs.createReadStream('./readme3.txt',{hightWaterMark : 16});
const data = [];

/* readStream은 이벤트 리스너를 붙여서 사용한다. 보통 data, end, error 이벤트를 사용한다.*/
readStream.on('data', (chunk)=>{
    data.push(chunk);
    console.log('data: ',chunk,chunk.length);
});

readStream.on('end',() => {
    console.log('end : ', Buffer.concat(data).toString);
});

readStream.on('error',(err)=>{
    console.log('error: ',err);
})

