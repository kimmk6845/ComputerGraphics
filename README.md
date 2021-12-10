# ComputerGraphics
2020-2학기 컴퓨터그래픽스

## HW1
1. x값을 0에서 4까지 0.005씩 증가시키면서 GL_POINTS를 이용하여 아래와 같은 점 그래프, f(x) = 𝑒^(−𝑥)cos(2𝜋𝑥),를 그려보고자 한다. 
for 반복문을 사용하자. 
가시 공간은 gluOrtho2D의 L=0.0, R=4.0, B=-1.0, T=1.0으로 설정하였고 screen window의 크기를 가로 400 pixel, 세로 200 pixel로 정하였다.

<div align="center">
  
  ![HW1_1](https://user-images.githubusercontent.com/71704350/145531738-79dd5a64-de80-4b75-a8fc-a8bf388be981.PNG)
  
</div>


2. 가시 공간과 screen window의 크기를 적절하게 설정하고 OpenGL의 GL_TRIANGLE_STRIP을 한번만 사용하여 아래와 같은 square annulus를 screen window에 출력하고자 한다.
아래는 triangle strip의 일부만 보여주고 나머지 부분은 직접 triangle strip을 완성하자. 
단, 최소한의 vertex를 이용하여 triangulation을 하고자 한다. 아래와 같이 square annulus의 코너점들을 활용하여 최소한의 vertex 개수를 사용해 보자. Triangulation이 보이도록 초록색과 파란색을 교대로 사용하여 삼각형의 색을 입혀보자.

<div align="center">

  ![HW1_2](https://user-images.githubusercontent.com/71704350/145532108-c6c13084-83e0-40f3-88a1-2b05dcdfb7e9.PNG)
  
</div>


3. OpenGL에서 물체를 그릴 때 그리는 순서에 따라서 앞의 물체 위에 뒤의 물체가 덮어 씌워질 수 이다. 아래 왼쪽과 같은 도넛 모양을 만들기 위한 한가지 방법은 빨간색 원 모양 (큰 원)을 먼저 그린 후 하얀색 원 (작은 원)을 나중에 덮어 씌우는 방법이다
drdisc함수가 drdisc(반지름, 원의 중심의 x좌표, 원의 중심의 y좌표)라고 정의된 함수라면 다음과 같이 drdisc 함수를 2번 연속으로 호출함으로써 빨간색 원 위에 흰색 원을 덮어 씌우는 효과를 줄 수 있다. 
drdisc 함수를 완성하여 아래 왼쪽과 같은 도넛 모양을 출력해보자 
(hint: 색이 칠해진 원은 GL_TRIANGLE_FAN을 이용하자. 원의 중심 기준으로 바깥쪽 점들을 N개로 샘플링하여 여러 개의 삼각형으로 쪼개면 된다). 
이를 이용하여 타원과 원을 덮어 씌워가며 오른쪽과 같은 로고 모양을 만들어 보자.

<div align="center">

  ![HW1_3](https://user-images.githubusercontent.com/71704350/145532221-52d991a5-2be5-4c8a-b7bb-03b0bbf2c0e0.PNG)
  
</div>


4. 원을 parametric form을 이용해 근사화 하는 방법을 배웠다. 
원을 모든 각도에서 그리지 않고 일부만 그리는 것을 4번 반복하면 다음과 같은 모양을 만들 수 있다. 
겉 테두리는 GL_LINE_STRIP 사용하여 그릴 수 있다 아래 왼쪽과 같은 모양을 만들어 보자.
여러 개의 viewport를 사용하여 비슷한 방법으로 아래 오른쪽과 같은 tiling을 만들어 보자.

<div align="center">
  
  ![HW1_4](https://user-images.githubusercontent.com/71704350/145532386-ca883673-aacb-43cd-981a-b64b2e74165b.PNG)

</div>



---------------------------

## HW2
1. 물체의 변환을 이용하여 아래 그림 (a)-1과 같은 눈송이 모양을 만들고자 한다. 
이 눈송이는 대칭형태로 각 spoke (살)는 6개가 있고 각각은 같은 모양으로 60°씩 떨어져 있다.
각 spoke를 이루는 축과 가지는 축을 기준으로 60°의 각도를 이루고 있다. 
눈송이 모양을 만들기 위하여 기본이 되는 하나의 spoke를 완성한 후 이를 60도씩 회전하면서 glRotatef 함수를 6번 반복하여 그려보고자 한다. 


2. CTM과 복합 변환을 이용하여 아래 그림 (b)와 같은 모양을 만들어 보자. 각각의 dinosaur는 회전된 형태로 각각의 발은 원점을 향하는 모양이다.


3. 보드 게임을 보면 아래 그림 (d)와 같은 hexagonal grid를 자주 보게 된다. 
Hexagonal grid를 이루는 각각의 hexagon은 6개의 같은 길이의 변으로 이루어진 6-gon으로 각 내각은 120° 총 내각의 합은 720° 이다.
가시 공간 안에 모든 hexagon들이 들어오도록 변의 길이는 적절히 주자.
CTM과 복합 변환을 이용하여 총 19개의 hexagon이 붙어 있는 (d) 형태의 hexagonal grid를 만들어 보자.

<div align="center">

  ![HW2](https://user-images.githubusercontent.com/71704350/145534551-b1d69fa2-edff-445e-8bc6-b002363a87b5.PNG)
  
</div>


4. 아래 Dropbox 링크에 있는 코드와 같이 gluLookAt() 함수에서 eye와 center 위치를 정하였다.
Eye의 위치는 고정하고 center의 위치만 아래 4개와 같이 변경하였을 때 물체의 출력 결과를 보여주고 왜 그렇게 보이는지 설명해 보자. 
frustum과 eye, center의 위치와 LOS를 표시해 보고 이를 이용하여 설명해 보자
이해하기 쉽게 frustum을 위에서 내려다 본것과 같이 z축과 x축만을 이용하여 2D로 설명해보자.

   https://www.dropbox.com/s/uy5tnsas80p7ro4/HW2_4.txt?dl=0

   (1) 0.0, 0.0, -10.0 
   (2) 0.0, 0.0, 20.0 
   (3) 0.0, 0.0, 15.0 
   (4) 5.0, 0.0, 0.0



-----------------------------------

## HW3
1. 아래의 DDA 알고리즘 코드와 MidpointLine함수를 이용하여 브레스넘 알고리즘 OpenGL 코드를 완성해 보고자 한다. 
원래 DDA 알고리즘 코드에서 불필요한 부분은 지워도 된다. 단,MidpointLine 함수에서 x2>x1이고 선분의 기울기는 1보다 작다고 가정하자.

   https://www.dropbox.com/s/w5vd1ieul2thvof/DDA.txt?dl=0
   
   
   1) 선분의 양 끝점의 (x, y) 좌표가 (0, 0), (9, 5)로 주어졌을 때, line rasterization 결과를 표시해 보자. 업데이트 되는 D값을 구해라.
   2) 브레스넘 알고리즘을 완성한 후에 1)에서의 예에 대해서 최초 결정 변수 D값부터 종료될 때까지의 D값을 출력해보자. 1)의 결과와 동일한가?
   3) 브레스넘 알고리즘은 다음 후보 픽셀들의 중점을 이용하여 선분의 rasterization을 수행한다. 2)번의 경우 총 몇 개의 중점을 이용하였는가? 


