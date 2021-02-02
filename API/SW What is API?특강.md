# What is API?

- 일반적으로 API는 프로그램이나 서비스를 만들 때 사용하는 인터페이스
- 여기서는 Open API + REST API로 범위를 줄여 말한다.
  - Open API : 외부에서 사용하도록 공개한 API들(ex. 주소 검색, 번역)
  - REST API : HTTP 메소드로 접근 가능한 API
- API를 가져다 쓰면 일을 줄이고 해커톤에서 하려는 것에 집중할 수 있다.



# How to use API



### REST API 사용법

- REST API는 POST/GET/PUT/DELETE 등 HTTP 메소드를 이용해서 호출
- 그러나 해커톤에서는 Open API를 사용하는 경우 GET 또는 POST를 쓰는 경우가 대부분
  - GET 
    - shell에서 curl로 요청 가능 
    - Browser에서 해당 주소를 입력하면 GET으로 요청됨
  - POST 
    - 사진과 같이 파일을 요청에 함께 보내거나, 발급 받은 사용키를 같이 보내야한다면 보통 POST 요청으로 보내야한다.
    - Postman : REST API를 관리하고 자유롭게 테스트 가능
- 서비스에서 API 호출하기
  - Networking 관련 Library에서 REST API는 거의 다 지원한다.
    - Android : Retrofit2, OkHttp
    - iOS : Alamofire, AFNetworking
    - Javascript : Axios
  - 일반적으로 API를 호출하고 받는 Response format으로 JSON 파일을 많이 쓴다
    - 적절한 JSON Parser Library를 찾아 붙이자
      - Android라면 Retrofit2 + Gson



# Where is API?

1. IT 회사들의 개발자 사이트
2. API Marketplace(ainize.ai / RapidAPI)
3. 공공데이터 포털(공공데이터포털 ainize.ai / 서울시 열린데이터 광장)



# Which API do I use?

1. 어떤 API들이 필요한지 파악한다.

2. 찾은 API를 직접 확인해본다. / API Doc이나 Tutorial을 확인해본다.

3. API가 없는 것에 대한 해결책을 찾아본다.

4. ex) [ainize marketplace](https://ainize.ai)

   ex) [showcase](link.ainize.ai/ainize-showcase)

   











