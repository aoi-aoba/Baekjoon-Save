# [Bronze III] 가지 한 두름 주세요 - 31628 

[문제 링크](https://www.acmicpc.net/problem/31628) 

### 성능 요약

메모리: 11628 KB, 시간: 68 ms

### 분류

구현, 문자열

### 제출 일자

2025년 7월 14일 10:47:05

### 문제 설명

<p>$10 \times 10$ 격자의 각 칸에 가지가 한 개씩 들어 있습니다. 키위새는 가로로 연속한 $10$개의 칸 혹은 세로로 연속한 $10$개의 칸에 들어 있는 모든 가지를 단 한 번 줄줄이 연결할 수 있습니다. 가지 한 두름은 같은 색의 가지를 정확히 $10$개 연결한 것입니다. 각 칸에 들어 있는 가지의 색이 주어질 때, 키위새가 가지 한 두름을 만들 수 있는지 판단해 봅시다.</p>

<p style="display:flex;flex-direction:column;align-items:center;"><img alt="가지 한 두름의 예" src="https://upload.acmicpc.net/cdfb0b0a-9951-4a0b-8e99-5c7d4581cbe0/-/preview/" style="max-height:24em;max-width:100%"><span style="text-align:center;">첫 행의 모든 가지로 가지 한 두름을 만든 모습</span></p>

### 입력 

 <p>첫 번째 줄부터 $10$개 줄 각각에 각 행에 들어 있는 가지 $10$개의 색을 나타내는 문자열이 공백으로 구분되어 주어집니다. 그중 $r$번째 줄의 $c$번째 문자열은 $r$행 $c$열에 위치한 가지의 색을 나타냅니다. 가지의 색은 영어 소문자로만 이루어진 길이 $1$ 이상 $8$ 이하의 문자열입니다.</p>

### 출력 

 <p>키위새가 가지 한 두름을 만들 수 있으면 <span style="color:#e74c3c;"><code>1</code></span>을, 만들 수 없으면 <span style="color:#e74c3c;"><code>0</code></span>을 출력합니다.</p>