2. ‘block.off’ 메쉬 파일은 off 파일 포맷을 사용하여 메쉬를 표현하였다. 파일을 편집기에서 열어보면 1번째 라인은 파일 포맷을 나타낸다 (이 부분은 메모리에 저장할 필요는 없다). 
2번째 line은 vertex 수, face 수, edge수를 의미 한다. 이 예에서는 edge 수를 사용하지 않으므로 무시하자. 
그 다음 라인부터는 vertex 수만큼 (이 예에서는 2,132개 ) vertex 의 x, y, z 좌표 정보가 담겨 있다. 
가장 위부터 vertex의 index를 나타낼 때 0번 vertex, 그 다음 line은 1번 vertex 이런 순서이다. 
그 후에는 face 수만큼 line이 있는데 각 line 에는 각 face의 vertex 수, 각 face를 이루는 vertex index (몇 번째 vertex) 정보가 있다.


   1) C나 C++의 파일 입출력을 이용하여 위의 ‘trim-star.off’ 메쉬 파일을 읽어보자.
   배열을 만들 때 1번째 line에서 읽은 vertex 수, face 수만큼 각각의 vertex, face 배열을 만들고 for 반복문을 이용하여 각 line 별로 읽으면서 Vertex의 x, y, z 좌표 정보 및 face 정보를 각 배열에 저장 하자.
   2) 1)에서 각 배열에 저장한 메쉬를 polygon으로 OpenGL을 이용하여 출력해보고 그 결과를 스크린샷으로 레포트에 넣어보자. 
   Meshlab으로 시각화한 결과와 비슷하게 나오는가? 각 polygon의 색은 임의로 정하고 적당한 가시 부피를 사용하자. 조명 처리는 따로 하지 않는다.


