public class Main {
    public static void main(String[] args) {
        for(int a=1; a<=100; a++) {
            for(int b=2; b<=a; b++) {
                for(int c=b; c<=a; c++) {
                    for(int d=c; d<=a; d++) {
                        if(a*a*a == b*b*b + c*c*c + d*d*d) {
                            System.out.printf("Cube = %d, Triple = (%d,%d,%d)\n", a,b,c,d);
                        }
                    }
                }
            }
        }
    }
}