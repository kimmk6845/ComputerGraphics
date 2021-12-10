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

3. OpenGL에서 물체를 그릴 때 그리는 순서에 따라서 앞의 물체 위에 뒤의 물체가 덮어 씌워질 수 이다. 아래 왼쪽과 같은 도넛 모양을 만들기 위한 한가지 방법은 빨간색 원 모양 (큰 원)을 먼저 그린 후 하얀색 원 (작은 원)을 나중에 덮어 씌우는 방법이다
drdisc함수가 drdisc(반지름, 원의 중심의 x좌표, 원의 중심의 y좌표)라고 정의된 함수라면 다음과 같이 drdisc 함수를 2번 연속으로 호출함으로써 빨간색 원 위에 흰색 원을 덮어 씌우는 효과를 줄 수 있다. 
drdisc 함수를 완성하여 아래 왼쪽과 같은 도넛 모양을 출력해보자 
(hint: 색이 칠해진 원은 GL_TRIANGLE_FAN을 이용하자. 원의 중심 기준으로 바깥쪽 점들을 N개로 샘플링하여 여러 개의 삼각형으로 쪼개면 된다). 
이를 이용하여 타원과 원을 덮어 씌워가며 오른쪽과 같은 로고 모양을 만들어 보자.

4. 원을 parametric form을 이용해 근사화 하는 방법을 배웠다. 
원을 모든 각도에서 그리지 않고 일부만 그리는 것을 4번 반복하면 다음과 같은 모양을 만들 수 있다. 
겉 테두리는 GL_LINE_STRIP 사용하여 그릴 수 있다 아래 왼쪽과 같은 모양을 만들어 보자.
여러 개의 viewport를 사용하여 비슷한 방법으로 아래 오른쪽과 같은 tiling을 만들어 보자.