3. 아래는 3차 (cubic) Bezier curve를 2번 사용하고 끝에 polyline을 연결하여 만들었다. 
적당한 가시공간을 설정하고 Bezier curve를 위한 control points들을 설정하고 아래와 같은 모양을 만들어 보자. 
어떻게 control points들을 설정하였고 polyline을 사용하였는지 설명하고 실행 결과를 보여라.

<div align="center">

  ![HW3](https://user-images.githubusercontent.com/71704350/145560559-56fd02f9-e4be-46ec-aca1-1e7a0d91cc63.PNG)
  
</div>



---------------------------

## HW4
1. basic barn 메쉬 정보를 이용하여 basic barn 메쉬를 그리고자 한다.
gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0)을 이용하여 입체감 있게 LOS를 조정하자. 조명 모델을 사용하지 않고 각 face에는 yellow color를 입혀보고 투영 시 ‘glFrustum’을 사용하자. 
배경색은 black color로 정하자.


2. 1의 basic barn의 각 face에 있는 실제 bitmap image의 texture를 입히려고 한다. 
이 경우에 1에서 사용한 face의 color는 무시하고 첨부한 ‘canTop.bmp’ 이미지 파일을 texture로 사용하자. 
수동 texture mapping 시에 왜곡이 생기지 않도록 basic barn의 face 모양 (비율)과 texture space에서의 모양 (비율)을
동일하도록 수동 texture mapping을 수행하자. 
Texture에서 어느 부분을 가져올지는 직접 정하고 어떻게 왜곡이 없도록 수동 texture mapping을 수행했는지 설명하자.


3. 2의 결과에 Lecture 14 page 52의 예에서 사용한 조명 모델을 사용해 보자. 
‘glNormal3f’ 함수를 사용하고 정규화된 법선벡터를 사용하자. 
Lecture 18와 같이 texture 옵션 설정 시에 ‘GL_REPLACE’와 ‘GL_MODULATE’에 차이가 있는지 확인해보고 두 결과를 모두 보여라.
‘GL_MODULATE’를 사용시에는 1에서 사용한 face의 색과 texture의 색이 혼합되어 나오는가?


4. 아래 그림은 두 개의 rectangle과 alpha값을 이용한 blending 방법을 사용하여 그린 것이다. 
아래에서 배경은 white, 두 rectangle의 색은 각각 red와 blue이다. 
Alpha값을 얼마를 주면 아래와 같은 결과를 얻을 수 있을까? 왼쪽 오른쪽 그림에서 각각 source와 destination은 무엇일까? 
리포트에 설명해 보자. 왜 아래와 같이 보이는지 리포트에 설명해 보자. 
만일 glEnable(GL_DEPTH_TEST)를 사용하여 depth buffer를 사용하면 결과가 어떻게 바뀔까? 
출력 결과를 보여주고 결과에 대해서 이유를 설명해보자.

<div align="center">
  
  ![HW4_4](https://user-images.githubusercontent.com/71704350/145563563-6550b08b-2d18-48f5-a078-216493043ad6.PNG)

</div>


5. 
