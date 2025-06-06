# [Bronze IV] Таблица результатов - 28808 

[문제 링크](https://www.acmicpc.net/problem/28808) 

### 성능 요약

메모리: 14148 KB, 시간: 100 ms

### 분류

구현, 문자열

### 제출 일자

2025년 3월 3일 21:52:15

### 문제 설명

<p>Ральф и Ванилопа во время путешествия по играм абсолютно случайно оказались на компьютере участника олимпиады по программированию. Более того, они выяснили, что участнику было предложено $n$ задач и по каждой из них можно отправлять решение не более $m$ раз.</p>

<p>Также герои обнаружили таблицу с результатами тестирования решений. Таблица состоит из $n$ строк и $m$ столбцов. В ячейке, которая находится в $i$-й строке и $j$-м столбце записан символ:</p>

<ul>
	<li><<<code>+</code>>>, если $j$-е отправленное решение по $i$-й задаче верное.</li>
	<li><<<code>-</code>>>, если $j$-е отправленное решение по $i$-й задаче неверное.</li>
	<li><<<code>.</code>>>, если по $i$-й задаче не было $j$ сданных решений.</li>
</ul>

<p>Ванилопа объяснила Ральфу, что первое верное решение по каждой задаче засчитывается и все остальные отправленные по данной задаче решения никак не влияют на результат участника.</p>

<p>Ральфу стало интересно, сколько же задач из предложенных участник олимпиады смог решить. Но так как он стесняется попросить о помощи Ванилопу, помогите ему!</p>

### 입력 

 <p>В первой строке даны два числа $n$ и $m$ --- число задач и максимальное возможное число отправленных решений по одной задаче соответственно ($1 \le n, m \le 100$).</p>

<p>В каждой из следующих $n$ строк содержится по $m$ символов <<<code>+</code>>>, <<<code>-</code>>> или <<<code>.</code>>> --- описание таблицы результатов.</p>

<p>Гарантируется, что после символа <<<code>.</code>>> могут находится только такие же символы.</p>

### 출력 

 <p>Выведите одно число --- количество задач, правильно решенных участником.</p>

