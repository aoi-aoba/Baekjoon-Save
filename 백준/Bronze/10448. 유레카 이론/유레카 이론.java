import java.io.*;

public class Main {
    static int[] gauss;    //삼각수 저장 배열
    static boolean[] check;    //삼각수 3개로 표현할 수 있는지 확인 배열

    public static void main(String[] args) throws IOException {
        //입력값 처리하는 BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //결과값 출력하는 BufferedWriter
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        gauss = new int[45];
        check = new boolean[1001];
        //1~44의 삼각수 미리 계산하기
        for (int i = 1; i < 45; i++)
            gauss[i] = i * (i + 1) / 2;
        //1~1000까지 3개의 삼각수의 합으로 표현가능한지 탐색
        for (int i = 1; i < 1001; i++)
            search(0, i, i);
        int T = Integer.parseInt(br.readLine());
        //T개의 수가 3개로 표현 가능한지 확인
        for (int i = 0; i < T; i++) {
            int K = Integer.parseInt(br.readLine());
            if (check[K])    //삼각수 3개로 표현 가능
                bw.write("1\n");
            else        //삼각수 3개로 표현 불가능
                bw.write("0\n");
        }
        bw.flush();        //결과 출력
        bw.close();
        br.close();
    }

    //삼각수 3개로 표현 가능한지 탐색하는 재귀함수
    static void search(int count, int cur, int index) {
        if (count == 3) {        //삼각수 3개를 사용했을 때
            if (cur == 0)    //삼각수 3개로 표현 가능할 때
                check[index] = true;
            return;
        }
        if (cur <= 0)    //삼각수 보다 커질 때
            return;
        //사용할 수 있는 삼각수 값들 모든 경우 탐색
        for (int i = 1; i < 45; i++) {
            if (cur < gauss[i])    //더 큰 삼각수일 경우 중단
                break;
            search(count + 1, cur - gauss[i], index);
        }
    }
}