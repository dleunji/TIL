## 00. Basic CLI

Command Line Interface

1. `ls` : 목록조회(list)

   ```
   00_basic_cli.md	a.txt		c.txt		markdown.md
   IMG_1043.JPG	b.txt		images
   ```

   `ls -al` : 상세 목록 조회

   ```
   total 3432
   drwxr-xr-x  10 Eunji  staff      320 12 29 15:08 .
   drwxr-xr-x+ 72 Eunji  staff     2304 12 29 13:18 ..
   drwxr-xr-x  13 Eunji  staff      416 12 29 13:24 .git
   -rw-r--r--@  1 Eunji  staff      205 12 29 15:08 00_basic_cli.md
   -rw-r--r--@  1 Eunji  staff  1746766 12 29 12:27 IMG_1043.JPG
   -rw-r--r--   1 Eunji  staff        0 12 29 13:19 a.txt
   -rw-r--r--   1 Eunji  staff        0 12 29 13:19 b.txt
   -rw-r--r--   1 Eunji  staff        0 12 29 13:19 c.txt
   drwxr-xr-x   3 Eunji  staff       96 12 29 14:35 images
   -rw-r--r--@  1 Eunji  staff      591 12 29 15:04 markdown.md
   ```

2. `cd` : 폴더 변경(change directory)
   1. `cd` :`~` 폴더 (home)로 이동
   2. `cd 폴더명` : `폴더명`으로 이동
      1. `cd 폴더명/폴더명/폴더명` : 여러 개의 폴더 한 번에 이동
   3. `cd ..` : 상위폴더로 이동 
3. `mkdir` : 폴더 생성(make directory)
   1. `mkdir A`: A이라는 이름의 폴더를 생성
4. `touch` : 파일 생성
   1. `touch A.txt`: `A.txt`파일을 생성(빈 파일)
5. `cp`: 파일 /폴더 복사
   1. `cp A B` : A라는 파일/폴더를 복사하여 B를 생성

6. `mv` : 파일/폴더 이동
   1. `mv A.txt b/A.txt` : A.txt파일을 B 폴더 안으로 이동
   2. `mv A.txt C.txt` : A.txt파일 이름을 C.txt로 변경
7. tab : 자동완성 기능
8. 



